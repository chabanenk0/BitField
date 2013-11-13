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
  friend BitField operator!(BitField & a); //not
  friend BitField operator^(BitField & a, BitField & b); //xor
  void show();
  friend ostream& operator<<(ostream& os, BitField & a); //print to stream
  friend istream& operator>>(istream& os, BitField & a); //read from string

  int setBit(int BitNumber, int bit);
  char getBit (int bitNumber);
};

// test the dev branch

long BitField::getData()
        {
             return data;
        }
        void BitField::setData(long newData)
        {
          data=newData;
        }

char BitField::getBit (int bitNumber)
{
  long z = data>>bitNumber;
  return z&1;
}

BitField::BitField(long newData)

{ data=newData;
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
void BitField::show()
{
for(int i=0; i<32; i++)
{
cout<<(int) getBit(i);
}
}

BitField operator!(BitField &a)
{BitField b;
//b.data=~a.data;
long x=a.getData();
b.setData(~x);
return b;
}


int main(int argc, char *argv[])
{
  BitField b1;
  BitField b2(255);
  BitField b3=b2;
  b2.show(); 
  system("PAUSE");
  return EXIT_SUCCESS;
}
