//## begin module.cm preserve=no
//	Código adequado para CBuilder (Componente)
//## end module.cm

//## begin module.cp preserve=no
//	(c) 2000 Giuseppe E. Proment Jr.
//## end module.cp

//## Module: IComponent; Package body
//## Subsystem: I++ para CBuilder
//## Source file: c:\devrico\codigo\persist\comp_c\icompo~1.cpp


//## begin module.additionalIncludes preserve=no
#include <vcl.h>
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#pragma hdrstop
//## end module.includes

// IComponent
#include "ICompo~1.h"

//## begin module.declarations preserve=no
#pragma option push -pr
#pragma package(smart_init)

// teste
static inline void ValidCtrCheck(INotificadorIndireto *)
{
  new INotificadorIndireto(NULL);
}
//-------------------------------------------------------
namespace Icomponent
{
  void __fastcall PACKAGE Register()
  {
     TComponentClass classes[1] = {__classid(INotificadorIndireto)};
     RegisterComponents("I++", classes, 0);
  }
}
//-------------------------------------------------------

//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


// Class IComponente 





//## begin IComponente::Default.attr preserve=no  public: static TypeEvento {V} "IComponente::Default"
TypeEvento IComponente::Default = "IComponente::Default";
//## end IComponente::Default.attr

IComponente::IComponente(TComponent* Owner)
  //## begin IComponente::IComponente%959306784.hasinit preserve=no
      : m_Pronto(false), m_notificarObservadores(true), m_nomeClasse("IComponente")
  //## end IComponente::IComponente%959306784.hasinit
  //## begin IComponente::IComponente%959306784.initialization preserve=yes
      ,TComponent( Owner )
  //## end IComponente::IComponente%959306784.initialization
{
  //## begin IComponente::IComponente%959306784.body preserve=yes
  //## end IComponente::IComponente%959306784.body
}


IComponente::~IComponente()
{
  //## begin IComponente::~IComponente%.body preserve=yes
  //## end IComponente::~IComponente%.body
}



//## Other Operations (implementation)
void IComponente::Loaded()
{
  //## begin IComponente::Loaded%959306787.body preserve=yes

  TComponent::Loaded();
  if ( ! IsPronto )
  {
    throw Exception("Componente nÆo pronto"); //nativa do CppBuilder
  }
  // "passos para inicialização em cascata"
  // 1. verifica this->IsPronto
  //    se retornar false, é merda
  //    dispara excessão IErro
  //    throw Exception("erro sei la do que") nativa do CppBuilder
  //    throw IErro("erro sei la do que")     nativa da IFrameWork
  //## end IComponente::Loaded%959306787.body
}

void IComponente::WriteState(TWriter* Writer)
{
  //## begin IComponente::WriteState%959306788.body preserve=yes
  TComponent::WriteState(Writer);
  //## end IComponente::WriteState%959306788.body
}

IComponente* IComponente::ligaNotificarObservadores()
{
  //## begin IComponente::ligaNotificarObservadores%907215654.body preserve=yes
  m_notificarObservadores = true;
  return this;
  //## end IComponente::ligaNotificarObservadores%907215654.body
}

IComponente* IComponente::desligaNotificarObservadores()
{
  //## begin IComponente::desligaNotificarObservadores%907215655.body preserve=yes
  m_notificarObservadores = false;
  return this;
  //## end IComponente::desligaNotificarObservadores%907215655.body
}

IComponente* IComponente::NotificarEventosPara(IComponente* Observador)
{
  //## begin IComponente::NotificarEventosPara%907215656.body preserve=yes
  // checa se já existe
  if ( m_Observadores.posicaoDe( Observador )==-1)
    m_Observadores.adiciona( Observador );
  return this;
  //## end IComponente::NotificarEventosPara%907215656.body
}

IComponente* IComponente::notificarObservadores(IEventoNotificacaoBuilder& evento)
{
  //## begin IComponente::notificarObservadores%907215657.body preserve=yes
  for (int i=1; i<=m_Observadores.count(); i++ )
  {
    m_Observadores[i]->quandoEventoNotificacao(evento);
  }
  return this;
  //## end IComponente::notificarObservadores%907215657.body
}

