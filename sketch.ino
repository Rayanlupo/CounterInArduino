#include <TM1637.h>
#include <Wire.h>
TM1637 display(12, 13);
int buttonPin = 26;
int lastState = LOW;
int counter = 0;
int ledPin = 22;
int buzzerPin = 19;
int buttonState = LOW;
unsigned long lastPressTime = 0; 
void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  
    lastState = digitalRead(buttonPin);
}

void loop() {
  
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && lastState == LOW){
  display.init();
  display.set(7);
  counter += 1;
  Serial.print(counter);
  delay(50);
    digitalWrite(ledPin, HIGH);     
    tone(buzzerPin, 262);         
    delay(100);
    digitalWrite(ledPin, LOW);      
    noTone(buzzerPin);             
  }
 lastState = buttonState;
 if (counter < 10){
  display.display(3, counter);
 }
 else if ( 10 <=  counter < 100){
  display.display(2, counter / 10);
  display.display(3, counter % 10);
 }
 else if (100 <= counter < 1000){
  display.display(1, counter / 100);
  display.display(2, (counter / 10) % 10);
  display.display(3, counter % 10);
 }
 if (millis()-lastPressTime > 60000){
  clearDisplay();
  digitalWrite(ledPin, LOW);  // Turn off LED
  noTone(buzzerPin);      
 }
 }
 void clearDisplay() {
  int8_t clearData[4] = { 0x7F, 0x7F, 0x7F, 0x7F }; 
  display.display(clearData);
}
