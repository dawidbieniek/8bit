#pragma once

#include "Arduino.h"

class Pulses
{
private:
  static const uint8_t PULSE_PIN = PIN_PB0;

  static const int TICKS_PER_SECOND = 1024;
  static const int LOW_STATE_SECONDS = 25;
  static const int HIGH_STATE_SECONDS = 1;

  volatile bool pulseState;

public:
  void setup();
  // Should be inside ISR(TIMER1_COMPA_vect)
  void handleInterrupt();

private:
  void setupPins();
  void setupTimer();
};