#include <IRremote.h>
#define ir 2
IRrecv receptor (ir);
decode_results IRcode;

void setup() {
  receptor.enableIRIn();
  Serial.begin(9600);
}

//the loop routine runs over and over again forever:

void loop () {
  if (receptor.decode(&IRcode)) {
    Serial.print(IRcode.value, HEX); Serial.print("\n");
    delay(200);
    receptor.resume();

  }
}
