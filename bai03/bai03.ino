int den = 13;
int nut_nhanh = 2;
int nut_cham = 3;

int tocdo = 500;
int tocdo_min = 100;
int tocdo_max = 2000;
int buoc = 100;

int trang_thai_den = LOW;
int thoi_diem_truoc = 0;

int trang_thai_nut_nhanh_truoc = LOW;
int trang_thai_nut_cham_truoc = LOW;

void setup() {
  pinMode(den, OUTPUT);
  pinMode(nut_nhanh, INPUT);
  pinMode(nut_cham, INPUT);
}

void loop() {
  int thoi_diem_hien_tai = millis();
  
  int trang_thai_nut_nhanh = digitalRead(nut_nhanh);
  int trang_thai_nut_cham = digitalRead(nut_cham);
  
  if (trang_thai_nut_nhanh == HIGH && trang_thai_nut_nhanh_truoc == LOW) {
    tocdo = tocdo - buoc;
    if (tocdo < tocdo_min) {
      tocdo = tocdo_min;
    }
  }
  
  if (trang_thai_nut_cham == HIGH && trang_thai_nut_cham_truoc == LOW) {
    tocdo = tocdo + buoc;
    if (tocdo > tocdo_max) {
      tocdo = tocdo_max;
    }
  }
  
  trang_thai_nut_nhanh_truoc = trang_thai_nut_nhanh;
  trang_thai_nut_cham_truoc = trang_thai_nut_cham;
  
  if (thoi_diem_hien_tai - thoi_diem_truoc >= tocdo) {
    thoi_diem_truoc = thoi_diem_hien_tai;
    
    if (trang_thai_den == LOW) {
      trang_thai_den = HIGH;
    } else {
      tran  g_thai_den = LOW;
    }
    
    digitalWrite(den, trang_thai_den);
  }
}
