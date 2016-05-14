//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IDataStore; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\idtstore.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IQueryStatement
#include "IQrySttm.h"
// IModifyStatement
#include "IMdfyStt.h"
// IStatement
#include "ISttment.h"
// IDataStore
#include "IDtStore.h"

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class IDataStore 




IDataStore::IDataStore()
  //## begin IDataStore::IDataStore%.hasinit preserve=no
      : m_nome("DEFAULT")
  //## end IDataStore::IDataStore%.hasinit
  //## begin IDataStore::IDataStore%.initialization preserve=yes
  //## end IDataStore::IDataStore%.initialization
{
  //## begin IDataStore::IDataStore%.body preserve=yes
  //## end IDataStore::IDataStore%.body
}

IDataStore::IDataStore(const IDataStore &right)
  //## begin IDataStore::IDataStore%copy.hasinit preserve=no
      : m_nome("DEFAULT")
  //## end IDataStore::IDataStore%copy.hasinit
  //## begin IDataStore::IDataStore%copy.initialization preserve=yes
  //## end IDataStore::IDataStore%copy.initialization
{
  //## begin IDataStore::IDataStore%copy.body preserve=yes
  //## end IDataStore::IDataStore%copy.body
}


IDataStore::~IDataStore()
{
  //## begin IDataStore::~IDataStore%.body preserve=yes
  //## end IDataStore::~IDataStore%.body
}



//## Other Operations (implementation)
bool IDataStore::execute(IModifyStatement& setenca)
{
  bool ok;

  //## begin IDataStore::execute%908596370.body preserve=yes
	IRASTRO( setenca.asSentencaSQL()+"\n" )
  ok=true;
  //## end IDataStore::execute%908596370.body

  return ok;
}

bool IDataStore::execute(IQueryStatement& anQuery)
{
  bool ok;

  //## begin IDataStore::execute%908596371.body preserve=yes
  ok=true;
  //## end IDataStore::execute%908596371.body

  return ok;
}

IDataStore& IDataStore::requisitaDados(IQueryStatement& theQuery, IDirecaoFetch tipo)
{
  //## begin IDataStore::requisitaDados%908596372.body preserve=yes
  //## end IDataStore::requisitaDados%908596372.body

  return *this;
}

bool IDataStore::isFim(IQueryStatement& theQuery)
{
  bool Final;

  //## begin IDataStore::isFim%908596373.body preserve=yes
  Final=false;
  //## end IDataStore::isFim%908596373.body

  return Final;
}

IDataStore& IDataStore::libereQuery(IQueryStatement& anQuery)
{
  //## begin IDataStore::libereQuery%908596374.body preserve=yes
  //## end IDataStore::libereQuery%908596374.body

  return *this;
}

IDataStore& IDataStore::ligar()
{
  //## begin IDataStore::ligar%910153638.body preserve=yes
  //## end IDataStore::ligar%910153638.body

  return *this;
}

IDataStore& IDataStore::desligar()
{
  //## begin IDataStore::desligar%910153639.body preserve=yes
  //## end IDataStore::desligar%910153639.body

  return *this;
}

//## Get and Set Operations for Class Attributes (implementation)

IString IDataStore::nome()
{
  //## begin IDataStore::nome%.get preserve=no
  return m_nome;
  //## end IDataStore::nome%.get
}

void IDataStore::setnome(const IString value)
{
  //## begin IDataStore::setnome%.set preserve=no
  m_nome = value;
  //## end IDataStore::setnome%.set
}

IString IDataStore::usuario()
{
  //## begin IDataStore::usuario%.get preserve=no
  return m_usuario;
  //## end IDataStore::usuario%.get
}

void IDataStore::setusuario(const IString value)
{
  //## begin IDataStore::setusuario%.set preserve=no
  m_usuario = value;
  //## end IDataStore::setusuario%.set
}

IString IDataStore::senha()
{
  //## begin IDataStore::senha%.get preserve=no
  return m_senha;
  //## end IDataStore::senha%.get
}

void IDataStore::setsenha(const IString value)
{
  //## begin IDataStore::setsenha%.set preserve=no
  m_senha = value;
  //## end IDataStore::setsenha%.set
}


// Additional Declarations
//## begin IDataStore.declarations preserve=yes
//## end IDataStore.declarations



