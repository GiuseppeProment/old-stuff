//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UnitEdicao.h"
#include "cadastro.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEdicao *Edicao;
//---------------------------------------------------------------------------
__fastcall TEdicao::TEdicao(TComponent* Owner)
        : TForm(Owner)
{
    isInicializado = false;
}
//---------------------------------------------------------------------------
void TEdicao::inicialize( IDataStore & dataStore )
{
    //TODO: Add your source code here
    Screen->Cursor = crSqlWait;
    destruaObjetosGrid();

    m_dataStore = &dataStore;
    // preencher a grid com todos os dados

    IColecao<Cadastro> OsCadastros;
    OsCadastros.pronto();
	OsCadastros.goPrimeiro();
    // fazer cabeçalho
    tabela->RowCount=1;
    tabela->Cells[0][0] = "Chave";
    tabela->Cells[1][0] = "Nome";
    tabela->Cells[2][0] = "Endereço";
    tabela->Cells[3][0] = "Peso";
    // incrementar RowCount para acrescentar linhas 0 based
	while ( OsCadastros.isFim()!= true )
    {
        tabela->RowCount++;
        tabela->Cells[0][tabela->RowCount-1]=OsCadastros.ObjectRef().ID().asString();
        tabela->Cells[1][tabela->RowCount-1]=(char*) OsCadastros.ObjectRef().nome;
        tabela->Cells[2][tabela->RowCount-1]=(char*) OsCadastros.ObjectRef().endereco;
        tabela->Cells[3][tabela->RowCount-1]= OsCadastros.ObjectRef().peso;
        // guarda uma copia do objeto
        Cadastro * pCadastro = new Cadastro( OsCadastros.ObjectRef() );
        tabela->Objects[0][tabela->RowCount-1] = (TObject*) pCadastro;
        Application->ProcessMessages();
		OsCadastros.goProximo();
	}
    tabela->FixedRows=1;
    Screen->Cursor = crDefault;
    isInicializado = true;
}
//---------------------------------------------------------------------------
void __fastcall TEdicao::FormDestroy(TObject *Sender)
{
destruaObjetosGrid();
}
//---------------------------------------------------------------------------
void TEdicao::destruaObjetosGrid()
{
    //TODO: Add your source code here
    if ( isInicializado ) {
        // destruir objetos do grid
        for (int l = tabela->RowCount-1,i=1; i<l; i++){
            delete ((Cadastro*) tabela->Objects[0][i]);
        }
    }
    isInicializado = false;
}


void __fastcall TEdicao::tabelaSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
    if ( ARow > 0 ) {
        CanSelect = true;
        // exibir dados nos campos de edição
        eChave->Caption = tabela->Cells[0][ARow];
        eNome->Text =(char*) ((Cadastro*)tabela->Objects[0][ARow])->nome;
        eEndereco->Text =(char*) ((Cadastro*)tabela->Objects[0][ARow])->endereco;
        ePeso->Text = ((Cadastro*)tabela->Objects[0][ARow])->peso;
    } else CanSelect = false;

}
//---------------------------------------------------------------------------

void __fastcall TEdicao::bGravarClick(TObject *Sender)
{
    int selecionada = tabela->Row;
    Cadastro* pCadastro;
    if (selecionada > 0) {
        // pegar objeto
        pCadastro = ((Cadastro*)tabela->Objects[0][selecionada]);
        // preencher novos valores
        pCadastro->nome = eNome->Text.c_str();
        pCadastro->endereco = eEndereco->Text.c_str();
        //pCadastro->peso = IString(ePeso->Text.c_str());
        // alterar strings da grid
        tabela->Cells[1][selecionada]=eNome->Text;
        tabela->Cells[2][selecionada]=eEndereco->Text;
        tabela->Cells[3][selecionada]=ePeso->Text;
        // persistir objeto
        pCadastro->save();
        }
}
//---------------------------------------------------------------------------

void __fastcall TEdicao::bNovoClick(TObject *Sender)
{
    Cadastro pCadastro;
    // preencher novos valores
    pCadastro.nome = eNome->Text.c_str();
    pCadastro.endereco = eEndereco->Text.c_str();
    pCadastro.numero =0;
    pCadastro.peso=0;
    //pCadastro->peso = IString(ePeso->Text.c_str());
    // persistir objeto
    try { pCadastro.save(); }
    catch( IErro e ) { ::MessageBox(NULL,e.textError(),"Erro",MB_ICONEXCLAMATION);}
    catch( ... ) { ::MessageBox(NULL,"Erro de arremesso indeterminado","Erro",MB_ICONEXCLAMATION);}    // coleção deve ser reavaliada
    this->inicialize( *m_dataStore );
}
//---------------------------------------------------------------------------

