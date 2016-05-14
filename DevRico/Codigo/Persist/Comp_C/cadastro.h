#if !defined(AFX_CADASTRO_H__9BE59461_E7A5_11D2_948B_00104B321AF0__INCLUDED_)
#define AFX_CADASTRO_H__9BE59461_E7A5_11D2_948B_00104B321AF0__INCLUDED_

#include "Iprsstnt.h"

class Cadastro : public IPersistente
{
public:
	int numero;
	IString	endereco;
	IString nome;
	double peso;
public:
  Cadastro() {};
  Cadastro( const Cadastro&);
  virtual ~Cadastro() {};
  char* getNomeClasse() {return "Cadastro";};
  void OnClassInfo()
  {
	registraMembro( ADI( Cadastro,numero ) ,IsInt);
	registraMembro( ADI( Cadastro,endereco ),IsStringFix);
	registraMembro( ADI( Cadastro,nome ),IsStringFix);
	registraMembro( ADI( Cadastro,peso ),IsDouble);
  };
};

class Titulo : public IPersistente
{
public:
	int numero;
	IString	cedente;
	IString vencimento;
	double valor;
public:
  Titulo() {};
  virtual ~Titulo() {};
  char* getNomeClasse() {return "Titulo";};
  void OnClassInfo()
  {
	registraMembro( ADI( Titulo,numero ) ,IsInt);
	registraMembro( ADI( Titulo,cedente ),IsStringFix);
	registraMembro( ADI( Titulo,vencimento ),IsStringFix);
	registraMembro( ADI( Titulo,valor ),IsDouble);
  };
};


#endif // !defined(AFX_CADASTRO_H__9BE59461_E7A5_11D2_948B_00104B321AF0__INCLUDED_)
