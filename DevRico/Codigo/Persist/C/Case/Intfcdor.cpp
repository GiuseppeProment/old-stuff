//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: INotificador; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\intfcdor.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// INotificador
#include "INtfcdor.h"
// IEventoNotificacao
#include "IvntNtfc.h"
// IObservador
#include "Ibsrvdor.h"

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class INotificador 




//## begin INotificador::evtDefault.attr preserve=no  public: static TypeEvento {V} "INotificador::Default"
TypeEvento INotificador::evtDefault = "INotificador::Default";
//## end INotificador::evtDefault.attr

INotificador::INotificador()
  //## begin INotificador::INotificador%.hasinit preserve=no
      : m_notificarObservadores(true), m_nomeClasse("INotificador")
  //## end INotificador::INotificador%.hasinit
  //## begin INotificador::INotificador%.initialization preserve=yes
  //## end INotificador::INotificador%.initialization
{
  //## begin INotificador::INotificador%.body preserve=yes
  //## end INotificador::INotificador%.body
}

INotificador::INotificador(const INotificador &right)
  //## begin INotificador::INotificador%copy.hasinit preserve=no
      : m_notificarObservadores(true), m_nomeClasse("INotificador")
  //## end INotificador::INotificador%copy.hasinit
  //## begin INotificador::INotificador%copy.initialization preserve=yes
  //## end INotificador::INotificador%copy.initialization
{
  //## begin INotificador::INotificador%copy.body preserve=yes
  //## end INotificador::INotificador%copy.body
}


INotificador::~INotificador()
{
  //## begin INotificador::~INotificador%.body preserve=yes
  //## end INotificador::~INotificador%.body
}



//## Other Operations (implementation)
INotificador& INotificador::ligaNotificarObservadores()
{
  //## begin INotificador::ligaNotificarObservadores%907215654.body preserve=yes
  //## end INotificador::ligaNotificarObservadores%907215654.body

  return *this;
}

INotificador& INotificador::desligaNotificarObservadores()
{
  //## begin INotificador::desligaNotificarObservadores%907215655.body preserve=yes
  //## end INotificador::desligaNotificarObservadores%907215655.body

  return *this;
}

INotificador& INotificador::NotificarEventosPara(IObservador& Observador)
{
  //## begin INotificador::NotificarEventosPara%907215656.body preserve=yes
  //## end INotificador::NotificarEventosPara%907215656.body

  return *this;
}

INotificador& INotificador::notificarObservadores(IEventoNotificacao& evento)
{
  //## begin INotificador::notificarObservadores%907215657.body preserve=yes
  //## end INotificador::notificarObservadores%907215657.body

  return *this;
}

INotificador& INotificador::PararNotificarEventosPara(IObservador& Observador)
{
  //## begin INotificador::PararNotificarEventosPara%908414770.body preserve=yes
  //## end INotificador::PararNotificarEventosPara%908414770.body

  return *this;
}

//## Get and Set Operations for Class Attributes (implementation)

IString INotificador::nomeClasse()
{
  //## begin INotificador::nomeClasse%.get preserve=no
  return m_nomeClasse;
  //## end INotificador::nomeClasse%.get
}

void INotificador::setnomeClasse(const IString value)
{
  //## begin INotificador::setnomeClasse%.set preserve=no
  m_nomeClasse = value;
  //## end INotificador::setnomeClasse%.set
}


// Additional Declarations
//## begin INotificador.declarations preserve=yes
//## end INotificador.declarations



