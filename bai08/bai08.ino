#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int eBtn = 6;
int oBtn = 7;
int fBtn = 8;
int sBtn = 9;

int prevE = 0;
int prevO = 0;
int prevF = 0;
int prevS = 0;

char last = 0;
int pos = 0;
int row = 0;

byte EE[8] = {
  B00100,
  B01010,
  B00000,
  B11111,
  B10000,
  B11110,
  B10000,
  B11111
};

byte OO[8] = {
  B00100,
  B01010,
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110
};

byte EF[8] = {
  B01000,
  B00100,
  B00000,
  B11111,
  B10000,
  B11110,
  B10000,
  B11111
};

byte ES[8] = {
  B00100,
  B01000,
  B00000,
  B11111,
  B10000,
  B11110,
  B10000,
  B11111
};

byte OF[8] = {
  B01000,
  B00100,
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110
};

byte OS[8] = {
  B00010,
  B00100,
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110
};

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, EE);
  lcd.createChar(1, OO);
  lcd.createChar(2, EF);
  lcd.createChar(3, ES);
  lcd.createChar(4, OF);
  lcd.createChar(5, OS);
  pinMode(eBtn, INPUT);
  pinMode(oBtn, INPUT);
  pinMode(fBtn, INPUT);
  pinMode(sBtn, INPUT);
  lcd.clear();
}

void loop() {
  int e = digitalRead(eBtn);
  int o = digitalRead(oBtn);
  int f = digitalRead(fBtn);
  int s = digitalRead(sBtn);

  if (pos >= 16) {
    pos = 0;
    row++;
    if (row >= 2) {
      row = 0;
      lcd.clear();
    }
  }

  if (e == HIGH && prevE == LOW) {
    if (last == 'E') {
      lcd.setCursor(pos - 1, row);
      lcd.write((byte)0);
      last = 0;
    } else {
      lcd.setCursor(pos, row);
      lcd.print("E");
      last = 'E';
      pos++;
    }
  }

  if (o == HIGH && prevO == LOW) {
    if (last == 'O') {
      lcd.setCursor(pos - 1, row);
      lcd.write((byte)1);
      last = 0;
    } else {
      lcd.setCursor(pos, row);
      lcd.print("O");
      last = 'O';
      pos++;
    }
  }

  if (f == HIGH && prevF == LOW) {
    if (last == 'E') {
      lcd.setCursor(pos - 1, row);
      lcd.write((byte)2);
      last = 0;
    } else if (last == 'O') {
      lcd.setCursor(pos - 1, row);
      lcd.write((byte)4);
      last = 0;
    } else {
      lcd.setCursor(pos, row);
      lcd.print("F");
      last = 'F';
      pos++;
    }
  }

  if (s == HIGH && prevS == LOW) {
    if (last == 'E') {
      lcd.setCursor(pos - 1, row);
      lcd.write((byte)3);
      last = 0;
    } else if (last == 'O') {
      lcd.setCursor(pos - 1, row);
      lcd.write((byte)5);
      last = 0;
    } else {
      lcd.setCursor(pos, row);
      lcd.print("S");
      last = 'S';
      pos++;
    }
  }

  prevE = e;
  prevO = o;
  prevF = f;
  prevS = s;
}
