#include <Arduino.h>
#include <AFMotor.h>

AF_DCMotor motor1(4);
AF_DCMotor motor2(1);
AF_DCMotor motor3(3);

byte buttonState1;
byte buttonState2;
byte buttonState3;
byte lastButtonState1;
byte lastButtonState2;
byte lastButtonState3;
byte motorState1;
byte motorState2;
byte motorState3;

unsigned long debounceDuration = 50; // millis
unsigned long lastTimeButtonState1Changed = 0;
unsigned long lastTimeButtonState2Changed = 0;
unsigned long lastTimeButtonState3Changed = 0;

void setup() 
{
  motor1.run(FORWARD);
  motor1.setSpeed(0);
  motor2.run(FORWARD);
  motor2.setSpeed(0);
  motor3.run(FORWARD);
  motor3.setSpeed(0);
  pinMode(A1,INPUT);
  pinMode(A3,INPUT);
  pinMode(A5,INPUT);
}

void loop() 
{
  if (millis() - lastTimeButtonState1Changed > debounceDuration) {
    if (analogRead(A1) <= 20) {
      buttonState1 = LOW;
    } else {
     buttonState1 = HIGH;
    }
    if (buttonState1 != lastButtonState1) {
      lastTimeButtonState1Changed = millis();
      lastButtonState1 = buttonState1;
      if (buttonState1 == HIGH) {
        motorState1 = (motorState1 == HIGH) ? LOW: HIGH;
      }
      if (motorState1 == HIGH) {
        motor1.setSpeed(255);
      } else {
        motor1.setSpeed(0);
      }
    }
  }

  if (millis() - lastTimeButtonState2Changed > debounceDuration) {
    if (analogRead(A3) <= 20) {
      buttonState2 = LOW;
    } else {
     buttonState2 = HIGH;
    }
    if (buttonState2 != lastButtonState2) {
      lastTimeButtonState2Changed = millis();
      lastButtonState2 = buttonState2;
      if (buttonState2 == HIGH) {
        motorState2 = (motorState2 == HIGH) ? LOW: HIGH;
      }
      if (motorState2 == HIGH) {
        motor2.setSpeed(255);
      } else {
        motor2.setSpeed(0);
      }
    }
  }

  if (millis() - lastTimeButtonState3Changed > debounceDuration) {
    if (analogRead(A5) <= 20) {
      buttonState3 = LOW;
    } else {
     buttonState3 = HIGH;
    }
    if (buttonState3 != lastButtonState3) {
      lastTimeButtonState3Changed = millis();
      lastButtonState3 = buttonState3;
      if (buttonState3 == HIGH) {
        motorState3 = (motorState3 == HIGH) ? LOW: HIGH;
      }
      if (motorState3 == HIGH) {
        motor3.setSpeed(255);
      } else {
        motor3.setSpeed(0);
      }
    }
  }
}