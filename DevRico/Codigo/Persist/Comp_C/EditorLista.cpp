//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "EditorLista.h"
#include "TelaEditorLista.h"
#include "TelaCreditos.h"
//---------------------------------------------------------------------------
//#pragma resource "*.dfm"
//#pragma resource "*.res"
#pragma package(smart_init)

// IBEditorLista
// * Editar o componente IBLista

__fastcall IBEditorLista::IBEditorLista(TComponent* AComponent, IFormDesigner* ADesigner)
                      : TComponentEditor(AComponent, ADesigner) { }

__fastcall IBEditorLista::~IBEditorLista(void) { }


int __fastcall IBEditorLista::GetVerbCount()
{
  return 2;
}

String __fastcall IBEditorLista::GetVerb(Integer Index)
{
  if (Index == 0)
    return  "Editar";
  if (Index == 1)
    return  "Créditos";
  else return "";
}

void __fastcall IBEditorLista::ExecuteVerb(Integer Index)
{
  if (Index == 0) Editar();
  if (Index == 1) Creditos();
}

void __fastcall IBEditorLista::Edit()
{
  // chamado quando o programador clica duas vezes o componente
  Editar();
}

void __fastcall IBEditorLista::Editar()
{

  TFormEditorLista * Tela;
  Tela = new TFormEditorLista(Application, Component);
  Tela->ShowModal();
  delete Tela;
}

void __fastcall IBEditorLista::Creditos()
{
  TFormCreditos * Tela;
  Tela = new TFormCreditos(Application);
  Tela->ShowModal();
  delete Tela;
}


// Tela de Creditos

//---------------------------------------------------------------------------
/*
__fastcall TFormCreditos::TFormCreditos(TComponent* Owner)
  : TForm(Owner)
{
}
*/
//---------------------------------------------------------------------------

