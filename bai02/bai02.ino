int do_A = 2;
int vang_A = 3;
int xanh_A = 4;

int do_B = 5;
int vang_B = 6;
int xanh_B = 7;

int do_C = 8;
int vang_C = 9;
int xanh_C = 10;

int thoigian_xanh = 5000;
int thoigian_vang = 2000;
int thoigian_do = 14000;

void setup() {
  pinMode(do_A, OUTPUT);
  pinMode(vang_A, OUTPUT);
  pinMode(xanh_A, OUTPUT);
  
  pinMode(do_B, OUTPUT);
  pinMode(vang_B, OUTPUT);
  pinMode(xanh_B, OUTPUT);
  
  pinMode(do_C, OUTPUT);
  pinMode(vang_C, OUTPUT);
  pinMode(xanh_C, OUTPUT);

}

void loop() {
  digitalWrite(xanh_A, HIGH);
  digitalWrite(do_B, HIGH);
  digitalWrite(do_C, HIGH);
  delay(thoigian_xanh);
  
  digitalWrite(xanh_A, LOW);
  digitalWrite(vang_A, HIGH);
  delay(thoigian_vang);
  
  digitalWrite(vang_A, LOW);
  digitalWrite(do_A, HIGH);
  
  digitalWrite(do_B, LOW);
  digitalWrite(xanh_B, HIGH);
  delay(thoigian_xanh);
  
  digitalWrite(xanh_B, LOW);
  digitalWrite(vang_B, HIGH);
  delay(thoigian_vang);
  
  digitalWrite(vang_B, LOW);
  digitalWrite(do_B, HIGH);
  
  digitalWrite(do_C, LOW);
  digitalWrite(xanh_C, HIGH);
  delay(thoigian_xanh);
  
  digitalWrite(xanh_C, LOW);
  digitalWrite(vang_C, HIGH);
  delay(thoigian_vang);
  
  digitalWrite(vang_C, LOW);
  digitalWrite(do_C, HIGH);
  digitalWrite(do_A, LOW);
}
