#include <iomanip.h>
#include <iostream.h>
#include <string.h>

char* retLiteral()
{
  return "00000000";
}

void main()
{
  char* literal = "ABCDEFGH";
  literal[1] = '1';
  cout << "literal=" << literal << endl;
  cout << "size   =" << sizeof(literal) << endl;
  char* lret = retLiteral();
  lret[1] ='X';
  cout << "lret   =" << lret    << endl;
}
