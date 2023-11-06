#include "button.h"
#include <Arduino.h>

Button::Button(int pin)
{
  m_pin = pin;
  m_previousState = false;
  m_currentState = false;
}

bool Button::isPressed()
{
  m_previousState = m_currentState;
  m_currentState = digitalRead(m_pin) == 1;

  return m_currentState && !m_previousState;
}