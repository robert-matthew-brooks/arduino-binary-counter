#include "button.h"

const int totalPins = 4;
const int ledPins[totalPins] = {5, 4, 3, 2};
const int upPin = 9;
const int downPin = 8;

const int minValue = 0;
const int maxValue = 15;

const int tick = 50;

int counter = 1;
Button up(upPin);
Button down(downPin);

struct BinaryArray
{
  int values[totalPins];
};

BinaryArray getBinaryArrayFromInt(int number)
{
  BinaryArray binaryArray = {0, 0, 0, 0};
  int remainingUnits = number;
  int power = totalPins - 1;

  while (remainingUnits > 0)
  {
    if (remainingUnits >= pow(2, power))
    {
      remainingUnits -= pow(2, power);
      binaryArray.values[power] = 1;
    }
    power--;
  }

  return binaryArray;
}

void lightLeds(BinaryArray ledsState)
{
  for (int i = 0; i < totalPins; i++)
    digitalWrite(ledPins[i], ledsState.values[i] ? HIGH : LOW);
};

void setup()
{
  for (int i = 0; i < totalPins; i++)
  {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(upPin, INPUT);
  pinMode(downPin, INPUT);

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

  BinaryArray ledsState = getBinaryArrayFromInt(counter);
  lightLeds(ledsState);

  delay(tick);
}