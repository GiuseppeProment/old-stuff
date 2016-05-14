//## begin module.cm preserve=no
//	Código adequado para CBuilder (Componente)
//## end module.cm

//## begin module.cp preserve=no
//	(c) 2000 Giuseppe Enrico Proment Junior
//## end module.cp

//## Module: IBObjeto; Package specification
//## Subsystem: I++ para CBuilder
//## Source file: g:\devrico\codigo\persist\comp_c\ibobjeto.h


#ifndef IBObjeto_h
#define IBObjeto_h 1

//## begin module.additionalIncludes preserve=no
#include <Classes.hpp>
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// Utilitarias
#include "IUtil.h"

//## begin module.declarations preserve=no
#pragma option push -pr
#define class class PACKAGE
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: IBObjeto
//	Tem por finalidade representar uma instancia de uma
//	classe de negócio ( subclasse de IPersistente )
//## Category: I++ para CBuilder
//## Subsystem: I++ para CBuilder
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class IBObjeto : public TComponent  //## Inherits: <unnamed>

{
  //## begin IBObjeto.initialDeclarations preserve=yes
  //## end IBObjeto.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IBObjeto%959306791
      IBObjeto(TComponent* Owner);

    //## Destructor (generated)
      ~IBObjeto();

    // Additional Public Declarations
      //## begin IBObjeto.public preserve=yes
  __published:
      //## end IBObjeto.public


  protected:
    // Additional Protected Declarations
      //## begin IBObjeto.protected preserve=yes
      //## end IBObjeto.protected


  private:
    // Additional Private Declarations
      //## begin IBObjeto.private preserve=yes
      //## end IBObjeto.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin IBObjeto.implementation preserve=yes
#pragma option pop
#undef class
      //## end IBObjeto.implementation

};



// Class IBObjeto 





#endif


