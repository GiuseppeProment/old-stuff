//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IErro; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\ierro.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes

// IErro
#include "IErro.h"

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class IErro


IErro::IErro()
  //## begin IErro::IErro%.hasinit preserve=no
  //## end IErro::IErro%.hasinit
  //## begin IErro::IErro%.initialization preserve=yes
  //## end IErro::IErro%.initialization
{
  //## begin IErro::IErro%.body preserve=yes
  //## end IErro::IErro%.body
}

IErro::IErro(const IErro &right)
  //## begin IErro::IErro%copy.hasinit preserve=no
  //## end IErro::IErro%copy.hasinit
  //## begin IErro::IErro%copy.initialization preserve=yes
  //## end IErro::IErro%copy.initialization
{
  //## begin IErro::IErro%copy.body preserve=yes
  m_textError=right.m_textError;
  //## end IErro::IErro%copy.body
}

IErro::IErro(char* texto)
  //## begin IErro::IErro%909032152.hasinit preserve=no
  //## end IErro::IErro%909032152.hasinit
  //## begin IErro::IErro%909032152.initialization preserve=yes
  //## end IErro::IErro%909032152.initialization
{
  //## begin IErro::IErro%909032152.body preserve=yes
  settextError(texto);
  //## end IErro::IErro%909032152.body
}


IErro::~IErro()
{
  //## begin IErro::~IErro%.body preserve=yes
  //## end IErro::~IErro%.body
}


//## Get and Set Operations for Class Attributes (implementation)

char* IErro::textError()
{
  //## begin IErro::textError%.get preserve=no
  return m_textError;
  //## end IErro::textError%.get
}

void IErro::settextError(char*const  value)
{
  //## begin IErro::settextError%.set preserve=no
  m_textError = value;
  //## end IErro::settextError%.set
}


// Additional Declarations
//## begin IErro.declarations preserve=yes
//## end IErro.declarations



