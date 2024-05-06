#include "Display.h"

#include "Arduino.h"

static uint8_t Display::digitMap[16] = 
{
  0B00000001,	// 0
  0B01001111,	// 1
  0B00010010,	// 2
  0B00000110,	// 3
  0B01001100,	// 4
  0B00100100,	// 5
  0B00100000,	// 6
  0B00001111,	// 7
  0B00000000,	// 8
  0B00000100,	// 9
  0B00001000,	// A
  0B01100000,	// b
  0B00110001,	// C
  0B01000010,	// d
  0B00110000,	// E
  0B00111000	// F
};

void Display::setupPins()
{
  pinMode(HEX_D1, OUTPUT);
  pinMode(HEX_D2, OUTPUT);
  pinMode(HEX_D3, OUTPUT);
  pinMode(HEX_D4, OUTPUT);
  pinMode(HEX_A, OUTPUT);
  pinMode(HEX_B, OUTPUT);
  pinMode(HEX_C, OUTPUT);
  pinMode(HEX_D, OUTPUT);
  pinMode(HEX_E, OUTPUT);
  pinMode(HEX_F, OUTPUT);
  pinMode(HEX_G, OUTPUT);
  pinMode(HEX_DP, OUTPUT);

  digitalWrite(HEX_D1, LOW);
  digitalWrite(HEX_D2, LOW);
  digitalWrite(HEX_D3, LOW);
  digitalWrite(HEX_D4, LOW);

  digitalWrite(HEX_DP, HIGH); // Turn off DP
}

void Display::displayNumber(uint16_t value)
{
  uint8_t first = (value & 0xF000) >> 12;
  uint8_t second = (value & 0x0F00) >> 8;
  uint8_t third = (value & 0x00F0) >> 4;
  uint8_t fourth = value & 0x000F;

  displayDigit(first, Display::Digit::D1);
  displayDigit(second, Display::Digit::D2);
  displayDigit(third, Display::Digit::D3);
  displayDigit(fourth, Display::Digit::D4);
}

void Display::displayDigit(uint8_t value, Display::Digit digit)
{
  Display::writeDigit(value);
  digitalWrite(static_cast<uint8_t>(digit), HIGH);
  delay(DIGIT_SHINE_TIME);
  digitalWrite(static_cast<uint8_t>(digit), LOW);
}

void Display::writeDigit(uint8_t value)
{
  uint8_t map = Display::digitMap[value];

  digitalWrite(HEX_A, bitRead(map, 6));
  digitalWrite(HEX_B, bitRead(map, 5));
  digitalWrite(HEX_C, bitRead(map, 4));
  digitalWrite(HEX_D, bitRead(map, 3));
  digitalWrite(HEX_E, bitRead(map, 2));
  digitalWrite(HEX_F, bitRead(map, 1));
  digitalWrite(HEX_G, bitRead(map, 0));
}