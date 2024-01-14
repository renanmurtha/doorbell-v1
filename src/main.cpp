#include <Arduino.h>
#include <FS.h>
#include <LittleFS.h>
#include <ArduinoJson.h>

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>

#include <PubSubClient.h>

#include <led.h>
#include <define.h>
#include <wifi.h>
#include <mqtt.h>
int toggle;
String msg;
#include <setupSpiffs.h>

void setup()
{
  Serial.begin(115200);
  Serial.setTimeout(2000);
  delay(1000);
  pinMode(LED_BUILTIN, OUTPUT);
  ledOn();

  /* Conecta ao WiFi */
  connectToWifi();

  /* Config json*/
  setupSpiffs();

  switch (status.toInt())
  {
  case 0:
    status = "1";
    msg = "SOS: Ativado";
    saveJson(status.c_str());
    break;
  case 1:
    status = "0";
    msg = "SOS: Desativado";
    saveJson(status.c_str());
    break;

  default:
    status = "1";
    msg = "SOS: Ativado";
     saveJson(status.c_str());
    break;
  }
  /* Send msg */
  publishMsg(msg);

  /*Deep sleep mode until RESET pin is connected to a LOW signal (pushbutton is pressed)*/
  ESP.deepSleep(0);
}

void loop()
{
}