//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IInsertStatement; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\insrtstt.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IInsertStatement
#include "InsrtStt.h"

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class IInsertStatement 

IInsertStatement::IInsertStatement()
  //## begin IInsertStatement::IInsertStatement%.hasinit preserve=no
  //## end IInsertStatement::IInsertStatement%.hasinit
  //## begin IInsertStatement::IInsertStatement%.initialization preserve=yes
  //## end IInsertStatement::IInsertStatement%.initialization
{
  //## begin IInsertStatement::IInsertStatement%.body preserve=yes
  //## end IInsertStatement::IInsertStatement%.body
}

IInsertStatement::IInsertStatement(const IInsertStatement &right)
  //## begin IInsertStatement::IInsertStatement%copy.hasinit preserve=no
  //## end IInsertStatement::IInsertStatement%copy.hasinit
  //## begin IInsertStatement::IInsertStatement%copy.initialization preserve=yes
  //## end IInsertStatement::IInsertStatement%copy.initialization
{
  //## begin IInsertStatement::IInsertStatement%copy.body preserve=yes
  //## end IInsertStatement::IInsertStatement%copy.body
}


IInsertStatement::~IInsertStatement()
{
  //## begin IInsertStatement::~IInsertStatement%.body preserve=yes
  //## end IInsertStatement::~IInsertStatement%.body
}



//## Other Operations (implementation)
IString IInsertStatement::asSentencaSQL()
{
  IString sentenca;
	int i;

  //## begin IInsertStatement::asSentencaSQL%908596361.body preserve=yes

	// teste : "Insert into <tabela> (coluna),... values ()
	sentenca="INSERT INTO ";
	sentenca+= tabelaAlvo();

	// colunas
	// id
	sentenca +=" (";
	sentenca += IBroker::nomeColunaID();
	for (i=1; i<= theColunas().count(); i++) {
		sentenca+=",";
		sentenca+= ( theColunas()[i] ) ;  
		 }

	// valores
	sentenca += ") VALUES( ";
	// id
	sentenca += ID().asString();
	for (i=1; i<= theValues().count(); i++) {
		sentenca+=",";
		sentenca+= ( theValues()[i] ) ;
		 }
	sentenca += ") ";
  //## end IInsertStatement::asSentencaSQL%908596361.body

  return sentenca;
}


// Additional Declarations
//## begin IInsertStatement.declarations preserve=yes
//## end IInsertStatement.declarations




