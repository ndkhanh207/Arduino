#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int buttonPin = 7;
int ledPin = 8;
bool lcdOn = true;
bool lastButton = LOW;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("LCD ON");
}

void loop() {
  bool buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && lastButton == LOW) {
    lcdOn = !lcdOn;
    if (lcdOn) {
      lcd.display();
      lcd.clear();
      lcd.print("LCD ON");
      digitalWrite(ledPin, LOW);
    } else {
      lcd.noDisplay();
      digitalWrite(ledPin, HIGH);
    }
  }
  lastButton = buttonState;
}
