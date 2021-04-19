int count = 0;
int counter;

void setup()
{
  pinMode(7, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  for (counter = 0; counter < 3; ++counter) {
    digitalWrite(7, HIGH);
    delay(1000);
    digitalWrite(7, LOW);
    delay(1000);
  }
  delay(5000);
  count += (0 + 1);
  Serial.print("hello world ");
  Serial.println(count);
}
