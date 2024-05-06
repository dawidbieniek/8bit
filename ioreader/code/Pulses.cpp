#include "Pulses.h"

#include "Arduino.h"

void Pulses::setup()
{
  setupPins();
  pulseState = LOW;

  noInterrupts();
  setupTimer();
  interrupts();
}

void Pulses::setupPins()
{
  pinMode(PULSE_PIN, OUTPUT);
  digitalWrite(PULSE_PIN, LOW);
}

void Pulses::setupTimer()
{
  // TCCR1A should be all 0s
  TCCR1A = 0b00000000;
  // Set Clear on Compare Match (clear timer counter when timer matches with comparator)
  // Set clock prescaler to 1024
  TCCR1B = 0b00001101;
  // Mask all timer interrups but TIMER1_COMPA interrupt
  TIMSK = 1 << OCIE1A;
  
  // Set comparator value to length of low pulse
  OCR1A = LOW_STATE_SECONDS * TICKS_PER_SECOND;
}

void Pulses::handleInterrupt()
{
  noInterrupts();

  if(pulseState == HIGH)  // Need to set to low state
  {
    pulseState = LOW;
    OCR1A = LOW_STATE_SECONDS * TICKS_PER_SECOND;
  }
  else  // Need to set to high state
  {
    pulseState = HIGH;
    OCR1A = HIGH_STATE_SECONDS * TICKS_PER_SECOND;
  }

  digitalWrite(PULSE_PIN, pulseState);
  
  interrupts();
}