//---------------------------------------------------------------------------
#ifndef TelaEditorListaH
#define TelaEditorListaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Mask.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
// dizento que o simbolo é uma classe
class IBLista;
class IMapClassTable;
//

class TFormEditorLista : public TForm
{
__published:	// IDE-managed Components
  TListBox *ListaAtributos;
  TLabel *Label2;
  TStaticText *NomeClasse;
  TListBox *ListaColunas;
  TLabel *Label1;
  TSpeedButton *BotaoAdiciona;
  TSpeedButton *BotaoRemove;
  TBitBtn *BitBtn1;
  TBitBtn *BitBtn2;
  TGroupBox *GroupBox1;
  TMaskEdit *getTamanho;
  TLabel *Label3;
  TLabel *Label4;
  TEdit *getDescricao;
  TLabel *Label5;
  TEdit *getImagem;
  TUpDown *UpDown1;
  void __fastcall BotaoAdicionaClick(TObject *Sender);
  void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:	// User declarations
  IBLista * oIBLista;
  IMapClassTable* oMapa;
  bool __fastcall ColecaoDisponivel();
  void __fastcall Inicialize();
public:		// User declarations
  __fastcall TFormEditorLista(TComponent* Owner, TComponent * ListaEditada);
};
//---------------------------------------------------------------------------
//extern PACKAGE TFormEditorLista *FormEditorLista;
//---------------------------------------------------------------------------
#endif
