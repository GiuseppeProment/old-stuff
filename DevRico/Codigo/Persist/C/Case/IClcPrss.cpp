//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IColecaoPersistenteBase; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: g:\devrico\codigo\persist\c\case\iclcprss.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IColecaoPersistenteBase
#include "IClcPrss.h"
// IPersistente
#include "IPrsstnt.h"
// IOrdem
#include "IOrdem.h"
// ICriterio
#include "ICritrio.h"
// IDataStore
#include "IDtStore.h"
// IBroker
#include "IBroker.h"

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class IColecaoPersistenteBase 







IColecaoPersistenteBase::IColecaoPersistenteBase()
  //## begin IColecaoPersistenteBase::IColecaoPersistenteBase%.hasinit preserve=no
  //## end IColecaoPersistenteBase::IColecaoPersistenteBase%.hasinit
  //## begin IColecaoPersistenteBase::IColecaoPersistenteBase%.initialization preserve=yes
  //## end IColecaoPersistenteBase::IColecaoPersistenteBase%.initialization
{
  //## begin IColecaoPersistenteBase::IColecaoPersistenteBase%.body preserve=yes
	m_InstanciaCorrente = NULL;
   setestado(nova);
  //## end IColecaoPersistenteBase::IColecaoPersistenteBase%.body
}

IColecaoPersistenteBase::IColecaoPersistenteBase(const IColecaoPersistenteBase &right)
  //## begin IColecaoPersistenteBase::IColecaoPersistenteBase%copy.hasinit preserve=no
  //## end IColecaoPersistenteBase::IColecaoPersistenteBase%copy.hasinit
  //## begin IColecaoPersistenteBase::IColecaoPersistenteBase%copy.initialization preserve=yes
  //## end IColecaoPersistenteBase::IColecaoPersistenteBase%copy.initialization
{
  //## begin IColecaoPersistenteBase::IColecaoPersistenteBase%copy.body preserve=yes
  //## end IColecaoPersistenteBase::IColecaoPersistenteBase%copy.body
}


IColecaoPersistenteBase::~IColecaoPersistenteBase()
{
  //## begin IColecaoPersistenteBase::~IColecaoPersistenteBase%.body preserve=yes
	setestado(terminada);
	if (m_InstanciaCorrente != NULL) delete m_InstanciaCorrente;
  //## end IColecaoPersistenteBase::~IColecaoPersistenteBase%.body
}



//## Other Operations (implementation)
int IColecaoPersistenteBase::count()
{
  int Contagem;

  //## begin IColecaoPersistenteBase::count%908340284.body preserve=yes
  Contagem=0;
  //## end IColecaoPersistenteBase::count%908340284.body

  return Contagem;
}

bool IColecaoPersistenteBase::isFim()
{
  bool Final;

  //## begin IColecaoPersistenteBase::isFim%908340285.body preserve=yes
  return m_theQuery.isFim();
  //## end IColecaoPersistenteBase::isFim%908340285.body

  return Final;
}

IColecaoPersistenteBase& IColecaoPersistenteBase::pronto()
{
  //## begin IColecaoPersistenteBase::pronto%908340283.body preserve=yes
	IBroker::processeColecao( *this );
	setestado( pronta );
  //## end IColecaoPersistenteBase::pronto%908340283.body

  return *this;
}

IColecaoPersistenteBase& IColecaoPersistenteBase::goPrimeiro()
{
  //## begin IColecaoPersistenteBase::goPrimeiro%908340286.body preserve=yes
	movePointer(primeiro);
  //## end IColecaoPersistenteBase::goPrimeiro%908340286.body

  return *this;
}

IColecaoPersistenteBase& IColecaoPersistenteBase::goUltimo()
{
  //## begin IColecaoPersistenteBase::goUltimo%908340287.body preserve=yes
	movePointer(ultimo);
  //## end IColecaoPersistenteBase::goUltimo%908340287.body

  return *this;
}

IColecaoPersistenteBase& IColecaoPersistenteBase::goProximo()
{
  //## begin IColecaoPersistenteBase::goProximo%908340288.body preserve=yes
	movePointer(proximo);
  //## end IColecaoPersistenteBase::goProximo%908340288.body

  return *this;
}

IColecaoPersistenteBase& IColecaoPersistenteBase::goAnterior()
{
  //## begin IColecaoPersistenteBase::goAnterior%908340289.body preserve=yes
	movePointer(previo);
  //## end IColecaoPersistenteBase::goAnterior%908340289.body

  return *this;
}

