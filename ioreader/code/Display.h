#pragma once

#include "Arduino.h"

class Display 
{
private:
  static const uint8_t HEX_D1 = PIN_PD1;
  static const uint8_t HEX_D2 = PIN_PD4;
  static const uint8_t HEX_D3 = PIN_PD5;
  static const uint8_t HEX_D4 = PIN_PB7;
  static const uint8_t HEX_A = PIN_PD2;
  static const uint8_t HEX_B = PIN_PD6;
  static const uint8_t HEX_C = PIN_PB5;
  static const uint8_t HEX_D = PIN_PB3;
  static const uint8_t HEX_E = PIN_PB2;
  static const uint8_t HEX_F = PIN_PD3;
  static const uint8_t HEX_G = PIN_PB6;
  static const uint8_t HEX_DP = PIN_PB4;

  static const int DIGIT_SHINE_TIME = 3;

  static uint8_t digitMap[16];

public:
  enum class Digit : uint8_t {
    D1 = HEX_D1,
    D2 = HEX_D2,
    D3 = HEX_D3,
    D4 = HEX_D4
  };

  void setupPins();
  void displayNumber(uint16_t value);

private:
  void displayDigit(uint8_t value, Display::Digit digit);
  void writeDigit(uint8_t value);
};
