#include <Arduino.h>

const int PIN_LED_RED = 4;    // The Number of the red LED pin.
const int PIN_LED_GREEN = 5;  // The Number of the green LED pin.
const int PIN_LED_BLUE = 6;   // The Number of the blue LED pin.
const int PIN_LED_YELLOW = 7; // The Number of the yellow LED pin.
const int PIN_BUTTON_1 = 8;   // The number of the button 1 (KEY1) pin.
const int PIN_BUTTON_2 = 9;   // The number of the button 2 (KEY2) pin.

void blinkLed(int LED_PIN, int x) {
  for (int i = 0; i < x; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(250);
    digitalWrite(LED_PIN, LOW);
    delay(250);
  }
}

void setup() {
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(PIN_BUTTON_1, INPUT_PULLUP);
  pinMode(PIN_BUTTON_2, INPUT_PULLUP);
}

void loop() {
  int buttonOneState = digitalRead(PIN_BUTTON_1);
  int buttonTwoState = digitalRead(PIN_BUTTON_2);

  if (buttonOneState == LOW) {
    blinkLed(PIN_LED_YELLOW, 3);
  }

  if (buttonTwoState == LOW) {
    blinkLed(PIN_LED_YELLOW, 5);
  }
}

