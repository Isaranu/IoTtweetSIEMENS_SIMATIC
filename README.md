# IoTtweetSIEMENS_SIMATIC
Library provided to send data to IoTtweet - Internet of Things platform compatible with SIEMENS SIMATIC IOT2020 and IOT2040<br>
![alt text](https://github.com/Isaranu/IoTtweetSIEMENS_SIMATIC/blob/master/IOT2000_IoTtweet.jpg "logo")

![alt_text](https://img.shields.io/badge/bulid-passing-brightgreen.svg "bulidpassing")
![alt_text](https://img.shields.io/badge/Compatible-ArduinoIDE-darkgreen.svg "bulidpassing")
![alt_text](https://img.shields.io/badge/Compatible-AISNBIoT-green.svg "bulidpassing")
![alt_text](https://img.shields.io/badge/Compatible-SIEMENS_SIMATIC_IOT2000-lightgrey.svg "bulidpassing")<br>
Library สำหรับใช้งานบน SIEMENS SIMATIC IOT2000 series, เพื่อส่งไปข้อมูลไปแสดงผลบน Internet of Things platform **"IoTtweet"** ทีมีหน้า Dashboard ที่สามารถออกแบบได้อย่างอิสระและสวยงามที่สุดแล้ว

### [Get started]
**- Hardware ที่ใช้ทำการทดสอบมีดังนี้**
1. SIEMENS SIMATIC IOT2020.
2. AIS NB-IoT shield. (Arduino UNO pin out compatible)
3. Power supply : 9V (สำหรับการจ่ายไฟให้กับ IOT2020 device)

**- การเชื่อมต่อ Hardware**
1. เปิดฝา IOT2020, ใส่ SD card ที่ download image จาก https://support.industry.siemens.com/cs/document/109741799/simatic-iot2000-sd-card-example-image?dti=0&lc=en-WW
2. นำ AIS NB-IoT shield มาต่อเข้ากับ Arduino compatible socket. ต้องต่อสายเพื่อย้าย port Serial ตามด้านล่างนี้
```
IOT2020/PIN 0 --> PIN8
IOT2020/PIN 1 --> PIN9
```
**หรือทำการย้าย Jumper ที่เลือก TX, RX บนบอร์ด AIS NB-IoT ให้เลือก PIN0, PIN1 ก็ทำได้ครับ**

3. จ่ายไฟ 9V เข้าที่ IOT2020, รอเวลาเพื่อทำการ boost ระบบ.
4. เชื่อมต่อสาย micro USB cable จาก IOT2020 เข้ากับคอมพิวเตอร์.
5. เปิดโปรแกรม Arduino IDE, ติดตั้งรายชื่ออุปกรณ์ โดยไปที่ Menu > Tool > Board > Board Manager.
จากนั้นพิมพ์ในช่องค้นหาว่า "i586" และทำการติดตั้งที่เวอร์ชั่น 1.6.7+1.0
6. ไปที่ Tool > Board, แล้วเลือก "Intel Galileo Gen 2". เลือก port ที่ปรากฏขึ้นมา.
7. Upload code ตัวอย่างจากใน Library นี้ และแก้ไข Parameter "userid" และ "key" ให้เป็นของเราเอง (วิธีการลงทะเบียนใช้งาน IoTtweet, อ่านได้จากด้านล่างครับ)


### [วิธีใช้งานกับ Dashboard IoTtweet]

- **สมัครใช้งาน IoTtweet** : เข้าไปที่ www.iottweet.com ทำการ Signup และ verify activate e-mail ให้เรียบร้อย. ไปที่ **"My IoT garage"** ทำการเพิ่ม device เพื่อรับ key ที่ใช้สำหรับใส่ลงใน code.

- **ออกแบบ Dashboard** : ไปที่ **"Dashboard"**, และทำการ Edit layout. เพิ่ม Widget ต่างๆที่ต้องการ พร้อมทั้งตั้งค่า (setting) widget แต่ละ element ให้เรียบร้อย. เมื่อเสร็จเรียบร้อย ให้กด **"Save layout"**.


**รายละเอียดเพิ่มเติม**
**website** : www.iottweet.com และ http://code.isaranu.com<br>
**facebook** : https://www.facebook.com/IoTtweet<br>
**facebook group** : https://www.facebook.com/groups/191156967967490<br>
**LINE ID** : @codeisaranu


