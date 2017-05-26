/*
CONNECTIONS:
ARDUINO
   GND - Breadboard GND

MOISTURE SENSOR
   VCC - Arduino 5V
   GND - Breadboard GND
   D0 - Arduino A0

RELAY
   IN - Arduino D3
   GND - Breadboard GND
   VCC - Breadboard Power

   Always Open (NO) - Water pump power
   Public - Breadboard power
   Always closed (NC)- DO NOT CONNECT

WATER PUMP
   GND (black wire) - Breadboard GND
   Power (red wire) already described above - Relay 'Always Open'
 
 */
// Connections
int greenLight = 13; // Green light power connects to pin D13
int soilSensor = 0; // Soil moisture sensor connects to Analog pin A0 
int relay = 3; // Connect the "IN" on the relay to pin D3 on the Arduino

// Variables
int dryValue = 850; // If the sensor returns a higher value than this - water
int sensorValue = 0; // Sensor variable, leave this at 0

/*
   Setup
*/
void setup() {
   // Tells the Arduino to start recording text in the Serial Monitor
   Serial.begin(9600); 
   // Use a green led to some running state, a red led for off
   // Tells the Arduino that a green led will be used to communicate
   pinMode(greenLight, OUTPUT); 
   // Tells the Arduino that a relay will be used to communicate and control the pump
   pinMode(relay, OUTPUT); 
   // When the Arduino starts, it will print this message in the Serial Monitor
   Serial.println("BEGIN PLANT MONITORING"); 
}

/*
   Loop @ ~1 sec
*/
void loop() {  
   // When the relay voltage is "low", no electricity is getting to the pump, so the pump is turned off
   digitalWrite(relay, LOW); 

   // Read from moisture sensor
   sensorValue= analogRead(soilSensor); 

   Serial.println(sensorValue);

   if(sensorValue < dryValue) 
   {  
      Serial.println("No need to water"); 

      // Wait here 4 hours
//      delay(14400000);
   }
   else // If the sensorValue is greater than dryVal (so, dry) Do this:
   {
      // Toggle green led to show running state
      digitalWrite(greenLight,HIGH);
      
      Serial.println("Watering now..."); 
      // Turn voltage to relay to high so power to pump is on
      digitalWrite(relay, HIGH);    
   }
   // Wait a while to allow water absorption
   delay(1000); // % seconds, then rechecking...

   digitalWrite(greenLight,LOW); // Toggle green led
   digitalWrite(relay, LOW); // Turn off the pump
}
