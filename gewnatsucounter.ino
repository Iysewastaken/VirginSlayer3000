int segmentPins[] = {4,5,6,7,8,9,10};
int buttonUp = 2;
int buttonDown = 3;

int counter = 0;
const int numDigits = 10;

const byte digits[numDigits][7] = {
  {1,1,1,1,1,1,0},//0
  {0,1,1,0,0,0,0},//1
  {1,1,0,1,1,0,1},//2
  {1,1,1,1,0,0,1},//3
  {0,1,1,0,0,1,1},//4
  {1,0,1,1,0,1,1},//5
  {1,0,1,1,1,1,1},//6
  {1,1,1,0,0,0,0},//7
  {1,1,1,1,1,1,1},//8
  {1,1,1,0,0,1,1},//9
};

void setup() {
  displayDigit(0);
  Serial.begin(9600);
  for (int i = 0; i < 7; i++){
	pinMode(segmentPins[i], OUTPUT);
  }
	pinMode(buttonUp, INPUT_PULLUP);
	pinMode(buttonDown, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonUp) == LOW)
	{
		counter++;
    	if (counter >= numDigits) counter = 0;
    	displayDigit(counter);
		delay(200);
  	}
  if (digitalRead(buttonDown) == LOW)
	{
		counter--;
    	if (counter < 0) counter = numDigits - 1;
    	displayDigit(counter);
		delay(200);
  	}

}

void displayDigit(int digit){
  for (int i = 0; i < 7; i++){
	digitalWrite(segmentPins[i], digits[digit][i]);
  }
}
