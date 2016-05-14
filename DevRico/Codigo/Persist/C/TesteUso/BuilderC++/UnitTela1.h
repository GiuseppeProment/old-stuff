//---------------------------------------------------------------------------
#ifndef UnitTela1H
#define UnitTela1H
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
//---------------------------------------------------------------------------

#include "IDtStrrc.h"
#include "IDtStrdb.h"
#include <vcl\Menus.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\Buttons.hpp>
#define crSqlWait (TCursor) 1

class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *m_Quadro;
	TBevel *Bevel1;
	TSpeedButton *bConecta;
	TSpeedButton *bDesconecta;
	TSpeedButton *bLista;
	TSpeedButton *bSobre;
        TLabel *Nome;
        TEdit *m_nome;
        TEdit *m_DSN;
        TEdit *m_senha;
        TLabel *senha;
        TLabel *DSN;
        TSpeedButton *bEdita;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall bDesconectaClick(TObject *Sender);
	void __fastcall bSobreClick(TObject *Sender);
        void __fastcall bEditarClick(TObject *Sender);
private:	// User declarations
	//IDataStoreOracleActivex oDs;
	IDataStoreODBC oDs;
        //IDataStore oDs;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
