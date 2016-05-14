//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IEventoNotificacao; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\ivntntfc.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IEventoNotificacao
#include "IvntNtfc.h"

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class IEventoNotificacao 



IEventoNotificacao::IEventoNotificacao(INotificador& notificador, TypeEvento evento)
  //## begin IEventoNotificacao::IEventoNotificacao%909098948.hasinit preserve=no
  //## end IEventoNotificacao::IEventoNotificacao%909098948.hasinit
  //## begin IEventoNotificacao::IEventoNotificacao%909098948.initialization preserve=yes
  //## end IEventoNotificacao::IEventoNotificacao%909098948.initialization
{
  //## begin IEventoNotificacao::IEventoNotificacao%909098948.body preserve=yes
  m_Notificador = &notificador;
  m_evento = evento;
  //## end IEventoNotificacao::IEventoNotificacao%909098948.body
}

IEventoNotificacao::IEventoNotificacao(INotificador& notificador)
  //## begin IEventoNotificacao::IEventoNotificacao%909098949.hasinit preserve=no
  //## end IEventoNotificacao::IEventoNotificacao%909098949.hasinit
  //## begin IEventoNotificacao::IEventoNotificacao%909098949.initialization preserve=yes
  //## end IEventoNotificacao::IEventoNotificacao%909098949.initialization
{
  //## begin IEventoNotificacao::IEventoNotificacao%909098949.body preserve=yes
  //## end IEventoNotificacao::IEventoNotificacao%909098949.body
}

IEventoNotificacao::IEventoNotificacao()
  //## begin IEventoNotificacao::IEventoNotificacao%909098950.hasinit preserve=no
  //## end IEventoNotificacao::IEventoNotificacao%909098950.hasinit
  //## begin IEventoNotificacao::IEventoNotificacao%909098950.initialization preserve=yes
  //## end IEventoNotificacao::IEventoNotificacao%909098950.initialization
{
  //## begin IEventoNotificacao::IEventoNotificacao%909098950.body preserve=yes
  //## end IEventoNotificacao::IEventoNotificacao%909098950.body
}


IEventoNotificacao::~IEventoNotificacao()
{
  //## begin IEventoNotificacao::~IEventoNotificacao%.body preserve=yes
  //## end IEventoNotificacao::~IEventoNotificacao%.body
}


//## Get and Set Operations for Has Relationships (implementation)

INotificador * IEventoNotificacao::Notificador()
{
  //## begin IEventoNotificacao::Notificador%.get preserve=no
  return m_Notificador;
  //## end IEventoNotificacao::Notificador%.get
}

//## Get and Set Operations for Class Attributes (implementation)

TypeEvento IEventoNotificacao::evento()
{
  //## begin IEventoNotificacao::evento%.get preserve=no
  return m_evento;
  //## end IEventoNotificacao::evento%.get
}


// Additional Declarations
//## begin IEventoNotificacao.declarations preserve=yes
//## end IEventoNotificacao.declarations



