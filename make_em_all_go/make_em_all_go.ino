//Written By Nikodem Bartnik - https://github.com/NikodemBartnik/ArduinoTutorials/blob/master/28BYJ-48/28BYJ-48.ino
//Edited by Iyse - All rights reserved
#define EXECUTE_BUTTON A1

#define STEPPER_PIN_1_1 2
#define STEPPER_PIN_1_2 3
#define STEPPER_PIN_1_3 4
#define STEPPER_PIN_1_4 5

#define STEPPER_PIN_2_1 6
#define STEPPER_PIN_2_2 7
#define STEPPER_PIN_2_3 8
#define STEPPER_PIN_2_4 9

#define STEPPER_PIN_3_1 10
#define STEPPER_PIN_3_2 11
#define STEPPER_PIN_3_3 12
#define STEPPER_PIN_3_4 13




int step_number = 0;

int on_state = 0;

int EXECUTE_BUTTON_State = 0;

void setup() {
pinMode(STEPPER_PIN_1_1, OUTPUT);
pinMode(STEPPER_PIN_1_2, OUTPUT);
pinMode(STEPPER_PIN_1_3, OUTPUT);
pinMode(STEPPER_PIN_1_4, OUTPUT);

pinMode(STEPPER_PIN_2_1, OUTPUT);
pinMode(STEPPER_PIN_2_2, OUTPUT);
pinMode(STEPPER_PIN_2_3, OUTPUT);
pinMode(STEPPER_PIN_2_4, OUTPUT);

pinMode(STEPPER_PIN_3_1, OUTPUT);
pinMode(STEPPER_PIN_3_2, OUTPUT);
pinMode(STEPPER_PIN_3_3, OUTPUT);
pinMode(STEPPER_PIN_3_4, OUTPUT);


pinMode(EXECUTE_BUTTON, INPUT);


Serial.begin(9600);
 Serial.println("start");

}

void loop() {
  delay(10);
 
  if (on_state == 1) {
    OneStep(false);
  }

  EXECUTE_BUTTON_State = digitalRead(EXECUTE_BUTTON);
 	if (EXECUTE_BUTTON_State == HIGH){
    Serial.println("pressed");

      while(EXECUTE_BUTTON_State == HIGH) {
        delay(100);
        EXECUTE_BUTTON_State = digitalRead(EXECUTE_BUTTON);
        
      }
    on_state = !on_state;
  }
}



