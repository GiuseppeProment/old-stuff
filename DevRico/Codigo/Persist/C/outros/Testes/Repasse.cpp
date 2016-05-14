#include <iostream.h>
#include <iomanip.h>

void func2( int& numero )
{
  cout << "func2 = "<< numero << endl;
}
void func1( int& numero )
{
  cout <<"func1 = "<< numero << endl;
  func2( numero );
}

void main()
{
  int numero120 = 120;
  func1( numero120 );
}
