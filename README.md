# [MKRFox1200](https://www.arduino.cc/en/Main.ArduinoBoardMKRFox1200) Weather Station :satellite::earth_africa:
This project discribes how to monitor weather data with the Sigfox network (LPWAN ~ 6 months battery life with 2x AA).

<a href="https://www.buymeacoffee.com/antoine" target="_blank"><img src="https://www.buymeacoffee.com/assets/img/custom_images/orange_img.png" alt="Buy Me A Coffee" style="height: 41px !important;width: 174px !important;box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;-webkit-box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;"></a>

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

## Support me
Hey dude! Help me out for a couple of :beers: or :coffee:!

<a href="https://www.buymeacoffee.com/antoine" target="_blank"><img src="https://www.buymeacoffee.com/assets/img/custom_images/orange_img.png" alt="Buy Me A Coffee" style="height: 41px !important;width: 174px !important;box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;-webkit-box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;"></a>
