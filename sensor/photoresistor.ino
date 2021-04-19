int ledPin = 7;					// pin Arduino yang terhubung ke LED

void setup() {
  pinMode(ledPin, OUTPUT);		// atur pin sebagai OUTPUT
  Serial.begin(9600);			// memulai port serial
}

void loop() {
  int value = analogRead(A0);	// baca sensor analog
  
  Serial.print("Nilai = ");
  Serial.println(value);
  
  if (value < 900){				// Nilai < 900
    digitalWrite(ledPin, HIGH);	// LED ON
  } else {
    digitalWrite(ledPin, LOW);
  }    
}
