//delulu copyright chuchu all rights reserved GPL license terms idfk
//you can copy this all you want n sht 
//made by me

#include <IRremote.h>

int ligmaballs = 2;
int yea;
int output;

int segmentPins[] = {4,5,6,7,8,9,10};

//vv imported
int counter = 0; //starting number
const int numDigits = 10; //max digits

const byte digits[numDigits][7] = {//sir's better library
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
//^^ imported


void setup()
{
	
	displayDigit(8);//8 so that i can check if all segments are working

	//vv Imported
	for (int i = 0; i < 7; i++){ //i becomes 0 before the codeblock is run, if i is less than 7, add to i everythime it loops
		pinMode(segmentPins[i], OUTPUT); //sets all pins inside the brackets of line 1 into OUTPUT 
  	}
	//^^ Imported

  Serial.begin(9600);
  IrReceiver.begin(ligmaballs, DISABLE_LED_FEEDBACK); // Start the receiver
}

void loop() {
	//ALL lines with "IrReceiver" is from https://github.com/Arduino-IRremote/Arduino-IRremote/blob/master/examples/SimpleReceiver/SimpleReceiver.ino
  if (IrReceiver.decode()) {
	decode_this_shiz();
    //Serial.println(output);
    displayDigit(output);
    IrReceiver.resume(); // Receive the next value
  }
  delay(100);
}

//my hex code library 
//IK ITS SO FKN INEFFICIENT ALRIGHT I JUST WANNA BE ABLE TO 
//READ IT THE NEXT TIME I LOOK AT IT
void decode_this_shiz() {
	
	if (IrReceiver.decodedIRData.command == 0xc) {
		output = 0;
	} else if (IrReceiver.decodedIRData.command == 0x10) {
     	output = 1;
  	} else if (IrReceiver.decodedIRData.command == 0x11) {
     	output = 2;
  	} else if (IrReceiver.decodedIRData.command == 0x12) {
     	output = 3;
  	} else if (IrReceiver.decodedIRData.command == 0x14) {//WHOS IDEA WAS IT TO REMOVE 13!???
     	output = 4;
  	} else if (IrReceiver.decodedIRData.command == 0x15) {
     	output = 5;
  	} else if (IrReceiver.decodedIRData.command == 0x16) {
     	output = 6;
  	} else if (IrReceiver.decodedIRData.command == 0x18) {//HOW DID SUPERSTITION END UP IN CODING BRO WTF
     	output = 7;
  	} else if (IrReceiver.decodedIRData.command == 0x19) {
     	output = 8;
  	} else if (IrReceiver.decodedIRData.command == 0x1a) {
     	output = 9;
  	} else {
		Serial.print("wtf did you just press");
		output = 20;
    }
  if (output != 20) {
	String S = String(IrReceiver.decodedIRData.command, HEX);
	Serial.println(S);
  }
	
	
}


//vv imported
void displayDigit(int digit){
  for (int i = 0; i < 7; i++){  
	digitalWrite(segmentPins[i], digits[digit][i]);
  }
}
//^^ imported

