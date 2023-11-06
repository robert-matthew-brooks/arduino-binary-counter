const int totalPins = 4;
const int ledPins[totalPins] = {5, 4, 3, 2};

int counter = 0;

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
  Serial.begin(115200);
}

void loop()
{
  while (counter <= 15)
  {
    counter++;
    BinaryArray ledsState = getBinaryArrayFromInt(counter);
    lightLeds(ledsState);
    delay(500);
  }
}