void OneStep(bool dir){
    if(dir){
      switch(step_number){
        case 0:
        digitalWrite(STEPPER_PIN_1_1, HIGH);
        digitalWrite(STEPPER_PIN_2_2, HIGH);
        digitalWrite(STEPPER_PIN_1_2, HIGH);
        Serial.print("\n\n\n\n\n\n\n\n");
         Serial.println("^");

        digitalWrite(STEPPER_PIN_1_2, LOW);
        digitalWrite(STEPPER_PIN_2_2, LOW);
        digitalWrite(STEPPER_PIN_3_2, LOW);

        digitalWrite(STEPPER_PIN_1_3, LOW);
        digitalWrite(STEPPER_PIN_2_3, LOW);
        digitalWrite(STEPPER_PIN_3_3, LOW);

        digitalWrite(STEPPER_PIN_1_4, LOW);
        digitalWrite(STEPPER_PIN_2_4, LOW);
        digitalWrite(STEPPER_PIN_3_4, LOW);
        break;
        case 1:
        digitalWrite(STEPPER_PIN_1_1, LOW);
        digitalWrite(STEPPER_PIN_2_2, LOW);
        digitalWrite(STEPPER_PIN_1_2, LOW);

        digitalWrite(STEPPER_PIN_1_2, HIGH);
        digitalWrite(STEPPER_PIN_2_2, HIGH);
        digitalWrite(STEPPER_PIN_3_2, HIGH);
        
        Serial.print("\n\n\n\n\n\n\n\n");
        Serial.println(">");

        digitalWrite(STEPPER_PIN_1_3, LOW);
        digitalWrite(STEPPER_PIN_2_3, LOW);
        digitalWrite(STEPPER_PIN_3_3, LOW);

        digitalWrite(STEPPER_PIN_1_4, LOW);
        digitalWrite(STEPPER_PIN_2_4, LOW);
        digitalWrite(STEPPER_PIN_3_4, LOW);
        break;
        case 2:
        digitalWrite(STEPPER_PIN_1_1, LOW);
        digitalWrite(STEPPER_PIN_2_2, LOW);
        digitalWrite(STEPPER_PIN_1_2, LOW);

        digitalWrite(STEPPER_PIN_1_2, LOW);
        digitalWrite(STEPPER_PIN_2_2, LOW);
        digitalWrite(STEPPER_PIN_3_2, LOW);

        digitalWrite(STEPPER_PIN_1_3, HIGH);
        digitalWrite(STEPPER_PIN_2_3, HIGH);
        digitalWrite(STEPPER_PIN_3_3, HIGH);

        Serial.print("\n\n\n\n\n\n\n\n");
        Serial.println("v");

        digitalWrite(STEPPER_PIN_1_4, LOW);
        digitalWrite(STEPPER_PIN_2_4, LOW);
        digitalWrite(STEPPER_PIN_3_4, LOW);
        break;
        case 3:
        digitalWrite(STEPPER_PIN_1_1, LOW);
        digitalWrite(STEPPER_PIN_2_2, LOW);
        digitalWrite(STEPPER_PIN_1_2, LOW);

        digitalWrite(STEPPER_PIN_1_2, LOW);
        digitalWrite(STEPPER_PIN_2_2, LOW);
        digitalWrite(STEPPER_PIN_3_2, LOW);

        digitalWrite(STEPPER_PIN_1_3, LOW);
        digitalWrite(STEPPER_PIN_2_3, LOW);
        digitalWrite(STEPPER_PIN_3_3, LOW);

        digitalWrite(STEPPER_PIN_1_4, HIGH);
        digitalWrite(STEPPER_PIN_2_4, HIGH);
        digitalWrite(STEPPER_PIN_3_4, HIGH);
        
        Serial.print("\n\n\n\n\n\n\n\n");
        Serial.println("<");
        break;
      } 
    }else{
      switch(step_number){
                case 0:
        digitalWrite(STEPPER_PIN_1_1, LOW);
        digitalWrite(STEPPER_PIN_2_2, LOW);
        digitalWrite(STEPPER_PIN_1_2, LOW);

        digitalWrite(STEPPER_PIN_1_2, LOW);
        digitalWrite(STEPPER_PIN_2_2, LOW);
        digitalWrite(STEPPER_PIN_3_2, LOW);

        digitalWrite(STEPPER_PIN_1_3, LOW);
        digitalWrite(STEPPER_PIN_2_3, LOW);
        digitalWrite(STEPPER_PIN_3_3, LOW);

        digitalWrite(STEPPER_PIN_1_4, HIGH);
        digitalWrite(STEPPER_PIN_2_4, HIGH);
        digitalWrite(STEPPER_PIN_3_4, HIGH);
        
        Serial.print("\n\n\n\n\n\n\n\n");
        Serial.println("<");
        
        break;
        case 1:
        digitalWrite(STEPPER_PIN_1_1, LOW);
        digitalWrite(STEPPER_PIN_2_2, LOW);
        digitalWrite(STEPPER_PIN_1_2, LOW);

        digitalWrite(STEPPER_PIN_1_2, LOW);
        digitalWrite(STEPPER_PIN_2_2, LOW);
        digitalWrite(STEPPER_PIN_3_2, LOW);

        digitalWrite(STEPPER_PIN_1_3, HIGH);
        digitalWrite(STEPPER_PIN_2_3, HIGH);
        digitalWrite(STEPPER_PIN_3_3, HIGH);
        
        Serial.print("\n\n\n\n\n\n\n\n");
        Serial.println("v");
        

        digitalWrite(STEPPER_PIN_1_4, LOW);
        digitalWrite(STEPPER_PIN_2_4, LOW);
        digitalWrite(STEPPER_PIN_3_4, LOW);
        break;
        case 2:
        digitalWrite(STEPPER_PIN_1_1, LOW);
        digitalWrite(STEPPER_PIN_2_2, LOW);
        digitalWrite(STEPPER_PIN_1_2, LOW);

        digitalWrite(STEPPER_PIN_1_2, HIGH);
        digitalWrite(STEPPER_PIN_2_2, HIGH);
        digitalWrite(STEPPER_PIN_3_2, HIGH);
        
        Serial.print("\n\n\n\n\n\n\n\n");
        Serial.println(">");

        digitalWrite(STEPPER_PIN_1_3, LOW);
        digitalWrite(STEPPER_PIN_2_3, LOW);
        digitalWrite(STEPPER_PIN_3_3, LOW);

        digitalWrite(STEPPER_PIN_1_4, LOW);
        digitalWrite(STEPPER_PIN_2_4, LOW);
        digitalWrite(STEPPER_PIN_3_4, LOW);
        break;
        case 3:
        digitalWrite(STEPPER_PIN_1_1, HIGH);
        digitalWrite(STEPPER_PIN_2_2, HIGH);
        digitalWrite(STEPPER_PIN_1_2, HIGH);
        
        Serial.print("\n\n\n\n\n\n\n\n");
        Serial.println("^");

        digitalWrite(STEPPER_PIN_1_2, LOW);
        digitalWrite(STEPPER_PIN_2_2, LOW);
        digitalWrite(STEPPER_PIN_3_2, LOW);

        digitalWrite(STEPPER_PIN_1_3, LOW);
        digitalWrite(STEPPER_PIN_2_3, LOW);
        digitalWrite(STEPPER_PIN_3_3, LOW);

        digitalWrite(STEPPER_PIN_1_4, LOW);
        digitalWrite(STEPPER_PIN_2_4, LOW);
        digitalWrite(STEPPER_PIN_3_4, LOW);
        break;
} 
  }
step_number++;
  if(step_number > 3){
    step_number = 0;
  }
}