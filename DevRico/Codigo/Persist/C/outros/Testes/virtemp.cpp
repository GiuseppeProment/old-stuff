/*

TESTE DE VIRTUAL

*/


#include <iostream.h>
#include <iomanip.h>

class base;

char* retorna(base&);

class base
{
public:
   base( base& pEu ) { retorna( pEu ); };
   virtual char* getClassName() = 0;
   char* addteste( ) { return getClassName(); };
};

template <class T>
class subClasse :public base
{
public:
   subClasse():base(*this) {};
   ~subClasse() {};
   char* getClassName();
};



template <class T>
char* subClasse<T>::getClassName()
{ return "subClasse"; }


char* retorna( base& pBase )
{
   //return pBase->addteste();
  return pBase.getClassName();
}

void main()
{
subClasse<int> oObj;
//subClasse<int> *pObj = new subClasse<int>;
cout << retorna(oObj) << endl;
//cout << retorna(pObj) << endl;

//delete pObj;
return;
}
