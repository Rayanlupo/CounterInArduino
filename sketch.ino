#include <TM1637.h>
#include <Wire.h>
int counter = 0;
int buttonPin = 26;
int buttonState;
void setup() {
  display.init();
  display.set(7);
  display.display();
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW)

  disp

}