IComponente* IComponente::PararNotificarEventosPara(IComponente* Observador)
{
  //## begin IComponente::PararNotificarEventosPara%908414770.body preserve=yes
  m_Observadores.removeObjeto( Observador );
	return this;
  //## end IComponente::PararNotificarEventosPara%908414770.body
}

IComponente* IComponente::quandoEventoNotificacao(IEventoNotificacaoBuilder& evento)
{
  //## begin IComponente::quandoEventoNotificacao%907215653.body preserve=yes

  // >>> codigo de rea‡Æo ao evento aqui <<<

  return this;
  //## end IComponente::quandoEventoNotificacao%907215653.body
}

bool IComponente::getPronto()
{
  //## begin IComponente::getPronto%959735967.body preserve=yes

  if ( m_Pronto != true )
  {
    // O loaded abaixo retira o csLoading do estado do componente
    // deve ser feito aqui pois caso contrário, se algum outro
    // componente fizer a chamada a IsPronto vamos entrar em
    // fazerRevisao em estado csLoading o que vai dar merda
    TComponent::Loaded();
    fazerRevisao();
  }
  m_Pronto = true;
  return m_Pronto;

  //## end IComponente::getPronto%959735967.body
}

//## Get and Set Operations for Class Attributes (implementation)

const IString IComponente::getnomeClasse() const
{
  //## begin IComponente::getnomeClasse%.get preserve=no
  return m_nomeClasse;
  //## end IComponente::getnomeClasse%.get
}

void IComponente::setnomeClasse(const IString value)
{
  //## begin IComponente::setnomeClasse%.set preserve=no
  m_nomeClasse = value;
  //## end IComponente::setnomeClasse%.set
}


// Additional Declarations
//## begin IComponente.declarations preserve=yes
//## end IComponente.declarations


// Class Utility IBUtilitaria 


//## Other Operations (implementation)
void IBUtilitaria::mensagemUsuario(char* texto)
{
  //## begin IBUtilitaria::mensagemUsuario%959826780.body preserve=yes
  Application->MessageBox(texto,"Condição Inválida", MB_OK);
  //## end IBUtilitaria::mensagemUsuario%959826780.body
}

void IBUtilitaria::inicioOperacaoLenta()
{
  //## begin IBUtilitaria::inicioOperacaoLenta%959826781.body preserve=yes
  Screen->Cursor = crSQLWait;
  //## end IBUtilitaria::inicioOperacaoLenta%959826781.body
}

void IBUtilitaria::finalOperacaoLenta()
{
  //## begin IBUtilitaria::finalOperacaoLenta%959826782.body preserve=yes
  Screen->Cursor = crDefault;
  //## end IBUtilitaria::finalOperacaoLenta%959826782.body
}


// Additional Declarations
//## begin IBUtilitaria.declarations preserve=yes
//## end IBUtilitaria.declarations


// Class INotificadorIndireto 


//## begin INotificadorIndireto::FazerRevisao.attr preserve=no  public: static TypeEvento {V} "INotificadorIndireto::FazerRevisao"
TypeEvento INotificadorIndireto::FazerRevisao = "INotificadorIndireto::FazerRevisao";
//## end INotificadorIndireto::FazerRevisao.attr

INotificadorIndireto::INotificadorIndireto(TComponent* Dono)
  //## begin INotificadorIndireto::INotificadorIndireto%960436829.hasinit preserve=no
  //## end INotificadorIndireto::INotificadorIndireto%960436829.hasinit
  //## begin INotificadorIndireto::INotificadorIndireto%960436829.initialization preserve=yes
  :IComponente( Dono )
  //## end INotificadorIndireto::INotificadorIndireto%960436829.initialization
{
  //## begin INotificadorIndireto::INotificadorIndireto%960436829.body preserve=yes
  //## end INotificadorIndireto::INotificadorIndireto%960436829.body
}

