/* 
  Kelompok 55
  Faiz Wafi Athallah Zain - 2106733673
  Rifqy Audzan Rusli - 2106733686
  Proyek Sisben 2023: SMART AIR QUALITY SYSTEM
*/

// library yang digunakan
#include <Wire.h>
#include <DHT.h>
#include <DHT_U.h>

//define pin pada arduino
#define DHTPIN 4
#define LEDPIN 8
#define DHTTYPE DHT11 

const int Sensor = A0;
DHT dht(DHTPIN,  DHTTYPE);

void setup() {
 Serial.begin(9600);
 pinMode(Sensor, INPUT);
 pinMode(LEDPIN, INPUT);
  dht.begin(DHTPIN);
  Wire.begin(8);
}

void loop() {

  Wire.onRequest(requestEvent);
  delay(1000);
}

void requestEvent() {
  // membaca nilai sensor gas, humidity, dan suhu
  int  gasLevel = analogRead(Sensor);
  float  h = dht.readHumidity();
  float t = dht.readTemperature();
  
  // memeriksa apakah pembacaan sensor sudah valid
  if (isnan(gasLevel) || isnan(h) || isnan(t)){
    digitalWrite(LEDPIN, HIGH);
  }else{
    digitalWrite(LEDPIN, LOW);

    // memeriksa tingkat gas dan memberikan output pada LCD
    if(gasLevel > 180){
      Serial.print("gasLevel");
      Wire.write("Pake Masker");
    }else if(h>60){
      Serial.print("h");
      Wire.write("Bawa Payung");
    }else{
      Wire.write("Hari Indah");
    }
  }
}