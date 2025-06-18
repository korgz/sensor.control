#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Sensor and LCD setup
#define DHTPIN 2          // DHT sensor data pin
#define DHTTYPE DHT11     // Type
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address, 16 cols, 2 rows

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();              
  lcd.backlight();         

  lcd.setCursor(0, 0);
  lcd.print("Temp & Humidity");
  delay(2000);
  lcd.clear();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    lcd.setCursor(0, 0);
    lcd.print("Sensor error    ");
    return;
  }

  // Serial Logging
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" °C, Humidity: ");
  Serial.print(h);
  Serial.println(" %");

  // LCD Display    
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t, 1);
  lcd.print(" C ");

  lcd.setCursor(0, 1);
  lcd.print("Hum : ");
  lcd.print(h, 1);
  lcd.print(" % ");

  delay(2000); // 2 seconds between readings
}