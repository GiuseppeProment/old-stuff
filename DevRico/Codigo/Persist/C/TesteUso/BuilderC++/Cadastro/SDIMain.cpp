//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "SDIMain.h"
#include "UnitAboutBox.h"
#include "UnitDialogoLogin.h"
#include "UnitDialogoEdicao.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TSDIAppForm *SDIAppForm;
//---------------------------------------------------------------------
__fastcall TSDIAppForm::TSDIAppForm(TComponent *AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TSDIAppForm::ShowHint(TObject *Sender)
{
	StatusBar->SimpleText = Application->Hint;
}
//---------------------------------------------------------------------
void __fastcall TSDIAppForm::ExitItemClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------
void __fastcall TSDIAppForm::Sobre(TObject *Sender)
{
	AboutBox->ShowModal();
}
//---------------------------------------------------------------------
void __fastcall TSDIAppForm::FormCreate(TObject *Sender)
{
	Application->OnHint = ShowHint;
  oODBC.setnome("ODBC");
  oOracle.setnome("ORACLE");
  //IBroker::addDataStore( oODBC );
  IBroker::addDataStore( oOracle );
  IBroker::inicialize();
}
//---------------------------------------------------------------------

void __fastcall TSDIAppForm::bConectaClick(TObject *Sender)
{
//TDialogoLogin * Dialogo = new TDialogoLogin( this );
if ( DialogoLogin->ShowModal() == mrOk )
{
	Application->ProcessMessages();
	Cadastro oCadastro;
	try {
		// fazer logon
	  Screen->Cursor = crSQLWait;
		switch (DialogoLogin->MeioAcesso->ItemIndex) {
			case 0 : // odbc
	    		oODBC.setDSN( DialogoLogin->DSN->Text.c_str() );
	    		oODBC.setsenha(  DialogoLogin->Senha->Text.c_str() );
	    		oODBC.setusuario(  DialogoLogin->Nome->Text.c_str() );
	        oODBC.ligar();
          //IBroker::regDataStoreForClass( oCadastro, "ODBC"  );
				break;
			case 1 : // oracle
	    		oOracle.setnomeDb( DialogoLogin->DSN->Text.c_str() );
	    		oOracle.setsenha(  DialogoLogin->Senha->Text.c_str() );
	    		oOracle.setusuario(  DialogoLogin->Nome->Text.c_str() );
	        oOracle.ligar();
          //IBroker::regDataStoreForClass( oCadastro, "ORACLE"  );
				break;
	  }
	  Screen->Cursor = crDefault;
    // ajustar botoes
    bConecta->Enabled = false;
    bDesconecta->Enabled = true;
    bEditar->Enabled = true;
    bDadosExemplo->Enabled = true;
    // ajustar estado
		MeioAcesso->ItemIndex = DialogoLogin->MeioAcesso->ItemIndex;
  }
  catch( IErro e ) { ::MessageBox(NULL,e.textError(),"Erro",MB_ICONEXCLAMATION);}
}

}
//---------------------------------------------------------------------------
void __fastcall TSDIAppForm::bDesconectaClick(TObject *Sender)
{
	try
  {	oODBC.desligar();
		oOracle.desligar();
    // ajustar botoes
    bConecta->Enabled = true;
    bDesconecta->Enabled = false;
    bEditar->Enabled = false;
    // ajustar estado
		MeioAcesso->ItemIndex = -1;
  }
  catch( IErro e ) { ::MessageBox(NULL,e.textError(),"Erro",MB_ICONEXCLAMATION);}
}
//---------------------------------------------------------------------------
void __fastcall TSDIAppForm::Edicao(TObject *Sender)
{
TDialogoEdicao * Dialogo = new TDialogoEdicao( this );
Dialogo->Show();
}
//---------------------------------------------------------------------------
void __fastcall TSDIAppForm::InsereLinhas(TObject *Sender)
{
	try {

  { Cadastro oPessoa;
  	oPessoa.nome = "Giuseppe E. Proment Jr.";
	  oPessoa.endereco = "Canedos - SP";
	  oPessoa.numero = 22;
	  oPessoa.peso = 54.5;
	  oPessoa.save();  }
  { Cadastro oPessoa;
  	oPessoa.nome = "Carmen M. O. Proment";
	  oPessoa.endereco = "Canedos - SP";
	  oPessoa.numero = 30;
	  oPessoa.peso = 60.0;
	  oPessoa.save();  }
  { Cadastro oPessoa;
  	oPessoa.nome = "Jose Mane";
	  oPessoa.endereco = "Rua Fagundes Dias";
	  oPessoa.numero = 34;
	  oPessoa.peso = 70.23;
	  oPessoa.save();  }

  }
  catch( IErro e ) { ::MessageBox(NULL,e.textError(),"Erro",MB_ICONEXCLAMATION);}
}
//---------------------------------------------------------------------------
