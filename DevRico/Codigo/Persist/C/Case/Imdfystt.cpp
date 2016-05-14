//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IModifyStatement; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\imdfystt.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IModifyStatement
#include "IMdfyStt.h"

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class IModifyStatement 


IModifyStatement::IModifyStatement()
  //## begin IModifyStatement::IModifyStatement%.hasinit preserve=no
  //## end IModifyStatement::IModifyStatement%.hasinit
  //## begin IModifyStatement::IModifyStatement%.initialization preserve=yes
  //## end IModifyStatement::IModifyStatement%.initialization
{
  //## begin IModifyStatement::IModifyStatement%.body preserve=yes
  //## end IModifyStatement::IModifyStatement%.body
}

IModifyStatement::IModifyStatement(const IModifyStatement &right)
  //## begin IModifyStatement::IModifyStatement%copy.hasinit preserve=no
  //## end IModifyStatement::IModifyStatement%copy.hasinit
  //## begin IModifyStatement::IModifyStatement%copy.initialization preserve=yes
  //## end IModifyStatement::IModifyStatement%copy.initialization
{
  //## begin IModifyStatement::IModifyStatement%copy.body preserve=yes
  //## end IModifyStatement::IModifyStatement%copy.body
}


IModifyStatement::~IModifyStatement()
{
  //## begin IModifyStatement::~IModifyStatement%.body preserve=yes
  //## end IModifyStatement::~IModifyStatement%.body
}



//## Other Operations (implementation)
IModifyStatement& IModifyStatement::addColunaValor(IString& coluna, IString& valor)
{
  //## begin IModifyStatement::addColunaValor%908596356.body preserve=yes
  addColuna( coluna );
  //:-/ devemos fazer uma copia, senao vai dar merda
  //    a destruicao ser  feita pela propria lista.
  //    depois deve ser revisto para os tipos blobs.
  theValues().adiciona( *(new IString(valor)) );

  //## end IModifyStatement::addColunaValor%908596356.body

  return *this;
}

IString IModifyStatement::getParteWhereID()
{
  IString PWID;

  //## begin IModifyStatement::getParteWhereID%908596357.body preserve=yes
	 PWID= " WHERE ";
	 PWID+= IBroker::nomeColunaID();
	 PWID+= "=";
	 PWID+= ID().asString();
  //## end IModifyStatement::getParteWhereID%908596357.body

  return PWID;
}

//## Get and Set Operations for Has Relationships (implementation)

IPersistID IModifyStatement::ID()
{
  //## begin IModifyStatement::ID%.get preserve=no
  return m_ID;
  //## end IModifyStatement::ID%.get
}

void IModifyStatement::setID(const IPersistID value)
{
  //## begin IModifyStatement::setID%.set preserve=no
  m_ID = value;
  //## end IModifyStatement::setID%.set
}


// Additional Declarations
//## begin IModifyStatement.declarations preserve=yes
//## end IModifyStatement.declarations




