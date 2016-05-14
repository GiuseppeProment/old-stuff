//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IEventoNotificacao; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\ivntntfc.h


#ifndef IvntNtfc_h
#define IvntNtfc_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes

// INotificador
#include "INtfcdor.h"

//## begin module.additionalDeclarations preserve=yes
#ifndef class
#ifdef GERAR_DLL
  #define class class __declspec(dllexport)
#else
  #define class class __declspec(dllimport)
#endif
#endif
//## end module.additionalDeclarations


//## Class: IEventoNotificacao
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class IEventoNotificacao
{
  //## begin IEventoNotificacao.initialDeclarations preserve=yes
  //## end IEventoNotificacao.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IEventoNotificacao%909098948
      IEventoNotificacao(INotificador& notificador, TypeEvento evento = INotificador::evtDefault);

      //## Operation: IEventoNotificacao%909098949
      IEventoNotificacao(INotificador& notificador);

      //## Operation: IEventoNotificacao%909098950
      IEventoNotificacao();

    //## Destructor (generated)
      ~IEventoNotificacao();

    //## Get and Set Operations for Has Relationships (generated)

      //## Documentation IEventoNotificacao::Notificador.has
      INotificador * Notificador();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: evento
      TypeEvento evento();

    // Additional Public Declarations
      //## begin IEventoNotificacao.public preserve=yes
      //## end IEventoNotificacao.public


  protected:
    // Additional Protected Declarations
      //## begin IEventoNotificacao.protected preserve=yes
      //## end IEventoNotificacao.protected


  private:
    // Additional Private Declarations
      //## begin IEventoNotificacao.private preserve=yes
      //## end IEventoNotificacao.private


  private:  //## implementation
    // Data Members for Has Relationships

      //## begin IEventoNotificacao::Notificador.has preserve=no  public: INotificador { -> 1RO}
      INotificador *m_Notificador;
      //## end IEventoNotificacao::Notificador.has

    // Data Members for Class Attributes

      //## begin IEventoNotificacao::evento.attr preserve=no  public: TypeEvento {U}
      TypeEvento m_evento;
      //## end IEventoNotificacao::evento.attr

    // Additional Implementation Declarations
      //## begin IEventoNotificacao.implementation preserve=yes
#undef class
      //## end IEventoNotificacao.implementation

};

// Class IEventoNotificacao





#endif


