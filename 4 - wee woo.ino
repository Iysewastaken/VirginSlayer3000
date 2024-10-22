//weewoo copyright chuchu all rights reserved GPL license terms idfk
//you can copy this all you want n sht 
//made by me
const int potPin = A1;
int potVal = 0;
int test;

const int analogOut = 3;

int Red = 13;
int Blue = 12;

void setup()
{
	pinMode(analogOut, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Blue, OUTPUT);
	Serial.begin(9600);
}

void loop()
{
  digitalWrite(analogOut, HIGH);
	delay(50);
	
  potVal = analogRead(potPin);
  test = analogRead(A5);

	//debug
	Serial.println("test vv ");
  Serial.println(test);
  Serial.println("input vv");
  Serial.println(potVal);

	//debug

  digitalWrite(analogOut, 0);
	
  gae();
  if (potVal < 3) {
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
  delay(450);
  tone(analogOut,494,450); 
  delay(500);
}
