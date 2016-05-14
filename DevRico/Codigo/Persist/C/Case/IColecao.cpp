//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IColecao; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: c:\devrico\codigo\persist\c\case\icolecao.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IColecao
#include "IColecao.h"
// IPersistente
#include "IPrsstnt.h"

//## begin module.additionalDeclarations preserve=yes
//#pragma package(smart_init)
//## end module.additionalDeclarations


// Parameterized Class IColecao 


template <class PersistenteSubClass>
IColecao<PersistenteSubClass>::IColecao()
  //## begin IColecao::IColecao%.hasinit preserve=no
  //## end IColecao::IColecao%.hasinit
  //## begin IColecao::IColecao%.initialization preserve=yes
  //## end IColecao::IColecao%.initialization
{
  //## begin IColecao::IColecao%.body preserve=yes
  IBroker::newColecao(*this);
  //## end IColecao::IColecao%.body
}

template <class PersistenteSubClass>
IColecao<PersistenteSubClass>::IColecao(const IColecao<PersistenteSubClass> &right)
  //## begin IColecao::IColecao%copy.hasinit preserve=no
  //## end IColecao::IColecao%copy.hasinit
  //## begin IColecao::IColecao%copy.initialization preserve=yes
  //## end IColecao::IColecao%copy.initialization
{
  //## begin IColecao::IColecao%copy.body preserve=yes
  //## end IColecao::IColecao%copy.body
}


template <class PersistenteSubClass>
IColecao<PersistenteSubClass>::~IColecao()
{
  //## begin IColecao::~IColecao%.body preserve=yes
  IBroker::libereColecao(*this);
  //## end IColecao::~IColecao%.body
}



//## Other Operations (implementation)
template <class PersistenteSubClass>
IPersistente* IColecao<PersistenteSubClass>::createDummy()
{
  //## begin IColecao::createDummy%908340282.body preserve=yes
  PersistenteSubClass *ptr = new PersistenteSubClass();
	return ptr;
  //## end IColecao::createDummy%908340282.body
}

template <class PersistenteSubClass>
void IColecao<PersistenteSubClass>::releaseDummy(IPersistente* pNulo)
{
  //## begin IColecao::releaseDummy%910837610.body preserve=yes
  delete pNulo;
  //## end IColecao::releaseDummy%910837610.body
}

template <class PersistenteSubClass>
PersistenteSubClass* IColecao<PersistenteSubClass>::ObjectPointer()
{
  //## begin IColecao::ObjectPointer%908407234.body preserve=yes
  return (PersistenteSubClass*) m_InstanciaCorrente;
  //## end IColecao::ObjectPointer%908407234.body
}

template <class PersistenteSubClass>
PersistenteSubClass& IColecao<PersistenteSubClass>::ObjectRef()
{
  //## begin IColecao::ObjectRef%908407233.body preserve=yes
  return *((PersistenteSubClass*) m_InstanciaCorrente);
  //## end IColecao::ObjectRef%908407233.body
}

template <class PersistenteSubClass>
PersistenteSubClass IColecao<PersistenteSubClass>::ObjectCopy()
{
  //## begin IColecao::ObjectCopy%908340294.body preserve=yes
  return *((PersistenteSubClass*) m_InstanciaCorrente);
  //## end IColecao::ObjectCopy%908340294.body
}

template <class PersistenteSubClass>
IPersistente& IColecao<PersistenteSubClass>::crieInstancia()
{
  //## begin IColecao::crieInstancia%908340292.body preserve=yes
  if (m_InstanciaCorrente != NULL) delete m_InstanciaCorrente;
	m_InstanciaCorrente = new PersistenteSubClass();
	return *m_InstanciaCorrente;
  //## end IColecao::crieInstancia%908340292.body
}


// Additional Declarations
//## begin IColecao.declarations preserve=yes
//## end IColecao.declarations




