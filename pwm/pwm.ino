void setup()
{

}

void loop()
{
  analogWrite(11,63);	// 25% duty cycle (490Hz)
  analogWrite(10,127);	// 50% duty cycle (490Hz)
  analogWrite(9,191);	// 75% duty cycle (490Hz)
}
