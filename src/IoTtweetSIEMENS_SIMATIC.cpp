
#include "IoTtweetSIEMENS_SIMATIC.h"

/* IoTtweet configuration parameter */
#define IoTtweetSIEMENS_SIMATIC_HOST "35.185.177.33"    // - New Cloud IoTtweet server
#define IoTtweetSIEMENS_SIMATIC_PORT "5683"             // - Default udp port
#define IoTtweetSIEMENS_SIMATIC_libVersion "v1.0"

/* AIS_NB_BC95 library parameter */
String apnName = "devkit.nb";
String serverIP = "35.185.177.33" ;
String serverPort = "5683";
String udpData = "HelloWorld";

AIS_NB_BC95_IOT2020 AISnb;

bool IoTtweetSIEMENS_SIMATIC:: init(){
  AISnb.debug = true;  /* Terminated all debug print */
  Serial.begin(9600);
  //Serial.println("--- NB-IoT device Initializing and network connecting..... ---");

  AISnb.setupDevice(serverPort);

  String ip1 = AISnb.getDeviceIP();
  pingRESP pingR = AISnb.pingIP(serverIP);

  Serial.println("----------------------------------------------------");
  Serial.println("## IoTtweet with SIEMENS SIMATIC IOT2020, IOT2040 ##");
  Serial.println("Initialize completed !..");
  Serial.println("Ready for data sending to IoTtweet.com");
  return true;
}

String IoTtweetSIEMENS_SIMATIC:: sendDashboard(String userid, String key, float slot0, float slot1, float slot2, float slot3, String tw, String twpb){

  _userid = userid;
  _key = key;
  _tw = tw;
  _twpb = twpb;

  _slot0 = slot0;
  _slot1 = slot1;
  _slot2 = slot2;
  _slot3 = slot3;

  char _s0[10], _s1[10], _s2[10], _s3[10];
  snprintf(_s0, sizeof(_s0), "%0.2f", _slot0);
  snprintf(_s1, sizeof(_s1), "%0.2f", _slot1);
  snprintf(_s2, sizeof(_s2), "%0.2f", _slot2);
  snprintf(_s3, sizeof(_s3), "%0.2f", _slot3);

  /* whitespace string replace to %20 */
  _tw.replace(" ","_");
  _twpb.replace(" ","_");

  Serial.println("------ Send to Cloud.IoTtweet -------");
             _packet = _userid;
             _packet += ":";
             _packet += _key;
             _packet += ":";
             _packet += String(_s0);
             _packet += ":";
             _packet += String(_s1);
             _packet += ":";
             _packet += String(_s2);
             _packet += ":";
             _packet += String(_s3);
             _packet += ":";
             _packet += _tw;
             _packet += ":";
             _packet += _twpb;

      Serial.println("packet sent : " + String(_packet));
      //unsigned int packetSize = _packet.length();
      //Serial.println("packet length : " + String(packetSize) + " byte.");

  Serial.println("--------------------------------------");

  UDPSend udp = AISnb.sendUDPmsgStr(serverIP, serverPort, _packet);
  return "OK";
}

/*
String IoTtweetSIEMENS_SIMATIC::receiveResponse(){

  UDPReceive resp = AISnb.waitResponse();
  //_response = resp.data;
  //Serial.println("IoTtweet response : " + _response);

  return "received";
}
*/

String IoTtweetSIEMENS_SIMATIC:: readRSSI(){

  signal chksignal = AISnb.getSignal();
  _rssi = chksignal.rssi;

  return _rssi;
}

String IoTtweetSIEMENS_SIMATIC:: getVersion()
{
  return IoTtweetSIEMENS_SIMATIC_libVersion;
}
