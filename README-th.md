## camera-tft-esp32
 [For English version](https://github.com/San279/Esp32-camera-to-tft)
 <br/>
 <br/>
 โปรเจ็คนี้ถูกออกแบบมาใช้กับ [FOMO](https://docs.edgeimpulse.com/docs/edge-impulse-studio/learning-blocks/object-detection/fomo-object-detection-for-constrained-devices) AI ตรวจจับวัตถุ ในส่วนของการเซ็ทอัพจอ TFT กับกล้อง AIoT บอร์ด หรือ Esp32 ที่มี PSRAM เท่านั้น
<br/>
## สิงที่ต้องมี
 - [AIoT](https://wirelesssolution.asia/) บอร์ด Esp32-S3 หรือ Esp32 ที่มี PSRAM
 - กล้อง OV 2640
 - ST7789 หรือ จอ TFT แบบไหนก้ได้ <br/>
 - [Arduino IDE](https://www.arduino.cc/en/software) อันเก่าหรือใหม่ก้ได้
   รูปแผงวงจรของกล้องกับจอ TFT ใน AIot บอร์ด <br/> <br/>
  ![alt_text](/images-for-readme/pinout.PNG)
## โครงสร้าง
 - camera-to-tft - มีไฟล์ Arduino เพื่อแสดงรูปภาพขึ้นบนหน้าจอ TFT.
 - User_Setup.h - เฮเด้อไฟล์สำหรับ c++ ต้องนำไฟล์นี้ไปแทนที่ไฟล์เดิมในแฟ้ม TFT_eSPI  <br/> <br/>
## วิธีรันโปรเจ็ค
<strong> 1. ดาวน์โหลดไลบราลี่เป็น zip และแตกไฟล์ในแฟ้ม Arduino. </strong>
<br /><br />
![alt_text](/images-for-readme/download_directory.PNG)
<br /><br /><br /><br />
<strong> 2. เปิดไฟล์ camera-to-tft.ino Arduino ในแฟ้มที่พึ่งแยกออก และในช่องด้ายซ้านมือให้กดไปที่ library และค้นหา TFT_eSPI เพื่อดาวโหลดไฟล์</strong>
<br /><br />
![alt_text](/images-for-readme/library_manager.PNG)
<br /><br /><br /><br />
<strong> 3. นำไฟล์ User_Setup.h ไปใว้แทนในแฟ้ม TFT_eSPI </strong> 
 - บนคอมพิวเตอร์เราไปที่ Documents -> Arduino -> libraries -> TFT_eSPI และนำไฟล์ User_Setup.h มาใว้แทนไฟล์ในนี้
<br/><br/>
![alt_text](/images-for-readme/replace.PNG)
<strong> 4. กดไปที่ tools ตรงตัวเลือกด้านบนและเปลี่ยน Board เป็น "ESP32S3 Dev Module" และเปลี่ยน PSRAM เป็น "OPI PSRAM".  </strong>
<br /><br />
![alt_text](/images-for-readme/library_manager.PNG)
<br /><br /><br /><br />
<strong> 5. อัพโหลดโค้ด </strong> <br/> <br/>
![alt_text](/images-for-readme/AIOT.PNG)
<br /><br /><br /><br />
## เครดิต
ต้องขอขอบคุณ [WIRELESS SOLUTION ASIA CO.,LTD](https://wirelesssolution.asia/) สำหรับการสนับสนุนโปรเจ็คนี้ และ [Bodmer / TFT_eSPI](https://github.com/Bodmer/TFT_eSPI/blob/master/README.md)
สำหรับโค้ดส่วนจอ TFT
