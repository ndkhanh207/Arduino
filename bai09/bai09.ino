#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

int lmPin = A0;
int buttonPin = 7;
int ledGreen = 0;
int ledYellow = 1;
int ledRed = 8;

bool show = true;
bool lastButtonState = 0;
int lastTimeChange = 0;
int timeDelay = 200;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Do nhiet do!");
  delay(800);
  lcd.clear();
}

void loop() {
  bool btn = digitalRead(buttonPin);
  if (btn != lastButtonState) lastTimeChange = millis();
  if ((millis() - lastTimeChange) > timeDelay) {
    if (btn == 1 && lastButtonState == 0) show = !show;
  }
  lastButtonState = btn;

  int inputTemp = analogRead(lmPin);
  int tempC = (inputTemp * 500) / 1023;
  int tempDisplay;

  if (show) {
    tempDisplay = tempC;
  } else {
    tempDisplay = (tempC * 9) / 5 + 32;
  }

  lcd.setCursor(0, 1);
  lcd.print("Temp= ");
  lcd.print(tempDisplay);
  if (show) lcd.print("C ");
  else lcd.print("F ");
  lcd.print("      ");

  if (tempC < 17) {
    digitalWrite(ledGreen, 1);
    digitalWrite(ledYellow, 0);
    digitalWrite(ledRed, 0);
  } else if (tempC <= 30) {
    digitalWrite(ledGreen, 0);
    digitalWrite(ledYellow, 1);
    digitalWrite(ledRed, 0);
  } else {
    digitalWrite(ledGreen, 0);
    digitalWrite(ledYellow, 0);
    digitalWrite(ledRed, 1);
  }

  delay(500);
}
