//## begin module.cm preserve=no
//	Código adequado para CBuilder (Componente)
//## end module.cm

//## begin module.cp preserve=no
//	(c) 2000 Giuseppe Enrico Proment Junior
//## end module.cp

//## Module: IComponent; Package specification
//## Subsystem: I++ para CBuilder
//## Source file: c:\devrico\codigo\persist\comp_c\icompo~1.h


#ifndef ICmpnent_h
#define ICmpnent_h 1

//## begin module.additionalIncludes preserve=no
#include <SYSUTILS.HPP>
#include <CONTROLS.HPP>
#include <CLASSES.HPP>
#include <FORMS.HPP>
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// Utilitarias
#include "IUtil.h"
// IBroker
#include "IBroker.h"

class IComponente;

//## begin module.declarations preserve=no
#pragma option push -pr
// este não é um componente
// mas precisa ser exportado 
#define class class PACKAGE
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: IBUtilitaria; Class Utility
//	Classe somente de métodos estáticos com funções para
//	exibição de erros e advertências, gravação de log de
//	erro, controle de cursor e outras funcionalidades
//	específicas para o C++Builder.
//## Category: I++ para CBuilder
//## Subsystem: I++ para CBuilder
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>; TApplication { -> }

class IBUtilitaria 
{
  //## begin IBUtilitaria.initialDeclarations preserve=yes
  //## end IBUtilitaria.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: mensagemUsuario%959826780
      //	Exibe uma mensagem ao usuário.
      static void mensagemUsuario(char* texto = "houve algo");

      //## Operation: inicioOperacaoLenta%959826781
      //	altera o cursor ou coisa parecida para indicar ao
      //	usuário que vai demorar...
      static void inicioOperacaoLenta();

      //## Operation: finalOperacaoLenta%959826782
      //	complementa o método inicioOperacaoLenta.
      static void finalOperacaoLenta();

    // Additional Public Declarations
      //## begin IBUtilitaria.public preserve=yes
      //## end IBUtilitaria.public


  protected:
    // Additional Protected Declarations
      //## begin IBUtilitaria.protected preserve=yes
      //## end IBUtilitaria.protected


  private:
    // Additional Private Declarations
      //## begin IBUtilitaria.private preserve=yes
      //## end IBUtilitaria.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin IBUtilitaria.implementation preserve=yes
      //## end IBUtilitaria.implementation

};



//## Class: IEventoNotificacaoBuilder
//	Evento para uso no CBuilder, a única diferença do
//	IEventoNotificacao da I++ é que o notificador é do tipo
//	IComponent
//## Category: I++ para CBuilder
//## Subsystem: I++ para CBuilder
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class IEventoNotificacaoBuilder 
{
  //## begin IEventoNotificacaoBuilder.initialDeclarations preserve=yes
  //## end IEventoNotificacaoBuilder.initialDeclarations

  public:
    //## Constructors (generated)
      IEventoNotificacaoBuilder(const IEventoNotificacaoBuilder &right);

    //## Constructors (specified)
      //## Operation: IEventoNotificacaoBuilder%909098948
      IEventoNotificacaoBuilder(IComponente* notificador, TypeEvento evento = IEventoNotificacaoBuilder::Default);

      //## Operation: IEventoNotificacaoBuilder%909098950
      IEventoNotificacaoBuilder();

    //## Destructor (generated)
      ~IEventoNotificacaoBuilder();

    //## Get and Set Operations for Has Relationships (generated)

      //## Documentation IEventoNotificacaoBuilder::Notificador.has
      //	Componente que disparou o evento
      IComponente * getNotificador();
      void setNotificador(IComponente *const  value);

    // Data Members for Class Attributes

      //## Attribute: evento
      //## begin IEventoNotificacaoBuilder::evento.attr preserve=no  public: TypeEvento {VA} 
      TypeEvento evento;
      //## end IEventoNotificacaoBuilder::evento.attr

      //## Attribute: Default
      //	evento que será usado se não for definido algum.
      //## begin IEventoNotificacaoBuilder::Default.attr preserve=no  public: static TypeEvento {V} "IEventoNotificacaoBuilder::Default"
      static TypeEvento Default;
      //## end IEventoNotificacaoBuilder::Default.attr

    // Additional Public Declarations
      //## begin IEventoNotificacaoBuilder.public preserve=yes
      //## end IEventoNotificacaoBuilder.public


  protected:
    // Data Members for Has Relationships

      //## begin IEventoNotificacaoBuilder::Notificador.has preserve=no  public: IComponente { -> 1RFO}
      IComponente *m_Notificador;
      //## end IEventoNotificacaoBuilder::Notificador.has

    // Additional Protected Declarations
      //## begin IEventoNotificacaoBuilder.protected preserve=yes
      //## end IEventoNotificacaoBuilder.protected


  private:
    // Additional Private Declarations
      //## begin IEventoNotificacaoBuilder.private preserve=yes
      //## end IEventoNotificacaoBuilder.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin IEventoNotificacaoBuilder.implementation preserve=yes
      //## end IEventoNotificacaoBuilder.implementation

};



