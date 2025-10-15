#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int btnOff = 6;
int btnLeft = 7;
int btnRight = 8;
bool lcdOn = true;
int pos = 0;
String text = "HELLO";
bool lastOff = LOW;
bool lastLeft = LOW;
bool lastRight = LOW;

void setup() {
  lcd.begin(16, 2);
  pinMode(btnOff, INPUT);
  pinMode(btnLeft, INPUT);
  pinMode(btnRight, INPUT);
  lcd.setCursor(pos, 0);
  lcd.print(text);
}

void loop() {
  bool stateOff = digitalRead(btnOff);
  bool stateLeft = digitalRead(btnLeft);
  bool stateRight = digitalRead(btnRight);

  if (stateOff == HIGH && lastOff == LOW) {
    lcdOn = !lcdOn;
    if (lcdOn) lcd.display();
    else lcd.noDisplay();
    delay(200);
  }

  if (lcdOn) {
    if (stateLeft == HIGH && lastLeft == LOW) {
      pos -= 2;
      if (pos < 0) pos = 0;
      lcd.clear();
      lcd.setCursor(pos, 0);
      lcd.print(text);
      delay(200);
    }

    if (stateRight == HIGH && lastRight == LOW) {
      pos += 2;
      if (pos > 16 - text.length()) pos = 16 - text.length();
      lcd.clear();
      lcd.setCursor(pos, 0);
      lcd.print(text);
      delay(200);
    }
  }

  lastOff = stateOff;
  lastLeft = stateLeft;
  lastRight = stateRight;
}
