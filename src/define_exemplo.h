#define TELEGRAM_BUTTON_PIN 2

#define DEVICE_NAME String(WiFi.hostname())
#define MECADDRESS String(WiFi.macAddress())
#define SENSOR_NAME "DoorBell-v1"

/*MQTT credenciais*/
#define MQTT_HOST "MQTT IP HOST"
#define MQTT_USER "mqtt user"
#define MQTT_PASS "MQTT PASS"
#define MQTT_PORT 1883

/* MQTT topic */
#define MQTT_TOPIC "iot/doorbell/recive"

/* WiFi credenciais */
#define WIFI_SSID "WIFI NAME"
#define WIFI_PASS "WIFI PASS"

/* MongoDB (on json) */
#define COLLECTION "events"
