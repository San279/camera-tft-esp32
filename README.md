# Esp32 camera feed to TFT
This project was indended to provide an insight for displaying Esp32 camera feed to ST7789 driver or any TFT screens using the Arduino IDE. The Hardware that was used were provided by [Wireless Solution Asia](https://wirelesssolution.asia/) Follow few steps below and you're good to go. For more information please visit [Bodmer / TFT_eSPI](https://github.com/Bodmer/TFT_eSPI/blob/master/README.md)<br/> <br/>
![alt_text](/images-for-readme/AIOT.PNG)
<br/> <br/>
## What you'll need
- [Arduino IDE](https://www.arduino.cc/en/software), preferably the latest ones, but older versions will still do the job.
- ESP32-S3 is preferable but older version will do just fine.
- ST7789 or any TFT screens <br/> <br/>
  Here's the Pinout of the AIoT Board with ESP32 Camera and ST7789 (TFT) used for this project. <br/> <br/>
- ![alt_text](/images-for-readme/pinout.PNG)
 <br/> <br/>
## Project files descriptions
- camera-to-tft - Contain Arduino codes to display camera feed to tft screen continously.
- User_Setup.h - Contain driver types, pinout, resolution, and etc. This needs to be placed inside the TFT_eSPI library.  <br/> <br/>
 # Run the project
1. Download the project and unzip it to your Arduino Directory. <br/> <br/>
![alt_text](/images-for-readme/download_directory.PNG)
 <br/> <br/> <br/> <br/>
2. Download TFT_eSPI library from Arduino's download manager or github [Bodmer / TFT_eSPI](https://github.com/Bodmer/TFT_eSPI/blob/master/README.md). If you're using github to download you will need to add custom library using zip file.<br/> <br/>
![alt_text](/images-for-readme/library_manager.PNG)
 <br/> <br/><br/> <br/>
4. Replace User_Setup.h inside TFT_eSPI library with this User_Setup.h. From Arduino's directory, go to libraries -> TFT_eSPI and replaced the file.
If you're using different Esp32 pinout, driver types, and resolutions please change it in User_Setup.h line 221 88 55  <br/> <br/>
![alt_text](/images-for-readme/replace.PNG)
 <br/> <br/> <br/> <br/>
5. Match the Esp32 settings to your board, here's my setting for AIOT board. Don't forget to enable OPI PSRAM.  <br/> <br/>
 ![alt_text](/images-for-readme/esp_setup.PNG)
 <br/> <br/> <br/> <br/>
6. Done! Upload the code to Esp32 and enjoy  <br/> <br/>
![alt_text](/images-for-readme/AIOT.PNG)
 <br/> <br/> <br/> <br/>
## Credits
Thanks to [Wireless Solution Asia](https://wirelesssolution.asia/) for providing essentials tools and [Bodmer / TFT_eSPI](https://github.com/Bodmer/TFT_eSPI/blob/master/README.md) for TFT libraries.
