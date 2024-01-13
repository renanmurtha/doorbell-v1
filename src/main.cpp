#include <Arduino.h>
#include <FS.h>
#include <ArduinoJson.h>
#include <LittleFS.h>

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>

#include <PubSubClient.h>

#include <led.h>
#include <define.h>
#include <wifi.h>
#include <mqtt.h>
#include <EEPROM.h> // incluir a biblioteca

int toggle;
String msg;
byte status;

void setup()
{
  Serial.begin(115200);
  Serial.setTimeout(2000);
  delay(1000);

  EEPROM.begin(4);                // Inicia a EEPROM com tamanho de 4 Bytes (minimo).
  Serial.println(EEPROM.read(0)); // Mostra no Monitor oque há antes de efetuar a gravação

  pinMode(LED_BUILTIN, OUTPUT);
  ledOn();

  /* Conecta ao WiFi */
  connectToWifi();

  /* EEPROM */
  byte status = EEPROM.read(toggle);
  delay(2000);
  Serial.println("status: " + status);
  switch (status)
  {
  case 0:
    status = 1;
    msg = "SOS: Ativado";
    EEPROM.write(toggle, status);
    break;
  case 1:
    status = 0;
    msg = "SOS: Desativado";
    EEPROM.write(toggle, status);
    break;

  default:
    status = 1;
    msg = "SOS: Ativado";
    EEPROM.write(toggle, status);
    break;
  }
  EEPROM.commit();
  Serial.println("status depois: " + status);
  /* Send msg */
  publishMsg(msg);

  /*Deep sleep mode until RESET pin is connected to a LOW signal (pushbutton is pressed)*/
  ESP.deepSleep(0);
}

void loop()
{
}