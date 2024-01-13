WiFiClient espClient;

/**
 * @brief Conecta ao WiFi
 */
void connectToWifi()
{
    WiFi.persistent(false);
    WiFi.mode(WIFI_OFF);
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    unsigned long wifiConnectStart = millis();

    while (WiFi.status() != WL_CONNECTED)
    {
        ledFail();
        if (WiFi.status() == WL_CONNECT_FAILED)
        {
            Serial.println("Falha ao conectar no WiFi. Por favor verifique as credenciais: ");
        }
        delay(500);
        Serial.println("...");
        if (millis() - wifiConnectStart > 5000)
        {
            Serial.println("Falha ao conectar no WiFi");
            return;
        }
    }

    Serial.println("");
    Serial.println("WiFi conectado");
    Serial.println("IP: ");
    Serial.println(WiFi.localIP());
}