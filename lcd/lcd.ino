#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);	// pin Arduino yang terhubung ke LCD

void setup() {
  lcd.begin(16, 2);						// atur jumlah kolom dan baris LCD
  lcd.print("hello, world!");			// menampilkan tulisan pada LCD
}

void loop() {
  lcd.setCursor(0, 1);					// atur kursor ke kolom 0 baris 1
  lcd.print(millis() / 1000);			// menampilkan waktu (dalam detik)
}