INotificadorIndireto::INotificadorIndireto(TComponent* Dono, IQuandoEventoClosure pClosure)
  //## begin INotificadorIndireto::INotificadorIndireto%960345881.hasinit preserve=no
  //## end INotificadorIndireto::INotificadorIndireto%960345881.hasinit
  //## begin INotificadorIndireto::INotificadorIndireto%960345881.initialization preserve=yes
  :IComponente( Dono )
  //## end INotificadorIndireto::INotificadorIndireto%960345881.initialization
{
  //## begin INotificadorIndireto::INotificadorIndireto%960345881.body preserve=yes
  setQuandoEvento(pClosure);
  //## end INotificadorIndireto::INotificadorIndireto%960345881.body
}


INotificadorIndireto::~INotificadorIndireto()
{
  //## begin INotificadorIndireto::~INotificadorIndireto%.body preserve=yes
  //## end INotificadorIndireto::~INotificadorIndireto%.body
}



//## Other Operations (implementation)
IComponente* INotificadorIndireto::quandoEventoNotificacao(IEventoNotificacaoBuilder& evento)
{
  //## begin INotificadorIndireto::quandoEventoNotificacao%907215653.body preserve=yes
  if ( m_QuandoEvento != NULL )
  {
    m_QuandoEvento( evento );
  }
  return this;
  //## end INotificadorIndireto::quandoEventoNotificacao%907215653.body
}

void INotificadorIndireto::fazerRevisao()
{
  //## begin INotificadorIndireto::fazerRevisao%960345883.body preserve=yes
  // teste
  IBUtilitaria::mensagemUsuario("INotificadorIndireto::fazerRevisao;foi chamado");
  // manda um evento para s¡ pr¢prio, que vai chegar at‚ dono
  quandoEventoNotificacao(
    IEventoNotificacaoBuilder( this,
                        INotificadorIndireto::FazerRevisao )  );
  //## end INotificadorIndireto::fazerRevisao%960345883.body
}

//## Get and Set Operations for Has Relationships (implementation)

const IQuandoEventoClosure INotificadorIndireto::getQuandoEvento() const
{
  //## begin INotificadorIndireto::getQuandoEvento%.get preserve=no
  return m_QuandoEvento;
  //## end INotificadorIndireto::getQuandoEvento%.get
}

void INotificadorIndireto::setQuandoEvento(const IQuandoEventoClosure value)
{
  //## begin INotificadorIndireto::setQuandoEvento%.set preserve=no
  m_QuandoEvento = value;
  //## end INotificadorIndireto::setQuandoEvento%.set
}


// Additional Declarations
//## begin INotificadorIndireto.declarations preserve=yes
//## end INotificadorIndireto.declarations


// Class IEventoNotificacaoBuilder 



//## begin IEventoNotificacaoBuilder::Default.attr preserve=no  public: static TypeEvento {V} "IEventoNotificacaoBuilder::Default"
TypeEvento IEventoNotificacaoBuilder::Default = "IEventoNotificacaoBuilder::Default";
//## end IEventoNotificacaoBuilder::Default.attr

IEventoNotificacaoBuilder::IEventoNotificacaoBuilder(const IEventoNotificacaoBuilder &right)
  //## begin IEventoNotificacaoBuilder::IEventoNotificacaoBuilder%copy.hasinit preserve=no
  //## end IEventoNotificacaoBuilder::IEventoNotificacaoBuilder%copy.hasinit
  //## begin IEventoNotificacaoBuilder::IEventoNotificacaoBuilder%copy.initialization preserve=yes
  //## end IEventoNotificacaoBuilder::IEventoNotificacaoBuilder%copy.initialization
{
  //## begin IEventoNotificacaoBuilder::IEventoNotificacaoBuilder%copy.body preserve=yes
  evento = right.evento;
  m_Notificador = right.getNotificador();
  //## end IEventoNotificacaoBuilder::IEventoNotificacaoBuilder%copy.body
}

