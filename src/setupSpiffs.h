char btn_status[40];
String status;

void saveJson(String value)
{
    DynamicJsonDocument doc(1024);
    doc["btn_status"] = value;
    File configFile = LittleFS.open("/config.json", "w");
    if (!configFile)
    {
        Serial.println("Save BTN Status -> failed to open config file for writing");
    }
    serializeJson(doc, Serial);
    serializeJson(doc, configFile);
    configFile.close();
    Serial.println("Save BTN Status -> end save");
}

void setupSpiffs()
{
    // LittleFS.format();
    Serial.println("Save BTN Status -> Mounting FS...");

    if (LittleFS.begin())
    {
        Serial.println("** Mounting file system **");
        if (LittleFS.exists("/config.json"))
        {
            Serial.println("** Reading config file **");
            File configFile = LittleFS.open("/config.json", "r");
            if (configFile)
            {
                size_t size = configFile.size();
                std::unique_ptr<char[]> buf(new char[size]);
                configFile.readBytes(buf.get(), size);
                DynamicJsonDocument doc(1024);
                DeserializationError error = deserializeJson(doc, buf.get());
                if (error)
                {
                    Serial.print(F("deserializeJson() failed: "));
                    Serial.println(error.c_str());
                    return;
                }
                status = strcpy(btn_status, doc["btn_status"]);               
            }
            else
            {
                saveJson("1");
                Serial.println("** Failed to load json config **");
            }
            configFile.close();
            Serial.println("** Closed file **");
        }
    }
    else
    {
        Serial.println("** Failed to mount FS **");
    }
}
