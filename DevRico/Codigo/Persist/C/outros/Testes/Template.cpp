#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <iomanip.h>

class IColecaoBase
{
  public:
  IColecaoBase() {};
  ~IColecaoBase() {};
  virtual char* getClassName() {return "IColecaoBase";};
};

typedef enum {Um,Muitos} assocCardinalidade;
typedef enum {Forte,Fraca} assocDependencia;

template <class Objeto,>
class IAssociacao :public IColecaoBase
{
  public:
  IAssociacao() {};
  ~IAssociacao() {};
  char* getClassName() {return "IAssociacao";};
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
