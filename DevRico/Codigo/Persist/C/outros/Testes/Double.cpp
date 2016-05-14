#include <iomanip.h>
#include <iostream.h>
#include <stdlib.h>

void main()
{
  float valor = 1234.101;
  char buffer[30];
  _gcvt(valor,10,buffer);
  cout << buffer << endl;
}
