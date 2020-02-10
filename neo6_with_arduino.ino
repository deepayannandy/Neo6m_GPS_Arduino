/* written by Deepayan Nandy
 * Date: 10/02/2020
 * www.dnyindia.com
 */

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 3, TXPin = 4;// Here we make pin 3 as RX of arduino & pin 4 as TX of arduino 
static const uint32_t GPSBaud = 9600;
float longitude,latitude;

TinyGPSPlus gps;

SoftwareSerial ss(RXPin, TXPin);

void setup()
{
  Serial.begin(9600);
  ss.begin(GPSBaud);

 
}

void loop()
{
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
      displayInfo();

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring!"));
    while(true);
  }
}

void displayInfo()
{
  Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    longitude= gps.location.lat(),6;  // You can use these values where ever you need them.
    latitude=  gps.location.lng(),6;
    Serial.print(longitude);
    Serial.print(F(","));
    Serial.println(latitude);
  }
  else
  {
    Serial.print(F("INVALID"));
  }


  
  Serial.println();
}
