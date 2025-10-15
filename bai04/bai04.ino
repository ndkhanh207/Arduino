int den_vang = 8;
int den_do = 9;
int nut = 2;

int trang_thai = 0;
int trang_thai_nut_truoc = LOW;

void setup() {
  pinMode(den_vang, OUTPUT);
  pinMode(den_do, OUTPUT);
  pinMode(nut, INPUT);
  
  digitalWrite(den_vang, LOW);
  digitalWrite(den_do, LOW);
}

void loop() {
  int trang_thai_nut = digitalRead(nut);
  
  if (trang_thai_nut == HIGH && trang_thai_nut_truoc == LOW) {
    trang_thai++;
    if (trang_thai > 3) {
      trang_thai = 0;
    }
    
    if (trang_thai == 0) {
      digitalWrite(den_vang, LOW);
      digitalWrite(den_do, LOW);
    }
    else if (trang_thai == 1) {
      digitalWrite(den_vang, HIGH);
      digitalWrite(den_do, HIGH);
    }
    else if (trang_thai == 2) {
      digitalWrite(den_vang, LOW);
      digitalWrite(den_do, LOW);
    }
    else if (trang_thai == 3) {
      digitalWrite(den_vang, HIGH);
      digitalWrite(den_do, LOW);
    }
  }
  
  trang_thai_nut_truoc = trang_thai_nut;
}
