//---------------------------------------------------------------------------
#ifndef UnitEdicaoH
#define UnitEdicaoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>

#include "IDtStrrc.h"
#include "IDtStrdb.h"

#define crSqlWait (TCursor) 1
//---------------------------------------------------------------------------
class TEdicao : public TForm
{
__published:	// IDE-managed Components
        TStringGrid *tabela;
    TEdit *eNome;
    TLabel *eChave;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TEdit *eEndereco;
    TEdit *ePeso;
    TButton *bGravar;
    TButton *bDeletar;
    TButton *bNovo;
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall tabelaSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
    void __fastcall bGravarClick(TObject *Sender);
    void __fastcall bNovoClick(TObject *Sender);
private:
    IDataStore* m_dataStore;
    bool isInicializado;
    void destruaObjetosGrid();	// User declarations
public:		// User declarations
        __fastcall TEdicao(TComponent* Owner);
    void inicialize( IDataStore & dataStore );
};
//---------------------------------------------------------------------------
extern PACKAGE TEdicao *Edicao;
//---------------------------------------------------------------------------
#endif
