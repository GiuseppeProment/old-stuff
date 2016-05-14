#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <iomanip.h>

class Teste
{
  public:
  Teste() {};
  ~Teste() {};
  int* pointer;
};


void main()
{
  // criar objeto
  Teste* p = new Teste();
  p->pointer = new int(23);
  cout << * (p->pointer) << endl;

  // atencao para criacao de copia implicita
  Teste obj;
  obj = *p;

  cout << * obj.pointer << endl;

  delete p->pointer;
  delete p;
}
