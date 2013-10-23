#include <iostream>

using namespace std;

class BitField
{
  protected:
      long data;
  public:
  BitField();
  BitField(long newData);
  BitField(const BitField &x);
  ~BitField();
  long getData();
  void setData(long newData);
  friend BitField operator&(BitField & a, BitField & b); //and
  friend BitField operator|(BitField & a, BitField & b); //or
  BitField operator!(); //not
  friend BitField operator^(BitField & a, BitField & b); //xor
  void show();
  friend ostream& operator<<(ostream& os, BitField & a); //print to stream
  friend istream& operator>>(istream& os, BitField & a); //read from string 
  int getBit(int BitNumber);
  int setBit(int BitNumber, int bit);
}
