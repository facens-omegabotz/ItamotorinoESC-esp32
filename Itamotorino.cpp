/*
  Itamotorino.h - A new esc Version
*/


#include "Arduino.h"
#include "Itamotorino.h"
#include <ESP32Servo.h>
Servo motorA;
Servo motorB;

Itamotorino::Itamotorino(int pinM1a, int pinM1b,
                         int valueMin, int valueMax,
                         int frequency, int initialValue)
{
  _pinM1a = pinM1a;
  _pinM1b = pinM1b;
  _valueMin = valueMin;
  _valueMax = valueMax;
  _frequency = frequency;
  _initialValue = initialValue;

  if (!motorA.attached() || !motorB.attached())
  {
    motorA.setPeriodHertz(frequency);          // standard 50 hz servo
    motorA.attach(pinM1a, valueMin, valueMax); // Attach the servo after it has been detatched
    motorB.setPeriodHertz(frequency);          // standard 50 hz servo
    motorB.attach(pinM1b, valueMin, valueMax); // Attach the servo after it has been detatched
  }
  motorA.write(initialValue);
  motorB.write(initialValue);
}

void Itamotorino::setSpeeds(int motorValueInsecondsA, int motorValueInsecondsB)
{
  motorA.write(motorValueInsecondsA);
  motorB.write(motorValueInsecondsB);
}
