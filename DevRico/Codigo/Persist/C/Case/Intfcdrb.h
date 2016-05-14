//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: INotificadorObservador; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\intfcdrb.h


#ifndef INtfcdrb_h
#define INtfcdrb_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes

// INotificador
#include "INtfcdor.h"
// IObservador
#include "Ibsrvdor.h"

//## begin module.additionalDeclarations preserve=yes
#ifndef class
#ifdef GERAR_DLL
  #define class class __declspec(dllexport)
#else
  #define class class __declspec(dllimport)
#endif
#endif
//## end module.additionalDeclarations


//## Class: INotificadorObservador
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class INotificadorObservador : public INotificador, //## Inherits: <unnamed>
	public IObservador  //## Inherits: <unnamed>

{
  //## begin INotificadorObservador.initialDeclarations preserve=yes
  //## end INotificadorObservador.initialDeclarations

  public:
    //## Constructors (generated)
      INotificadorObservador();

      INotificadorObservador(const INotificadorObservador &right);

    //## Destructor (generated)
      ~INotificadorObservador();

    // Additional Public Declarations
      //## begin INotificadorObservador.public preserve=yes
      //## end INotificadorObservador.public


  protected:
    // Additional Protected Declarations
      //## begin INotificadorObservador.protected preserve=yes
      //## end INotificadorObservador.protected


  private:
    // Additional Private Declarations
      //## begin INotificadorObservador.private preserve=yes
      //## end INotificadorObservador.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin INotificadorObservador.implementation preserve=yes
#undef class
      //## end INotificadorObservador.implementation

};

// Class INotificadorObservador





#endif


