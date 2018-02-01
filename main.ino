// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2
// Sensors Count
#define SENSORS_COUNT 1
// Request every x ms
#define REQUEST_DELAY 10000

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

/*
 * The setup function. We only start the sensors here
 */
void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Arduino DS18B20 Script ~ fipso.de 2018");

  // Start up the library
  sensors.begin();
}

/*
 * Main function, get and show the temperature
 */
void loop(void)
{ 
  sensors.requestTemperatures(); 
  
  for(int i = 0; i < SENSORS_COUNT; i++)
  {
    Serial.println("SENSOR " + i + " " + sensors.getTempCByIndex(i) + " C°");
  }

  delay(REQUEST_DELAY);

}
