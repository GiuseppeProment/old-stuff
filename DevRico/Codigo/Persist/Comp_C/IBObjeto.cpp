//## begin module.cm preserve=no
//	Código adequado para CBuilder (Componente)
//## end module.cm

//## begin module.cp preserve=no
//	(c) 2000 Giuseppe E. Proment Jr.
//## end module.cp

//## Module: IBObjeto; Package body
//## Subsystem: I++ para CBuilder
//## Source file: g:\devrico\codigo\persist\comp_c\ibobjeto.cpp


//## begin module.additionalIncludes preserve=no
#include <vcl.h>
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#pragma hdrstop
//## end module.includes

// IBObjeto
#include "IBObjeto.h"

//## begin module.declarations preserve=no
#pragma option push -pr
#pragma package(smart_init)

static inline void ValidCtrCheck(IBObjeto *)
{
  new IBObjeto(NULL);
}
//-------------------------------------------------------
namespace Ibobjeto
{
  void __fastcall PACKAGE Register()
  {
     TComponentClass classes[1] = {__classid(IBObjeto)};
     RegisterComponents("I++", classes, 0);
  }
}
//-------------------------------------------------------

//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


// Class IBObjeto 

IBObjeto::IBObjeto(TComponent* Owner)
  //## begin IBObjeto::IBObjeto%959306791.hasinit preserve=no
  //## end IBObjeto::IBObjeto%959306791.hasinit
  //## begin IBObjeto::IBObjeto%959306791.initialization preserve=yes
  :TComponent( Owner )
  //## end IBObjeto::IBObjeto%959306791.initialization
{
  //## begin IBObjeto::IBObjeto%959306791.body preserve=yes
  //## end IBObjeto::IBObjeto%959306791.body
}


IBObjeto::~IBObjeto()
{
  //## begin IBObjeto::~IBObjeto%.body preserve=yes
  //## end IBObjeto::~IBObjeto%.body
}



// Additional Declarations
//## begin IBObjeto.declarations preserve=yes
#pragma option pop
//## end IBObjeto.declarations




