#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int lmPin = A0;
int buttonC = 7;
int buttonF = 6;

int mode = 0;

void setup() {
  pinMode(lmPin, INPUT);
  pinMode(buttonC, INPUT);
  pinMode(buttonF, INPUT);
  lcd.begin(16, 2);
  lcd.print("Do nhiet do:");
  delay(800);
  lcd.clear();
}

void loop() {
  long val = analogRead(lmPin);
  long tempC = (val * 500) / 1023;
  long tempF = (tempC * 9) / 5 + 32;

  if (digitalRead(buttonC) == 1) mode = 0;
  if (digitalRead(buttonF) == 1) mode = 1;

  lcd.setCursor(0, 0);
  lcd.print("Nhiet do:     ");

  lcd.setCursor(0, 1);
  if (mode == 0) {
    lcd.print(tempC);
    lcd.print((char)223);
    lcd.print("C   ");
  } else {
    lcd.print(tempF);
    lcd.print((char)223);
    lcd.print("F   ");
  }
}
