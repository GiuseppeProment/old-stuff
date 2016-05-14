#include <iostream.h>
#include <iomanip.h>

void func()
{
  int a;
  throw 0;
}

void main()
{
  cout << "Entrou" << endl;
  try { func(); }
  catch(...) { cout << "excessao capturada" << endl; }
  cout << "Saiu" << endl;
}
