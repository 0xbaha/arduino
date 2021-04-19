int pwmPin = 9;			// pin 9 (490Hz)
  
void setup()
{

}

void loop()
{
  analogWrite(pwmPin,63);	// 25% duty cycle
  delay(5000);
  analogWrite(pwmPin,127);	// 50% duty cycle
  delay(5000);
  analogWrite(pwmPin,191);	// 75% duty cycle
  delay(5000);
  analogWrite(pwmPin,255);	// 100% duty cycle
  delay(5000);
  analogWrite(pwmPin,0);	// 0% duty cycle
  delay(5000);
}
