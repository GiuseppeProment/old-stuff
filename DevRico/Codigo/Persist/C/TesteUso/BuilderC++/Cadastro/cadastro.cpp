// cadastro.cpp: implementation of the Cadastro class.
//
//////////////////////////////////////////////////////////////////////

//#include "stdafx.h"
//#include "TesteVisual.h"

#include "cadastro.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
Cadastro::Cadastro( const Cadastro &pRight ):IPersistente( pRight )
{
	// sera que roda o superior ?
	numero = pRight.numero;
	endereco = pRight.endereco;
	nome = pRight.nome;
	peso = pRight.peso;
};

