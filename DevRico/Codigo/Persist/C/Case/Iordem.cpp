//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IOrdem; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\iordem.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IOrdem
#include "IOrdem.h"

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class IOrdem 




IOrdem::IOrdem(const IOrdem &right)
  //## begin IOrdem::IOrdem%copy.hasinit preserve=no
      : m_isAsc(true)
  //## end IOrdem::IOrdem%copy.hasinit
  //## begin IOrdem::IOrdem%copy.initialization preserve=yes
  //## end IOrdem::IOrdem%copy.initialization
{
  //## begin IOrdem::IOrdem%copy.body preserve=yes
  //## end IOrdem::IOrdem%copy.body
}

IOrdem::IOrdem(IString& atributo, bool isAsc)
  //## begin IOrdem::IOrdem%908596358.hasinit preserve=no
      : m_isAsc(true)
  //## end IOrdem::IOrdem%908596358.hasinit
  //## begin IOrdem::IOrdem%908596358.initialization preserve=yes
  //## end IOrdem::IOrdem%908596358.initialization
{
  //## begin IOrdem::IOrdem%908596358.body preserve=yes
  //## end IOrdem::IOrdem%908596358.body
}


IOrdem::~IOrdem()
{
  //## begin IOrdem::~IOrdem%.body preserve=yes
  //## end IOrdem::~IOrdem%.body
}


//## Get and Set Operations for Class Attributes (implementation)

IString IOrdem::atributo()
{
  //## begin IOrdem::atributo%.get preserve=no
  return m_atributo;
  //## end IOrdem::atributo%.get
}

void IOrdem::setatributo(const IString value)
{
  //## begin IOrdem::setatributo%.set preserve=no
  m_atributo = value;
  //## end IOrdem::setatributo%.set
}

bool IOrdem::isAsc()
{
  //## begin IOrdem::isAsc%.get preserve=no
  return m_isAsc;
  //## end IOrdem::isAsc%.get
}

void IOrdem::setisAsc(const bool value)
{
  //## begin IOrdem::setisAsc%.set preserve=no
  m_isAsc = value;
  //## end IOrdem::setisAsc%.set
}

IString IOrdem::coluna()
{
  //## begin IOrdem::coluna%.get preserve=no
  return m_coluna;
  //## end IOrdem::coluna%.get
}

void IOrdem::setcoluna(const IString value)
{
  //## begin IOrdem::setcoluna%.set preserve=no
  m_coluna = value;
  //## end IOrdem::setcoluna%.set
}


// Additional Declarations
//## begin IOrdem.declarations preserve=yes
//## end IOrdem.declarations




