//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UnitDialogoEdicao.h"
#include "cadastro.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TDialogoEdicao *DialogoEdicao;
//---------------------------------------------------------------------
__fastcall TDialogoEdicao::TDialogoEdicao(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TDialogoEdicao::FormShow(TObject *Sender)
{
  try {
		IColecao<Cadastro> OsCadastros;
		OsCadastros.pronto();
		OsCadastros.goPrimeiro();
		Lista->Items->BeginUpdate();
		while ( OsCadastros.isFim()!= true )
		{
			TListItem*p = Lista->Items->Add();
			p->Caption = (char*) OsCadastros.ObjectRef().nome;
			p->Data = (void*) new Cadastro( OsCadastros.ObjectRef() );
			p->ImageIndex = 0;
      Application->ProcessMessages();
			OsCadastros.goProximo();
		}
		Lista->Items->EndUpdate();
  }
  catch( IErro e ) {
		MessageBox(NULL,e.textError(),"Erro",MB_ICONEXCLAMATION);
	}
/*
Lista->Items->BeginUpdate();
TListItem*p = Lista->Items->Add();
p->Caption = ;
p->Data = (void*);
p->ImageIndex = 0;
p->SubItems->Add( "xxx" );
Lista->Items->EndUpdate();*/
}
//---------------------------------------------------------------------------
void __fastcall TDialogoEdicao::FormClose(TObject *Sender, TCloseAction &Action)
{
  // liberar memória
	Action = caFree;
  // liberar ponteiros da lista
  for (int n = 0; n < Lista->Items->Count; n++)
  	delete ( (Cadastro*) Lista->Items->Item[n]->Data );
}
//---------------------------------------------------------------------------
void __fastcall TDialogoEdicao::OnExcluir(TObject *Sender)
{
try {
	Cadastro* pCadastro = (Cadastro*) Lista->ItemFocused->Data;
	pCadastro->erase();
	delete pCadastro;
	Lista->ItemFocused->Delete();
  }
  catch( IErro e ) {
		MessageBox(NULL,e.textError(),"Erro",MB_ICONEXCLAMATION);
	}
}
//---------------------------------------------------------------------------
