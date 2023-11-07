#include "shiftregister.h"
#include "binaryarray.h"
#include <Arduino.h>

ShiftRegister::ShiftRegister(int dataPin, int shiftPin, int storagePin)
{
  m_dataPin = dataPin;
  m_shiftPin = shiftPin;
  m_storagePin = storagePin;
}

void ShiftRegister::set(BinaryArray state)
{
  for (int i = state.getSize() - 1; i >= 0; i--)
  {
    digitalWrite(m_dataPin, state.isTrue(i) ? HIGH : LOW);

    digitalWrite(m_shiftPin, HIGH);
    digitalWrite(m_shiftPin, LOW);
  }

  digitalWrite(m_storagePin, HIGH);
  digitalWrite(m_storagePin, LOW);
};
