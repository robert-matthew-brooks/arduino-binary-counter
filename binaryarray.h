#ifndef BINARYARRAY_H
#define BINARYARRAY_H

class BinaryArray
{
public:
  BinaryArray(const int size);
  void setFromInt(const int number);
  void setFromArray(const int array[]);
  int isTrue(const int which);
  int getSize();

private:
  int m_size;
  bool m_values[8];
  void clear();
};

#endif