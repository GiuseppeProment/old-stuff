unit IUtil;

interface

uses classes;
{
#include <string.h>
#include <IString.h>
#include <Lista.h>
#include <ListaPtr.h>
#include <IStdGnRc.h>
#include <Typevnto.h>
#include <IErro.h>
#include <offset.h>
char* DecToBin(unsigned int nNumber, char*buffer, int);
char BinToByte(const char * cNumber, int);
}


(* facilitadores para conversao C++ p/ Pascal *)

type
  bool = Boolean;
  int  = Integer;
  TypeEvento = String;
  IString = String;

(* Classe Lista *)
  Lista = class(TList);
  ListaPointer = Lista;

implementation

end.



