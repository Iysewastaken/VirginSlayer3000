//weewoo copyright chuchu all rights reserved GPL license terms idfk
//you can copy this all you want n sht 
int buzzerPin = 10;
int buttonPin = 5;
int buzzinPin = 12;

int sequence_count = 0;


void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
  pinMode(buzzinPin, OUTPUT);
  tone(buzzinPin, 2000, 2000);
  Serial.begin(9600);
}

void loop() {
  noTone(buzzinPin);
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    digitalWrite(buzzerPin, HIGH);
    
    sequence_count ++;
    Serial.println(sequence_count);
    
  }

  if (buttonState == HIGH) {
    digitalWrite(buzzerPin, LOW);
    Serial.println("lo");
    if (sequence_count < 30){
		sequence_count = 0;
    } else {
      	digitalWrite(buzzerPin, LOW);
		play_this_sht();
      	sequence_count = 0;
    }
    
  }
  delay(100);
}

//↓↓ megalovania notes parodied from this guy ↓↓
//https://github.com/AnonymousAlly/Arduino-Music-Codes

int play_this_sht() {
  //start
Serial.println("start");

tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,1175,250);//D6
delay(250);
tone(buzzinPin,880,250);//A5
delay(325);
tone(buzzinPin,831,125);//Ab5
delay(250);
tone(buzzinPin,784,250);//G5
delay(250);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,784,125);//G5
delay(125);
tone(buzzinPin,523,125);//C5
delay(125);
tone(buzzinPin,523,125);//C5
delay(125);
tone(buzzinPin,1175,250);//D6
delay(250);
tone(buzzinPin,880,250);//A5
delay(325);
tone(buzzinPin,831,125);//Ab5
delay(250);
tone(buzzinPin,784,250);//G5
delay(250);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,784,125);//G5
delay(125);
tone(buzzinPin,494,125);//B4
delay(125);
tone(buzzinPin,494,125);//B4
delay(125);
tone(buzzinPin,1175,250);//D6
delay(250);
tone(buzzinPin,880,250);//A5
delay(325);
tone(buzzinPin,831,125);//Ab5
delay(250);
tone(buzzinPin,784,250);//G5
delay(250);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,784,125);//G5
delay(125);
tone(buzzinPin,466,125);//Bb4
delay(125);
tone(buzzinPin,466,125);//Bb4
delay(125);
tone(buzzinPin,1175,250);//D6
delay(250);
tone(buzzinPin,880,250);//A5
delay(325);
tone(buzzinPin,831,125);//Ab5
delay(250);
tone(buzzinPin,784,250);//G5
delay(250);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,784,125);//G5
delay(125);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,1175,250);//D6
delay(250);
tone(buzzinPin,880,250);//A5
delay(325);
tone(buzzinPin,831,125);//Ab5
delay(250);
tone(buzzinPin,784,250);//G5
delay(250);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,784,125);//G5
delay(125);
tone(buzzinPin,523,125);//C5
delay(125);
tone(buzzinPin,523,125);//C5
delay(125);
tone(buzzinPin,1175,250);//D6
delay(250);
tone(buzzinPin,880,250);//A5
delay(325);
tone(buzzinPin,831,125);//Ab5
delay(250);
tone(buzzinPin,784,250);//G5
delay(250);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,784,125);//G5
delay(125);
tone(buzzinPin,494,125);//B4
delay(125);
tone(buzzinPin,494,125);//B4
delay(125);
tone(buzzinPin,1175,250);//D6
delay(250);
tone(buzzinPin,880,250);//A5
delay(325);
tone(buzzinPin,831,125);//Ab5
delay(250);
tone(buzzinPin,784,250);//G5
delay(250);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,784,125);//G5
delay(125);
tone(buzzinPin,466,125);//Bb4
delay(125);
tone(buzzinPin,466,125);//Bb4
delay(125);
tone(buzzinPin,1175,250);//D6
delay(250);
tone(buzzinPin,880,250);//A5
delay(325);
tone(buzzinPin,831,125);//Ab5
delay(250);
tone(buzzinPin,784,250);//G5
delay(250);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,784,125);//G5
delay(125);

