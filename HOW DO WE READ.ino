//weewoo copyright chuchu all rights reserved GPL license terms idfk
//you can copy this all you want n sht 
//made by me
const int potPin = A1;
int potVal = 0;

const int analogOut = 3;

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
  digitalWrite(analogOut, HIGH);
  potVal = analogRead(potPin);
	Serial.println(potVal);
  digitalWrite(analogOut, 0);
	
  gae();
  if (potVal < 4) {
	digitalWrite(Blue, 1);
    digitalWrite(Red, 0);
  } else if (potVal > 940){
	digitalWrite(Blue, 0);
    digitalWrite(Red, 1);
  } else {
	digitalWrite(Blue, 0);
    digitalWrite(Red, 0);
  }
  
}

void gae(){
  tone(analogOut,523,500); 
  delay(100);
	delay(350);
  tone(analogOut,494,500); 
  delay(500);
}
