//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IUpdateStatement; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\ipdtsttm.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IUpdateStatement
#include "IpdtSttm.h"

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class IUpdateStatement 

IUpdateStatement::IUpdateStatement()
  //## begin IUpdateStatement::IUpdateStatement%.hasinit preserve=no
  //## end IUpdateStatement::IUpdateStatement%.hasinit
  //## begin IUpdateStatement::IUpdateStatement%.initialization preserve=yes
  //## end IUpdateStatement::IUpdateStatement%.initialization
{
  //## begin IUpdateStatement::IUpdateStatement%.body preserve=yes
  //## end IUpdateStatement::IUpdateStatement%.body
}

IUpdateStatement::IUpdateStatement(const IUpdateStatement &right)
  //## begin IUpdateStatement::IUpdateStatement%copy.hasinit preserve=no
  //## end IUpdateStatement::IUpdateStatement%copy.hasinit
  //## begin IUpdateStatement::IUpdateStatement%copy.initialization preserve=yes
  //## end IUpdateStatement::IUpdateStatement%copy.initialization
{
  //## begin IUpdateStatement::IUpdateStatement%copy.body preserve=yes
  //## end IUpdateStatement::IUpdateStatement%copy.body
}


IUpdateStatement::~IUpdateStatement()
{
  //## begin IUpdateStatement::~IUpdateStatement%.body preserve=yes
  //## end IUpdateStatement::~IUpdateStatement%.body
}



//## Other Operations (implementation)
IString IUpdateStatement::asSentencaSQL()
{
  IString sentenca;

  //## begin IUpdateStatement::asSentencaSQL%908596355.body preserve=yes
	sentenca="UPDATE ";
	sentenca+= tabelaAlvo();
	sentenca+=" SET ";

	// colunas e valores
	for (int i=1; i<= theColunas().count(); i++) {
		if (i!=1) sentenca+=",";
		sentenca+= ( theColunas()[i] ) ;  
		sentenca+= "=";
		sentenca+= ( theValues()[i] ) ;  
		 }

	// parte where
	sentenca += getParteWhereID();

  //## end IUpdateStatement::asSentencaSQL%908596355.body

  return sentenca;
}


// Additional Declarations
//## begin IUpdateStatement.declarations preserve=yes
//## end IUpdateStatement.declarations




