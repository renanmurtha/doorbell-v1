bool shouldSaveConfig = false;

char mqtt_server[40];
char mqtt_port[6];
char mqtt_user[40];
char mqtt_pass[40];
char mqtt_topic[40];

// callback que indica que o ESP entrou no modo AP
void configModeCallback(WiFiManager *myWiFiManager)
{
    Serial.println("WiFi-> Entered configuration mode");
    Serial.println(WiFi.softAPIP());                      // imprime o IP do AP
    Serial.println(myWiFiManager->getConfigPortalSSID()); // imprime o SSID criado da rede

    Serial.println(WiFi.hostname());
}

// callback que indica que salvamos uma nova rede para se conectar (modo estação)
void saveConfigCallback()
{
    Serial.println("WiFi-> saved configuration");
    shouldSaveConfig = true;
}

void setupSpiffs()
{
    // LittleFS.format();
    Serial.println("WiFi-> mounting FS...");

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
                strcpy(mqtt_server, doc["mqtt_server"]);
                strcpy(mqtt_port, doc["mqtt_port"]);
                strcpy(mqtt_user, doc["mqtt_user"]);
                strcpy(mqtt_pass, doc["mqtt_pass"]);
                strcpy(mqtt_topic, doc["mqtt_topic"]);
            }
            else
            {
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

void connectToWifi()
{
    // WiFiManager
    // Local intialization. Once its business is done, there is no need to keep it around
    WiFiManager wifiManager;
    // wifiManager.setTimeout(300);
    setupSpiffs();
    
    wifiManager.setConfigPortalTimeout(180);
    wifiManager.setAPCallback(configModeCallback);
    wifiManager.setSaveConfigCallback(saveConfigCallback);

    // custom parameters
    WiFiManagerParameter custom_mqtt_server("server", "mqtt server", mqtt_server, 40);
    WiFiManagerParameter custom_mqtt_port("port", "mqtt port", mqtt_port, 6);
    WiFiManagerParameter custom_mqtt_user("user", "mqtt user", mqtt_user, 40);
    WiFiManagerParameter custom_mqtt_pass("pass", "mqtt pass", mqtt_pass, 40);
    WiFiManagerParameter custom_mqtt_topic("topic", "mqtt topic", mqtt_topic, 40);
    wifiManager.addParameter(&custom_mqtt_server);
    wifiManager.addParameter(&custom_mqtt_port);
    wifiManager.addParameter(&custom_mqtt_user);
    wifiManager.addParameter(&custom_mqtt_pass);
    wifiManager.addParameter(&custom_mqtt_topic);

    WiFi.mode(WIFI_STA);

    Serial.println();
    Serial.println("WIFI-> Connecting ...");

    while (!wifiManager.autoConnect(SENSOR_NAME))
    {
      ledProcess();
    }

    // read paramters
    if (shouldSaveConfig)
    {
        strcpy(mqtt_server, custom_mqtt_server.getValue());
        strcpy(mqtt_port, custom_mqtt_port.getValue());
        strcpy(mqtt_user, custom_mqtt_user.getValue());
        strcpy(mqtt_pass, custom_mqtt_pass.getValue());
        strcpy(mqtt_topic, custom_mqtt_topic.getValue());

        DynamicJsonDocument doc(1024);
        doc["mqtt_server"] = mqtt_server;
        doc["mqtt_port"] = mqtt_port;
        doc["mqtt_user"] = mqtt_user;
        doc["mqtt_pass"] = mqtt_pass;
        doc["mqtt_topic"] = mqtt_topic;
        File configFile = LittleFS.open("/config.json", "w");
        if (!configFile)
        {
            Serial.println("WiFi-> failed to open config file for writing");
        }
        serializeJson(doc, Serial);
        serializeJson(doc, configFile);
        configFile.close();
        Serial.println("WiFi-> end save");
    }

    // if you get here you have connected to the WiFi
    ledOn();
}
