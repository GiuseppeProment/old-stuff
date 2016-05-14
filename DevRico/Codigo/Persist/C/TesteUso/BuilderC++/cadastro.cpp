// cadastro.cpp: implementation of the Cadastro class.
//
//////////////////////////////////////////////////////////////////////

#include "cadastro.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Cadastro::Cadastro( const Cadastro &pRight ):IPersistente(pRight)
{
	// sera que roda o superior ?
	numero = pRight.numero;
	endereco = pRight.endereco;
	nome = pRight.nome;
	peso = pRight.peso;
};

