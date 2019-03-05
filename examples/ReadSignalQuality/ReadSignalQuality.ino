#include "IoTtweetSIEMENS_SIMATIC.h"

String userid = "your-IoTtweet-account-ID";       /*IoTtweet account user ID (6 digits, included zero pre-fix)*/
String key = "your-device-key";                   /*IoTtweet registered device key in "MY IOT Garage"*/
float data0, data1, data2, data3;                 /*Your sending data variable.*/
String private_tweet = "SIEMENS IOT2020";              /*Your private tweet meassage to dashboard*/
String public_tweet = "";           /*Your public tweet message to dashboard*/

const long looptime = 5;                         /* Loop delay time in sec. */
unsigned long previousMillis = 0;

long cnt = 0;

IoTtweetSIEMENS_SIMATIC mySIMATIC;

void setup()
{ 
  mySIMATIC.init();
  previousMillis = millis();

}
void loop()
{ 
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= looptime*1000)
    {
      cnt++;
      public_tweet = "data counter = " + String(cnt);     

      signal SignalQuality = mySIMATIC.readSignalQuality();
      String csq = SignalQuality.csq;
      String rssi = SignalQuality.rssi;
      String ber = SignalQuality.ber;

      Serial.println();
      Serial.println("--------------Signal quality read out------------");
      Serial.println("CSQ = " + csq);
      Serial.println("RSSI = " + rssi);
      Serial.println("BER = " + ber);
     
      previousMillis = currentMillis;
  
    }
     
}