//DU DU DUDU DU DU DU

Serial.println("du du dudu");

tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,698,125);//F5
delay(250);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,587,250);//D5
delay(250);
tone(buzzinPin,587,625);//D5
delay(625);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,698,125);//F5
delay(250);
tone(buzzinPin,784,250);//G5
delay(250);
tone(buzzinPin,831,250);//Ab5
delay(250);
tone(buzzinPin,784,42);//G5
delay(42);
tone(buzzinPin,831,42);//Ab5
delay(42);
tone(buzzinPin,784,42);//G5
delay(42);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,784,125);//G5
delay(375);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,698,125);//F5
delay(250);
tone(buzzinPin,784,250);//G5
delay(250);
tone(buzzinPin,831,125);//Ab5
delay(250);
tone(buzzinPin,880,250);//A5
delay(250);
tone(buzzinPin,1046,250);//C6
delay(250);
tone(buzzinPin,880,375);//A5
delay(375);
tone(buzzinPin,1175,250);//D6
delay(250);
tone(buzzinPin,1175,250);//D6
delay(250);
tone(buzzinPin,1175,125);//D6
delay(125);
tone(buzzinPin,880,125);//A5
delay(125);
tone(buzzinPin,1175,125);//D6
delay(125);
tone(buzzinPin,1046,625);//C6
delay(625);
tone(buzzinPin,1568,500);//G6
delay(500);

//DU DU DUDU DU DU DUU (INTENSIFIES)

Serial.println("du du dudu (intense)");

tone(buzzinPin,880,250);//A5
delay(250);
tone(buzzinPin,880,125);//A5
delay(125);
tone(buzzinPin,880,125);//A5
delay(250);
tone(buzzinPin,880,250);//A5
delay(250);
tone(buzzinPin,880,250);//A5
delay(250);
tone(buzzinPin,784,250);//G5
delay(250);
tone(buzzinPin,784,625);//G5
delay(625);
tone(buzzinPin,880,250);//A5
delay(250);
tone(buzzinPin,880,125);//A5
delay(125);
tone(buzzinPin,880,125);//A5
delay(250);
tone(buzzinPin,880,250);//A5
delay(250);
tone(buzzinPin,784,125);//G5
delay(250);
tone(buzzinPin,880,250);//A5
delay(250);
tone(buzzinPin,1175,125);//D6
delay(250);
tone(buzzinPin,880,125);//A5
delay(125);
tone(buzzinPin,784,250);//G5
delay(250);
tone(buzzinPin,1175,250);//D6
delay(250);
tone(buzzinPin,880,250);//A5
delay(250);
tone(buzzinPin,784,250);//G5
delay(250);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,1046,250);//C6
delay(250);
tone(buzzinPin,784,250);//G5
delay(250);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,659,250);//E5
delay(250);
tone(buzzinPin,466,250);//Bb4
delay(250);
tone(buzzinPin,523,125);//C5
delay(125);
tone(buzzinPin,587,125);//D5
delay(250);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,1046,1125);//C6
delay(1125);

//Epic part

Serial.println("epic");

tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,784,125);//G5
delay(125);
tone(buzzinPin,831,125);//Ab5
delay(125);
tone(buzzinPin,784,125);//G5
delay(125);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,831,63);//Ab5
delay(63);
tone(buzzinPin,784,63);//G5
delay(63);
tone(buzzinPin,698,63);//F5
delay(63);
tone(buzzinPin,587,63);//D5
delay(63);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,784,1125);//G5
delay(1125);
tone(buzzinPin,831,250);//Ab5
delay(250);
tone(buzzinPin,880,125);//A5
delay(125);
tone(buzzinPin,1046,250);//C6
delay(250);
tone(buzzinPin,880,125);//A5
delay(125);
tone(buzzinPin,831,125);//Ab5
delay(125);
tone(buzzinPin,784,125);//G5
delay(125);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,659,125);//E5
delay(125);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,784,250);//G5
delay(250);
tone(buzzinPin,880,250);//A5
delay(250);
tone(buzzinPin,1046,250);//C6
delay(250);
tone(buzzinPin,1109,250);//Db6
delay(250);
tone(buzzinPin,831,250);//Ab5
delay(250);
tone(buzzinPin,831,125);//Ab5
delay(125);
tone(buzzinPin,784,125);//G5
delay(125);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,784,1125);//G5
delay(1125);
tone(buzzinPin,349,250);//F4
delay(250);
tone(buzzinPin,392,250);//G4
delay(250);
tone(buzzinPin,440,250);//A4
delay(250);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,659,500);//E5
delay(500);
tone(buzzinPin,587,500);//D5
delay(500);
tone(buzzinPin,659,500);//E5
delay(500);
tone(buzzinPin,698,500);//F5
delay(500);
tone(buzzinPin,784,500);//G5
delay(500);
tone(buzzinPin,659,500);//E5
delay(500);
tone(buzzinPin,880,1000);//A5
delay(1000);
tone(buzzinPin,880,125);//A5
delay(125);
tone(buzzinPin,831,125);//Ab5
delay(125);
tone(buzzinPin,784,125);//G5
delay(125);
tone(buzzinPin,740,125);//Gb5
delay(125);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,659,125);//E5
delay(125);
tone(buzzinPin,622,125);//Eb5
delay(125);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,554,1000);//Db5
delay(1000);
tone(buzzinPin,622,1000);//Eb5
delay(1000);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,784,125);//G5
delay(125);
tone(buzzinPin,831,125);//Ab5
delay(125);
tone(buzzinPin,784,125);//G5
delay(125);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,831,63);//Ab5
delay(63);
tone(buzzinPin,784,63);//G5
delay(63);
tone(buzzinPin,698,63);//F5
delay(63);
tone(buzzinPin,587,63);//D5
delay(63);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,784,1125);//G5
delay(1125);
tone(buzzinPin,831,250);//Ab5
delay(250);
tone(buzzinPin,880,125);//A5
delay(125);
tone(buzzinPin,1046,250);//C6
delay(250);
tone(buzzinPin,880,125);//A5
delay(125);
tone(buzzinPin,831,125);//Ab5
delay(125);
tone(buzzinPin,784,125);//G5
delay(125);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,659,125);//E5
delay(125);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,784,250);//G5
delay(250);
tone(buzzinPin,880,250);//A5
delay(250);
tone(buzzinPin,1046,250);//C6
delay(250);
tone(buzzinPin,1109,250);//Db6
delay(250);
tone(buzzinPin,831,250);//Ab5
delay(250);
tone(buzzinPin,831,125);//Ab5
delay(125);
tone(buzzinPin,784,125);//G5
delay(125);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,784,1125);//G5
delay(1125);
tone(buzzinPin,349,250);//F4
delay(250);
tone(buzzinPin,392,250);//G4
delay(250);
tone(buzzinPin,440,250);//A4
delay(250);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,659,500);//E5
delay(500);
tone(buzzinPin,587,500);//D5
delay(500);
tone(buzzinPin,659,500);//E5
delay(500);
tone(buzzinPin,698,500);//F5
delay(500);
tone(buzzinPin,784,500);//G5
delay(500);
tone(buzzinPin,659,500);//E5
delay(500);
tone(buzzinPin,880,1000);//A5
delay(1000);
tone(buzzinPin,880,125);//A5
delay(125);
tone(buzzinPin,831,125);//Ab5
delay(125);
tone(buzzinPin,784,125);//G5
delay(125);
tone(buzzinPin,740,125);//Gb5
delay(125);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,659,125);//E5
delay(125);
tone(buzzinPin,622,125);//Eb5
delay(125);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,554,1000);//Db5
delay(1000);
tone(buzzinPin,622,1000);//Eb5
delay(1000);

//Opera

Serial.println("woooohhhh");

