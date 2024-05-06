#include "Display.h"
#include "Input.h"
#include "Pulses.h"

const int REFRESH_DELAY = 5;

int valueToDisplay = 0;

Display hexDisplay;
Input input;
Pulses pulses;

const int PULSE_PIN = PIN_PB0;
volatile bool pulseState = LOW;

void setup() 
{
  hexDisplay.setupPins();
  input.setupPins();
  pulses.setup();
}

ISR(TIMER1_COMPA_vect)
{
  pulses.handleInterrupt();
}

void loop() 
{
  valueToDisplay = input.readInput();
  hexDisplay.displayNumber(valueToDisplay);

  delay(REFRESH_DELAY);
}