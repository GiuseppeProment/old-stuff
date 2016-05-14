// cadastro.h: interface for the Cadastro class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CADASTRO_H__9BE59461_E7A5_11D2_948B_00104B321AF0__INCLUDED_)
#define AFX_CADASTRO_H__9BE59461_E7A5_11D2_948B_00104B321AF0__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


#include "IPersistencia.h"

class Cadastro : public IPersistente  
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

#endif // !defined(AFX_CADASTRO_H__9BE59461_E7A5_11D2_948B_00104B321AF0__INCLUDED_)
