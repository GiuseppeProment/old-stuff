#include "IPersistencia.h"
#include <iostream.h>
#include "Istring.h"
#include <iomanip.h>
//#include <string.h>
#include <winUser.h>

#pragma comment (lib,"Persistencia.lib")

class Cadastro :public IPersistente
{
public:
	int			numero;
	IString	endereco;
	IString nome;
	double  peso;
public:
  Cadastro() {};
  Cadastro( const Cadastro &pRight );
  ~Cadastro() {};
  char* getNomeClasse() {return "Cadastro";};
  void OnClassInfo()
  {
	registraMembro( ADI( Cadastro,numero ) ,IsInt);
	registraMembro( ADI( Cadastro,endereco ),IsStringFix);
	registraMembro( ADI( Cadastro,nome ),IsStringFix);
	registraMembro( ADI( Cadastro,peso ),IsDouble);
  };
};

Cadastro::Cadastro( const Cadastro &pRight ):IPersistente(pRight)
{
	// sera que roda o superior ?
	numero = pRight.numero;
	endereco = pRight.endereco;
	nome = pRight.nome;
	peso = pRight.peso;
};

//template class IColecao<Cadastro>;
//template IPersistente IColecao<Cadastro>::getDummy(void);


void main()
{

  try {
    IDataStoreODBC oDs;
		oDs.setDSN("XBASE");
		oDs.ligar();

    IBroker::addDataStore( oDs );
    IBroker::inicialize();

		{
    Cadastro oPessoa;
		oPessoa.numero = 1;
		oPessoa.peso = 100.10;
		oPessoa.nome = "Giuseppe nome1";
		oPessoa.endereco = "Endereco um 1";
    oPessoa.save();
		}

		{
    Cadastro oPessoa;
		oPessoa.numero = 2;
		oPessoa.peso = 200.20;
		oPessoa.nome = "Carmen nome2";
		oPessoa.endereco = "Endereco Ender2";
    oPessoa.save();
		}
		{
    Cadastro oPessoa;
		oPessoa.numero = 3;
		oPessoa.peso = 300.30;
		oPessoa.nome = "Caroline nome3";
		oPessoa.endereco = "Endereco Ender3";
    oPessoa.save();
		}
		{
    Cadastro oPessoa;
		oPessoa.numero = 4;
		oPessoa.peso = -400.40;
		oPessoa.nome = "Dirce nome4";
		oPessoa.endereco = "Endereço Ender4";
    oPessoa.save();
		}

		IColecao<Cadastro> OsCadastros;
		//OsCadastros.addCriterio( ICriterio()   );
		//OsCadastros.addOrdem(   );


		OsCadastros.pronto();

		OsCadastros.goPrimeiro();

		Cadastro oPrimeiro = OsCadastros.ObjectCopy();

		oPrimeiro.nome = "Novo Nome";
		oPrimeiro.save();

		OsCadastros.goPrimeiro();

		cout  << "** goPrimeiro"
			<< "endereco:" << OsCadastros.ObjectRef().endereco << endl
			<< "numero  :" << OsCadastros.ObjectRef().numero		<< endl
			<< "peso    :" << OsCadastros.ObjectRef().peso			<< endl
			<< "nome    :" << OsCadastros.ObjectRef().nome			<< endl
			<< "-----------------------------------------" << endl;

		OsCadastros.goProximo();
		cout  << "** goProximo"
			<< "endereco:" << OsCadastros.ObjectRef().endereco << endl
			<< "numero  :" << OsCadastros.ObjectRef().numero		<< endl
			<< "peso    :" << OsCadastros.ObjectRef().peso			<< endl
			<< "nome    :" << OsCadastros.ObjectRef().nome			<< endl
			<< "-----------------------------------------" << endl;
		OsCadastros.goProximo();
		cout  << "** goProximo"
			<< "endereco:" << OsCadastros.ObjectRef().endereco << endl
			<< "numero  :" << OsCadastros.ObjectRef().numero		<< endl
			<< "peso    :" << OsCadastros.ObjectRef().peso			<< endl
			<< "nome    :" << OsCadastros.ObjectRef().nome			<< endl
			<< "-----------------------------------------" << endl;
		OsCadastros.goProximo();
		cout  << "** goProximo"
			<< "endereco:" << OsCadastros.ObjectRef().endereco << endl
			<< "numero  :" << OsCadastros.ObjectRef().numero		<< endl
			<< "peso    :" << OsCadastros.ObjectRef().peso			<< endl
			<< "nome    :" << OsCadastros.ObjectRef().nome			<< endl
			<< "-----------------------------------------" << endl;
		OsCadastros.goProximo();
		cout  << "** goProximo"
			<< "endereco:" << OsCadastros.ObjectRef().endereco << endl
			<< "numero  :" << OsCadastros.ObjectRef().numero		<< endl
			<< "peso    :" << OsCadastros.ObjectRef().peso			<< endl
			<< "nome    :" << OsCadastros.ObjectRef().nome			<< endl
			<< "-----------------------------------------" << endl;
		OsCadastros.goAnterior();
		cout  << "** goAnterior"
			<< "endereco:" << OsCadastros.ObjectRef().endereco << endl
			<< "numero  :" << OsCadastros.ObjectRef().numero		<< endl
			<< "peso    :" << OsCadastros.ObjectRef().peso			<< endl
			<< "nome    :" << OsCadastros.ObjectRef().nome			<< endl
			<< "-----------------------------------------" << endl;
		OsCadastros.goAnterior();
		cout  << "** goAnterior"
			<< "endereco:" << OsCadastros.ObjectRef().endereco << endl
			<< "numero  :" << OsCadastros.ObjectRef().numero		<< endl
			<< "peso    :" << OsCadastros.ObjectRef().peso			<< endl
			<< "nome    :" << OsCadastros.ObjectRef().nome			<< endl
			<< "-----------------------------------------" << endl;
		OsCadastros.goAnterior();
		cout  << "** goAnterior"
			<< "endereco:" << OsCadastros.ObjectRef().endereco << endl
			<< "numero  :" << OsCadastros.ObjectRef().numero		<< endl
			<< "peso    :" << OsCadastros.ObjectRef().peso			<< endl
			<< "nome    :" << OsCadastros.ObjectRef().nome			<< endl
			<< "-----------------------------------------" << endl;

		OsCadastros.goUltimo();
		cout  << "** goUltimo"
			<< "endereco:" << OsCadastros.ObjectRef().endereco << endl
			<< "numero  :" << OsCadastros.ObjectRef().numero		<< endl
			<< "peso    :" << OsCadastros.ObjectRef().peso			<< endl
			<< "nome    :" << OsCadastros.ObjectRef().nome			<< endl
			<< "-----------------------------------------" << endl;



		cout << endl << "*** TESTE DE EOF C/ VARREDURA ***" << endl;
		OsCadastros.goPrimeiro();
		while ( OsCadastros.isFim()!= true )
		{
			cout << OsCadastros.ObjectRef().nome <<  endl;
			OsCadastros.goProximo();
		}


	  IRASTRO( IBroker::asDebug() );
  }
  catch( IErro e ) {
		MessageBox(NULL,e.textError(),"Erro",MB_ICONEXCLAMATION);
	}
}

