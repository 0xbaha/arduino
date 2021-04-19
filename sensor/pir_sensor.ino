int ledPin = 8;				// pin Arduino yang terhubung ke LED(Green)
int pirPin = 7;				// pin Arduino yang akan membaca output sensor	
int pirStat = 0;			// pin Arduino yang akan membaca output sensor
 
void setup() {
  pinMode(pirPin, INPUT);  	// atur pin sebagai INPUT 
  pinMode(ledPin, OUTPUT); 	// atur pin sebagai OUTPUT  
}
 
void loop(){
  
  pirStat = digitalRead(pirPin); 	// baca sensor digital
   
  if (pirStat == 1) {            	// ada gerakan terdeteksi
    digitalWrite(ledPin, HIGH);  	// LED ON
  } 
  else {							// tidak ada gerakan
    digitalWrite(ledPin, LOW); 		// LED OFF
   
  }
}
