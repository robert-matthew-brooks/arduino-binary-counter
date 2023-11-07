#ifndef SHIFTREGISTER_H
#define SHIFTREGISTER_H

#include "binaryarray.h"

class ShiftRegister
{
public:
  ShiftRegister(int dataPin, int shiftPin, int storagePin);
  void set(BinaryArray state);

private:
  int m_dataPin;
  int m_shiftPin;
  int m_storagePin;
};

#endif