//## Class: IComponente; Abstract
//	subclasse de TComponent da VCL (Visual Classes Library)
//	com capacidade igual ao esquema de notificação
//	implementado pela "IFrameWork"
//## Category: I++ para CBuilder
//## Subsystem: I++ para CBuilder
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>; IEventoNotificacaoBuilder { -> }

class IComponente : public TComponent  //## Inherits: <unnamed>

{
  //## begin IComponente.initialDeclarations preserve=yes
  //## end IComponente.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IComponente%959306784
      //	Construtor requerido para uso dentro do ambiente da IDE
      //	do C++Builder
      //## Semantics:
      //	inicializa m_Pronto para false, m_notificarObservadores
      //	para true e m_nomeClasse para 'IComponent' que deve ser
      //	alterado pela subclasse através do método setNomeClasse.
      IComponente(TComponent* Owner);

    //## Destructor (generated)
      virtual ~IComponente();


    //## Other Operations (specified)
      //## Operation: ligaNotificarObservadores%907215654
      //	passa a fazer notificação.
      IComponente* ligaNotificarObservadores();

      //## Operation: desligaNotificarObservadores%907215655
      //	passa a não fazer notificação.
      IComponente* desligaNotificarObservadores();

      //## Operation: NotificarEventosPara%907215656
      //	Inclui o componente na lista de Observadores
      IComponente* NotificarEventosPara(IComponente* Observador);

      //## Operation: PararNotificarEventosPara%908414770
      //	remove o Observador da lista.
      IComponente* PararNotificarEventosPara(IComponente* Observador);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: nomeClasse
      //	contém o nome da classe, deve ser atribuida pelo método
      //	setnomeClasse, utilizada pelo método nomeClasse.
      const IString getnomeClasse() const;
      void setnomeClasse(const IString value);

    // Data Members for Class Attributes

      //## Attribute: Default
      //	TypeEvento é sinonimo de char* que é o tipo do dado
      //	usado para construir objetos do tipo IEventoNotificação,
      //	podem existir vários eventos definidos pela classe, por
      //	exemplo
      //	TypeEvento IMinhaClasse::evtMudado =
      //	"IMinhaClasse::evtMudado", este dado será usado pela
      //	classe notificada para saber que tipo de evento ocorreu
      //	na classe notificadora que é enviada junto no objeto
      //	evento
      //## begin IComponente::Default.attr preserve=no  public: static TypeEvento {V} "IComponente::Default"
      static TypeEvento Default;
      //## end IComponente::Default.attr

    // Additional Public Declarations
      //## begin IComponente.public preserve=yes
  __property bool
    IsPronto = {read=getPronto};

  __published:
      //## end IComponente.public


  protected:

    //## Other Operations (specified)
      //## Operation: Loaded%959306787
      //	método herdado do TComponent que é chamado quando o
      //	componente acabou de ser lido da fila ( arquivo...) e
      //	teve suas propriedades 'property' escritas.
      //## Semantics:
      //	"passos para inicialização em cascata"
      //	 verifica this->IsPronto
      //	 se retornar false, é merda
      //	 dispara excessão IErro
      //	  throw Exception("erro sei la do que") nativa do
      //	CppBuilder
      //	  throw IErro("erro sei la do que")     nativa da
      //	IFrameWork
      virtual void Loaded();

      //## Operation: WriteState%959306788
      //	método herdado do TComponent, que é chamado quando o
      //	componente será gravado em uma fila ( arquivo, form ).
      virtual void WriteState(TWriter* Writer);

      //## Operation: fazerRevisao%959306789
      //	método abstrato que deve ser definido pelo subclasse.
      //## Semantics:
      //	Deve verificar a propriedade IsPronto de cada componente
      //	agregado que é derivado de IComponent, com isso todos os
      //	componentes agregados serão inicializados corretamente.
      //	Se por acaso algum deles retornar 'false' deve disparar
      //	uma excessão.
      virtual void fazerRevisao() = 0;

