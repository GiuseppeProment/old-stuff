//## begin module.cm preserve=no
//	Código adequado para CBuilder (Componente)
//## end module.cm

//## begin module.cp preserve=no
//	(c) 2000 Giuseppe E. Proment Jr.
//## end module.cp

//## Module: IBBroker; Package body
//## Subsystem: I++ para CBuilder
//## Source file: g:\devrico\codigo\persist\comp_c\ibbroker.cpp


//## begin module.additionalIncludes preserve=no
#include <vcl.h>
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#pragma hdrstop
//## end module.includes

// IBBroker
#include "IBBroker.h"

//## begin module.declarations preserve=no
#pragma option push -pr
#pragma package( smart_init )
static inline void ValidCtrCheck( IBBroker * )
{
    new IBBroker(NULL);
}
// ------
namespace Ibbroker
{
    void __fastcall PACKAGE Register()
     {
        TComponentClass classes[1]=
        {__classid(IBBroker)};
        RegisterComponents("I++",classes,0);
     }
}
//---------
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


// Class IBBroker 

IBBroker::IBBroker(TComponent* Dono)
  //## begin IBBroker::IBBroker%960259193.hasinit preserve=no
  //## end IBBroker::IBBroker%960259193.hasinit
  //## begin IBBroker::IBBroker%960259193.initialization preserve=yes
  :IComponente( Dono )
  //## end IBBroker::IBBroker%960259193.initialization
{
  //## begin IBBroker::IBBroker%960259193.body preserve=yes
  //## end IBBroker::IBBroker%960259193.body
}


IBBroker::~IBBroker()
{
  //## begin IBBroker::~IBBroker%.body preserve=yes
  //## end IBBroker::~IBBroker%.body
}



//## Other Operations (implementation)
void IBBroker::fazerRevisao()
{
  //## begin IBBroker::fazerRevisao%960345882.body preserve=yes
  //## end IBBroker::fazerRevisao%960345882.body
}


// Additional Declarations
//## begin IBBroker.declarations preserve=yes
#pragma option pop
//## end IBBroker.declarations



