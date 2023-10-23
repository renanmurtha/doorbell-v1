#define TELEGRAM_BUTTON_PIN 2

#define DEVICE_NAME String(WiFi.hostname())
#define MECADDRESS String(WiFi.macAddress())
#define SENSOR_NAME "DoorBell-v1"

/*MQTT credenciais*/
#define MQTT_HOST "143.47.225.51"
#define MQTT_USER "mqtt-user"
#define MQTT_PASS "x#MQTT@70c9b1"
#define MQTT_PORT 1883

/* MQTT topic */
#define MQTT_TOPIC "iot/doorbell/recive"

/* WiFi credenciais */
#define WIFI_SSID "Allsafe"
#define WIFI_PASS "#de3sw2aq1"

/* MongoDB */
#define COLLECTION "events"
