//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TelaEditorLista.h"
#include "IBLista.h"
#include "Impclsst.h"
#include "Iclssmap.h"
#include "Iprsstnt.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//TFormEditorLista *FormEditorLista;
//---------------------------------------------------------------------------
__fastcall TFormEditorLista::TFormEditorLista(TComponent* Owner, TComponent * ListaEditada)
  : TForm(Owner)
{
  // verificar se a coleção está pronta
  // encher as listas
  // ok
  oIBLista = dynamic_cast<IBLista*>(ListaEditada);
  if ( ColecaoDisponivel() )
  {
    Inicialize();
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormEditorLista::Inicialize()
{
  // obter o mapa

  IColecaoPersistenteBase *oColecao = const_cast<IColecaoPersistenteBase*>(oIBLista->ColecaoRepresentada->getColecaoBase());
  IPersistente *umPersistente = oColecao->createDummy();
  //IMapClassTable& oMapa = IClassMap::getMapaFor( *umPersistente );
  oMapa = & (IClassMap::getMapaFor( *umPersistente ));
  // exibir o nome da classe representada pela coleção
  NomeClasse->Caption = umPersistente->getNomeClasse();
  oColecao->releaseDummy(umPersistente);
  // encher as listas de atributos/colunas
  // os atributos já escolhidos estão em oIBLista->colunas

  // encher a lista de atributos
  for (int i=1; i<=oMapa->ListaAtributos().count(); i++ )
  {
    //ListaColunas->Items->Add(IntToStr(statbuf.st_size));
    ListaAtributos->Items->AddObject(
      (char*) oMapa->ListaAtributos()[i]->nomeMembro(),
      (TObject*) i ); // gambiarra feia
  }
  // encher a lista de Colunas
  for (int i=0; i<oIBLista->colunas->Count; i++ )
  {
    ListaColunas->Items->AddObject(
      ((IColuna*)(oIBLista->colunas->Items[i]))->descricao,
      oIBLista->colunas->Items[i]  );
  }
}

//---------------------------------------------------------------------------
bool __fastcall TFormEditorLista::ColecaoDisponivel()
{
  bool ret;
  if (oIBLista->ColecaoRepresentada != NULL )
  {
    if (!(ret = ( oIBLista->ColecaoRepresentada->getColecaoBase() != NULL )))

      IBUtilitaria::mensagemUsuario("ColecaoRepresentada sem Classe de negócio definida");
  }
  else
  {
    IBUtilitaria::mensagemUsuario("Propriedade ColecaoRepresentada está indefinida");
    ret = false;
  }
  return ret;
}
//---------------------------------------------------------------------------


void __fastcall TFormEditorLista::BotaoAdicionaClick(TObject *Sender)
{
  // variavel de trabalho
  IColuna* item;
  int x;
  // okey pegar o que estiver selecionado na listaColunas e passar para listaAtributos
  // verificar através do Selected

  for (int i=0; i<ListaAtributos->Items->Count; i++ ) {
    if ( ListaAtributos->Selected[i] ) {
      // criar o item em colunas:TCollection
      x = (int) ListaAtributos->Items->Objects[i];
      item = dynamic_cast<IColuna*> (oIBLista->colunas->Add());
      item->indexDoAtributo = x;
      item->descricao       =(char*) oMapa->ListaAtributos()[x]->nomeMembro();
      item->largura         = oMapa->ListaAtributos()[x]->tamanho();
      // adicionar na lista de colunas
      ListaColunas->Items->AddObject(
        item->descricao,
        item  );
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormEditorLista::FormCloseQuery(TObject *Sender,
      bool &CanClose)
{
  CanClose = true;
  oIBLista->montar();
}
//---------------------------------------------------------------------------
