/*
   Refer to README for connection information
 */
#include <elapsedMillis.h>

// Constants
// TODO: +Feature add a means to update flow and read interval id:11 gh:3
// If soil is wet, sleep for a few hours (4)
int WETSOILSLEEP = 3000;
// int WETSOILSLEEP = 14400000;
// Control period the pump is on to avoid flooding
//  and allow soil absorption
unsigned int WATERDURATION = 3000;

// Variables
// If the sensor returns a higher value than this - water
int dryValue = 850;
// Sensor values
int sensorValue = 0;
// boolean to control messages
bool pumpOn = false;

// Connections
// Green LED power connects to pin            D13
int greenLED = 13;
// Soil moisture sensor connects to Analog pin  A0
int soilSensor = 0;
// Connect the "IN" on the relay to pin         D3
int relay = 3;
// Set up a time for the pump
elapsedMillis timer0;
#define interval WATERDURATION

/*
   Setup
 */
void setup()
{
    // Start recording text at the Serial Monitor
    Serial.begin(9600);
    // Use a green led to some running state
    pinMode(greenLED, OUTPUT);
    // Setup relay to control pump
    pinMode(relay, OUTPUT);
    Serial.println("Monitoring - START");
    timer0 = 0; // clear the timer at the end of startup
}

/*
   Loop @ ~1 sec

   TODO: +Bug in looping, where the interval timer is backing up for the pump action when delayed. This will cause issues when the delay() is set to hours, rather than seconds... id:6 gh:1
 */
void loop()
{
    // When the relay voltage is "low", pump is 'off'
    // digitalWrite(greenLED, LOW);
    // digitalWrite(relay, LOW);
    // Read from moisture sensor - a low number will be returned from a wetter reading
    sensorValue = analogRead(soilSensor);
    // If it needs watering only do it for a set period (3000 millis)
    if (sensorValue > dryValue)
    {
        if (timer0 > interval) {
            pumpOn = !pumpOn;
            if (pumpOn) {
                Serial.println("Sensor value: "+String(sensorValue)+" vs. dry value: "+String(dryValue));
                Serial.println("Watering now...");
            }
            else {
                Serial.println("Watering paused...");
            }
            timer0 -= interval; //reset the timer
            int ledPin = digitalRead(greenLED);
            int relayPin = digitalRead(relay);
            // Control: read the current state and write the opposite
            digitalWrite(greenLED, !ledPin);
            digitalWrite(relay, !relayPin);
        }
    }
    else {
        Serial.println("Pump off");
        pumpOn = false;
        digitalWrite(greenLED, LOW); // Toggle green led
        digitalWrite(relay, LOW); // Turn off the pump
        delay(WETSOILSLEEP); // Can wait a while if the soil is wet - 4 hours
    }
}
