#  DoorBell-v1 (ESP-01 S)

C/C++ application aimed at IOT.
- [README PT-BR](README.md)
#

## Type of use:

- Emergency button;
- Bell;
- Others

#
## Material

- Device: ESP-01S
- Battery: 902030 Li Ion - 550mah - 3.7v
- Charge controller: TP4056 (18650)
- 1A cell phone charger (Higher amperage may damage the battery and/or charge controller)
- Button (Push Button Key); I used these for the campaign
<br/>

#

## Adjustment in the project

- Initial configuration via hotspot

   - A network with the device name will be created, and can be accessed from any other device with WiFi.
 
   - Device name is initially: "DoorBell-v1"; which can be changed in define.h in the SENSOR_NAME constant
 
     - IP after connected: 192.168.4.1
 
     - Example and documentation: https://github.com/tzapu/WiFiManager



    ![WiFiManager 1](https://github.com/renanmurtha/doorbell-v1/blob/main/img/WiFiManager_1.png?raw=true "WiFiManager 1")
    

    ![WiFiManager 2](https://github.com/renanmurtha/doorbell-v1/blob/main/img/WiFiManager_1.png?raw=true "WiFiManager 2")

<br/>
<br/>

# Operation:

Device remains in "deep sleep" until the reset button is pressed. The device "wakes up", sends a message to the mqtt server and returns to the "deep sleep" state.

In my use, I added a 902030 Li Ion battery - 550mah - 3.7v.

To charge the battery, I added the TP4056 (18650) charge controller to the project; * Use a 1A charger to avoid damaging the charger or the battery.

#

## Message Pattern

I chose to use the Json standard to send messages to the mqtt server built into Node-Red.
<br/>
Using Json, I can do several actions using the json string.
 
  ### Examples
 
  * Save event to mongo DB
  * Send message to telegram
  * Send message to WhatsApp

  With the message data in json, it can be processed by device, and trigger actions for different recipients according to the device identification.

  #

<br/>

  - JSON example

   ![JSON example](https://github.com/renanmurtha/doorbell-v1/blob/main/img/json.png?raw=true "Exemplo JSON")
  
  - Node-Red (NODES)

  <br/>
  
  ![Nodes I use (Node-Red)](https://github.com/renanmurtha/doorbell-v1/blob/main/img/node-red.png?raw=true "Nodes I use (Node-Red)")

   - Sketch
  
  <br/>
  
  ![Sketch](https://github.com/renanmurtha/doorbell-v1/blob/main/img/Sketch.png?raw=true "Sketch")