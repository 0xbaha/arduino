#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(5, 4, 3, 2, A4, A5);	// pin Arduino yang terhubung ke LCD
const byte ROWS = 4;  					// jumlah baris Keypad
const byte COLS = 4;  					// jumlah kolom Keypad
char keys[ROWS][COLS] = {				// karakter pada Keypad
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {A0, A1, 11, 10};  // pin Arduino yang terhubung ke Keypad (baris)
byte colPins[COLS] = {9, 8, 7, 6};      // pin Arduino yang terhubung ke Keypad (kolom)
int LCDRow = 0;							// inisialisasi posisi kursor LCD (baris)
int LCDCol = 0;							// inisialisasi posisi kursor LCD (kolom)

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);					// memulai port serial
  lcd.begin(16, 2);               		// atur jumlah kolom dan baris LCD
  lcd.setCursor(LCDRow, LCDCol);        // atur kursor LCD
}

void loop() {
  char key = keypad.getKey();     

  if (key){                       
    Serial.println(key);
    lcd.print(key);
    lcd.setCursor(++LCDRow, 0);
  }
}
 
