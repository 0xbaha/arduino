int const gasPin = A1;	// pin Arduino yang akan membaca output sensor
int ledG_Pin = 7;		// pin Arduino yang terhubung ke LED(Green)
int ledY_Pin = 6;		// pin Arduino yang terhubung ke LED(Yellow)
int ledO_Pin = 5;		// pin Arduino yang terhubung ke LED(Orange)
int ledR_Pin = 4;		// pin Arduino yang terhubung ke LED(Red)

void setup()
{
  pinMode(ledG_Pin, OUTPUT);	// atur pin sebagai OUTPUT
  pinMode(ledY_Pin, OUTPUT);	// atur pin sebagai OUTPUT
  pinMode(ledO_Pin, OUTPUT);	// atur pin sebagai OUTPUT
  pinMode(ledR_Pin, OUTPUT);	// atur pin sebagai OUTPUT
  Serial.begin(9600);			// memulai port serial
}

void loop()
{
  int value = analogRead(gasPin);	// baca sensor analog
  
  Serial.print("Nilai = ");
  Serial.println(value);
  
  digitalWrite(ledG_Pin, HIGH);		// LED Green ON
  
  if (value >= 400){				// Nilai >= 400
    digitalWrite(ledY_Pin, HIGH);	// LED Yellow ON
  } else {
    digitalWrite(ledY_Pin, LOW);
  }
  
  if (value >= 500){				// Nilai >= 500
    digitalWrite(ledO_Pin, HIGH);	// LED Orange ON
  } else {
    digitalWrite(ledO_Pin, LOW);
  }
  
  if (value >= 700){				// Nilai >= 700
    digitalWrite(ledR_Pin, HIGH);	// LED Red ON
  } else {
    digitalWrite(ledR_Pin, LOW);
  }
  
  delay(250);
}
