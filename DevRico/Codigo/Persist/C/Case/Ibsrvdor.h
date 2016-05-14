//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IObservador; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\ibsrvdor.h


#ifndef Ibsrvdor_h
#define Ibsrvdor_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes


class IEventoNotificacao;

//## begin module.additionalDeclarations preserve=yes
#ifndef class
#ifdef GERAR_DLL
  #define class class __declspec(dllexport)
#else
  #define class class __declspec(dllimport)
#endif
#endif
//## end module.additionalDeclarations


//## Class: IObservador
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>; IEventoNotificacao { -> F}

class IObservador
{
  //## begin IObservador.initialDeclarations preserve=yes
  //## end IObservador.initialDeclarations

  public:
    //## Constructors (generated)
      IObservador();

      IObservador(const IObservador &right);

    //## Destructor (generated)
      ~IObservador();


    //## Other Operations (specified)
      //## Operation: quandoEventoNotificacao%907215653
      virtual IObservador& quandoEventoNotificacao(IEventoNotificacao& evento);

    // Additional Public Declarations
      //## begin IObservador.public preserve=yes
      //## end IObservador.public


  protected:
    // Additional Protected Declarations
      //## begin IObservador.protected preserve=yes
      //## end IObservador.protected


  private:
    // Additional Private Declarations
      //## begin IObservador.private preserve=yes
      //## end IObservador.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin IObservador.implementation preserve=yes
#undef class
      //## end IObservador.implementation

};

// Class IObservador





#endif


