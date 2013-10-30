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
  char getBit (int bitNumber);
}

// test the dev branch

char BitField::getBit (int bitNumber)
{
  long z = data>>bitNumber;
  return z&1;
}  

BitField::BitField(long newData)

{  data=newData;
}

BitField::BitField(const BitField &x)
{
  data=x.data;

}

BitField::BitField()
{
  data=0;
}

BitField::~BitField()
{

}

int main(int argc, char *argv[])
{
  BitField b1;
  BitField b2(256);
  BitField b3=b2;
  system("PAUSE");
  return EXIT_SUCCESS;
}
