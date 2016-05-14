//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "IBLista.h"
#include "Editores.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
// ------
// não funciona separado do componente a editar
// funcionou junto do componente, pelo menos o registro.
namespace editores
{
  void __fastcall PACKAGE Register()
  {
    RegisterComponentEditor(__classid(IBLista),__classid(IBEditorDeLista));
  }
}
//---------
int __fastcall IBEditorDeLista::GetVerbCount(void)
{
  Application->MessageBox("GetVerbCount","chamado", MB_OK);
  return 2;
}

System::AnsiString __fastcall IBEditorDeLista::GetVerb(int Index)
{
  switch (Index)
  {
    case 0:return "&Comando A..." ;
    case 1:return "&Comando B..." ;
  }
  return "porra nenhuma";
}

void __fastcall IBEditorDeLista::ExecuteVerb(int Index)
{
  switch (Index)
  {
    case 0:
      Application->MessageBox("Comando","Comando A executado", MB_OK);
    break;
    case 1:
      Application->MessageBox("Comando","Comando B executado", MB_OK);
    break;
  }
}

