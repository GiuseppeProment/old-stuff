//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Buttons.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TComboBox *cPorta;
	TLabel *Label2;
	TComboBox *cVelocidade;
	TLabel *Label3;
	TComboBox *cByteSize;
	TLabel *Label4;
	TComboBox *cParidade;
	TLabel *Label5;
	TComboBox *cStopBits;
	TMemo *cLog;
	TLabel *Label6;
	TBitBtn *bLiga;
	TBitBtn *bDesliga;
	TBitBtn *bLimpaLog;
	TEdit *cOutput;
	TLabel *Label7;
	TSpeedButton *bEnvia;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall bLigaClick(TObject *Sender);

	void __fastcall bDesligaClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall bLimpaLogClick(TObject *Sender);
	void __fastcall bEnviaClick(TObject *Sender);
private:	// User declarations
	DCB dcb;
	HANDLE hCom;
    OVERLAPPED overLap;
    void ShowErroWin32();
public:		// User declarations
    void log( char* frase);
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
