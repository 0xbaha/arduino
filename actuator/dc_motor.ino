int npnPin = 7;					// pin Arduino yang terhubung ke NPN Transistor
const int buzzPin = 8;			// pin Arduino yang terhubung ke Buzzer

void setup() {
  pinMode(npnPin, OUTPUT);		// atur pin sebagai OUTPUT
  pinMode(buzzPin, OUTPUT);		// atur pin sebagai OUTPUT
  Serial.begin(9600);			// memulai port serial
}

void loop() {
  tone(buzzPin, 523, 500); 		// putar nada (f = 523 Hz, durasi = 500 ms) 
  Serial.println("Start");
  digitalWrite(npnPin, HIGH);	// motor ON
  delay(5000);					// tunggu 5 detik
  Serial.println("Stop"); 
  digitalWrite(npnPin, LOW);	// motor OFF
  delay(5000);					// tunggu 5 detik
}

