//delulu copyright chuchu all rights reserved GPL license terms idfk
//you can copy this all you want n sht 
//made by me

#include <IRremote.h>

int ligmaballs = 2;
int output;

int L1 = 3;
int L2 = 4;
int L3 = 5;

int led;
int i=0;
int sleep;

void setup()
{
	pinMode(L1, OUTPUT);
	pinMode(L2, OUTPUT);
	pinMode(L3, OUTPUT);

  Serial.begin(9600);
  IrReceiver.begin(ligmaballs); // Start the receiver
}

void loop() {
	int i=0;

	//ALL lines with "IrReceiver" is from https://github.com/Arduino-IRremote/Arduino-IRremote/blob/master/examples/SimpleReceiver/SimpleReceiver.ino
  if (IrReceiver.decode()) {
	decode_this_shiz();
    //Serial.println(output);
    
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
		led = L1;
		sleep = 2000;
		blink();
  	} else if (IrReceiver.decodedIRData.command == 0x11) {
     	output = 2;
		led = L2;
		sleep = 1000;
		blink();
  	} else if (IrReceiver.decodedIRData.command == 0x12) {
     	output = 3;
		led = L3;
		sleep = 500;
		blink();
  	} else {
		Serial.print("wtf did you just press");
		output = 20;
    }
  if (output != 20) {
	String S = String(IrReceiver.decodedIRData.command, HEX);
	Serial.println(S);
  }
	Serial.println(output);
}

void blink(){
  for (i=1;i<5;i++){
	digitalWrite(led, HIGH);
	delay(sleep);
	digitalWrite(led, LOW);
	delay(sleep);
  }
}

