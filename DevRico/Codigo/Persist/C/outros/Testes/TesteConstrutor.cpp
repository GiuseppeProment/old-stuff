/*

TESTE DE CONSTRUTOR NAO DEFAULT

*/


#include <iostream.h>
#include <iomanip.h>

class basica
{
public:
  basica( char* ) { cout << "basica::basica(null)" << endl; };
  basica() { cout << "basica::basica" << endl; };
  virtual ~basica() { cout << "basica::~basica" << endl;};
};

class subClasse :public basica
{
public:
  subClasse( char* ) {cout << "subClasse::subClasse(null)" << endl; };
  subClasse() {cout << "subClasse::subClasse" << endl; };
  ~subClasse() {cout << "subClasse::~subClasse" << endl; };
};

class usuaria
{
public:
   usuaria(basica& theBasica) {};
   ~usuaria() {};
};

void main()
{
  //subClasse sub;
  // usuaria obj(sub);
  subClasse *p;
  p = new subClasse( "TESTE" );
  delete p;
  return;
}
