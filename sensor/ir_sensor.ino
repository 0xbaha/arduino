int irPin = 7; 				// pin Arduino yang akan membaca output sensor
int ledPin = 8;				// pin Arduino yang terhubung ke LED

void setup() 
{
  pinMode(irPin, INPUT);	// atur pin sebagai INPUT
  pinMode(ledPin, OUTPUT);	// atur pin sebagai OUTPUT
}

void loop()
{
  int statusSensor = digitalRead (irPin);	// baca sensor digital
  
  if (statusSensor == 1){					// statusSensor = 1
    digitalWrite(ledPin, LOW);				
  } else {
    digitalWrite(ledPin, HIGH);				// LED Green ON
  }
}
