//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IMapAtrColuna; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\imptrcln.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IPersistente
#include "IPrsstnt.h"
// IMapAtrColuna
#include "IMptrCln.h"

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class IMapAtrColuna









IMapAtrColuna::IMapAtrColuna()
  //## begin IMapAtrColuna::IMapAtrColuna%.hasinit preserve=no
      : m_varSizeMax(0), m_isProxy(false)
  //## end IMapAtrColuna::IMapAtrColuna%.hasinit
  //## begin IMapAtrColuna::IMapAtrColuna%.initialization preserve=yes
  //## end IMapAtrColuna::IMapAtrColuna%.initialization
{
  //## begin IMapAtrColuna::IMapAtrColuna%.body preserve=yes
  //## end IMapAtrColuna::IMapAtrColuna%.body
}

IMapAtrColuna::IMapAtrColuna(const IMapAtrColuna &right)
  //## begin IMapAtrColuna::IMapAtrColuna%copy.hasinit preserve=no
      : m_varSizeMax(0), m_isProxy(false)
  //## end IMapAtrColuna::IMapAtrColuna%copy.hasinit
  //## begin IMapAtrColuna::IMapAtrColuna%copy.initialization preserve=yes
  //## end IMapAtrColuna::IMapAtrColuna%copy.initialization
{
  //## begin IMapAtrColuna::IMapAtrColuna%copy.body preserve=yes
  //## end IMapAtrColuna::IMapAtrColuna%copy.body
}


IMapAtrColuna::~IMapAtrColuna()
{
  //## begin IMapAtrColuna::~IMapAtrColuna%.body preserve=yes
  //## end IMapAtrColuna::~IMapAtrColuna%.body
}



//## Other Operations (implementation)
IString IMapAtrColuna::asString(IPersistente& anPersist)
{
  IString conteudo;

  //## begin IMapAtrColuna::asString%908596383.body preserve=yes
	// teste com int,char[]
	char* pObjeto = (char*) &anPersist;
	switch(m_tipoMembro)
	{
		case IsInt:
			conteudo = *( (int*) (pObjeto+m_offSet));
			break;
		case IsDouble:
      conteudo = *( (double*) (pObjeto+m_offSet));
			break;
		case IsFloat:
      conteudo = *( (float*) (pObjeto+m_offSet));
			break;
		case IsShortInt:
      conteudo = *( (short int*) (pObjeto+m_offSet));
			break;
		case IsChar:
      conteudo += "'";
      conteudo += *( (char*) (pObjeto+m_offSet));
      conteudo += "'";
      break;
    case IsStringVar:
    case IsStringFix:
      conteudo += "'";
      conteudo +=  *( (IString*) (pObjeto+m_offSet));
      conteudo += "'";
      break;
    case IsCharArray:
      conteudo += "'";
      conteudo +=  ( (char*) (pObjeto+m_offSet));
      conteudo += "'";
      break;
		case IsTimestamp:
		case IsStringBlob:
    case IsUnknow:
		// ponteiros
		case IsDoublePointer:
		case IsFloatPointer:
		case IsIntPointer:
		case IsShortIntPointer:
		case IsCharPointer:
		case IsCharArrayPointer:
		case IsTimestampPointer:
		case IsStringBlobPointer:
		case IsStringVarPointer:
		case IsStringFixPointer:
		case IsUnknowPointer:
		default:
			throw(IErro("IMapAtrColuna::asString tipoMembro desconhecido"));
	}

  //## end IMapAtrColuna::asString%908596383.body

  return conteudo;
}

void IMapAtrColuna::setValue(IPersistente& anPersist, char* dado, int copyLen)
{
  //## begin IMapAtrColuna::setValue%908596384.body preserve=yes
	char* pObjeto = (char*) &anPersist;
	switch(m_tipoMembro)
	{
		case IsInt:
			*( (int*) (pObjeto+m_offSet)) = atoi(dado);
			break;
		case IsDouble:
      *( (double*) (pObjeto+m_offSet)) = atof(dado);
			break;
		case IsFloat:
      *( (float*) (pObjeto+m_offSet)) = atol(dado);
			break;
		case IsShortInt:
      *( (short int*) (pObjeto+m_offSet)) = atoi(dado);
			break;
		case IsChar:
      *( (char*) (pObjeto+m_offSet)) = (char) dado;
      break;
    case IsStringVar:
    case IsStringFix:
      *( (IString*) (pObjeto+m_offSet)) = dado;
      break;
    case IsCharArray:
			strncpy(  (char*) (pObjeto+m_offSet), dado , m_tamanho );
      break;
		case IsTimestamp:
		case IsStringBlob:
    case IsUnknow:
		// ponteiros
		case IsDoublePointer:
		case IsFloatPointer:
		case IsIntPointer:
		case IsShortIntPointer:
		case IsCharPointer:
		case IsCharArrayPointer:
		case IsTimestampPointer:
		case IsStringBlobPointer:
		case IsStringVarPointer:
		case IsStringFixPointer:
		case IsUnknowPointer:
		default:
			throw(IErro("IMapAtrColuna::setValue tipoMembro desconhecido"));
	}

	//## end IMapAtrColuna::setValue%908596384.body
}

