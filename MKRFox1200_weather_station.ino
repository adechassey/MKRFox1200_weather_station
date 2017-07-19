// -------------------------------------------------------------------------
// This project sends DHT11 temperature and humidity through Sigfox network
//
// Created: 16.05.2017
// Author: Antoine de Chassey
// Code: https://github.com/AntoinedeChassey/MKRFOX1200_weather_station
// --------------------------------------------------------------------------

#include "SigFox.h"
#include "ArduinoLowPower.h"
#include "DHT.h"

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

#define DHTPIN        1                // What digital pin we're connected to
#define DHTTYPE       DHT11
#define DEBUG         true             // Set DEBUG to false to disable serial prints
#define SLEEPTIME     15 * 60 * 1000   // Set the delay to 15 minutes (15 min x 60 seconds x 1000 milliseconds)

#define UINT16_t_MAX  65536
#define INT16_t_MAX   UINT16_t_MAX/2

typedef struct __attribute__ ((packed)) sigfox_message {
        int16_t moduleTemperature;
        int16_t dhtTemperature;
        uint16_t dhtHumidity;
        uint8_t lastMessageStatus;
} SigfoxMessage;

// Stub for message which will be sent
SigfoxMessage msg;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
        if (DEBUG) {
                // We are using Serial1 instead than Serial because we are going in standby
                // and the USB port could get confused during wakeup. To read the DEBUG prints,
                // connect pins 13-14 (TX-RX) to a 3.3V USB-to-serial converter
                Serial1.begin(115200);
                while (!Serial1) {}
        }

        if (!SigFox.begin()) {
                // Something is really wrong, try rebooting
                // Reboot is useful if we are powering the board using an unreliable power source
                // (eg. solar panels or other energy harvesting methods)
                reboot();
        }

        // Send module to standby until we need to send a message
        SigFox.end();

        if (DEBUG) {
                // Enable DEBUG prints and LED indication if we are testing
                SigFox.debug();
        }

        dht.begin();
}

void loop() {
        // Reading temperature or humidity takes about 250 milliseconds!
        // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
        float h = dht.readHumidity();
        // Read temperature as Celsius (the default)
        float t = dht.readTemperature();
        // Check if any reads failed and exit early (to try again).
        if (isnan(h) || isnan(t)) {
                Serial.println("Failed to read from DHT sensor!");
                return;
        }

        msg.dhtTemperature = convertoFloatToInt16(t, 60, -60);
        msg.dhtHumidity = convertoFloatToUInt16(h, 110);

        if(DEBUG) {
                Serial.print("Humidity: ");
                Serial.print(h);
                Serial.print(" %\t");
                Serial.print("Temperature: ");
                Serial.print(t);
                Serial.print(" *C ");
        }
        // Start the module
        SigFox.begin();
        // Wait at least 30ms after first configuration (100ms before)
        delay(100);

        // We can only read the module temperature before SigFox.end()
        t = SigFox.internalTemperature();
        msg.moduleTemperature = convertoFloatToInt16(t, 60, -60);

        // Clears all pending interrupts
        SigFox.status();
        delay(1);

        SigFox.beginPacket();
        SigFox.write((uint8_t*)&msg, 12);

        msg.lastMessageStatus = SigFox.endPacket();

        SigFox.end();
        //Sleep for 15 minutes
        LowPower.sleep(SLEEPTIME);
}

void reboot() {
        NVIC_SystemReset();
        while (1) ;
}

int16_t convertoFloatToInt16(float value, long max, long min) {
        float conversionFactor = (float) (INT16_t_MAX) / (float)(max - min);
        return (int16_t)(value * conversionFactor);
}

uint16_t convertoFloatToUInt16(float value, long max) {
        float conversionFactor = (float) (UINT16_t_MAX) / (float)(max);
        return (uint16_t)(value * conversionFactor);
}
