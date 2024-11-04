//weewoo copyright chuchu all rights reserved GPL license terms idfk
//you can copy this all you want n sht just be grateful i did this
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);

char *mode[] = {"needs water", "wants CR", "Heart Attacking", "Cardiac Arrestin", "is SUS"}; 
int mode_number;
int ouch; //<-- becomes 0 when pressed, if u cause a bug cuz u 
		  //forgot this istg
const int pinnie = 13;
const int pzzpzz = 12;
int clock_down = 0;

void setup()
{
	//ok i pull up, hop out at the aftah party
	pinMode(13,INPUT_PULLUP);
  
  	Serial.begin(9600);

	lcd.init();
  	lcd.backlight();
  
  //the set backlight thing isnt in the docs but it makes it
	//glow based on boolean

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

		lcd.setBacklight(1);
		delay(50);
		 lcd.setBacklight(0);
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
	lcd.clear();
	clock_down = 0;
  }
  
  
}

void panic()
{
	lcd.clear();
  if (clock_down > 0) {
		mode_number += 1;
  }
	
	lcd.setBacklight(1);
	lcd.setCursor(0, 0);

	
	lcd.print("Nurse!A patient:");

	lcd.setCursor(0, 1);
	lcd.print(mode[mode_number]);
	/* debug */ Serial.println("Mode rn:");
	/* debug */ Serial.print(mode_number);

  if (mode_number > 3) {
	hehe();
  }
	
}

void depanic()
{
	lcd.clear();
	
	
	lcd.setBacklight(1);
	lcd.setCursor(0, 0);
	lcd.print("ok na diay ");

	lcd.setCursor(0, 1);
	lcd.print("'te. lamats");
	delay(700);
}

void hehe() // when the imposter is sus
{
	
  tone(pzzpzz, 1046); 
  delay(250);
  lcd.setBacklight(1);
  tone(pzzpzz, 1244); 
  delay(250); 
  lcd.setBacklight(0);
  tone(pzzpzz, 1400); 
  delay(250); 
  lcd.setBacklight(1);
  tone(pzzpzz, 1510); 
  delay(250);
  lcd.setBacklight(0);
  tone(pzzpzz, 1400); 
  delay(250);
  lcd.setBacklight(1);
  tone(pzzpzz, 1244); 
  delay(250); 
  lcd.setBacklight(0);
  tone(pzzpzz, 1046); 
  delay(250); 
  lcd.setBacklight(1);
  noTone(pzzpzz); 
  delay(500); 
  lcd.setBacklight(0);
  tone(pzzpzz, 932); 
  delay(125);
  lcd.setBacklight(1);
  tone(pzzpzz, 1174); 
  delay(125); 
  lcd.setBacklight(0);
  tone(pzzpzz, 1046); 
  delay(250);
  lcd.setBacklight(1);

  noTone(pzzpzz); 
  delay(500); 
  lcd.setBacklight(0);
  tone(pzzpzz, 780); 
  delay(250); 
  lcd.setBacklight(1);
  tone(pzzpzz, 525); 
  delay(250); 
  lcd.setBacklight(0);
  noTone(pzzpzz); 
  delay(250);
  lcd.setBacklight(1);
  //secont part
  tone(pzzpzz, 1046); 
  delay(250);
  lcd.setBacklight(0);
  tone(pzzpzz, 1244); 
  delay(250); 
  lcd.setBacklight(1);
  tone(pzzpzz, 1400); 
  delay(250); 
  lcd.setBacklight(0);
  tone(pzzpzz, 1510); 
  delay(250);
  lcd.setBacklight(1);
  tone(pzzpzz, 1400); 
  delay(250);
  lcd.setBacklight(0);
  tone(pzzpzz, 1244); 
  delay(250);
  lcd.setBacklight(1);
  tone(pzzpzz, 1400); 
  delay(250);
  lcd.setBacklight(0);
  noTone(pzzpzz); 
  delay(750);
  lcd.setBacklight(1);
  //fast part
  tone(pzzpzz, 1510); 
  delay(125);
  lcd.setBacklight(0);
  tone(pzzpzz, 1400); 
  delay(125);
  lcd.setBacklight(1);
  tone(pzzpzz, 1244); 
  delay(125);
  lcd.setBacklight(0);
  tone(pzzpzz, 1510); 
  delay(125);
  lcd.setBacklight(1);
  tone(pzzpzz, 1400); 
  delay(125);
  lcd.setBacklight(0);
  tone(pzzpzz, 1244); 
  delay(125);
  lcd.setBacklight(1);

  tone(pzzpzz, 780, 100); 
  delay(110);
  lcd.setBacklight(0);
}
