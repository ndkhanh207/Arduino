#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Mỗi ký tự là mảng 8 byte (mỗi byte là 1 hàng 5 pixel)
byte char_AW[8] = {
  B10001,
  B01110,
  B00000,
  B01110,
  B10001,
  B11111,
  B10001,
  B01111
};

byte char_AA[8] = {
  B00100,
  B01010,
  B00000,
  B01110,
  B10001,
  B11111,
  B10001,
  B10001
};

byte char_DD[8] = {
  B01110,
  B01001,
  B11101,
  B01001,
  B01001,
  B01110,
  B00000,
  B00000
};

byte char_EE[8] = {
  B00100,
  B01010,
  B00000,
  B11111,
  B10000,
  B11110,
  B10000,
  B11111
};

byte char_OO[8] = {
  B00100,
  B01010,
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110
};

byte char_OW[8] = {
  B00010,
  B00001,
  B00010,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110
};

byte char_UW[8] = {
  B00010,
  B00001,
  B00010,
  B10010,
  B10010,
  B10010,
  B01100,
  B00000
};

void setup() {
  lcd.begin(16, 2);

  lcd.createChar(0, char_AW);
  lcd.createChar(1, char_AA);
  lcd.createChar(2, char_DD);
  lcd.createChar(3, char_EE);
  lcd.createChar(4, char_OO);
  lcd.createChar(5, char_OW);
  lcd.createChar(6, char_UW);

  lcd.setCursor(0, 0);
  lcd.write(byte(0)); lcd.print(" ");
  lcd.write(byte(1)); lcd.print(" ");
  lcd.write(byte(2)); lcd.print(" ");
  lcd.write(byte(3)); lcd.print(" ");
  lcd.write(byte(4)); lcd.print(" ");
  lcd.write(byte(5)); lcd.print(" ");
  lcd.write(byte(6));
}

void loop() {

}
