#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);	    // pin Arduino terhubung LCD
const int TMP36_Pin = A0;				    // pin Arduino terhubung Temperature Sensor
int TMP36_read;						        // simpan nilai output Temperature sensor
double TMP_value;        				    // simpan nilai suhu (derajat Celcius)

void setup() {
  lcd.begin(16, 2);						    // atur jumlah kolom dan baris LCD
  lcd.print("TMP36 Sensor");
}

void loop() {
  TMP_value = read_sensor_temperature();
  
  /* Print to LCD */
  lcd.setCursor(0,1);					    // atur kursor ke kolom 0 baris 1
  lcd.print("Suhu ");
  lcd.setCursor(6,1);					    // atur kursor ke kolom 6 baris 1
  lcd.print(TMP_value);
  print_unit_celcius(TMP_value);  
}

double read_sensor_temperature(){
  /* baca dari Temperature Sensor */
  
  double temp;
  TMP36_read = analogRead(TMP36_Pin);	    // baca sensor analog
  temp = (double)TMP36_read / 1024;	        // hitung persentase dari pembacaan input
  temp = temp * 5;                          // dikali dengan 5V untuk mendapat nilai tegangan
  temp = temp - 0.5;                        // dikurangi dengan offset 
  temp = temp * 100;                        // konversi menjadi derajat Celcius 
  return temp;
}

void print_unit_celcius(long TMP){
  /* cetak satuan Celcius */
  
  int ROW = 1;								// nomor baris
  int ERR_Digit = 6;						// koordinat kolom
  int fourDigit = 10;						// koordinat kolom
  int fiveDigit = 11;						// koordinat kolom
  int sixDigit = 12;						// koordinat kolom
  int lenUnit = 1;							// jumlah karakter satuan
  
  if ((TMP >= -40 && TMP < -9) || (TMP >= 100 && TMP < 125)) {
    // 6 digit
    lcd.setCursor(sixDigit,ROW);			// atur posisi kursor
  	lcd.print("C");
    print_blank(sixDigit+lenUnit,ROW);
  } else if ((TMP >= -9 && TMP < 0) || (TMP >= 10 && TMP < 100)) {
    // 5 digit
    lcd.setCursor(fiveDigit,ROW);			// atur posisi kursor
  	lcd.print("C");
    print_blank(fiveDigit+lenUnit,ROW);
  } else if (TMP >= 0 && TMP < 10){
    // 4 digit
    lcd.setCursor(fourDigit,ROW);			// atur posisi kursor
  	lcd.print("C");
    print_blank(fourDigit+lenUnit,ROW);
  } else {
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
