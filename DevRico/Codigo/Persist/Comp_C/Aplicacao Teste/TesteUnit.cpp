//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TesteUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IComponent"
#pragma link "IBBroker"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AtivarClick(TObject *Sender)
{
try
   {
    IBDataStoreODBC1->Ativo = true;
    IBColecao1->Ativo=true;
   }
catch(IErro& erro) { IBUtilitaria::mensagemUsuario( erro.textError() ); }
catch(...) { IBUtilitaria::mensagemUsuario( "Algum outro erro ..." );}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
try
   {
    IBColecao1->Ativo=false;
    IBDataStoreODBC1->Ativo = false;
   }
catch(IErro& erro) { IBUtilitaria::mensagemUsuario( erro.textError() ); }
catch(...) { IBUtilitaria::mensagemUsuario( "Algum outro erro ..." );}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonIconesClick(TObject *Sender)
{
  IBLista1->ViewStyle = vsIcon;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonReportClick(TObject *Sender)
{
  IBLista1->ViewStyle = vsReport;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonListaClick(TObject *Sender)
{
  IBLista1->ViewStyle = vsList;
}
//---------------------------------------------------------------------------

                     