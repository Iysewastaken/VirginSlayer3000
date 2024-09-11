// C++ code
//
const int potPin = A1;
int potVal = 0;

int Red = 13;
int Blue = 12;

void setup()
{
	
  pinMode(Red, OUTPUT);
  pinMode(Blue, OUTPUT);
	Serial.begin(9600);
}

void loop()
{
  gae();
  
	potVal = analogRead(potPin);
	Serial.println(potVal);
  if (potVal < 4) {
	digitalWrite(Blue, 1);
    digitalWrite(Red, 0);
  } else if (potVal > 1020){
	digitalWrite(Blue, 0);
    digitalWrite(Red, 1);
  } else {
	digitalWrite(Blue, 0);
    digitalWrite(Red, 0);
  }
  
}

void gae(){
  
  tone(A0,523,500); 
	delay(450);
  tone(A0,494,500); 
  delay(450);}
