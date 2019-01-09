#include <WiFi.h>
#include <WiFiUdp.h>

//Access Point Setting
const char *APSSID = "ESP_WROOM_32";
const char *APPASS = "hoge4009";
unsigned int localPort = 8888;

WiFiUDP UDP;
char packetBuffer[255];

void setup() {

  Serial.begin(115200);
  Serial.println();

  WiFi.softAP(APSSID, APPASS);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  UDP.begin(localPort);

}

void loop() {

  int packetSize = UDP.parsePacket();

  if (packetSize) {

    int len = UDP.read(packetBuffer, packetSize);
    //終端文字設定
    if (len > 0) packetBuffer[len] = '\0';

    Serial.print(UDP.remoteIP());
    Serial.print(" / ");
    Serial.println(packetBuffer);
  }

}
