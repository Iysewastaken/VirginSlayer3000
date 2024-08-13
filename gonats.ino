const int ButtonRight = 2;
const int ButtonCenter = 3;
const int ButtonLeft = 4;

const int PinBottomRight = 7;
const int PinBottom = 8;
const int PinBottomLeft = 9;
const int PinTopRight = 10;
const int PinTop = 11;
const int PinTopLeft = 12;
const int PinCenter = 13;

int ButtonRight_State = 0;
int ButtonCenter_State = 0;
int ButtonLeft_State = 0;

int Hold = 0;
int Held = 0;
int yo_delay = 1000;
int number = 0;

int first_number = 0;

int operation = 0;
const int plus = 1;
const int minus = 0;

void setup()
{
    pinMode(ButtonRight, INPUT);
    pinMode(ButtonCenter, INPUT);
    pinMode(ButtonLeft, INPUT);

    pinMode(PinBottomRight, OUTPUT);
    pinMode(PinBottom, OUTPUT);
    pinMode(PinBottomLeft, OUTPUT);
    pinMode(PinTopRight, OUTPUT);
    pinMode(PinTop, OUTPUT);
    pinMode(PinTopLeft, OUTPUT);
    pinMode(PinCenter, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
    readCenter();
    readLeft();
    readRight();
}

int readRight(){
    ButtonRight_State = digitalRead(ButtonRight);
    if (ButtonRight_State == HIGH){ 
        while (ButtonRight_State == HIGH) {
            delay(100); 
            ButtonRight_State = digitalRead(ButtonRight);
            Hold += 1;
            if (Hold > 10){
                Held = 1;
            }
        }
        if (Held == 1) {
            spin(); //Held
            first_number = number;
            operation = plus;
            number = 0;
            Serial.println(first_number);
            Serial.println("^^ Plus");
            
        } else {
            Serial.println("*Add*"); //Clicked once
            number += 1;
            displaynumber();
            ButtonRight_State = digitalRead(ButtonRight);  
        }
        
    } 
    Hold = 0;
    Held = 0;
}

int readLeft(){
    ButtonLeft_State = digitalRead(ButtonLeft);
    if (ButtonLeft_State == HIGH){ 
        while (ButtonLeft_State == HIGH) {
            delay(100); 
            ButtonLeft_State = digitalRead(ButtonLeft);
            Hold += 1;
            if (Hold > 10){
                Held = 1;
            }
        }
        if (Held == 1) {
            spin(); //Held
            first_number = number;
            operation = minus;
            number = 0;
            Serial.println(first_number);
            Serial.println("^^ Minus");
            
        } else {
            Serial.println("*Subtract*"); //Clicked once
            number -= 1;
            displaynumber();
            ButtonLeft_State = digitalRead(ButtonLeft);  
        }
        
    } 
    Hold = 0;
    Held = 0;
}

int readCenter(){
    ButtonCenter_State = digitalRead(ButtonCenter);
    if (ButtonCenter_State == HIGH){
        Serial.println("Center");
        while (ButtonCenter_State == HIGH) {
            delay(100);
            ButtonCenter_State = digitalRead(ButtonCenter);
        }
        if (first_number > 0) {
            if (number > 0) {
                if (operation == minus) {
                    Serial.println(first_number);
                    Serial.println("Minus");
                    Serial.println(number);
                    Serial.println("Equals");
                    number = first_number - number;
                    displaynumber(); 
                    Serial.println(number);
                } else {
                    Serial.println(first_number);
                    Serial.println("Plus");
                    Serial.println(number);
                    Serial.println("Equals");
                    number = first_number + number;
                    displaynumber(); 
                    Serial.println(number);
                }
            } 
        }
    } 
}

int displaynumber(){
    if (number == 1) {
        one();
    } else if (number == 2) {
        two();
    } else if (number == 3) {
        three();
    } else if (number == 4) {
        four();
    } else if (number == 5) {
        five();
    } else if (number == 6) {
        six();
    } else if (number == 7) {
        seven();
    } else if (number == 8) {
        eight();
    } else if (number == 9) {
        nine();
    } else {
        
        if (number < 0) {
            number = 9;
            nine();
        } else {
            number = 0;
            zero();
        }
    } 
}

int spin(){
    Hold = 0;
    Serial.println("Spimn");
    Serial.println(number);
    digitalWrite(PinCenter, LOW);
    digitalWrite(PinBottomRight, HIGH);
    delay(50);
    digitalWrite(PinBottomRight, LOW);
    digitalWrite(PinTopRight, HIGH);
    delay(50);
    digitalWrite(PinTopRight, LOW);
    digitalWrite(PinTop, HIGH);
    delay(50);
    digitalWrite(PinTop, LOW);
    digitalWrite(PinTopLeft, HIGH);
    delay(50);
    digitalWrite(PinTopLeft, LOW);
    digitalWrite(PinBottomLeft, HIGH);
    delay(50);
    digitalWrite(PinBottomLeft, LOW);
    digitalWrite(PinBottom, HIGH);
    delay(50);
    digitalWrite(PinBottom, LOW);
}

//Segment library

int one(){
    digitalWrite(PinBottomRight, HIGH);
    digitalWrite(PinBottom, LOW);
    digitalWrite(PinBottomLeft, LOW);
    digitalWrite(PinTopRight, HIGH);
    digitalWrite(PinTop, LOW);
    digitalWrite(PinTopLeft, LOW);
    digitalWrite(PinCenter, LOW);
    delay(yo_delay);
}

int two(){
    digitalWrite(PinBottomRight, LOW);
    digitalWrite(PinBottom, HIGH);
    digitalWrite(PinBottomLeft, HIGH);
    digitalWrite(PinTopRight, HIGH);
    digitalWrite(PinTop, HIGH);
    digitalWrite(PinTopLeft, LOW);
    digitalWrite(PinCenter, HIGH);
    delay(yo_delay);
}

int three(){
    digitalWrite(PinBottomRight, HIGH);
    digitalWrite(PinBottom, HIGH);
    digitalWrite(PinBottomLeft, LOW);
    digitalWrite(PinTopRight, HIGH);
    digitalWrite(PinTop, HIGH);
    digitalWrite(PinTopLeft, LOW);
    digitalWrite(PinCenter, HIGH);
    delay(yo_delay);
}

int four(){
    digitalWrite(PinBottomRight, HIGH);
    digitalWrite(PinBottom, LOW);
    digitalWrite(PinBottomLeft, LOW);
    digitalWrite(PinTopRight, HIGH);
    digitalWrite(PinTop, LOW);
    digitalWrite(PinTopLeft, HIGH);
    digitalWrite(PinCenter, HIGH);
    delay(yo_delay);
}

int five(){
    digitalWrite(PinBottomRight, HIGH);
    digitalWrite(PinBottom, HIGH);
    digitalWrite(PinBottomLeft, LOW);
    digitalWrite(PinTopRight, LOW);
    digitalWrite(PinTop, HIGH);
    digitalWrite(PinTopLeft, HIGH);
    digitalWrite(PinCenter, HIGH);
    delay(yo_delay);
}

int six(){
    digitalWrite(PinBottomRight, HIGH);
    digitalWrite(PinBottom, HIGH);
    digitalWrite(PinBottomLeft, HIGH);
    digitalWrite(PinTopRight, LOW);
    digitalWrite(PinTop, HIGH);
    digitalWrite(PinTopLeft, HIGH);
    digitalWrite(PinCenter, HIGH);
    delay(yo_delay);
}

int seven(){
    digitalWrite(PinBottomRight, HIGH);
    digitalWrite(PinBottom, LOW);
    digitalWrite(PinBottomLeft, LOW);
    digitalWrite(PinTopRight, HIGH);
    digitalWrite(PinTop, HIGH);
    digitalWrite(PinTopLeft, LOW);
    digitalWrite(PinCenter, LOW);
    delay(yo_delay);
}

int eight(){
    digitalWrite(PinBottomRight, HIGH);
    digitalWrite(PinBottom, HIGH);
    digitalWrite(PinBottomLeft, HIGH);
    digitalWrite(PinTopRight, HIGH);
    digitalWrite(PinTop, HIGH);
    digitalWrite(PinTopLeft, HIGH);
    digitalWrite(PinCenter, HIGH);
    delay(yo_delay);
}

int nine(){
    digitalWrite(PinBottomRight, HIGH);
    digitalWrite(PinBottom, LOW);
    digitalWrite(PinBottomLeft, LOW);
    digitalWrite(PinTopRight, HIGH);
    digitalWrite(PinTop, HIGH);
    digitalWrite(PinTopLeft, HIGH);
    digitalWrite(PinCenter, HIGH);
    delay(yo_delay);
}

int zero(){
    digitalWrite(PinBottomRight, HIGH);
    digitalWrite(PinBottom, HIGH);
    digitalWrite(PinBottomLeft, HIGH);
    digitalWrite(PinTopRight, HIGH);
    digitalWrite(PinTop, HIGH);
    digitalWrite(PinTopLeft, HIGH);
    digitalWrite(PinCenter, LOW);
    delay(yo_delay);
}

//remember to use a fkn cathode (the resistor in the middle)