char const* IMapAtrColuna::asPuro(IPersistente& anPersist)
{
  //## begin IMapAtrColuna::asPuro%908596385.body preserve=yes
  #pragma message(":-/ Falta Implementar IMapAtrColuna::asPuro")
  return "shit";
  //## end IMapAtrColuna::asPuro%908596385.body
}

//## Get and Set Operations for Has Relationships (implementation)

IKnowType IMapAtrColuna::tipoMembro()
{
  //## begin IMapAtrColuna::tipoMembro%.get preserve=no
  return m_tipoMembro;
  //## end IMapAtrColuna::tipoMembro%.get
}

void IMapAtrColuna::settipoMembro(const IKnowType value)
{
  //## begin IMapAtrColuna::settipoMembro%.set preserve=no
  m_tipoMembro = value;
  //## end IMapAtrColuna::settipoMembro%.set
}

IKnowType IMapAtrColuna::tipoColuna()
{
  //## begin IMapAtrColuna::tipoColuna%.get preserve=no
  return m_tipoColuna;
  //## end IMapAtrColuna::tipoColuna%.get
}

void IMapAtrColuna::settipoColuna(const IKnowType value)
{
  //## begin IMapAtrColuna::settipoColuna%.set preserve=no
  m_tipoColuna = value;
  //## end IMapAtrColuna::settipoColuna%.set
}

//## Get and Set Operations for Class Attributes (implementation)

IString IMapAtrColuna::nomeMembro()
{
  //## begin IMapAtrColuna::nomeMembro%.get preserve=no
  return m_nomeMembro;
  //## end IMapAtrColuna::nomeMembro%.get
}

void IMapAtrColuna::setnomeMembro(const IString value)
{
  //## begin IMapAtrColuna::setnomeMembro%.set preserve=no
  m_nomeMembro = value;
  //## end IMapAtrColuna::setnomeMembro%.set
}

unsigned int IMapAtrColuna::offSet()
{
  //## begin IMapAtrColuna::offSet%.get preserve=no
  return m_offSet;
  //## end IMapAtrColuna::offSet%.get
}

void IMapAtrColuna::setoffSet(const unsigned int value)
{
  //## begin IMapAtrColuna::setoffSet%.set preserve=no
  m_offSet = value;
  //## end IMapAtrColuna::setoffSet%.set
}

unsigned int IMapAtrColuna::tamanho()
{
  //## begin IMapAtrColuna::tamanho%.get preserve=no
  return m_tamanho;
  //## end IMapAtrColuna::tamanho%.get
}

void IMapAtrColuna::settamanho(const unsigned int value)
{
  //## begin IMapAtrColuna::settamanho%.set preserve=no
  m_tamanho = value;
  //## end IMapAtrColuna::settamanho%.set
}

unsigned int IMapAtrColuna::varSizeMax()
{
  //## begin IMapAtrColuna::varSizeMax%.get preserve=no
  return m_varSizeMax;
  //## end IMapAtrColuna::varSizeMax%.get
}

void IMapAtrColuna::setvarSizeMax(const unsigned int value)
{
  //## begin IMapAtrColuna::setvarSizeMax%.set preserve=no
  m_varSizeMax = value;
  //## end IMapAtrColuna::setvarSizeMax%.set
}

IString IMapAtrColuna::nomeColuna()
{
  //## begin IMapAtrColuna::nomeColuna%.get preserve=no
  return m_nomeColuna;
  //## end IMapAtrColuna::nomeColuna%.get
}

void IMapAtrColuna::setnomeColuna(const IString value)
{
  //## begin IMapAtrColuna::setnomeColuna%.set preserve=no
  m_nomeColuna = value;
  //## end IMapAtrColuna::setnomeColuna%.set
}

bool IMapAtrColuna::isProxy()
{
  //## begin IMapAtrColuna::isProxy%.get preserve=no
  return m_isProxy;
  //## end IMapAtrColuna::isProxy%.get
}

void IMapAtrColuna::setisProxy(const bool value)
{
  //## begin IMapAtrColuna::setisProxy%.set preserve=no
  m_isProxy = value;
  //## end IMapAtrColuna::setisProxy%.set
}


// Additional Declarations
//## begin IMapAtrColuna.declarations preserve=yes
//## end IMapAtrColuna.declarations



