#pragma once

#include "Arduino.h"

class Input
{
private:
  // 0 - PORT A
  // 1 - PORT B
  // 2 - PORT C
  // 3 - PORT D

  static const uint8_t INPUT_A = 0;
  static const uint8_t INPUT_B = 2;

public:
  void setupPins();
  uint16_t readInput();

private:
  static uint8_t rotateBits(uint8_t byte);
  uint8_t readInputA();
  uint8_t readInputB();
};