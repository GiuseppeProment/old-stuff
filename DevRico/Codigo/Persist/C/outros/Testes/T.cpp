#include <iostream.h>
#include <iomanip.h>

void recebeReferencia( int& ref )
{
  cout << ref << endl;
}

void main()
{
  int *p;
  p=new int(32);
  cout << p << endl;
  recebeReferencia( *p );
}
