#pragma hdrstop
#include <condefs.h>
#include <system.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <iomanip.h>


/*
class base
{
  public:
  base() {};
  ~base() {};
  virtual char* getClassName() {return "base";};
};

class CriaPorMetaClasse
{
	public:
	CriaPorMetaClasse()	{};
	void setTipo( System::TMetaClass * itemClass )
	{
		fItemClass = itemClass;
	};
	TObject* add()
	{
    // return TObject::NewInstance( fItemClass );
    // TObject
    return ;
	}
	ShortString nome() {return TObject::ClassName( fItemClass ) ;}
	System::TMetaClass * fItemClass;
	int a;
};

class teste :public TObject
{
	public:
	int a;
};

//---------------------------------------------------------------------------
#pragma argsused
int main(int argc, char* argv[])
{
  AnsiString x;
	CriaPorMetaClasse pCriadora;
	pCriadora.setTipo( __classid(teste) );
	x = pCriadora.nome();
    cout << x.c_str() << endl;
    Teste *oTeste;
    oTeste = pCriadora.add();

    return 0;
}
*/


class NotificadoraIndireta
{
  public:
  NotificadoraIndireta() {};
  ~NotificadoraIndireta() {};
  virtual char* getClassName() {return "NotificadoraIndireta";};
  void ( __closure *pQuandoOcorrerEvento ) (void);
  void chame() { cout <<"NotificadoraIndireta::chame"<<endl;pQuandoOcorrerEvento(); };
};

class teste
{
	public:
    int a;
    void quandoOcorrerEvento() { cout<<"teste::quandoOcorrerEvento()"<<endl;};
};

//---------------------------------------------------------------------------
#pragma argsused
int main(int argc, char* argv[])
{
    NotificadoraIndireta oNotificadora;
    teste oteste;

    oNotificadora.pQuandoOcorrerEvento = oteste.quandoOcorrerEvento;
    oNotificadora.chame();

    return 0;
}
