#include <Arduino.h>

// Define pin numbers
const int ButtonPin = 19;  // GPIO19 connected to the pushbutton
const int LedPin = 18;     // GPIO18 connected to the LED
const int RelayPin = 23;   // GPIO23 connected to the relay module

void setup() {
  // Set pin modes
  pinMode(ButtonPin, INPUT_PULLUP);  // Set the button pin as an input with an internal pull-up resistor
  pinMode(LedPin, OUTPUT);           // Set the LED pin as an output
  pinMode(RelayPin, OUTPUT);         // Set the relay pin as an output

  // Initialize the outputs to be OFF
  digitalWrite(LedPin, LOW);
  digitalWrite(RelayPin, LOW);
}

void loop() {
  // Read the state of the button
  int buttonState = digitalRead(ButtonPin);

  // Check if the button is pressed
  // Since the button is wired to pull the pin LOW when pressed, we check for LOW
  if (buttonState == LOW) {
    digitalWrite(LedPin, HIGH);     // Turn on the LED
    digitalWrite(RelayPin, HIGH);   // Turn on the relay
  } else {
    digitalWrite(LedPin, LOW);      // Turn off the LED
    digitalWrite(RelayPin, LOW);    // Turn off the relay
  }
}


