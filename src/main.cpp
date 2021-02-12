#include <Arduino.h>
#include "DHT.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

/*
  # the sensor value description
  # 0  ~300     dry soil
  # 300~700     humid soil
  # 700~950     in water
*/

#define pin_moisture A0
#define pin_temperature 2 

#define DHTTYPE DHT11
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(pin_temperature, DHTTYPE);

void setup() {
  Serial.begin(9600);
  lcd.init();       
  lcd.backlight();
  pinMode(pin_moisture, INPUT);
  dht.begin();
}

void loop() {
  lcd.clear();
  // Write constant info on lcd-display
  lcd.setCursor(0, 0);
  lcd.printstr("EF: ");
  lcd.setCursor(8, 0);
  lcd.printstr("LF: ");
  lcd.setCursor(0, 1);
  lcd.printstr("Temperatur: ");

  float moistureValue = 0;
  float temperaturValue = 0;
  float humidityValue = 0;
  // Calculate average value from 100 measures
  for (int i = 0; i < 100; i++)
  {
    moistureValue = moistureValue + analogRead(pin_moisture);
    temperaturValue = temperaturValue + dht.readTemperature();
    humidityValue = humidityValue + dht.readHumidity();
  }
  float moistureValueMapped = map(moistureValue/100, 0.00, 950.00, 0.00, 100.00);
  // Print measures into serial monitor with 9600 Baud
  Serial.println("-------------------------------------------------------");
  Serial.println("Erdfeuchtigkeit:  " + String(moistureValueMapped) + "%");
  Serial.println("Temperatur:       " + String(temperaturValue/100) + "*C");
  Serial.println("Luftfeuchtigkeit: " + String(humidityValue) + "%");
  // Write measure on lcd-display
  lcd.setCursor(4, 0);
  lcd.print(String((int)moistureValueMapped) + "%");
  lcd.setCursor(12, 0);
  lcd.print(String((int)humidityValue) + "%");
  lcd.setCursor(12, 1);
  lcd.print(String((int)temperaturValue/100) + (char)223 + "C");
  // Wait 3 seconds till next measurement
  delay(3000);
}