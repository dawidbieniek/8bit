#include "Input.h"

#include "wiring_extras.h"

static uint8_t Input::rotateBits(uint8_t byte)
{
  uint8_t result = 0;
  for (uint8_t i = 0; i < 8; i++) 
  {
    result = (result << 1) | (byte & 1);
    byte >>= 1;
  }
  return result;
}

void Input::setupPins()
{
  portMode(INPUT_A, INPUT);
  portMode(INPUT_B, INPUT);
}

uint8_t Input::readInputA()
{
  return rotateBits(portRead(INPUT_A));
}

uint8_t Input::readInputB()
{
  return portRead(INPUT_B);
}

uint16_t Input::readInput()
{
  return (static_cast<uint16_t>(readInputA()) << 8) | readInputB();
}