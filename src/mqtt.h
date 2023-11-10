/* MQTT credenciais */
const char *mqttServer = MQTT_HOST;
const int mqttPort = MQTT_PORT;
const char *mqttuser = MQTT_USER;
const char *mqttpass = MQTT_PASS;

WiFiClient espClient;
PubSubClient client(espClient);

String sendJson = "";
StaticJsonDocument<200> json;


void publishMsg(String mensangem)
{
  client.setServer(mqttServer, mqttPort);

  bool ret = false;

  while (!client.connected() && !ret)
  {
    Serial.println("Conectando ao MQTT...");

    if (client.connect(mqttServer, mqttuser, mqttpass))
    {
      json["device"] = DEVICE_NAME;
      json["collection"] = COLLECTION;
      json["message"] = mensangem;
      json["sensor"] = SENSOR_NAME;
      json["macAddress"] = MECADDRESS;

      serializeJson(json, sendJson);

      Serial.println("Conectado com Sucesso");
      ret = client.publish(MQTT_TOPIC, String(sendJson).c_str(), true);
      delay(5000);
      ledOff();
    }
    else
    {
      Serial.print("Falha: ");
      Serial.print(client.state());
    }
  }
}