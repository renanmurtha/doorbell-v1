void resetSetting()
{
    File configFile = LittleFS.open("/config.json", "w");
    if (configFile)
    {
        DynamicJsonDocument doc(1024);
        doc["mqtt_server"] = "";
        doc["mqtt_port"] = "";
        doc["mqtt_user"] = "";
        doc["mqtt_pass"] = "";
        doc["mqtt_topic"] = "";
        serializeJson(doc, Serial);
        serializeJson(doc, configFile);
        configFile.close();
        delay(2000);
    }

    ESP.eraseConfig();
    delay(2000);
    ESP.reset();
}