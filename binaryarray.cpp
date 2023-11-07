#include "binaryarray.h"
#include <math.h>

BinaryArray::BinaryArray(const int size)
{
  m_size = size;
  clear();
}

void BinaryArray::clear()
{
  for (int i = 0; i < m_size; i++)
  {
    m_values[i] = 0;
  }
}

void BinaryArray::setFromInt(const int number)
{
  clear();
  int remainingUnits = number;
  int power = m_size - 1;

  while (remainingUnits > 0)
  {
    if (remainingUnits >= pow(2, power))
    {
      remainingUnits -= pow(2, power);
      m_values[power] = 1;
    }
    power--;
  }
}

void BinaryArray::setFromArray(const int array[])
{
  for (int i = 0; i < m_size; i++)
  {
    m_values[i] = array[i];
  }
};

int BinaryArray::isTrue(const int which)
{
  return m_values[which];
}

int BinaryArray::getSize()
{
  return m_size;
}