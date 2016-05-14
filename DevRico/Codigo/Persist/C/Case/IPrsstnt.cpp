//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IPersistente; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: g:\devrico\codigo\persist\c\case\iprsstnt.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IClassMap
#include "IClssMap.h"
// IMapClassTable
#include "IMpClssT.h"
// IEventoNotificacao
#include "IvntNtfc.h"
// IBroker
#include "IBroker.h"
// IPersistente
#include "IPrsstnt.h"

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class IPersistente 




//## begin IPersistente::evtSalvando.attr preserve=no  public: static TypeEvento {V} "IPersistente::Salvando"
TypeEvento IPersistente::evtSalvando = "IPersistente::Salvando";
//## end IPersistente::evtSalvando.attr


IPersistente::IPersistente()
  //## begin IPersistente::IPersistente%.hasinit preserve=no
      : m_isPersistido(false), m_isProxy(false)
  //## end IPersistente::IPersistente%.hasinit
  //## begin IPersistente::IPersistente%.initialization preserve=yes
  //## end IPersistente::IPersistente%.initialization
{
  //## begin IPersistente::IPersistente%.body preserve=yes
  //## end IPersistente::IPersistente%.body
}

IPersistente::IPersistente(const IPersistente &right)
  //## begin IPersistente::IPersistente%copy.hasinit preserve=no
      : m_isPersistido(false), m_isProxy(false)
  //## end IPersistente::IPersistente%copy.hasinit
  //## begin IPersistente::IPersistente%copy.initialization preserve=yes
  //## end IPersistente::IPersistente%copy.initialization
{
  //## begin IPersistente::IPersistente%copy.body preserve=yes
	m_ID = right.m_ID; 
	m_isPersistido = right.m_isPersistido;
	m_isProxy = right.m_isProxy;
  //## end IPersistente::IPersistente%copy.body
}


IPersistente::~IPersistente()
{
  //## begin IPersistente::~IPersistente%.body preserve=yes
  //## end IPersistente::~IPersistente%.body
}



//## Other Operations (implementation)
void IPersistente::save()
{
  //## begin IPersistente::save%906522273.body preserve=yes

  notificarObservadores(
    IEventoNotificacao( *this,IPersistente::evtSalvando )
    );

  IBroker::saveMe(*this);

  //## end IPersistente::save%906522273.body
}

void IPersistente::erase()
{
  //## begin IPersistente::erase%906522274.body preserve=yes

  //:-| falta Notificacao.
  IBroker::deleteMe(*this);

  //## end IPersistente::erase%906522274.body
}

char* IPersistente::getNomeClasse()
{
  //## begin IPersistente::getNomeClasse%906522275.body preserve=yes
  throw(
    IErro("funcao-membro IPersistente::getNomeClasse nao foi redefinida.")
    );
  //## end IPersistente::getNomeClasse%906522275.body

  return "Disparar Excessao";
}

IPersistente& IPersistente::registraMembro(char* nomeMembro, unsigned int offSet, unsigned int tamanho, IKnowType tipoMembro, unsigned int varSizeMax, bool isProxy)
{
  //## begin IPersistente::registraMembro%908414768.body preserve=yes
  IClassMap::registraMembroClasse(
    *this,
    nomeMembro,
    offSet,
    tamanho,
    tipoMembro,
    varSizeMax,
    isProxy);
  //## end IPersistente::registraMembro%908414768.body

  return *this;
}

void IPersistente::OnClassInfo()
{
  //## begin IPersistente::OnClassInfo%908414767.body preserve=yes
  /*-----------------21/10/98 18:12-------------------
  Use registraMembro( ADI( classe, membro) [,tipo,varSizeMax,isProxy] )
  para cada membro.
  --------------------------------------------------*/
  throw(
    IErro("funcao-membro IPersistente::OnClassInfo nao foi redefinida.")
    );
  //## end IPersistente::OnClassInfo%908414767.body
}

IString IPersistente::getCampoPorNome(char* campo)
{
  //## begin IPersistente::getCampoPorNome%958376567.body preserve=yes

  IString retorno;

  // pega o mapa para eu proprio
  IMapClassTable& mapa =
		IClassMap::getMapaFor( *this );

  // procura pelo campo
  for (int i=1; i<=mapa.ListaAtributos().count(); i++ )
  {
    if (mapa.ListaAtributos()[i]->nomeMembro()==campo)
      { retorno =
          mapa.ListaAtributos()[i]->asString( *this );
        break;
      }
  }
  // se não achou vai retornar vazio
  return retorno;
  //## end IPersistente::getCampoPorNome%958376567.body
}

IString IPersistente::getCampoPorIndice(int indice)
{
  //## begin IPersistente::getCampoPorIndice%958376568.body preserve=yes

  IString retorno;

  // pega o mapa para eu proprio
  IMapClassTable& mapa =
		IClassMap::getMapaFor( *this );

  // consiste o indice
  if (indice > 0 && indice <=mapa.ListaAtributos().count())
    retorno =
      mapa.ListaAtributos()[indice]->asString( *this );
  // se indice invalido vai retornar vazio
  return retorno;
  //## end IPersistente::getCampoPorIndice%958376568.body
}

int IPersistente::quantosCampos()
{
  //## begin IPersistente::quantosCampos%958376569.body preserve=yes
  // pega o mapa para eu proprio
  IMapClassTable& mapa =
		IClassMap::getMapaFor( *this );
  // obvious abaixo
  return mapa.ListaAtributos().count();
  //## end IPersistente::quantosCampos%958376569.body
}

//## Get and Set Operations for Has Relationships (implementation)

IPersistID IPersistente::ID()
{
  //## begin IPersistente::ID%.get preserve=no
  return m_ID;
  //## end IPersistente::ID%.get
}

void IPersistente::setID(const IPersistID value)
{
  //## begin IPersistente::setID%.set preserve=no
  m_ID = value;
  //## end IPersistente::setID%.set
}

//## Get and Set Operations for Class Attributes (implementation)

bool IPersistente::isPersistido()
{
  //## begin IPersistente::isPersistido%.get preserve=no
  return m_isPersistido;
  //## end IPersistente::isPersistido%.get
}

void IPersistente::setisPersistido(const bool value)
{
  //## begin IPersistente::setisPersistido%.set preserve=no
  m_isPersistido = value;
  //## end IPersistente::setisPersistido%.set
}

bool IPersistente::isProxy()
{
  //## begin IPersistente::isProxy%.get preserve=no
  return m_isProxy;
  //## end IPersistente::isProxy%.get
}

void IPersistente::setisProxy(const bool value)
{
  //## begin IPersistente::setisProxy%.set preserve=no
  m_isProxy = value;
  //## end IPersistente::setisProxy%.set
}


// Additional Declarations
//## begin IPersistente.declarations preserve=yes
//## end IPersistente.declarations




