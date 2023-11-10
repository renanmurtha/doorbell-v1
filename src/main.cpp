#include <Arduino.h>
#include <FS.h>
#include <ArduinoJson.h>
#include <LittleFS.h>

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>

#include <PubSubClient.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

#include <led.h>
#include <define.h>
#include <wifi.h>
#include <mqtt.h>


void setup()
{
  Serial.begin(115200);
  Serial.setTimeout(2000);

  pinMode(LED_BUILTIN, OUTPUT);
  ledOn();
  /* Conecta ao WiFi */
  connectToWifi();

  /* Send msg */
  publishMsg("toc-toc");

  /*Deep sleep mode until RESET pin is connected to a LOW signal (pushbutton is pressed)*/
  ESP.deepSleep(0);
}

void loop()
{
}