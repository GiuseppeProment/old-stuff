//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IQueryStatement; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: c:\docume~1\projetos\persist\codigo\casecode\iqrysttm.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IOrdem
#include "IOrdem.h"
// IQueryStatement
#include "IQrySttm.h"
// ICriterio
#include "ICritrio.h"

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class IQueryStatement 






IQueryStatement::IQueryStatement()
  //## begin IQueryStatement::IQueryStatement%.hasinit preserve=no
      : m_lowLayerSlot(NULL), m_isFim(false)
  //## end IQueryStatement::IQueryStatement%.hasinit
  //## begin IQueryStatement::IQueryStatement%.initialization preserve=yes
  //## end IQueryStatement::IQueryStatement%.initialization
{
  //## begin IQueryStatement::IQueryStatement%.body preserve=yes
	m_ValueID.setLenTo( 17 );
  //## end IQueryStatement::IQueryStatement%.body
}

IQueryStatement::IQueryStatement(const IQueryStatement &right)
  //## begin IQueryStatement::IQueryStatement%copy.hasinit preserve=no
      : m_lowLayerSlot(NULL), m_isFim(false)
  //## end IQueryStatement::IQueryStatement%copy.hasinit
  //## begin IQueryStatement::IQueryStatement%copy.initialization preserve=yes
  //## end IQueryStatement::IQueryStatement%copy.initialization
{
  //## begin IQueryStatement::IQueryStatement%copy.body preserve=yes
	m_ValueID.setLenTo( 17 );
  //## end IQueryStatement::IQueryStatement%copy.body
}


IQueryStatement::~IQueryStatement()
{
  //## begin IQueryStatement::~IQueryStatement%.body preserve=yes
  //## end IQueryStatement::~IQueryStatement%.body
}



//## Other Operations (implementation)
IString IQueryStatement::asSentencaSQL()
{
  IString sentenca;

  //## begin IQueryStatement::asSentencaSQL%908596354.body preserve=yes
	sentenca="SELECT ";

	
	// colunas
	for (int i=1; i<= theColunas().count(); i++) {
		//if(i!=1) sentenca+=",";
		sentenca+= ( theColunas()[i] ) ;
		sentenca+= ",";
		 }

	// ID vai no final
	sentenca+=IBroker::nomeColunaID();

	sentenca+= " FROM ";
	sentenca+= tabelaAlvo();

  //## end IQueryStatement::asSentencaSQL%908596354.body

  return sentenca;
}

//## Get and Set Operations for Has Relationships (implementation)

Lista<IOrdem>* IQueryStatement::theIOrdem()
{
  //## begin IQueryStatement::theIOrdem%.get preserve=no
  return m_theIOrdem;
  //## end IQueryStatement::theIOrdem%.get
}

void IQueryStatement::settheIOrdem(Lista<IOrdem>*const  value)
{
  //## begin IQueryStatement::settheIOrdem%.set preserve=no
  m_theIOrdem = value;
  //## end IQueryStatement::settheIOrdem%.set
}

Lista<ICriterio>* IQueryStatement::theICriterio()
{
  //## begin IQueryStatement::theICriterio%.get preserve=no
  return m_theICriterio;
  //## end IQueryStatement::theICriterio%.get
}

void IQueryStatement::settheICriterio(Lista<ICriterio>*const  value)
{
  //## begin IQueryStatement::settheICriterio%.set preserve=no
  m_theICriterio = value;
  //## end IQueryStatement::settheICriterio%.set
}

//## Get and Set Operations for Class Attributes (implementation)

bool IQueryStatement::isFim()
{
  //## begin IQueryStatement::isFim%.get preserve=no
  return m_isFim;
  //## end IQueryStatement::isFim%.get
}

void IQueryStatement::setisFim(const bool value)
{
  //## begin IQueryStatement::setisFim%.set preserve=no
  m_isFim = value;
  //## end IQueryStatement::setisFim%.set
}

IString & IQueryStatement::ValueID()
{
  //## begin IQueryStatement::ValueID%.get preserve=no
  return m_ValueID;
  //## end IQueryStatement::ValueID%.get
}

void IQueryStatement::setValueID(const IString &value)
{
  //## begin IQueryStatement::setValueID%.set preserve=no
  m_ValueID = value;
  //## end IQueryStatement::setValueID%.set
}


// Additional Declarations
//## begin IQueryStatement.declarations preserve=yes
//## end IQueryStatement.declarations



