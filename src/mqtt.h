/* MQTT credenciais */
const char *mqttServer = mqtt_server;
int porta = atoi(mqtt_port);
const int mqttPort = porta;
const char *mqttuser = mqtt_user;
const char *mqttpass = mqtt_pass;

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
      ret = client.publish(mqtt_topic, String(sendJson).c_str(), true);
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