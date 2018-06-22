//#define BLYNK_DEBUG
#define BLYNK_PRINT Serial    // Remove to disable prints and save space
#include <ESP8266_SoftSer.h>
#include <BlynkSimpleShieldEsp8266_SoftSer.h>

#include <Wire.h>
#include <Adafruit_MPL3115A2.h>
#include "Adafruit_Si7021.h"

Adafruit_MPL3115A2 mpl_ba = Adafruit_MPL3115A2();
Adafruit_Si7021 si_th = Adafruit_Si7021();


// Set ESP8266 Serial object
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(3, 2); // RX, TX

ESP8266 wifi(EspSerial);


// You should get Auth Token in the Blynk App.
// Go to the Project Settings at Blynk app.
char auth[] = "adfbde15595e4d01a688f1de37f63b5c";

void sendUptime()
{
  float h = si_th.readHumidity(); // Read humidity from Kortex A1
  float t = si_th.readTemperature(); // Read temperature from Kortex A1
  float b = mpl_ba.getPressure(); // Read pressure from Kortex A1
  float a = mpl_ba.getAltitude(); // Read altitude from Kortex A1

  Blynk.virtualWrite(0, t); // virtual pin (Temperature)
  Blynk.virtualWrite(1, h); // virtual pin (Humidity)
  Blynk.virtualWrite(2, a); // virtual pin (Altitude)
  Blynk.virtualWrite(3, b/133); // virtual pin (Pressure)
}

void setup()
{
  
  Serial.begin(9600);  // Set console baud rate
  delay(10);

  EspSerial.begin(9600);   // Set ESP8266 baud rate (9600 is recommended for Software Serial)
  delay(10);
  
  si_th.begin(); // Initialize SI7021 sensor
  mpl_ba.begin(); // Initilize MPL3115A2 sensor
  Blynk.begin(auth, wifi, "RWS-890", "allahalwatanalmalek"); // Initilize Blynk
}

void loop()
{
  Blynk.run();
  sendUptime();
}

