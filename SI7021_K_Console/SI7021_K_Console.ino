#include "Adafruit_Si7021.h"

Adafruit_Si7021 sensor = Adafruit_Si7021();

void setup() {
  Serial.begin(115200);

  // wait for serial port to open
  while (!Serial) {
    delay(10);
  }

  Serial.println("KORTEX A1 SERIAL: SI7021 Humidity/Temperature sensor");
  
  if (!sensor.begin()) {
    Serial.println("SI7021 NOT DETECTED: Please check your power source, or contact kortex.biz@gmail.com");
    while (true);
  }
}

void loop() {
  Serial.print("Humidity:    "); Serial.print(sensor.readHumidity(), 2);
  Serial.print("\tTemperature: "); Serial.println(sensor.readTemperature(), 2);
  delay(100);
}
