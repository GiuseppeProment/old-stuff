//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IObservador; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\ibsrvdor.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IEventoNotificacao
#include "IvntNtfc.h"
// IObservador
#include "Ibsrvdor.h"

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class IObservador 

IObservador::IObservador()
  //## begin IObservador::IObservador%.hasinit preserve=no
  //## end IObservador::IObservador%.hasinit
  //## begin IObservador::IObservador%.initialization preserve=yes
  //## end IObservador::IObservador%.initialization
{
  //## begin IObservador::IObservador%.body preserve=yes
  //## end IObservador::IObservador%.body
}

IObservador::IObservador(const IObservador &right)
  //## begin IObservador::IObservador%copy.hasinit preserve=no
  //## end IObservador::IObservador%copy.hasinit
  //## begin IObservador::IObservador%copy.initialization preserve=yes
  //## end IObservador::IObservador%copy.initialization
{
  //## begin IObservador::IObservador%copy.body preserve=yes
  //## end IObservador::IObservador%copy.body
}


IObservador::~IObservador()
{
  //## begin IObservador::~IObservador%.body preserve=yes
  //## end IObservador::~IObservador%.body
}



//## Other Operations (implementation)
IObservador& IObservador::quandoEventoNotificacao(IEventoNotificacao& evento)
{
  //## begin IObservador::quandoEventoNotificacao%907215653.body preserve=yes
  //## end IObservador::quandoEventoNotificacao%907215653.body

  return *this;
}


// Additional Declarations
//## begin IObservador.declarations preserve=yes
//## end IObservador.declarations