      //## Operation: notificarObservadores%907215657
      //	deve ser chamado para enviar o evento. É chamado pela
      //	subclasse. O evento conterá this, que é o notificador e
      //	o identificador de evento ( vide atributo evtDefault ).
      IComponente* notificarObservadores(IEventoNotificacaoBuilder& evento);

      //## Operation: quandoEventoNotificacao%907215653
      //	este método será chamado toda vez que um evento checar
      //	ao Observador. Deve ser sobrescrito pela subclasse, ou
      //	caso seja utilizado o método de colocar o
      //	NotificadorObservador como agregado o ponteiro 'closure'
      //	para função membro QuandoEvento deve ter sido preenchido
      //	pelo agregando e será chamado neste método ( logicamente
      //	se estiver preenchido ).
      //	um exemplo de código seria:
      //	if (
      //	evento.notificador.nomeClasse()=="IBDataStoreJasmim" )
      //	  if ( evento.evento==IBDataStoreJasmim::evtDesligado )
      //	     // faça algo
      virtual IComponente* quandoEventoNotificacao(IEventoNotificacaoBuilder& evento);

    // Data Members for Has Relationships

      //## Documentation IComponente::Observadores.has
      //	Lista de observadores que receberão notificação de
      //	eventos. É uma classe template. Observadores são
      //	adicionados e removidos pelos métodos
      //	NotificarEventosPara e ParaNotificarEventosPara
      //	respectivamente.
      //## begin IComponente::Observadores.has preserve=no  protected: IComponente { -> 0..nRO}
      ListaPointer<IComponente> m_Observadores;
      //## end IComponente::Observadores.has

    // Data Members for Class Attributes

      //## Attribute: Pronto
      //	'true' se o componente esta preparado. é utilizado pela
      //	'property' IsPronto.
      //## begin IComponente::Pronto.attr preserve=no  private: bool {V} false
      bool m_Pronto;
      //## end IComponente::Pronto.attr

      //## Attribute: notificarObservadores
      //	'true' se deve notificar os observadores quanto aos
      //	eventos disparados.
      //## begin IComponente::notificarObservadores.attr preserve=no  private: bool  {U} true
      bool  m_notificarObservadores;
      //## end IComponente::notificarObservadores.attr

      //## begin IComponente::nomeClasse.attr preserve=no  public: IString {V} "IComponente"
      IString m_nomeClasse;
      //## end IComponente::nomeClasse.attr

    // Additional Protected Declarations
      //## begin IComponente.protected preserve=yes
      //## end IComponente.protected


  private:

    //## Other Operations (specified)
      //## Operation: getPronto%959735967
      //	get da propriedade IsPronto.
      bool getPronto();

    // Additional Private Declarations
      //## begin IComponente.private preserve=yes
      //## end IComponente.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin IComponente.implementation preserve=yes
      //## end IComponente.implementation

};



//## Class: IBDataStore; Abstract
//	Apenas para unificar os diversos DataStore sob um tipo,
//	é analoga a IDataStore da I++, mas como os tipo
//	IBDataStore são classes 'wrap', esta é fazia.
//## Category: I++ para CBuilder
//## Subsystem: I++ para CBuilder
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>; IBroker { -> }

class IBDataStore : public IComponente  //## Inherits: <unnamed>

{
  //## begin IBDataStore.initialDeclarations preserve=yes
  //## end IBDataStore.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IBDataStore%960521282
      IBDataStore(TComponent* Dono);

    //## Destructor (generated)
      virtual ~IBDataStore();

    // Data Members for Class Attributes

      //## Attribute: Ativo
      //	Disparado quando o datastore está conectado ao banco.
      //## begin IBDataStore::Ativo.attr preserve=no  public: static TypeEvento {V} "IBDataStore::Ativo"
      static TypeEvento Ativo;
      //## end IBDataStore::Ativo.attr

      //## Attribute: Inativo
      //	Disparado quando o datastore está desconectado do banco
      //	de dados.
      //## begin IBDataStore::Inativo.attr preserve=no  public: static TypeEvento {V} "IBDataStore::Inativo"
      static TypeEvento Inativo;
      //## end IBDataStore::Inativo.attr

      //## Attribute: Revisado
      //	Disparado quando o datastore sofre uma revisão.
      //## begin IBDataStore::Revisado.attr preserve=no  public: static TypeEvento {V} "IBDataStore::Revisado"
      static TypeEvento Revisado;
      //## end IBDataStore::Revisado.attr

    // Additional Public Declarations
      //## begin IBDataStore.public preserve=yes
      //## end IBDataStore.public


