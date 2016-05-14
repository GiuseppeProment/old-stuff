//---------------------------------------------------------------------------
#ifndef TelaCreditosH
#define TelaCreditosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormCreditos : public TForm
{
__published:	// IDE-managed Components
  TPanel *Panel1;
  TImage *ProgramIcon;
  TLabel *ProductName;
  TLabel *Version;
  TLabel *Copyright;
  TLabel *Comments;
  TLabel *Label1;
  TLabel *Label2;
  TLabel *Label3;
  TLabel *Label4;
  TLabel *Label5;
  TLabel *Label6;
  TLabel *Label7;
  TLabel *Label8;
  TLabel *Label9;
  TLabel *Label10;
  TLabel *Label11;
private:	// User declarations
public:		// User declarations
  __fastcall TFormCreditos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormCreditos *FormCreditos;
//---------------------------------------------------------------------------
#endif
