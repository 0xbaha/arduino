#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);	    // pin Arduino terhubung LCD
const int TMP36_Pin = A0;				    // pin Arduino terhubung Temperature Sensor
const int ping_Pin = A1;				    // pin Arduino terhubung Ultrasonic Sensor
const int photo_Pin = A2;					// pin Arduino terhubung Photoresistor
const int pir_Pin = A3;						// pin Arduino terhubung PIR Sensor

void setup() {
  lcd.begin(16, 2);						    // atur jumlah kolom dan baris LCD
}

void loop() {
  read_sensor_pir();
  read_sensor_photoresistor();
  read_sensor_ultrasonic();
  read_sensor_temperature();
}

void read_sensor_pir(){
  /* baca dari PIR Sensor */

  int pirStat = digitalRead(pir_Pin); 		// baca PIR Sensor
  
  lcd.setCursor(0,1);					    // atur posisi kursor

  if (pirStat == 1){    
  	lcd.print("Gerak");
  } else {
    lcd.print("Diam ");
  }
}

void read_sensor_photoresistor(){
  /* baca dari Photoresistor */
  
  int value = analogRead(photo_Pin);		// baca Photoresistor
  
  lcd.setCursor(0,0);					    // atur posisi kursor

  if (value < 900){    
  	lcd.print("Gelap ");
  } else {
    lcd.print("Terang");
  }
}

void read_sensor_ultrasonic(){
  /* baca dari Ultrasonic Sensor */
  
  long dur, cm;							    // simpan nilai durasi dan jarak (cm)
  
  pinMode(ping_Pin, OUTPUT);				// atur pin sebagai OUTPUT
  digitalWrite(ping_Pin, LOW);			    // beri sinyal awal LOW
  delayMicroseconds(2);					    // jeda 2 µs
  digitalWrite(ping_Pin, HIGH);			    // trigger sensor dengan sinyal HIGH
  delayMicroseconds(5);					    // trigger sensor selama 5 µs
  digitalWrite(ping_Pin, LOW);			    // beri sinyal LOW

  pinMode(ping_Pin, INPUT);				    // atur pin sebagai INPUT
  dur = pulseIn(ping_Pin, HIGH);			// sinyal HIGH untuk dapat durasi (dalam µs)
  cm = ms_to_cm(dur);					    // konversi µs ke cm
   
  lcd.setCursor(9,0);					    // atur posisi kursor (kolom 13, baris 0)
  if (cm >= 2 && cm <= 330){
    lcd.print(cm);
  } else {
    lcd.print("0");
  }
  lcd.print("  ");							// 2 spasi isi perbedaan ruang antara 1 dan 3 digit
}

long ms_to_cm(long ms) {
  // kecepatan suara 340 m/s atau 29 µs/cm
  // dibagi dua untuk mencari jarak sensor-objek
  return ms / 29 / 2;	
}

void read_sensor_temperature(){
  /* baca dari Temperature Sensor */
  
  int TMP36_read;						    // simpan nilai output Temperature sensor
  double TMP_value;        				    // simpan nilai suhu (derajat Celcius)
  
  TMP36_read = analogRead(TMP36_Pin);	    // baca sensor analog
  TMP_value = (double)TMP36_read / 1024;	// hitung persentase dari pembacaan input
  TMP_value = TMP_value * 5;                // dikali dengan 5V untuk mendapat nilai tegangan
  TMP_value = TMP_value - 0.5;              // dikurangi dengan offset 
  TMP_value = TMP_value * 100;              // konversi menjadi derajat Celcius 
   
  lcd.setCursor(9,1);					    // atur posisi kursor (kolom 0, baris 1)
  lcd.print(TMP_value);
  lcd.print("  ");							// 2 spasi isi perbedaan ruang antara 4 dan 6 digit
}
