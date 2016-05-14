//----------------------------------------------------------------------------
#ifndef UnitDialogoEdicaoH
#define UnitDialogoEdicaoH
//----------------------------------------------------------------------------
#include <vcl\ExtCtrls.hpp>
#include <vcl\ComCtrls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include <vcl\Menus.hpp>
//----------------------------------------------------------------------------
class TDialogoEdicao : public TForm
{
__published:
	TPanel *Panel1;
	TPageControl *PageControlEdicao;
	TTabSheet *FolhaLista;
	TTabSheet *FolhaEdicao;
	TImageList *ImageList1;
	TListView *Lista;
	TPopupMenu *PopupMenuLista;
	TMenuItem *mEditar;
	TMenuItem *mIncluir;
	TMenuItem *mExcluir;
	TMenuItem *N1;
	TMenuItem *mVer;
	TMenuItem *mOperaes;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall OnExcluir(TObject *Sender);
private:
public:
	virtual __fastcall TDialogoEdicao(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern TDialogoEdicao *DialogoEdicao;
//----------------------------------------------------------------------------
#endif    
