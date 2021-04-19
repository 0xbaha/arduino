int sensePin = A0;		// pin Arduino yang akan membaca output sensor
int sensorInput;		// variabel untuk simpan nilai output sensor
double temp;        	// variabel untuk simpan nilai suhu (derajat Celcius)

void setup()
{
  Serial.begin(9600);	// memulai port serial
}

void loop()
{
  sensorInput = analogRead(sensePin);	// baca sensor analog
  temp = (double)sensorInput / 1024;	// hitung persentase dari pembacaan input
  temp = temp * 5;                     	// dikali dengan 5V untuk mendapat nilai tegangan
  temp = temp - 0.5;                   	// dikurangi dengan offset 
  temp = temp * 100;                   	// konversi menjadi derajat Celcius 
  
  Serial.print("Suhu: ");
  Serial.print(temp);
  Serial.println(" Celcius");
}

