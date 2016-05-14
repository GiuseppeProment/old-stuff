#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <iomanip.h>

class base
{
  public:
  base() {};
  ~base() {};
  virtual char* getClassName() {return "base";};
};

template <class T>
class subTemplate :public base
{
  public:
  subTemplate() {};
  ~subTemplate() {};
  char* getClassName() {return "subTemplate";};
  T membro;
};



void main()
{
  base* matrizBase[3];

  subTemplate< subTemplate<int> > objeto1;
  subTemplate<char> objeto2;

  matrizBase[0] = &objeto1;
  matrizBase[1] = &objeto2;

  cout << matrizBase[0]->getClassName() << endl;
  cout << matrizBase[1]->getClassName() << endl;
}