tone(buzzinPin,247,1500);//B3
delay(1500);
tone(buzzinPin,349,500);//F4
delay(500);
tone(buzzinPin,330,1000);//E4
delay(1000);
tone(buzzinPin,294,1000);//D4
delay(1000);
tone(buzzinPin,349,4000);//F4
delay(4000);
tone(buzzinPin,247,1500);//B3
delay(1500);
tone(buzzinPin,349,500);//F4
delay(500);
tone(buzzinPin,330,1000);//E4
delay(1000);
tone(buzzinPin,294,1000);//D4
delay(1000);
tone(buzzinPin,294,1000);//D4
delay(1000);
tone(buzzinPin,294,83);//D4
delay(83);
tone(buzzinPin,277,83);//Db4
delay(83);
tone(buzzinPin,262,83);//C4(not middle)     
delay(83);
tone(buzzinPin,247,83);//B3
delay(83);
tone(buzzinPin,247,83);//B3
delay(83);
tone(buzzinPin,220,83);//A3
delay(83);
tone(buzzinPin,208,83);//Ab3
delay(83);
tone(buzzinPin,196,83);//G3
delay(83);
tone(buzzinPin,185,83);//Gb3
delay(83);
tone(buzzinPin,175,83);//F3
delay(83);
tone(buzzinPin,165,83);//E3
delay(83);
tone(buzzinPin,156,83);//Eb3
delay(83);
tone(buzzinPin,147,2000);//D3
delay(2000);
tone(buzzinPin,247,1500);//B3
delay(1500);
tone(buzzinPin,349,500);//F4
delay(500);
tone(buzzinPin,330,1000);//E4
delay(1000);
tone(buzzinPin,294,1000);//D4
delay(1000);
tone(buzzinPin,349,2000);//F4
delay(2000);
tone(buzzinPin,123,125);//B2
delay(125);
tone(buzzinPin,196,125);//G3
delay(125);
tone(buzzinPin,349,125);//F4
delay(125);
tone(buzzinPin,294,125);//D4
delay(125);
tone(buzzinPin,392,250);//G4
delay(250);
tone(buzzinPin,349,125);//F4
delay(125);
tone(buzzinPin,262,125);//C4(not middle)     
delay(125);
tone(buzzinPin,294,125);//D4
delay(125);
tone(buzzinPin,262,250);//C4(not middle)     
delay(250);
tone(buzzinPin,220,250);//A3
delay(250);
tone(buzzinPin,196,125);//G3
delay(125);
tone(buzzinPin,262,125);//C4(not middle)     
delay(125);
tone(buzzinPin,247,1500);//B3
delay(1500);
tone(buzzinPin,349,500);//F4
delay(500);
tone(buzzinPin,330,1000);//E4
delay(1000);
tone(buzzinPin,294,1000);//D4
delay(1000);
tone(buzzinPin,147,125);//D3
delay(125);
tone(buzzinPin,147,125);//D3
delay(125);
tone(buzzinPin,349,250);//F4
delay(250);
tone(buzzinPin,330,250);//E4
delay(250);
tone(buzzinPin,262,125);//C4(not middle)     
delay(250);
tone(buzzinPin,330,250);//E4
delay(250);
tone(buzzinPin,247,250);//B3
delay(250);
tone(buzzinPin,196,125);//G3
delay(125);
tone(buzzinPin,220,125);//A3
delay(125);
tone(buzzinPin,262,125);//C4(not middle)     
delay(125);
tone(buzzinPin,147,125);//D3
delay(125);
tone(buzzinPin,147,125);//D3
delay(125);
tone(buzzinPin,349,250);//F4
delay(250);
tone(buzzinPin,330,250);//E4
delay(250);
tone(buzzinPin,262,125);//C4(not middle)     
delay(250);
tone(buzzinPin,330,250);//E4
delay(250);
tone(buzzinPin,247,250);//B3
delay(250);
tone(buzzinPin,196,125);//G3
delay(125);
tone(buzzinPin,220,125);//A3
delay(125);
tone(buzzinPin,262,125);//C4(not middle)     
delay(125);
  
  
  //end
Serial.println("start");
  
 tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,1175,250);//D6
delay(250);
tone(buzzinPin,880,250);//A5
delay(325);
tone(buzzinPin,831,125);//Ab5
delay(250);
tone(buzzinPin,784,250);//G5
delay(250);
tone(buzzinPin,698,250);//F5
delay(250);
tone(buzzinPin,587,125);//D5
delay(125);
tone(buzzinPin,698,125);//F5
delay(125);
tone(buzzinPin,784,125);//G5
delay(125);


}


	
