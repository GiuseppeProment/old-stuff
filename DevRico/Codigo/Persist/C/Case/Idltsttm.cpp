//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IDeleteStatement; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\idltsttm.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IDeleteStatement
#include "IDltSttm.h"

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class IDeleteStatement 

IDeleteStatement::IDeleteStatement()
  //## begin IDeleteStatement::IDeleteStatement%.hasinit preserve=no
  //## end IDeleteStatement::IDeleteStatement%.hasinit
  //## begin IDeleteStatement::IDeleteStatement%.initialization preserve=yes
  //## end IDeleteStatement::IDeleteStatement%.initialization
{
  //## begin IDeleteStatement::IDeleteStatement%.body preserve=yes
  //## end IDeleteStatement::IDeleteStatement%.body
}

IDeleteStatement::IDeleteStatement(const IDeleteStatement &right)
  //## begin IDeleteStatement::IDeleteStatement%copy.hasinit preserve=no
  //## end IDeleteStatement::IDeleteStatement%copy.hasinit
  //## begin IDeleteStatement::IDeleteStatement%copy.initialization preserve=yes
  //## end IDeleteStatement::IDeleteStatement%copy.initialization
{
  //## begin IDeleteStatement::IDeleteStatement%copy.body preserve=yes
  //## end IDeleteStatement::IDeleteStatement%copy.body
}


IDeleteStatement::~IDeleteStatement()
{
  //## begin IDeleteStatement::~IDeleteStatement%.body preserve=yes
  //## end IDeleteStatement::~IDeleteStatement%.body
}



//## Other Operations (implementation)
IString IDeleteStatement::asSentencaSQL()
{
  IString Sentenca;

  //## begin IDeleteStatement::asSentencaSQL%908596362.body preserve=yes
	Sentenca="DELETE FROM ";
	Sentenca+= tabelaAlvo();
	// parte where
	Sentenca += getParteWhereID();
  //## end IDeleteStatement::asSentencaSQL%908596362.body

  return Sentenca;
}


// Additional Declarations
//## begin IDeleteStatement.declarations preserve=yes
//## end IDeleteStatement.declarations