  protected:
    // Additional Protected Declarations
      //## begin IBDataStore.protected preserve=yes
      //## end IBDataStore.protected


  private:
    // Additional Private Declarations
      //## begin IBDataStore.private preserve=yes
      //## end IBDataStore.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin IBDataStore.implementation preserve=yes
      //## end IBDataStore.implementation

};



//## Class: IQuandoEventoClosure
//	é apenas
//	typedef void (__closure *IQuandoEventoClosure ) (
//	IEventoNotificacaoBuilder& );
//	somente para simplificar os tipos.
//## Category: I++ para CBuilder
//## Subsystem: I++ para CBuilder
//## Persistence: Transient
//## Cardinality/Multiplicity: n


typedef void (__closure *  IQuandoEventoClosure) ( IEventoNotificacaoBuilder& );


//## Class: INotificadorIndireto
//## Category: I++ para CBuilder
//## Subsystem: I++ para CBuilder
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class INotificadorIndireto : public IComponente  //## Inherits: <unnamed>

{
  //## begin INotificadorIndireto.initialDeclarations preserve=yes
  //## end INotificadorIndireto.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: INotificadorIndireto%960436829
      INotificadorIndireto(TComponent* Dono);

      //## Operation: INotificadorIndireto%960345881
      //	o evento closure é obrigatório, caso contrário não
      //	existe necessidade de utilizar esta classe. o evento
      //	closure é o meio de comunicação com o dono (agregando).
      //	ESTRANHAMENTE ESTE CONSTRUTOR NÃO É 'VISTO' PELO
      //	COMPILADOR !
      //	**PESQUISAR**
      INotificadorIndireto(TComponent* Dono, IQuandoEventoClosure pClosure);

    //## Destructor (generated)
      ~INotificadorIndireto();

    //## Get and Set Operations for Has Relationships (generated)

      //## Documentation INotificadorIndireto::QuandoEvento.has
      //	Ponteiro closure chamado durante o método
      //	quandoEventoNotificacao. É utilizado quando o IComponent
      //	é usado como agregado, para que o Agregando possa
      //	indicar um método a ser chamado quando um evento
      //	ocorrer, o método deve ter a assinatura de
      //	IQuandoEventoClosure
      const IQuandoEventoClosure getQuandoEvento() const;
      void setQuandoEvento(const IQuandoEventoClosure value);

    // Data Members for Class Attributes

      //## Attribute: FazerRevisao
      //	Será disparado no método fazerRevisão.
      //## begin INotificadorIndireto::FazerRevisao.attr preserve=no  public: static TypeEvento {V} "INotificadorIndireto::FazerRevisao"
      static TypeEvento FazerRevisao;
      //## end INotificadorIndireto::FazerRevisao.attr

    // Additional Public Declarations
      //## begin INotificadorIndireto.public preserve=yes
      //## end INotificadorIndireto.public


  protected:

    //## Other Operations (specified)
      //## Operation: quandoEventoNotificacao%907215653
      //	este método será chamado toda vez que um evento checar
      //	ao Observador. o ponteiro 'closure' para função membro
      //	QuandoEvento deve ter sido preenchido pelo agregando e
      //	será chamado neste método ( logicamente se estiver
      //	preenchido ).
      //	um exemplo de código seria:
      //	if (
      //	evento.notificador.nomeClasse()=="IBDataStoreJasmim" )
      //	  if ( evento.evento==IBDataStoreJasmim::evtDesligado )
      //	     // faça algo
      virtual IComponente* quandoEventoNotificacao(IEventoNotificacaoBuilder& evento);

    // Data Members for Has Relationships

      //## begin INotificadorIndireto::QuandoEvento.has preserve=no  public: IQuandoEventoClosure { -> 1VO}
      IQuandoEventoClosure m_QuandoEvento;
      //## end INotificadorIndireto::QuandoEvento.has

    // Additional Protected Declarations
      //## begin INotificadorIndireto.protected preserve=yes
      //## end INotificadorIndireto.protected


  private:

    //## Other Operations (specified)
      //## Operation: fazerRevisao%960345883
      void fazerRevisao();

    // Additional Private Declarations
      //## begin INotificadorIndireto.private preserve=yes
      //## end INotificadorIndireto.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin INotificadorIndireto.implementation preserve=yes
#pragma option pop
#undef class
      //## end INotificadorIndireto.implementation

};



// Class IComponente 





// Class Utility IBUtilitaria 





// Class INotificadorIndireto 





// Class IEventoNotificacaoBuilder 





// Class IBDataStore 





// Class IQuandoEventoClosure 





#endif


