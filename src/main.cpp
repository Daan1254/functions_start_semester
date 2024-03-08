#include <Arduino.h>

const int PIN_LED_RED = 4;    // The Number of the red LED pin.
const int PIN_LED_GREEN = 5;  // The Number of the green LED pin.
const int PIN_LED_BLUE = 6;   // The Number of the blue LED pin.
const int PIN_LED_YELLOW = 7; // The Number of the yellow LED pin.
const int PIN_BUTTON_1 = 8;   // The number of the button 1 (KEY1) pin.
const int PIN_BUTTON_2 = 9;   // The number of the button 2 (KEY2) pin.

byte prevButtonState = HIGH;

void blinkLed(int LED_PIN, int x) {
  for (int i = 0; i < x; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(250);
    digitalWrite(LED_PIN, LOW);
    delay(250);
  }
}


void readButton(int BUTTON_PIN, int LED_PIN, int x) {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == prevButtonState) return;

  prevButtonState = buttonState;

  if (buttonState == LOW) {
    blinkLed(LED_PIN, x);
  }
}

void setup() {
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_BUTTON_1, INPUT_PULLUP);
  pinMode(PIN_BUTTON_2, INPUT_PULLUP);
}

void loop() {
  readButton(PIN_BUTTON_1, PIN_LED_YELLOW, 5);
  readButton(PIN_BUTTON_2, PIN_LED_GREEN, 3);
}

