#include "binaryarray.h"
#include "shiftregister.h"
#include "button.h"
#include "sevenseg.h"

// LED constants
const int ledPins[4] = {8, 9, 11, 12};
const int upPin = 4;
const int downPin = 3;

// shift register constants
const int dataPin = 2;
const int shiftPin = 6;
const int storagePin = 5;

// program constants
const int minValue = 0;
const int maxValue = 15;
const int tick = 50;

// program vars
int counter = 1;

ShiftRegister shiftRegister(dataPin, shiftPin, storagePin);
BinaryArray ledsState(sizeof(ledPins));
BinaryArray sevenSegState(7);
Button up(upPin);
Button down(downPin);

void lightLeds(BinaryArray ledsState)
{
  for (int i = 0; i < sizeof(ledPins); i++)
    digitalWrite(ledPins[i], ledsState.isTrue(i) ? HIGH : LOW);
};

void setup()
{
  pinMode(upPin, INPUT);
  pinMode(downPin, INPUT);

  for (int pin : ledPins)
  {
    pinMode(pin, OUTPUT);
  }

  pinMode(dataPin, OUTPUT);
  pinMode(storagePin, OUTPUT);
  pinMode(shiftPin, OUTPUT);
  digitalWrite(storagePin, LOW);

  Serial.begin(115200);
}

void loop()
{
  if (up.isPressed() && (counter < maxValue))
  {
    counter++;
  }
  else if (down.isPressed() && (counter > minValue))
  {
    counter--;
  };

  ledsState.setFromInt(counter);
  lightLeds(ledsState);

  sevenSegState.setFromArray(sevenSegArrays[counter]);
  shiftRegister.set(sevenSegState);

  delay(tick);
}
