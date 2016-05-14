#include "CoisaImp.hpp"
#include <iostream.h>
#include <iomanip.h>
#include <windows.h>

void main()
{
  typedef void (*Constroe) (void*);
  typedef void (*VoidRetVoid) (const void*);
  Constroe pf;
  HINSTANCE handle;
  cout << "Inicio..." << endl;
  cout << ((handle = LoadLibrary("Coisa.dll"))==NULL?"load falhou.":"load OK") << endl;

  // construir
  pf = (Constroe) GetProcAddress(handle,(char*) 0x1);
  cout << ( pf==NULL?"pf -> nulo":"pf -> valido" ) << endl;
  void* p;
  p = new void* [sizeof(Coisa)];
  pf(p);

  // chama metodo
  VoidRetVoid pm;
  pm = (VoidRetVoid) GetProcAddress(handle,(char*) 0x3);
  cout << ( pm==NULL?"pm -> nulo":"pm -> valido" ) << endl;
  pm(p);

  // destruir
  pf = (Constroe) GetProcAddress(handle,(char*) 0x2);
  cout << ( pf==NULL?"pf -> nulo":"pf -> valido" ) << endl;
  pf(p);
  delete [] p;

  cout << (FreeLibrary(handle)==1?"Free OK":"Free Falhou") << endl;
}
