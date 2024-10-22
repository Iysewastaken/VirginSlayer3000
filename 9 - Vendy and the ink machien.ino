//vv Coin Debit System vv


const int Five_Pesos = A3;
const int Ten_Pesos = A2;
const int Twenty_Pesos = A1;
const int Fifty_Pesos = A0;

int Five_Pesos_pressed;
int Ten_Pesos_pressed;
int Twenty_Pesos_pressed;
int Fifty_Pesos_pressed;

int money_inside;

//^^ Coin Debit System ^^

//vv Speacial FX
const int buzzer = A5;

int sounding = 0;
//^^ Special FX

//vv light system
const int item_nestle = 13;
const int item_dasani = 12;
const int item_redwine = 11;
const int item_belle = 10;
const int item_kennard = 9;


//^^ light system



// vv input system (copy pasted) from:
// https://github.com/Chris--A/Keypad/blob/master/examples/CustomKeypad/CustomKeypad.ino
#include <Keypad.h>

const byte ROWS = 3; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'}
};
byte rowPins[ROWS] = {8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

String input;


const int send_pin = A4;
int send;

// ^^ input system

// vv Buy system
String itemlist[5]={"A1", "B3", "B7", "A2", "69"};
String itemnames[5]={
"Nestle", 
"Dasani", 
"Red Wine",
"Bath Water",
"Kennard"};
int itemprices[5]={10, 28, 90, 3, 100};
int i;

int hold_send;
int refunding;

int found;
// ^^ Buy system


void setup()
{
	/* Debug */ Serial.begin(9600);
	
	//vv Coin Debit System vv
  	pinMode(Five_Pesos,INPUT_PULLUP);
	pinMode(Ten_Pesos,INPUT_PULLUP);
	pinMode(Twenty_Pesos,INPUT_PULLUP);
	pinMode(Fifty_Pesos,INPUT_PULLUP);

	//^^ Coin Debit System ^^

	// vv light system
	pinMode(item_nestle, OUTPUT);
	pinMode(item_dasani, OUTPUT);
	pinMode(item_redwine, OUTPUT);
	pinMode(item_belle, OUTPUT);
	pinMode(item_kennard, OUTPUT);
	// ^^ light system

    // vv input system
    pinMode(send_pin,INPUT_PULLUP);
    // ^^ input system
	
}


void loop()
{
	//vv Coin Debit System vv
	debit_read();

	if (Five_Pesos_pressed == 0) {
		money_inside += 5;
    } else if (Ten_Pesos_pressed == 0) {
		money_inside += 10;
    } else if (Twenty_Pesos_pressed == 0) {
		money_inside += 20;
    } else if (Fifty_Pesos_pressed == 0) {
		money_inside += 50;
    }

    for (sounding = 1; (Five_Pesos_pressed == 0) or (Ten_Pesos_pressed == 0) or (Twenty_Pesos_pressed == 0) or (Fifty_Pesos_pressed == 0); ) {
		 
		if (sounding == 1){
			tone(buzzer, 587, 50);
			sounding = 0;
			debug();
        }
      delay(100);
      debit_read();
    }
	
//^^ Coin Debit System ^^

// vv light system
check_price(1, item_nestle, 10);
check_price(2, item_dasani, 28);
check_price(3, item_redwine, 90);
check_price(4, item_belle, 3);
check_price(5, item_kennard, 100);

// ^^ light system

// vv input system
  char customKey = customKeypad.getKey();
  
  if (customKey){
    //Serial.println(customKey);
    if (money_inside) {
		tone(buzzer, 500, 50);
		debug();
		Serial.print("InputBox:");
		input += String(customKey);
    	Serial.println(input);
    } else {
		tone(buzzer, 900, 100);
		Serial.println("\n\n\n\n\n\n");
		Serial.println("Put some money first");
    }
	
  }
// ^^ input system

// vv Buy system
	send = digitalRead(send_pin);
	if (send == 0) {
		hold_send = 0;
		refunding = 0;
		tone(buzzer, 587, 50);
		
      while (send == 0){
		hold_send += 1;
		send = digitalRead(send_pin);
		delay(100);
        if (hold_send > 4) {
			tone(buzzer, 700, 250);
			input = "";
			
			refunding = 1;
			Serial.print("\n\n\n\n Input Reset. You've been refunded P");
			Serial.print(money_inside);

			money_inside = 0;
			while (send == 0){
				send = digitalRead(send_pin);
				delay(100);
            }
        }
      }
      if (refunding == 0) {
		buy_check();
      }
		hold_send = 0;
    }
// ^^ Buy system


/* End of Main Loop ----- */ } /* ----- End of Main Loop */

void debit_read(){
	Five_Pesos_pressed = digitalRead(Five_Pesos);
	Ten_Pesos_pressed = digitalRead(Ten_Pesos);
	Twenty_Pesos_pressed = digitalRead(Twenty_Pesos);
	Fifty_Pesos_pressed = digitalRead(Fifty_Pesos);
}

void debug(){
	Serial.println("\n\n\n\n\n\n");
	Serial.print("money inside:");
	Serial.println(money_inside);
}

void check_price(int item_pos, int LED, int price){
    if (money_inside >= price) {
        digitalWrite(LED, HIGH); 
    } else {
        digitalWrite(LED, LOW);
    }
}

void buy_check(){
	found = 0;
  for (i = 0; i < 5; i ++) {
    if (input == itemlist[i]){
		Serial.print("tried to buy:");
		Serial.println(itemnames[i]);
		Serial.print("which is ");
		Serial.print(itemprices[i]);
		Serial.println(" Pesos. \n");
		found = 1;
		
      if (itemprices[i] <= money_inside){ //Transaction complete
		money_inside -= itemprices[i];
		Serial.print("Transaction complete! Here is your [");
		Serial.print(itemnames[i]);
		Serial.println("]");

		reward(itemnames[i]);
		money_inside = 0;
		input = "";
      } else { //too poor
		Serial.println("Unfortunately, you're poor");
		Serial.print("You still have P");
		Serial.print(money_inside); 
		Serial.print(" in the vending machine. \n hold send to withdraw");
      }
    }
  } 
  if (found == 0) {
	Serial.print("wrong item");
	input = "";
	tone(buzzer, 900, 250);
  }
}

void reward(String item){

  if (item == "Nestle"){
		Serial.println("  ___");
		Serial.println("  )-(  ");
		Serial.println("  | |    ");
		Serial.println(" .'-'.  ");
		Serial.println("/-:.-\\");
		Serial.println(")_   _(");
		Serial.println("|;::  |");
		Serial.println("|;::  |");
		Serial.println("|;::  |");
		Serial.println("|;::._|");
		Serial.println("`-...-'");
  } else if (item == "Dasani"){
        Serial.println("     #");
        Serial.println("    :#:");
        Serial.println("    : :");
        Serial.println("    : :");
        Serial.println("  .'   '.");
        Serial.println("  :_   _:");
        Serial.println("  |     |");
        Serial.println("  |     |");
        Serial.println("  |     |");
        Serial.println("  |_   _|");
        Serial.println("  :_____:");
  } else if (item == "Red Wine"){
        Serial.println("      |=|");
        Serial.println("      | |");
        Serial.println("      | |");
        Serial.println("     /  \\");
        Serial.println("    |----|");
        Serial.println("    |    |");
        Serial.println("    |----|");
        Serial.println("    |____|");
  } else if (item == "Bath Water"){
        Serial.println("     ______");
        Serial.println("    '.___,'");
        Serial.println("     (_ _)");
        Serial.println("     < . >");
        Serial.println("      ) (");
        Serial.println("     /`-.\\");
        Serial.println("    /     \\");
        Serial.println("   / _    _\\");
        Serial.println("  :,' `-.' `:");
        Serial.println("  |         |");
        Serial.println("  :         ;");
        Serial.println("   \\       /");
        Serial.println("    `.___.'");
  } else if (item == "Kennard"){
		Serial.println("                  _");
        Serial.println("                _|_|_");
        Serial.println("                / -_-)");
        Serial.println("        _.---._/ /");
        Serial.println("    ___/        /");
        Serial.println(" __/  (  |  (  |");
        Serial.println("/__.-'|_|----|_|");
  }
	Serial.print(item);
	delay(1000);
  if (item == "Bath Water") {
	Serial.print("\n\n");
	Serial.print("...ew");
  }
} 

