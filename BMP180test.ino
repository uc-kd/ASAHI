#include <Wire.h>
#include <Adafruit_BMP280.h>

// Select I2C sensor pin
#define I2C_SCL (5)    // GPIO5
#define I2C_SDA (4)    // GPIO4
Adafruit_BMP280 bmp; // I2C

void setup() {
  Serial.begin(74880);
  Wire.begin();
  if (!bmp.begin()) {
      Serial.println("Could not find a valid BMP280 sensor, check wiring!");
      while (1); // Hung up!
  }
  delay(100); // let sensor boot up
}

void loop() {
  // Get data from BMP280 sensor
  float t = bmp.readTemperature();       // C
  float p = bmp.readPressure() / 100.0F; // hPa
  Serial.print("Temperature:");
  Serial.println(t);
  Serial.print("Pressure:");
  Serial.println(p);
  Serial.println();
  delay(2000);
}
