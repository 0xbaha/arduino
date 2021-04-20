int motorPin = 3;				// pin Arduino yang terhubung ke BJT

void setup() {
  Serial.begin(9600);			// memulai port serial
}

void loop()
{
  Serial.println("25%");
  analogWrite(motorPin,63);		// 25% duty cycle
  delay(10000);					// tunggu 10 detik
  Serial.println("50%");
  analogWrite(motorPin,127);	// 50% duty cycle
  delay(10000);					// tunggu 10 detik
  Serial.println("75%");
  analogWrite(motorPin,191);	// 75% duty cycle
  delay(10000);					// tunggu 10 detik
  Serial.println("100%");
  analogWrite(motorPin,255);	// 100% duty cycle
  delay(10000);					// tunggu 10 detik
  Serial.println("0%");
  analogWrite(motorPin,0);		// 0% duty cycle
  delay(10000);					// tunggu 10 detik
}
