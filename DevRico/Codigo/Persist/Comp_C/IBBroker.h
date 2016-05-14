//## begin module.cm preserve=no
//	Código adequado para CBuilder (Componente)
//## end module.cm

//## begin module.cp preserve=no
//	(c) 2000 Giuseppe Enrico Proment Junior
//## end module.cp

//## Module: IBBroker; Package specification
//## Subsystem: I++ para CBuilder
//## Source file: g:\devrico\codigo\persist\comp_c\ibbroker.h


#ifndef IBBroker_h
#define IBBroker_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IComponent
#include "ICompo~1.h"

//## begin module.declarations preserve=no
#pragma option push -pr
#define class class PACKAGE
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: IBBroker
//## Category: I++ para CBuilder
//## Subsystem: I++ para CBuilder
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class IBBroker : public IComponente  //## Inherits: <unnamed>

{
  //## begin IBBroker.initialDeclarations preserve=yes
  //## end IBBroker.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IBBroker%960259193
      IBBroker(TComponent* Dono);

    //## Destructor (generated)
      ~IBBroker();

    // Additional Public Declarations
      //## begin IBBroker.public preserve=yes
  __published:
      //## end IBBroker.public


  protected:
    // Additional Protected Declarations
      //## begin IBBroker.protected preserve=yes
      //## end IBBroker.protected


  private:

    //## Other Operations (specified)
      //## Operation: fazerRevisao%960345882
      void fazerRevisao();

    // Additional Private Declarations
      //## begin IBBroker.private preserve=yes
      //## end IBBroker.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin IBBroker.implementation preserve=yes
#undef class
#pragma option pop
      //## end IBBroker.implementation

};



// Class IBBroker 





#endif


