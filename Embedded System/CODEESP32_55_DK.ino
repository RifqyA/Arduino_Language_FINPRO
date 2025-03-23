/* 
  Kelompok 55
  Faiz Wafi Athallah Zain - 2106733673
  Rifqy Audzan Rusli - 2106733686
  Proyek Sisben 2023: SMART AIR QUALITY SYSTEM
*/

// library yang digunakan
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// mengatur kolom dan baris pada LCD
int lcdColumns = 16;
int lcdRows = 2;

// mengatur alamat, baris, dan kolom pada LCD
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

// define pin pada ESP32
#define SDA 16
#define SCL 17 

void setup() {
  Serial.begin(9600);
  Wire.begin();    
  Wire1.begin(SDA, SCL); 
  // menginisialisasi LCD
  lcd.init();
  // menyalakan backlight pada LCD                    
  lcd.backlight();       
  lcd.setCursor(0,0);
}

void loop() {
  // menghapus pesan pada LCD
lcd.clear();
delay(1);
Wire.requestFrom(8, 12, false); 
// menuliskan pesan yang dikirimkan dari Arduino   
  while (Wire.available()) {
     lcd.clear();
     char msg = Wire.read();
     Serial.print(msg );
     lcd.print(msg);
     delay(1000);
  }
}

