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
{
   data=newData;
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

BitField operator|(BitField &a, BitField &b)
{BitField c;
long x=a.getData();
long y=b.getData();
c.setData(x|y);
return c;}


BitField operator^(BitField &a,BitField &b)
{   BitField c;
	c.setData( a.getData()^b.getData());
	return c;
	//XoR
}

BitField operator!(BitField &a)
{BitField b;
//b.data=~a.data;
long x=a.getData();
b.setData(~x);
return b;
}

BitField operator&(BitField &a, BitField &b)
{BitField c;
 long x=a.getData();
 long y=b.getData();
 c.setData(x&y);
 return c;
}


int main(int argc, char *argv[])
{
  BitField b1;
  BitField b2(255);
  BitField b3(127);
  cout<<"b2:\t\t\t";
  b2.show(); 
    cout<<endl;
  cout<<"b3:\t\t\t";
  b3.show(); 
    cout<<endl;
  cout<<"b4=b2^b3:\t\t";
  BitField b4=b1^b2;
  b4.show();
  cout<<endl;
  cout<<"b4=b2&b3:\t\t";
  b4=b2&b3;
  b4.show();
    cout<<endl;
  cout<<"b4=b2|b3:\t\t";
  b4=b2|b3;
  b4.show();
    cout<<endl;
  cout<<"b4=!b2:\t\t\t";
  b4=!b2;
  b4.show();
  cout<<endl;

  system("PAUSE");
  return EXIT_SUCCESS;
}
