//weewoo copyright chuchu all rights reserved GPL license terms idfk
//you can copy this all you want n sht just be grateful i did this
#include <Adafruit_LiquidCrystal.h>

char *mode[] = {"needs water", "wants CR", "Heart Attack", "Cardiac Arrest", "SUS"}; 
int mode_number;
int ouch; //<-- becomes 0 when pressed, if u cause a bug cuz u 
		  //forgot this istg
const int pinnie = 13;
const int pzzpzz = 12;
int clock_down = 0;

Adafruit_LiquidCrystal liquidussy(0);

void setup()
{
	//ok i pull up, hop out at the aftah party
	pinMode(13,INPUT_PULLUP);
	
	/* idfk what the 1st parameter is but the 2nd one */
	// is for the rows
  	liquidussy.begin(16, 2);
  
  	Serial.begin(9600);

  	// makes the next text start appearing at the top left corner
	// or is it right, im dyslexic asf
	liquidussy.setCursor(0, 1);
	//for some fkn reason, the first row corresponds to zero
	//and the 2nd row is 1, i dont get it either. WHY!?
  
  //the set backlight thing isnt in the docs but it makes it
	//glow based on boolean
  liquidussy.setBacklight(1);

	pinMode(pzzpzz, OUTPUT);
	
}

void loop()
{
	/* debug */ Serial.println(clock_down);
	

	ouch = digitalRead(pinnie);
	
  if (ouch == 0) {
	tone(pzzpzz, 587);
	panic();
	clock_down = 30;
    while (ouch == 0) {
		 
		ouch = digitalRead(pinnie);

		liquidussy.setBacklight(1);
		delay(50);
		 liquidussy.setBacklight(0);
		delay(50);
  	}
	noTone(pzzpzz);
	
  }
	delay(100);
  if (clock_down > 1) {
	clock_down -= 1;
  } else if (clock_down == 1){
	depanic();
	mode_number = 0;
	delay(100);
	liquidussy.clear();
	clock_down = 0;
  }
  
  
}

void panic()
{
	liquidussy.clear();
  if (clock_down > 0) {
		mode_number += 1;
  }
	
	liquidussy.setBacklight(1);
	liquidussy.setCursor(0, 0);

	
	liquidussy.print("The patient is:");

	liquidussy.setCursor(0, 1);
	liquidussy.print(mode[mode_number]);

  if (mode_number > 3) {
	hehe();
  }
	
}

void depanic()
{
	liquidussy.clear();
	
	
	liquidussy.setBacklight(1);
	liquidussy.setCursor(0, 0);
	liquidussy.print("ok na diay ");

	liquidussy.setCursor(0, 1);
	liquidussy.print("te. lamats");
}

void hehe() // when the imposter is sus
{
	liquidussy.clear();

	liquidussy.setCursor(0, 0);
	liquidussy.print("When the imposter");
	liquidussy.setCursor(0, 1);
	liquidussy.print("is SUS");
	
  tone(pzzpzz, 1046); 
  delay(250);
  liquidussy.setBacklight(1);
  tone(pzzpzz, 1244); 
  delay(250); 
  liquidussy.setBacklight(0);
  tone(pzzpzz, 1400); 
  delay(250); 
  liquidussy.setBacklight(1);
  tone(pzzpzz, 1510); 
  delay(250);
  liquidussy.setBacklight(0);
  tone(pzzpzz, 1400); 
  delay(250);
  liquidussy.setBacklight(1);
  tone(pzzpzz, 1244); 
  delay(250); 
  liquidussy.setBacklight(0);
  tone(pzzpzz, 1046); 
  delay(250); 
  liquidussy.setBacklight(1);
  noTone(pzzpzz); 
  delay(500); 
  liquidussy.setBacklight(0);
  tone(pzzpzz, 932); 
  delay(125);
  liquidussy.setBacklight(1);
  tone(pzzpzz, 1174); 
  delay(125); 
  liquidussy.setBacklight(0);
  tone(pzzpzz, 1046); 
  delay(250);
  liquidussy.setBacklight(1);

  noTone(pzzpzz); 
  delay(500); 
  liquidussy.setBacklight(0);
  tone(pzzpzz, 780); 
  delay(250); 
  liquidussy.setBacklight(1);
  tone(pzzpzz, 525); 
  delay(250); 
  liquidussy.setBacklight(0);
  noTone(pzzpzz); 
  delay(250);
  liquidussy.setBacklight(1);
  //secont part
  tone(pzzpzz, 1046); 
  delay(250);
  liquidussy.setBacklight(0);
  tone(pzzpzz, 1244); 
  delay(250); 
  liquidussy.setBacklight(1);
  tone(pzzpzz, 1400); 
  delay(250); 
  liquidussy.setBacklight(0);
  tone(pzzpzz, 1510); 
  delay(250);
  liquidussy.setBacklight(1);
  tone(pzzpzz, 1400); 
  delay(250);
  liquidussy.setBacklight(0);
  tone(pzzpzz, 1244); 
  delay(250);
  liquidussy.setBacklight(1);
  tone(pzzpzz, 1400); 
  delay(250);
  liquidussy.setBacklight(0);
  noTone(pzzpzz); 
  delay(750);
  liquidussy.setBacklight(1);
  //fast part
  tone(pzzpzz, 1510); 
  delay(125);
  liquidussy.setBacklight(0);
  tone(pzzpzz, 1400); 
  delay(125);
  liquidussy.setBacklight(1);
  tone(pzzpzz, 1244); 
  delay(125);
  liquidussy.setBacklight(0);
  tone(pzzpzz, 1510); 
  delay(125);
  liquidussy.setBacklight(1);
  tone(pzzpzz, 1400); 
  delay(125);
  liquidussy.setBacklight(0);
  tone(pzzpzz, 1244); 
  delay(125);
  liquidussy.setBacklight(1);

  tone(pzzpzz, 780, 100); 
  delay(110);
  liquidussy.setBacklight(0);
}