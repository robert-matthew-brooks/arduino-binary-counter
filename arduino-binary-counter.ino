int pattern = 0;
int patterns[5][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 1},
    {0, 0, 1, 1},
    {0, 1, 1, 1},
    {1, 1, 1, 1},
};
int totalPatterns = sizeof(patterns) / sizeof(patterns[0]);

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  digitalWrite(2, patterns[pattern][0] == 1 ? HIGH : LOW);
  digitalWrite(3, patterns[pattern][1] == 1 ? HIGH : LOW);
  digitalWrite(4, patterns[pattern][2] == 1 ? HIGH : LOW);
  digitalWrite(5, patterns[pattern][3] == 1 ? HIGH : LOW);
  pattern++;

  if (pattern == totalPatterns)
  {
    pattern = 0;
  }

  delay(1000);
}