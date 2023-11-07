#include "binaryarray.h"
#include "shiftregister.h"
#include "button.h"
#include "sevenseg.h"

// LED constants
const int ledPins[4] = {5, 4, 3, 2};
const int upPin = 6;
const int downPin = 7;

// shift register constants
const int dataPin = 8;
const int shiftPin = 9;
const int storagePin = 10;

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
