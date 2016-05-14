//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: Modelo; Package body
//## Subsystem:  Classes Negócio
//## Source file: c:\devrico\codigo\persist\comp_c\modelo.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include "IColecao.cpp"
//## end module.includes

// Modelo
#include "Modelo.h"

//## begin module.declarations preserve=no
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class Cadastro 






// Additional Declarations
//## begin Cadastro.declarations preserve=yes
//## end Cadastro.declarations


// Class Pessoa 






// Additional Declarations
//## begin Pessoa.declarations preserve=yes
//## end Pessoa.declarations


// Class Titulo 




// Additional Declarations
//## begin Titulo.declarations preserve=yes
//## end Titulo.declarations


// Instantiated Class ColecaoCadastro 

//## begin ColecaoCadastro.instantiation preserve=yes
template class IColecao<Cadastro>;
//## end ColecaoCadastro.instantiation


// Instantiated Class ColecaoPessoa 

//## begin ColecaoPessoa.instantiation preserve=yes
template class IColecao<Pessoa>;
//## end ColecaoPessoa.instantiation


// Instantiated Class ColecaoTitulo 

//## begin ColecaoTitulo.instantiation preserve=yes
template class IColecao<Titulo>;
//## end ColecaoTitulo.instantiation



