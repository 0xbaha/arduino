#include <Servo.h>
Servo servo_0;					// deklarasi Servo yang dipakai (bisa 1 atau lebih)
Servo servo_1;					// deklarasi Servo yang dipakai (bisa 1 atau lebih)
Servo servo_2;					// deklarasi Servo yang dipakai (bisa 1 atau lebih)
const int servo0_Pin = 7;		// pin Arduino yang terhubung ke Servo 0
const int servo1_Pin = 8;		// pin Arduino yang terhubung ke Servo 0
const int servo2_Pin = 9;		// pin Arduino yang terhubung ke Servo 0
const int ledR_Pin = 2;			// pin Arduino yang terhubung ke LED(Red)
const int ledB_Pin = 3;			// pin Arduino yang terhubung ke LED(Blue)
const int ledG_Pin = 4;			// pin Arduino yang terhubung ke LED(Green)
const int buzzPin = 5;			// pin Arduino yang terhubung ke Buzzer
int pos = 0;					// variabel untuk simpan nilai posisi (derajat)

void setup()
{
  pinMode(ledR_Pin, OUTPUT);				// atur pin sebagai OUTPUT
  pinMode(ledB_Pin, OUTPUT);				// atur pin sebagai OUTPUT
  pinMode(ledG_Pin, OUTPUT);				// atur pin sebagai OUTPUT
  pinMode(buzzPin, OUTPUT);					// atur pin sebagai OUTPUT
  servo_0.attach(servo0_Pin, 500, 2500);	// min = 500 µs, max = 2500 µs
  servo_1.attach(servo1_Pin, 500, 2500);	// min = 500 µs, max = 2500 µs
  servo_2.attach(servo2_Pin, 500, 2500);	// min = 500 µs, max = 2500 µs
  servo_0.write(pos);						// inisialisasi posisi awal Servo 0
  servo_1.write(pos);						// inisialisasi posisi awal Servo 1
  servo_2.write(pos);						// inisialisasi posisi awal Servo 2
}

void loop()
{
  /* Servo 0 */
  tone(buzzPin, 523, 500); 		// putar nada (f = 523 Hz, durasi = 500 ms) 
  digitalWrite(4, HIGH);		// LED Green ON  
  for (pos = 0; pos <= 90; pos += 1) {
    servo_0.write(pos);			// minta servo agar menuju posisi di variabel 'pos'
    delay(15);					// tunggu 15 ms untuk servo mencapai posisi
  }
  delay(2000); 					// tunggu 2 detik 
  digitalWrite(4, LOW);			// LED Green OFF
  digitalWrite(2, HIGH);		// LED Red ON
  for (pos = 90; pos >= 0; pos -= 1) {
    servo_0.write(pos);			// minta servo agar menuju posisi di variabel 'pos'
    delay(15);					// tunggu 15 ms untuk servo mencapai posisi
  }
  digitalWrite(4, HIGH);		// LED Green ON --> Yellow
  delay(2000);					// tunggu 2 detik
  digitalWrite(2, LOW);			// LED Red OFF --> Green
  
  /* Servo 1 */
  tone(buzzPin, 523, 500); 		// putar nada (f = 523 Hz, durasi = 500 ms) 
  digitalWrite(4, HIGH);		// LED Green ON  
  for (pos = 0; pos <= 90; pos += 1) {
    servo_1.write(pos);			// minta servo agar menuju posisi di variabel 'pos'
    delay(15);					// tunggu 15 ms untuk servo mencapai posisi
  }
  delay(2000); 					// tunggu 2 detik 
  digitalWrite(4, LOW);			// LED Green OFF
  digitalWrite(2, HIGH);		// LED Red ON
  for (pos = 90; pos >= 0; pos -= 1) {
    servo_1.write(pos);			// minta servo agar menuju posisi di variabel 'pos'
    delay(15);					// tunggu 15 ms untuk servo mencapai posisi
  }
  digitalWrite(4, HIGH);		// LED Green ON --> Yellow
  delay(2000);					// tunggu 2 detik
  digitalWrite(2, LOW);			// LED Red OFF --> Green
  
  /* Servo 2 */
  tone(buzzPin, 523, 500); 		// putar nada (f = 523 Hz, durasi = 500 ms) 
  digitalWrite(4, HIGH);		// LED Green ON  
  for (pos = 0; pos <= 90; pos += 1) {
    servo_2.write(pos);			// minta servo agar menuju posisi di variabel 'pos'
    delay(15);					// tunggu 15 ms untuk servo mencapai posisi
  }
  delay(2000); 					// tunggu 2 detik 
  digitalWrite(4, LOW);			// LED Green OFF
  digitalWrite(2, HIGH);		// LED Red ON
  for (pos = 90; pos >= 0; pos -= 1) {
    servo_2.write(pos);			// minta servo agar menuju posisi di variabel 'pos'
    delay(15);					// tunggu 15 ms untuk servo mencapai posisi
  }
  digitalWrite(4, HIGH);		// LED Green ON --> Yellow
  delay(2000);					// tunggu 2 detik
  digitalWrite(2, LOW);			// LED Red OFF --> Green
}

