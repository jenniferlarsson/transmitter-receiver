#include <RCSwitch.h>

const int buttonPin = 2;     // the number of the pushbutton pin
boolean hasSentSignal = false;

RCSwitch mySwitch = RCSwitch();

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
  mySwitch.enableTransmit(10);  // Using Pin #10
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    if (!hasSentSignal) {
      mySwitch.send("000000000001010100010001");
      Serial.println("Sending Message");
      hasSentSignal = true;
    }
  } else {
    // Om man ska stänga av alla ljud genom att dra ner handtaget sänd detta 
    //mySwitch.send("000000000001010100010011");
    hasSentSignal = false;
  }
}
