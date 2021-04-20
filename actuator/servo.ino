#include <Servo.h>
Servo servo_0;					// deklarasi Servo yang dipakai (bisa 1 atau lebih)
const int servoPin = 7;			// pin Arduino yang terhubung ke Servo 0
const int ledPin = 2;			// pin Arduino yang terhubung ke LED			
int pos = 0;					// variabel untuk simpan nilai posisi (derajat)

void setup()
{
  pinMode(ledPin, OUTPUT);				// atur pin sebagai OUTPUT
  servo_0.attach(servoPin, 500, 2500);	// min = 500 µs, max = 2500 µs
  servo_0.write(pos);					// inisialisasi posisi awal Servo 0
}

void loop()
{
  digitalWrite(2, HIGH);		// LED ON  
  for (pos = 0; pos <= 90; pos += 1) {
    servo_0.write(pos);			// minta servo agar menuju posisi di variabel 'pos'
    delay(15);					// tunggu 15 ms untuk servo mencapai posisi
  }
  delay(2000); 					// tunggu 2 detik
  
  digitalWrite(2, LOW);			// LED OFF 
  for (pos = 90; pos >= 0; pos -= 1) {
    servo_0.write(pos);			// minta servo agar menuju posisi di variabel 'pos'
    delay(15);					// tunggu 15 ms untuk servo mencapai posisi
  }
  delay(2000);					// tunggu 2 detik
}

