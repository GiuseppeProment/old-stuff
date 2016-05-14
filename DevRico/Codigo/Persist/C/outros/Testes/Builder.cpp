#include <system.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <iomanip.h>

#pragma link "vcl.lib"

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
	void add() 
	{
		return;
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

void main()
{
	CriaPorMetaClasse pCriadora;
	pCriadora.setTipo( __classid(teste) );
	pCriadora.nome();
}