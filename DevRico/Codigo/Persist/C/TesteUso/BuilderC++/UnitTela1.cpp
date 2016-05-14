//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "UnitTela1.h"
#include "cadastro.h"
#include "UnitAboutBox.h"
#include "UnitEdicao.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

try {
    Screen->Cursor = crSqlWait;

    //oDs.setnomeDb(  "ORL" );
    oDs.setDSN( m_DSN->Text.c_str() );
    oDs.setsenha(  m_senha->Text.c_str() );
    oDs.setusuario(  m_nome->Text.c_str() );

    oDs.ligar();
    m_Quadro->Lines->Add("** IDataStoreODBC Ligado ***");
    //IBroker::addDataStore( oDs );
    //IBroker::inicialize();
    //m_Quadro->Lines->Add("** IBroker ((c)Giuseppe) inicializado**");
    Screen->Cursor = crDefault;
    bLista->Enabled = true;
    bConecta->Enabled = false;
    bDesconecta->Enabled = true;
  }
  catch( IErro e ) { ::MessageBox(NULL,e.textError(),"Erro",MB_ICONEXCLAMATION);}
  catch( ... ) { ::MessageBox(NULL,"Erro de arremesso indeterminado","Erro",MB_ICONEXCLAMATION);}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  // limpar o quadro
  m_Quadro->Clear();
  try {
	m_Quadro->Lines->Add("Preparando Colecao...");
        IColecao<Cadastro> OsCadastros;
	OsCadastros.pronto();
	m_Quadro->Lines->Add("Colecao Pronta.");
	m_Quadro->Lines->Add( "*** TESTE DE EOF C/ VARREDURA ***");
	OsCadastros.goPrimeiro();
	while ( OsCadastros.isFim()!= true )
	{
	        m_Quadro->Lines->Add( (char*) OsCadastros.ObjectRef().nome );
                Application->ProcessMessages();
		OsCadastros.goProximo();
	}
  }
  catch( IErro e ) {
		MessageBox(NULL,e.textError(),"Erro",MB_ICONEXCLAMATION);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	oDs.desligar();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    // carregar o meu cursor de espera para SQL cursor
    Screen->Cursors[crSqlWait] = LoadCursor(HInstance, "SQLWAIT");
    //Screen->Cursor= crSQLWait;
    IBroker::addDataStore( oDs );
    IBroker::inicialize();
    m_Quadro->Lines->Add("** IBroker ((c)Giuseppe) inicializado**");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::bDesconectaClick(TObject *Sender)
{
   bLista->Enabled = false;
   bConecta->Enabled = true;
   bDesconecta->Enabled = false;
   oDs.desligar();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::bSobreClick(TObject *Sender)
{
AboutBox->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::bEditarClick(TObject *Sender)
{
// ainda nada definido
Edicao->inicialize( oDs );
Edicao->ShowModal();
}
//---------------------------------------------------------------------------
