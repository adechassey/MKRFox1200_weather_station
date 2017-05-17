# MKRFOX1200 Weather Station
This project discribes how to monitor weather data with the Sigfox network.

![alt text](https://shop.snoc.fr/media/wysiwyg/site/yadom/Sigfox_Logo_RGB_1.png)

## Prerequisite
- Create an account on the Sigfox Backend | https://backend.sigfox.com/ (if you don't already have one)
- Create an account on the thethings.iO plateform | https://panel.thethings.io/#/register

## Installations
- Install the Arduino IDE
- Select the MKRFox1200 board
- Install the following librairies:
* Arduino SigFox for MKRFox1200
* Arduino Low Power
* RTCZero
* DHT sensor library (Adafruit)

- Flash the board with the code in this repo
- Copy/paste the following code in the "Cloud Code" 'sigfox_parser' function at https://sigfox.thethings.io/#/ | https://jsbin.com/coxetafuvu/1/edit?js 


> *Antoine de Chassey*