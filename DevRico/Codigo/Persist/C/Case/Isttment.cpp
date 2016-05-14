//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IStatement; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: c:\docume~1\projetos\persist\codigo\casecode\isttment.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IStatement
#include "ISttment.h"

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class IStatement 






IStatement::IStatement()
  //## begin IStatement::IStatement%.hasinit preserve=no
      : m_linhasCount(0)
  //## end IStatement::IStatement%.hasinit
  //## begin IStatement::IStatement%.initialization preserve=yes
  //## end IStatement::IStatement%.initialization
{
  //## begin IStatement::IStatement%.body preserve=yes
  m_theValues.setApagueObjetosNaSaida(true);
  m_theColunas.setApagueObjetosNaSaida(true);
  //## end IStatement::IStatement%.body
}

IStatement::IStatement(const IStatement &right)
  //## begin IStatement::IStatement%copy.hasinit preserve=no
      : m_linhasCount(0)
  //## end IStatement::IStatement%copy.hasinit
  //## begin IStatement::IStatement%copy.initialization preserve=yes
  //## end IStatement::IStatement%copy.initialization
{
  //## begin IStatement::IStatement%copy.body preserve=yes
  //## end IStatement::IStatement%copy.body
}


IStatement::~IStatement()
{
  //## begin IStatement::~IStatement%.body preserve=yes
  //## end IStatement::~IStatement%.body
}



//## Other Operations (implementation)
IStatement& IStatement::addColuna(IString& nome)
{
  //## begin IStatement::addColuna%908596359.body preserve=yes
  m_theColunas.adiciona( *(new IString(nome)) );
  //## end IStatement::addColuna%908596359.body

  return *this;
}

//## Get and Set Operations for Has Relationships (implementation)

ListaString & IStatement::theColunas()
{
  //## begin IStatement::theColunas%.get preserve=no
  return m_theColunas;
  //## end IStatement::theColunas%.get
}

void IStatement::settheColunas(const ListaString &value)
{
  //## begin IStatement::settheColunas%.set preserve=no
  m_theColunas = value;
  //## end IStatement::settheColunas%.set
}

ListaString & IStatement::theValues()
{
  //## begin IStatement::theValues%.get preserve=no
  return m_theValues;
  //## end IStatement::theValues%.get
}

void IStatement::settheValues(const ListaString &value)
{
  //## begin IStatement::settheValues%.set preserve=no
  m_theValues = value;
  //## end IStatement::settheValues%.set
}

IEstadoStatement IStatement::estado()
{
  //## begin IStatement::estado%.get preserve=no
  return m_estado;
  //## end IStatement::estado%.get
}

void IStatement::setestado(const IEstadoStatement value)
{
  //## begin IStatement::setestado%.set preserve=no
  m_estado = value;
  //## end IStatement::setestado%.set
}

//## Get and Set Operations for Class Attributes (implementation)

IString IStatement::tabelaAlvo()
{
  //## begin IStatement::tabelaAlvo%.get preserve=no
  return m_tabelaAlvo;
  //## end IStatement::tabelaAlvo%.get
}

void IStatement::settabelaAlvo(const IString value)
{
  //## begin IStatement::settabelaAlvo%.set preserve=no
  m_tabelaAlvo = value;
  //## end IStatement::settabelaAlvo%.set
}

int IStatement::linhasCount()
{
  //## begin IStatement::linhasCount%.get preserve=no
  return m_linhasCount;
  //## end IStatement::linhasCount%.get
}

void IStatement::setlinhasCount(const int value)
{
  //## begin IStatement::setlinhasCount%.set preserve=no
  m_linhasCount = value;
  //## end IStatement::setlinhasCount%.set
}


// Additional Declarations
//## begin IStatement.declarations preserve=yes
//## end IStatement.declarations



