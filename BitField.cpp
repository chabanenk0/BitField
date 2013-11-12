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

  int setBit(int BitNumber, int bit);
  char getBit (int bitNumber);
};

// test the dev branch

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


int main(int argc, char *argv[])
{
  BitField b1;
  BitField b2(255);
  BitField b3=b2;
  b2.show(); 
  { extern void _bits(unsigned sp);//бітове представлення беззнакового цілого числа 0 <= п <= 255.

     unsigned val;

     printf("Введіть ціле беззнакове число n ");
      scanf("%u",&val);

     if (val>=0) _bits(val); }

 void _bits(unsigned sp);

{const int max=7; 
int i;
int sp;
printf("\n Битове представлення для %u",sp);
 
     for (double i=max;i>=0; i--)

     printf("%d", sp>>i&l);

}
  system("PAUSE");
  return EXIT_SUCCESS;
}
