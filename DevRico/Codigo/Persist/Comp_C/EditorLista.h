//---------------------------------------------------------------------------
#ifndef EditorListaH
#define EditorListaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <dsgnintf.hpp>

class PACKAGE IBEditorLista : public TComponentEditor
{
public:
  virtual void __fastcall Edit();
	virtual void __fastcall ExecuteVerb(int Index);
	virtual AnsiString __fastcall GetVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
	__fastcall virtual IBEditorLista(TComponent* AComponent, IFormDesigner* ADesigner);
	__fastcall virtual ~IBEditorLista(void);
private:
  void __fastcall Editar();
  void __fastcall Creditos();
};


//---------------------------------------------------------------------------
/*
class PACKAGE TFormCreditos : public TForm
{
__published:	// IDE-managed Components
  TLabel *Label1;
  TLabel *Label2;
private:	// User declarations
public:		// User declarations
  __fastcall TFormCreditos(TComponent* Owner);
};
*/
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#endif