IEventoNotificacaoBuilder::IEventoNotificacaoBuilder(IComponente* notificador, TypeEvento evento)
  //## begin IEventoNotificacaoBuilder::IEventoNotificacaoBuilder%909098948.hasinit preserve=no
  //## end IEventoNotificacaoBuilder::IEventoNotificacaoBuilder%909098948.hasinit
  //## begin IEventoNotificacaoBuilder::IEventoNotificacaoBuilder%909098948.initialization preserve=yes
  //## end IEventoNotificacaoBuilder::IEventoNotificacaoBuilder%909098948.initialization
{
  //## begin IEventoNotificacaoBuilder::IEventoNotificacaoBuilder%909098948.body preserve=yes
  m_Notificador = notificador;
  this->evento = evento;
  //## end IEventoNotificacaoBuilder::IEventoNotificacaoBuilder%909098948.body
}

IEventoNotificacaoBuilder::IEventoNotificacaoBuilder()
  //## begin IEventoNotificacaoBuilder::IEventoNotificacaoBuilder%909098950.hasinit preserve=no
  //## end IEventoNotificacaoBuilder::IEventoNotificacaoBuilder%909098950.hasinit
  //## begin IEventoNotificacaoBuilder::IEventoNotificacaoBuilder%909098950.initialization preserve=yes
  //## end IEventoNotificacaoBuilder::IEventoNotificacaoBuilder%909098950.initialization
{
  //## begin IEventoNotificacaoBuilder::IEventoNotificacaoBuilder%909098950.body preserve=yes
  m_Notificador = NULL;
  //## end IEventoNotificacaoBuilder::IEventoNotificacaoBuilder%909098950.body
}


IEventoNotificacaoBuilder::~IEventoNotificacaoBuilder()
{
  //## begin IEventoNotificacaoBuilder::~IEventoNotificacaoBuilder%.body preserve=yes
  //## end IEventoNotificacaoBuilder::~IEventoNotificacaoBuilder%.body
}


//## Get and Set Operations for Has Relationships (implementation)

IComponente * IEventoNotificacaoBuilder::getNotificador()
{
  //## begin IEventoNotificacaoBuilder::getNotificador%.get preserve=no
  return m_Notificador;
  //## end IEventoNotificacaoBuilder::getNotificador%.get
}

void IEventoNotificacaoBuilder::setNotificador(IComponente *const  value)
{
  //## begin IEventoNotificacaoBuilder::setNotificador%.set preserve=no
  m_Notificador = value;
  //## end IEventoNotificacaoBuilder::setNotificador%.set
}


// Additional Declarations
//## begin IEventoNotificacaoBuilder.declarations preserve=yes
//## end IEventoNotificacaoBuilder.declarations


// Class IBDataStore 

//## begin IBDataStore::Ativo.attr preserve=no  public: static TypeEvento {V} "IBDataStore::Ativo"
TypeEvento IBDataStore::Ativo = "IBDataStore::Ativo";
//## end IBDataStore::Ativo.attr

//## begin IBDataStore::Inativo.attr preserve=no  public: static TypeEvento {V} "IBDataStore::Inativo"
TypeEvento IBDataStore::Inativo = "IBDataStore::Inativo";
//## end IBDataStore::Inativo.attr

//## begin IBDataStore::Revisado.attr preserve=no  public: static TypeEvento {V} "IBDataStore::Revisado"
TypeEvento IBDataStore::Revisado = "IBDataStore::Revisado";
//## end IBDataStore::Revisado.attr

IBDataStore::IBDataStore(TComponent* Dono)
  //## begin IBDataStore::IBDataStore%960521282.hasinit preserve=no
  //## end IBDataStore::IBDataStore%960521282.hasinit
  //## begin IBDataStore::IBDataStore%960521282.initialization preserve=yes
	:IComponente( Dono )
  //## end IBDataStore::IBDataStore%960521282.initialization
{
  //## begin IBDataStore::IBDataStore%960521282.body preserve=yes
  //## end IBDataStore::IBDataStore%960521282.body
}


IBDataStore::~IBDataStore()
{
  //## begin IBDataStore::~IBDataStore%.body preserve=yes
  //## end IBDataStore::~IBDataStore%.body
}



// Additional Declarations
//## begin IBDataStore.declarations preserve=yes
#pragma option pop
//## end IBDataStore.declarations


// Class IQuandoEventoClosure 





