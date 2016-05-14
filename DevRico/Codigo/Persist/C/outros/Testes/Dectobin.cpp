#include <iostream.h>
#include <iomanip.h>
#include <IString.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#pragma comment(lib,"IPersiste.lib")
IString DecToBin( unsigned int , int );
char BinToDec(const char *);


void main()
{
	cout << DecToBin( 1999,11) << endl;
	cout << (int) BinToDec( "110010" ) << endl;
	cout << BinToDec( "110010" ) << endl;
}


IString DecToBin( unsigned int nNumber, int size = 8)
{
  IString cRetValue;
  bool lSign = (nNumber < 0);
  bool lOddNumber = (nNumber%2)!=0;
  unsigned int nStart = 1;
  nNumber = abs(nNumber);

  while( (nStart * 2) <= nNumber )
     nStart *= 2;

  while( nStart > 1 )
  {
      if( nNumber >= nStart )
      {
        cRetValue    += "1";
        nNumber -= nStart;
      }
      else
        cRetValue += "0";
      nStart /= 2;
  }
  IString cTmp(cRetValue);
  cRetValue = lSign?"-":"";
  cRetValue += cTmp;
  cRetValue += lOddNumber?"1":"0";

  int nPad = (size-cRetValue.len());
  int i;

  cTmp = "";
  for (i=1;i<=nPad;i++)
    cTmp += "0";

return cTmp+cRetValue;
}



char BinToDec(const char * cNumber)
{
	unsigned char nRetValue;
	unsigned char nPower;
	unsigned char nBase; 
#pragma warning (disable : 4244 )
	nPower = pow(2,(strlen(cNumber)-1));
	nBase = 0;
	cNumber;
	unsigned char conta =0;
	while ( nPower > 1 ) {
		nBase += ( cNumber[conta]=='0'?0:1 )*nPower;
		nPower /= 2;
	  conta++;
		}

  nRetValue = (nBase + ( (cNumber[conta]=='0'?0:1) * nPower ) ); 
return nRetValue; 
}

