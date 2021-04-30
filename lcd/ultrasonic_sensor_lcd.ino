#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);	    // pin Arduino terhubung LCD
const int ping_Pin = A1;				    // pin Arduino terhubung Ultrasonic Sensor
long dur, cm;							    // simpan nilai durasi dan jarak (cm)

void setup() {
  lcd.begin(16, 2);						    // atur jumlah kolom dan baris LCD
  lcd.print("PING Sensor");
}

void loop() {
  cm = read_sensor_ultrasonic();
  
  /* Print to LCD */
  lcd.setCursor(0,1);					    // atur kursor ke kolom 0 baris 1
  lcd.print("Jarak ");
  lcd.setCursor(6,1);					    // atur kursor ke kolom 6 baris 1
  lcd.print(cm);							// cetak nilai jarak
  print_unit_cm(cm);						// cetak satuan (cm)
}

int read_sensor_ultrasonic(){
  /* baca dari Ultrasonic Sensor */
  
  pinMode(ping_Pin, OUTPUT);				// atur pin sebagai OUTPUT
  digitalWrite(ping_Pin, LOW);			    // beri sinyal awal LOW
  delayMicroseconds(2);					    // jeda 2 µs
  digitalWrite(ping_Pin, HIGH);			    // trigger sensor dengan sinyal HIGH
  delayMicroseconds(5);					    // trigger sensor selama 5 µs
  digitalWrite(ping_Pin, LOW);			    // beri sinyal LOW

  pinMode(ping_Pin, INPUT);				    // atur pin sebagai INPUT
  dur = pulseIn(ping_Pin, HIGH);			// sinyal HIGH untuk dapat durasi (dalam µs)
  cm = ms_to_cm(dur);					    // konversi µs ke cm
  
  if (cm >= 2 && cm <= 330){
    return cm;
  } else {
    return 0;
  }
}

long ms_to_cm(long ms) {
  // kecepatan suara 340 m/s atau 29 µs/cm
  // dibagi dua untuk mencari jarak sensor-objek
  return ms / 29 / 2;	
}

void print_unit_cm(long cm){
  /* cetak satuan cm */
  
  int ROW = 1;								// nomor baris
  int ERR_Digit = 6;						// koordinat kolom
  int oneDigit = 7;							// koordinat kolom
  int twoDigit = 8;							// koordinat kolom
  int threeDigit = 9;						// koordinat kolom
  int lenUnit = 2;							// jumlah karakter satuan
  
  if (cm >= 2 && cm < 10){					// jarak 2-9cm
    lcd.setCursor(oneDigit,ROW);			// atur posisi kursor
  	lcd.print("cm");
    print_blank(oneDigit+lenUnit,ROW);
  } else if (cm >= 10 && cm < 100){			// jarak 10-99cm
    lcd.setCursor(twoDigit,ROW);			// atur posisi kursor
  	lcd.print("cm");
    print_blank(twoDigit+lenUnit,ROW);
  } else if (cm >= 100 && cm <= 330){		// jarak >100cm
    lcd.setCursor(threeDigit,ROW);			// atur posisi kursor
  	lcd.print("cm");
    print_blank(threeDigit+lenUnit,ROW);
  } else {									// di luar jarak ukur
    lcd.setCursor(ERR_Digit,ROW);			// atur posisi kursor
    print_blank(ERR_Digit,ROW);
  }
}

void print_blank(int col, int row){
  /* cetak spasi/blank sampai kolom ke-16 */
  
  int total_col = 16;
  for (int i = col; i < total_col; i++){
    lcd.setCursor(i,row);
    lcd.print(" ");
  }
}
