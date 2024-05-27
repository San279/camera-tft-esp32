#include "esp_camera.h"
#include <SPI.h>
#include <TFT_eSPI.h>

#define PWDN_GPIO_NUM -1
#define RESET_GPIO_NUM -1
#define XCLK_GPIO_NUM 15
#define SIOD_GPIO_NUM 4
#define SIOC_GPIO_NUM 5

#define Y9_GPIO_NUM 16
#define Y8_GPIO_NUM 17
#define Y7_GPIO_NUM 18
#define Y6_GPIO_NUM 12
#define Y5_GPIO_NUM 10
#define Y4_GPIO_NUM 8
#define Y3_GPIO_NUM 9
#define Y2_GPIO_NUM 11
#define VSYNC_GPIO_NUM 6
#define HREF_GPIO_NUM 7
#define PCLK_GPIO_NUM 13

camera_fb_t* fb = NULL;
TFT_eSPI tft = TFT_eSPI();
unsigned long previousMillis = 0;  // Stores the time when the timer was last updated
const long interval = 1000;
int fps = 0;
String strFps = "";
void setup() {
  Serial.begin(115200);
  camera_config_t config;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;

  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;

  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_240X240;
  config.jpeg_quality = 15;
  config.fb_count = 1;

  config.fb_location = CAMERA_FB_IN_PSRAM;
  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;

  displayInit();
  //tft.invertDisplay(true);
  // Camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }
  sensor_t * s = esp_camera_sensor_get();
  s->set_vflip(s, 1); 
  Serial.println("camera ok");
  // Wi-Fi connection
}

void displayInit() {
  tft.begin();
  tft.setRotation(2);
  tft.fillScreen(TFT_BLACK);
  tft.setSwapBytes(true);
  tft.setTextColor(TFT_GREEN);
  tft.setTextSize(2);  // Adjust text size as needed
}

void loop() {
  unsigned long currentMillis = millis();
  tft.setCursor(10, 10);
  tft.print("FPS : ");
  tft.print(strFps);
  fb = esp_camera_fb_get();
  if (!fb) {
    Serial.printf("Camera capture failed!");
    tft.drawString("Camera capture failed!", 0, 240);
  } else {
    uint8_t* rgb565 = (uint8_t*)malloc(240 * 240 * 3);
    jpg2rgb565(fb->buf, fb->len, rgb565, JPG_SCALE_NONE);
    tft.pushImage(0,0,240,240,(uint16_t*)rgb565);
    if (currentMillis - previousMillis >= interval) {
      Serial.printf("FPS %d\n", fps);
      strFps = String(fps);
      fps = 0;
      previousMillis = currentMillis;
    }
    free(rgb565);
    fps++;
  }
  esp_camera_fb_return(fb);
  fb = NULL;
}
