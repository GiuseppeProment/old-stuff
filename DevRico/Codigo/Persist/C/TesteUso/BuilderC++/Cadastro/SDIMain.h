//----------------------------------------------------------------------------
#ifndef SDIMainH
#define SDIMainH
//----------------------------------------------------------------------------
#include <vcl\ComCtrls.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Dialogs.hpp>
#include <vcl\Menus.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>

#include "Cadastro.h"
//----------------------------------------------------------------------------
class TSDIAppForm : public TForm
{
__published:
	TMainMenu *MainMenu;
	TMenuItem *Help1;
	TMenuItem *About1;
	TPanel *SpeedPanel;
	TStatusBar *StatusBar;
	TSpeedButton *bConecta;
	TSpeedButton *bDesconecta;
	TSpeedButton *bSobre;
	TRadioGroup *MeioAcesso;
	TSpeedButton *bEditar;
	TMemo *Memo1;
	TSpeedButton *bDadosExemplo;
	void __fastcall ShowHint(TObject *Sender);
	void __fastcall ExitItemClick(TObject *Sender);
	
	
	void __fastcall Sobre(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);

	void __fastcall bConectaClick(TObject *Sender);
	void __fastcall bDesconectaClick(TObject *Sender);
	void __fastcall Edicao(TObject *Sender);
	void __fastcall InsereLinhas(TObject *Sender);
private:
public:
	virtual __fastcall TSDIAppForm(TComponent *AOwner);
	IDataStoreODBC oODBC;
  IDataStoreOracleActivex oOracle;
};
//----------------------------------------------------------------------------
extern TSDIAppForm *SDIAppForm;
//----------------------------------------------------------------------------
#endif
