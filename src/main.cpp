#include <Arduino.h>
#include <LiquidCrystal.h>

#define NTC_PIN 26
#define BETA 3950
#define RESOLUTION 4095.0

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);

  analogReadResolution(12); // resolucion 12-bit mapping de 0-4095
}

void loop()
{
  int ntcValue = analogRead(NTC_PIN);
  float voltage = ntcValue * (3.3 / RESOLUTION);
  float temperature = 1 / (log(1 / (RESOLUTION / ntcValue - 1)) / BETA + 1.0 / 298.15) - 273.15;

  lcd.setCursor(0, 0);
  lcd.print("Voltaje: ");
  lcd.print(voltage);

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  delay(500);
}
