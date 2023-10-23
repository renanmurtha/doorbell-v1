#  DoorBell-v1 (ESP-01 S)

C++ application aimed at IOT.
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

- Rename the file define_exemplo.h to define.h and rename the constants with the credentials of your mqtt server and wifi.

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

- [JSON example](img/json.png)
- [Nodes I use (Node-Red)](img/node-red.png)