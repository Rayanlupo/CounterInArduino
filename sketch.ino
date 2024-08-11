#include <TM1637.h>
#include <Wire.h>

int buttonPin = 26;
int lastState = LOW;
int counter = 0;
int ledPin = 22;
int buzzerPin = 19;
void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  display.init();
  display.set(7);
}

void loop() {
  
  int buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && lastState == LOW){
  counter += 1;
  Serial.print(counter);
  delay(50);
 
  }
   if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);     
    tone(buzzerPin, 262);         
  } else {
    digitalWrite(ledPin, LOW);      
    noTone(buzzerPin);             
  }
 lastState = buttonState;
 if (counter < 10){
  display(0, counter);
 }
 else if ( 10 =< counter <100){
  display(2, counter / 10);
  display(3, counter % 10);
 }
 }
