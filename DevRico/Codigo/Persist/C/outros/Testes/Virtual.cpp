/*

TESTE DE VIRTUAL

*/


#include <iostream.h>
#include <iomanip.h>


class base
{
public:
   base() {};
   virtual char* getClassName() {return "base";};
   char* addteste( ) { return getClassName(); };
};

class subClasse :public base
{
public:
   subClasse() {};
   ~subClasse() {};
   char* getClassName() {return "subClasse";};
};

char* retorna( base* pBase )
{
   return pBase->addteste();
}

void main()
{
/*
subClasse oObj;
cout << oObj.addteste() << endl;
subClasse* pObj = new subClasse;
cout << pObj->addteste() << endl;
base* pBase = pObj;
cout << pBase->addteste() << endl;
delete pObj;
*/
subClasse oObj;
subClasse* pObj = new subClasse;
cout << retorna(&oObj) << endl;
cout << retorna(pObj) << endl;

delete pObj;
return;
}
