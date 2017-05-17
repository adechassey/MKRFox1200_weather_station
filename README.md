# MKRFOX1200 Weather Station
This project discribes how to monitor weather data with the Sigfox network.

![alt text](https://shop.snoc.fr/media/wysiwyg/site/yadom/Sigfox_Logo_RGB_1.png)

## Prerequisite
- Create an account on the Sigfox Backend | https://backend.sigfox.com/ (if you don't already have one)
- Create an account on the thethings.iO plateform | https://panel.thethings.io/#/register

## Installations
1. Install the Arduino IDE
2. Select the MKRFox1200 board
3. Install the following librairies:
    * Arduino SigFox for MKRFox1200
    * Arduino Low Power
    * RTCZero
    * DHT sensor library (Adafruit)

4. Flash the board with the code in this repo
5. Copy/paste the following code in the "Cloud Code" 'sigfox_parser' function at https://sigfox.thethings.io/#/ | https://jsbin.com/coxetafuvu/1/edit?js 
6. Create a Sigfox backend callback for your device
    * Use the following custom payload config:
    ```
    moduleTemp::int:16:little-endian dhtTemp::int:16:little-endian dhtHum::uint:16:little-endian lastMsg::uint:8
    ```
    * Use the following URL pattern:
    ```
    https://subscription.thethings.io/sgfx/XXXXX/XXXXXXXXXXXXX?id={device}&data={data}&moduleTemp={customData#moduleTemp}&dhtTemp={customData#dhtTemp}&dhtHum={customData#dhtHum}&lastMsg={customData#lastMsg}
    ```

> *Antoine de Chassey*