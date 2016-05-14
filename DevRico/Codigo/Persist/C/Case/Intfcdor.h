//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: INotificador; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\intfcdor.h


#ifndef INtfcdor_h
#define INtfcdor_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes


class IEventoNotificacao;
class IObservador;

//## begin module.additionalDeclarations preserve=yes
#ifndef class
#ifdef GERAR_DLL
  #define class class __declspec(dllexport)
#else
  #define class class __declspec(dllimport)
#endif
#endif
//## end module.additionalDeclarations


//## Class: INotificador
//	Classe que visa manter relações de notificação simples
//	entre objetos.
//	Temos o Cliente e o Servidor, ambos descendendo de
//	INotifyProtocol
//	Protocolo:
//	Cliente (->) Servidor.enableNotifyEventsFor( Cliente );
//	Servidor on Event : Servidor.notifyObservers(
//	INotifyEvent );
//	Cliente.onReceiveNotifyEvent( INotifyEvent );
//	Cliente (->) Servidor.disableNotifyEventsFor( Cliente );
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>; IEventoNotificacao { -> F}

class INotificador
{
  //## begin INotificador.initialDeclarations preserve=yes
  //## end INotificador.initialDeclarations

  public:
    //## Constructors (generated)
      INotificador();

      INotificador(const INotificador &right);

    //## Destructor (generated)
      ~INotificador();


    //## Other Operations (specified)
      //## Operation: ligaNotificarObservadores%907215654
      INotificador& ligaNotificarObservadores();

      //## Operation: desligaNotificarObservadores%907215655
      INotificador& desligaNotificarObservadores();

      //## Operation: NotificarEventosPara%907215656
      INotificador& NotificarEventosPara(IObservador& Observador);

      //## Operation: notificarObservadores%907215657
      INotificador& notificarObservadores(IEventoNotificacao& evento);

      //## Operation: PararNotificarEventosPara%908414770
      INotificador& PararNotificarEventosPara(IObservador& Observador);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: nomeClasse
      //	pode ser sobrescrito com o nome da subclasse.
      IString nomeClasse();
      void setnomeClasse(const IString value);

    // Data Members for Class Attributes

      //## Attribute: evtDefault
      //## begin INotificador::evtDefault.attr preserve=no  public: static TypeEvento {V} "INotificador::Default"
      static TypeEvento evtDefault;
      //## end INotificador::evtDefault.attr

    // Additional Public Declarations
      //## begin INotificador.public preserve=yes
      //## end INotificador.public


  protected:
    // Additional Protected Declarations
      //## begin INotificador.protected preserve=yes
      //## end INotificador.protected


  private:
    // Additional Private Declarations
      //## begin INotificador.private preserve=yes
      //## end INotificador.private


  private:  //## implementation
    // Data Members for Has Relationships

      //## Documentation INotificador::Observadores.has
      //## begin INotificador::Observadores.has preserve=no  public: IObservador { -> 0..nRFO}
      ListaPointer<IObservador> m_Observadores;
      //## end INotificador::Observadores.has

    // Data Members for Class Attributes

      //## Attribute: notificarObservadores
      //	estado de notificação de observadores on/off.
      //## begin INotificador::notificarObservadores.attr preserve=no  private: bool {U} true
      bool m_notificarObservadores;
      //## end INotificador::notificarObservadores.attr

      //## begin INotificador::nomeClasse.attr preserve=no  public: IString {U} "INotificador"
      IString m_nomeClasse;
      //## end INotificador::nomeClasse.attr

    // Additional Implementation Declarations
      //## begin INotificador.implementation preserve=yes
#undef class
      //## end INotificador.implementation

};

// Class INotificador





#endif


