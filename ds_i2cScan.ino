/*
 * Demonstrate use of function to find devices on I2C port
 */

#include <Arduino.h>
#include <Wire.h>

void setup() {
    serialInit(57600);   // set up usb serial port

    i2cScan();        // requires serial port to be initialized prior to use
}


void loop(void) {
    ;
}


void i2cScan() {
    Serial.println ("\ni2cScan...\n");
    static int count = 0;

    Wire.begin();
    for (int i = 8; i < 120; i++)
    {
        Wire.beginTransmission(i);          // probe this i2c address
        if (Wire.endTransmission() == 0)
        {
            Serial.print ("  device at: 0x" + String(i, HEX) + "  [" + String(i) + "] \n");
            count++;
            delay (1);
        }
    }
    Serial.print("\nTotal devices:  " + String(count) + "\n");
}


// Serial initialization accounts for integrated USB, as on Teensy3 and Due and some others
void serialInit(int baudrate) {
    Serial.begin(baudrate); // serial IO routed through USB console
    while (!Serial && (millis() < 5000)) {} // include timeout if print console isn't opened
    Serial.println("USB Serial Print initialized.");
}



