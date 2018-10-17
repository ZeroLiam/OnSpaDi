# OnSpaDi
Arduino and RaspPi backups
## NOTE: latest update will be done on October 18th after 18:00!!


- [Arduino](#arduino)
    - [Ultrasonic Sensor](#ultrasonicsensor)
    - [ESP8266Client (WiFi Module)](#esp8266client-wifi-module)

## Arduino
### UltrasonicSensor
This one contains the trigger and measurement from the ultrasonic sensor. The location is `./Arduino/UltrasonicSensor/`. The blueprints will be located in `./blueprints/arduino/ultrasonicsensor/`, in jpeg/png/fritz.

### ESP8266Client (WiFi Module)
This one contains the `VERSION 1` (TO BE IMPROVED) connection and use of the wifi module. The location is `./Arduino/wifimodule/`. The blueprints will be located in `./blueprints/arduino/wifimodule/`, in jpeg/png/fritz.

### ESP8266v8_RaspberryPi (WiFi Module connects to RaspPi)
This one works with the library `WiFiEsp`. It works, don't ask me why it works with this one only. Also, the physical setup (circuit diagram to be posted soon) changed, now it connects the `CH_PD` to a `10K` resistor on the breadboard, and the `reset` pin is connected directly to the Arduino.

#### To do:
    - Find out why the `GET` request is not working properly
    - Ask _Freddie_ if we can have a local wifi to test the setup outside  
