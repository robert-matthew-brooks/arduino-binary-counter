#ifndef BUTTON_H
#define BUTTON_H

class Button
{
public:
  Button(int pin);
  bool isPressed();

private:
  int m_pin;
  bool m_previousState;
  bool m_currentState;
};

#endif