/*
  Itamotorino.h - A new esc Version
*/

#ifndef Itamotorino_h
#define Itamotorino_h

#include "Arduino.h"

class Itamotorino
{
public:
  Itamotorino(int pinM1a, int pinM1b,
              int valueMin, int valueMax,
              int frequency, int initialValue);
  void setSpeeds(int m1, int m2);

private:
  int _pinM1a, _pinM1b;
  int _valueMin, _valueMax;
  int _frequency;
  int _initialValue;

  int motorValueInsecondsA, motorValueInsecondsB;
};

#endif
