//----------------------------------------------------------------------------
#ifndef UnitDialogoLoginH
#define UnitDialogoLoginH
//----------------------------------------------------------------------------
#include <vcl\Buttons.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include <vcl\ExtCtrls.hpp>
//----------------------------------------------------------------------------
class TDialogoLogin : public TForm
{
__published:
	TLabel *Label1;
	TEdit *Nome;
	TButton *OKBtn;
	TButton *CancelBtn;
	TLabel *Label2;
	TEdit *Senha;
	TLabel *Label3;
	TEdit *DSN;
	TRadioGroup *MeioAcesso;
private:
public:
	virtual __fastcall TDialogoLogin(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern TDialogoLogin *DialogoLogin;
//----------------------------------------------------------------------------
#endif    
