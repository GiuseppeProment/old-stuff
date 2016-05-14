//---------------------------------------------------------------------------
#ifndef TesteUnitH
#define TesteUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "IBColecao.h"
#include "IBDataStoreODBC.h"
#include "IBLista.h"
#include "IComponent.h"
#include <ComCtrls.hpp>
#include "IBObjeto.h"
#include "IBBroker.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
  TButton *Ativar;
        TButton *Button1;
   IBBroker *IBBroker1;
   IBDataStoreODBC *IBDataStoreODBC1;
   IBColecao *IBColecao1;
   TButton *ButtonIcones;
   TButton *ButtonReport;
   TButton *ButtonLista;
   IBLista *IBLista1;
  void __fastcall AtivarClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
   void __fastcall ButtonIconesClick(TObject *Sender);
   void __fastcall ButtonReportClick(TObject *Sender);
   void __fastcall ButtonListaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
       