//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IMapClassTable; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\impclsst.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IMapClassTable
#include "IMpClssT.h"
// IDataStore
#include "IDtStore.h"

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class IMapClassTable






IMapClassTable::IMapClassTable()
  //## begin IMapClassTable::IMapClassTable%.hasinit preserve=no
      : m_isComplete(false)
  //## end IMapClassTable::IMapClassTable%.hasinit
  //## begin IMapClassTable::IMapClassTable%.initialization preserve=yes
  //## end IMapClassTable::IMapClassTable%.initialization
{
  //## begin IMapClassTable::IMapClassTable%.body preserve=yes
  m_ListaAtributos.setApagueObjetosNaSaida(true);
  m_DataStore = NULL;
  //## end IMapClassTable::IMapClassTable%.body
}

IMapClassTable::IMapClassTable(const IMapClassTable &right)
  //## begin IMapClassTable::IMapClassTable%copy.hasinit preserve=no
      : m_isComplete(false)
  //## end IMapClassTable::IMapClassTable%copy.hasinit
  //## begin IMapClassTable::IMapClassTable%copy.initialization preserve=yes
  //## end IMapClassTable::IMapClassTable%copy.initialization
{
  //## begin IMapClassTable::IMapClassTable%copy.body preserve=yes
  //## end IMapClassTable::IMapClassTable%copy.body
}


IMapClassTable::~IMapClassTable()
{
  //## begin IMapClassTable::~IMapClassTable%.body preserve=yes
  //## end IMapClassTable::~IMapClassTable%.body
}


//## Get and Set Operations for Has Relationships (implementation)

ListaPointer<IMapAtrColuna> & IMapClassTable::ListaAtributos()
{
  //## begin IMapClassTable::ListaAtributos%.get preserve=no
  return m_ListaAtributos;
  //## end IMapClassTable::ListaAtributos%.get
}

IDataStore * IMapClassTable::DataStore()
{
  //## begin IMapClassTable::DataStore%.get preserve=no
  return m_DataStore;
  //## end IMapClassTable::DataStore%.get
}

void IMapClassTable::setDataStore(IDataStore *const  value)
{
  //## begin IMapClassTable::setDataStore%.set preserve=no
  m_DataStore = value;
  //## end IMapClassTable::setDataStore%.set
}

//## Get and Set Operations for Class Attributes (implementation)

IString IMapClassTable::nomeClasse()
{
  //## begin IMapClassTable::nomeClasse%.get preserve=no
  return m_nomeClasse;
  //## end IMapClassTable::nomeClasse%.get
}

void IMapClassTable::setnomeClasse(const IString value)
{
  //## begin IMapClassTable::setnomeClasse%.set preserve=no
  m_nomeClasse = value;
  //## end IMapClassTable::setnomeClasse%.set
}

IString IMapClassTable::nomeTabela()
{
  //## begin IMapClassTable::nomeTabela%.get preserve=no
  return m_nomeTabela;
  //## end IMapClassTable::nomeTabela%.get
}

void IMapClassTable::setnomeTabela(const IString value)
{
  //## begin IMapClassTable::setnomeTabela%.set preserve=no
  m_nomeTabela = value;
  //## end IMapClassTable::setnomeTabela%.set
}

bool IMapClassTable::isComplete()
{
  //## begin IMapClassTable::isComplete%.get preserve=no
  return m_isComplete;
  //## end IMapClassTable::isComplete%.get
}

void IMapClassTable::setisComplete(const bool value)
{
  //## begin IMapClassTable::setisComplete%.set preserve=no
  m_isComplete = value;
  //## end IMapClassTable::setisComplete%.set
}


// Additional Declarations
//## begin IMapClassTable.declarations preserve=yes
//## end IMapClassTable.declarations