IColecaoPersistenteBase& IColecaoPersistenteBase::ReavalieColecao()
{
  //## begin IColecaoPersistenteBase::ReavalieColecao%908340290.body preserve=yes
  //## end IColecaoPersistenteBase::ReavalieColecao%908340290.body

  return *this;
}

IColecaoPersistenteBase& IColecaoPersistenteBase::ReavaliePointer()
{
  //## begin IColecaoPersistenteBase::ReavaliePointer%908340291.body preserve=yes
	movePointer(reavalia);
  //## end IColecaoPersistenteBase::ReavaliePointer%908340291.body

  return *this;
}

IColecaoPersistenteBase& IColecaoPersistenteBase::movePointer(IDirecaoFetch direcao)
{
  //## begin IColecaoPersistenteBase::movePointer%908340293.body preserve=yes
	IBroker::requisitaObjeto(*this, direcao);
  //## end IColecaoPersistenteBase::movePointer%908340293.body

  return *this;
}

IColecaoPersistenteBase& IColecaoPersistenteBase::addCriterio(ICriterio umCriterio)
{
  //## begin IColecaoPersistenteBase::addCriterio%908581620.body preserve=yes
  //## end IColecaoPersistenteBase::addCriterio%908581620.body

  return *this;
}

IColecaoPersistenteBase& IColecaoPersistenteBase::addOrdem(IOrdem umaOrdem)
{
  //## begin IColecaoPersistenteBase::addOrdem%908581621.body preserve=yes
  //## end IColecaoPersistenteBase::addOrdem%908581621.body

  return *this;
}

IPersistente& IColecaoPersistenteBase::crieInstancia()
{
  //## begin IColecaoPersistenteBase::crieInstancia%908340292.body preserve=yes
	throw(IErro("IColecaoPersistenteBase:crieInstancia virtual nao redefinida"));
	return *(IPersistente*)0; // NUNCA CHEGARA AQUI.
  //## end IColecaoPersistenteBase::crieInstancia%908340292.body
}

//## Get and Set Operations for Has Relationships (implementation)

IDataStore * IColecaoPersistenteBase::theDataStore()
{
  //## begin IColecaoPersistenteBase::theDataStore%.get preserve=no
  return m_theDataStore;
  //## end IColecaoPersistenteBase::theDataStore%.get
}

void IColecaoPersistenteBase::settheDataStore(IDataStore *const  value)
{
  //## begin IColecaoPersistenteBase::settheDataStore%.set preserve=no
  m_theDataStore = value;
  //## end IColecaoPersistenteBase::settheDataStore%.set
}

IQueryStatement & IColecaoPersistenteBase::theQuery()
{
  //## begin IColecaoPersistenteBase::theQuery%.get preserve=no
  return m_theQuery;
  //## end IColecaoPersistenteBase::theQuery%.get
}

void IColecaoPersistenteBase::settheQuery(const IQueryStatement &value)
{
  //## begin IColecaoPersistenteBase::settheQuery%.set preserve=no
  m_theQuery = value;
  //## end IColecaoPersistenteBase::settheQuery%.set
}

IEstadoColecao IColecaoPersistenteBase::estado()
{
  //## begin IColecaoPersistenteBase::estado%.get preserve=no
  return m_estado;
  //## end IColecaoPersistenteBase::estado%.get
}

void IColecaoPersistenteBase::setestado(const IEstadoColecao value)
{
  //## begin IColecaoPersistenteBase::setestado%.set preserve=no
  m_estado = value;
  //## end IColecaoPersistenteBase::setestado%.set
}

Lista<ICriterio> & IColecaoPersistenteBase::ListaCriterio()
{
  //## begin IColecaoPersistenteBase::ListaCriterio%.get preserve=no
  return m_ListaCriterio;
  //## end IColecaoPersistenteBase::ListaCriterio%.get
}

Lista<IOrdem> & IColecaoPersistenteBase::ListaOrdem()
{
  //## begin IColecaoPersistenteBase::ListaOrdem%.get preserve=no
  return m_ListaOrdem;
  //## end IColecaoPersistenteBase::ListaOrdem%.get
}

//## Get and Set Operations for Class Attributes (implementation)

IPersistente * IColecaoPersistenteBase::InstanciaCorrente()
{
  //## begin IColecaoPersistenteBase::InstanciaCorrente%.get preserve=no
  return m_InstanciaCorrente;
  //## end IColecaoPersistenteBase::InstanciaCorrente%.get
}


// Additional Declarations
//## begin IColecaoPersistenteBase.declarations preserve=yes
//## end IColecaoPersistenteBase.declarations




