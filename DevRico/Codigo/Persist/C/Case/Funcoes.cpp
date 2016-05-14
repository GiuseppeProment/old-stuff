#include <math.h> 

#pragma package(smart_init)

char* DecToBin(unsigned int nNumber, char*buffer,int len)
{
	len--;
  int count = 0;
  int power;
  while ( count <= len )
#pragma warning (disable : 4244 )
  { power = pow(2,count);
    buffer[len-count]=((nNumber&power)==0?'0':'1');
    count++;
  }
  return buffer;
}

char BinToByte(const char * cNumber,int len)
{
	len--;
  int count = 0;
  char ret=0;
  while ( count <= len )
#pragma warning (disable : 4244 )
  { if (cNumber[len-count]=='1')
      ret+=pow(2,count);
    count++;
  }
  return ret;
}