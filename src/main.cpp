#include <Arduino.h>
#include <LiquidCrystal.h>

#define NTC_PIN 26
#define BETA 3950
#define RESOLUTION 2047.0

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup()
{
  lcd.begin(16, 2);

  analogReadResolution(11); // resolucion 11-bit mapping de 0 a 2047
}

void loop()
{
  int potenciometro = analogRead(NTC_PIN);
  float voltage = potenciometro * (3.3 / RESOLUTION);

  lcd.setCursor(0, 0);
  lcd.print("Voltaje: ");
  lcd.print(voltage);
  lcd.setCursor(0, 1);
  lcd.print("Pot: ");
  lcd.print(potenciometro);

  delay(500);
}
