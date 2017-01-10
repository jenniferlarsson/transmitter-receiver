#include <RCSwitch.h>

const int buttonPin2 = 11;
const int piezo = 5;
boolean active = false;

RCSwitch mySwitch = RCSwitch();

// variables will change:
int button2State = 0;

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin2, INPUT);
}

void loop() {
  // ta emot radio och starta eller stäng av ljud
  if (mySwitch.available()) {
    Serial.println("available");
    int value = mySwitch.getReceivedValue();
        
    if (value == 0) {
      // fel i sändning
    } else {
      Serial.println(value);
      if (value == 5393) {
        active = true;
      } else if (value == 5395) {
        active = false;
        noTone(piezo);
      }
    }
    mySwitch.resetAvailable();
  }
  
  button2State = digitalRead(buttonPin2);
  
  if (active) {
    tone(piezo, 33, 1000);
  }
  
  // stng av grej-knappen
  if(button2State == HIGH) {
    noTone(piezo);
    active = false;
  }
}
