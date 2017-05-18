# MKRFOX1200 Weather Station :satellite::earth_africa:
This project discribes how to monitor weather data with the Sigfox network.

![alt text](https://pbs.twimg.com/media/C8VV3O6XkAAO3UG.jpg)

## Prerequisite
- Activate your device and create an account (if you don't already have one) on the [Sigfox Backend](https://backend.sigfox.com/activate) platform
- Create an account on [sigfox.thethings.io](https://sigfox.thethings.io/#/register)

## Installations
1. Install the [Arduino IDE](https://www.arduino.cc/en/Main/Software)
2. Select the MKRFox1200 board
3. Install the following librairies:
    * Arduino SigFox for MKRFox1200
    * Arduino Low Power
    * RTCZero
    * DHT sensor library (Adafruit) :exclamation: **version 1.2.3** :exclamation:

4. Flash the board with the code provided in this repo
5. Copy & paste [this](https://jsbin.com/coxetafuvu/1/edit?js) code in the "Cloud Code" `sigfox_parser` function at https://sigfox.thethings.io/  
6. Create a [Sigfox backend](https://backend.sigfox.com/) callback for your device
    * Use the following custom payload config:
    ```
    moduleTemp::int:16:little-endian dhtTemp::int:16:little-endian dhtHum::uint:16:little-endian lastMsg::uint:8
    ```
    * Use the following URL pattern (replace the 'X' with your own subscription URL information after creating a new product on [sigfox.thethings.io](https://sigfox.thethings.io/#/register))
    ```
    https://subscription.thethings.io/sgfx/XXXXX/XXXXXXXXXXXXX?id={device}&data={data}&moduleTemp={customData#moduleTemp}&dhtTemp={customData#dhtTemp}&dhtHum={customData#dhtHum}&lastMsg={customData#lastMsg}
    ```
7. Design a nice dashboard for your Sigfox connected weather station
8. Enjoy! :+1:

> *Antoine de Chassey*