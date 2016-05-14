//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: ICriterio; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\icritrio.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// ICriterio
#include "ICritrio.h"

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class ICriterio 








ICriterio::ICriterio(const ICriterio &right)
  //## begin ICriterio::ICriterio%copy.hasinit preserve=no
      : m_isNecessitaTraducao(false), m_isArgPrecisaAspas(true)
  //## end ICriterio::ICriterio%copy.hasinit
  //## begin ICriterio::ICriterio%copy.initialization preserve=yes
  //## end ICriterio::ICriterio%copy.initialization
{
  //## begin ICriterio::ICriterio%copy.body preserve=yes
  //## end ICriterio::ICriterio%copy.body
}

ICriterio::ICriterio(IString& atributo, IOperComparacao comparacao, char* argumento)
  //## begin ICriterio::ICriterio%908596363.hasinit preserve=no
      : m_isNecessitaTraducao(false), m_isArgPrecisaAspas(true)
  //## end ICriterio::ICriterio%908596363.hasinit
  //## begin ICriterio::ICriterio%908596363.initialization preserve=yes
  //## end ICriterio::ICriterio%908596363.initialization
{
  //## begin ICriterio::ICriterio%908596363.body preserve=yes
  //## end ICriterio::ICriterio%908596363.body
}

ICriterio::ICriterio(IString& atributo, IOperComparacao comparacao, int argumento)
  //## begin ICriterio::ICriterio%908596364.hasinit preserve=no
      : m_isNecessitaTraducao(false), m_isArgPrecisaAspas(true)
  //## end ICriterio::ICriterio%908596364.hasinit
  //## begin ICriterio::ICriterio%908596364.initialization preserve=yes
  //## end ICriterio::ICriterio%908596364.initialization
{
  //## begin ICriterio::ICriterio%908596364.body preserve=yes
  //## end ICriterio::ICriterio%908596364.body
}

ICriterio::ICriterio(IString& atributo, IOperComparacao comparacao, IString& argumento)
  //## begin ICriterio::ICriterio%908596365.hasinit preserve=no
      : m_isNecessitaTraducao(false), m_isArgPrecisaAspas(true)
  //## end ICriterio::ICriterio%908596365.hasinit
  //## begin ICriterio::ICriterio%908596365.initialization preserve=yes
  //## end ICriterio::ICriterio%908596365.initialization
{
  //## begin ICriterio::ICriterio%908596365.body preserve=yes
  //## end ICriterio::ICriterio%908596365.body
}

ICriterio::ICriterio(char* FraseLivre)
  //## begin ICriterio::ICriterio%908596366.hasinit preserve=no
      : m_isNecessitaTraducao(false), m_isArgPrecisaAspas(true)
  //## end ICriterio::ICriterio%908596366.hasinit
  //## begin ICriterio::ICriterio%908596366.initialization preserve=yes
  //## end ICriterio::ICriterio%908596366.initialization
{
  //## begin ICriterio::ICriterio%908596366.body preserve=yes
  //## end ICriterio::ICriterio%908596366.body
}

ICriterio::ICriterio(IOperLogicoPrecedencia conectorLogico)
  //## begin ICriterio::ICriterio%908596367.hasinit preserve=no
      : m_isNecessitaTraducao(false), m_isArgPrecisaAspas(true)
  //## end ICriterio::ICriterio%908596367.hasinit
  //## begin ICriterio::ICriterio%908596367.initialization preserve=yes
  //## end ICriterio::ICriterio%908596367.initialization
{
  //## begin ICriterio::ICriterio%908596367.body preserve=yes
  //## end ICriterio::ICriterio%908596367.body
}


ICriterio::~ICriterio()
{
  //## begin ICriterio::~ICriterio%.body preserve=yes
  //## end ICriterio::~ICriterio%.body
}



//## Other Operations (implementation)
char* ICriterio::asSentencaSQL()
{
  IString Sentenca;

  //## begin ICriterio::asSentencaSQL%908414766.body preserve=yes
  //## end ICriterio::asSentencaSQL%908414766.body

  return Sentenca;
}

//## Get and Set Operations for Class Attributes (implementation)

IString ICriterio::atributo()
{
  //## begin ICriterio::atributo%.get preserve=no
  return m_atributo;
  //## end ICriterio::atributo%.get
}

void ICriterio::setatributo(const IString value)
{
  //## begin ICriterio::setatributo%.set preserve=no
  m_atributo = value;
  //## end ICriterio::setatributo%.set
}

IOperComparacao ICriterio::comparador()
{
  //## begin ICriterio::comparador%.get preserve=no
  return m_comparador;
  //## end ICriterio::comparador%.get
}

void ICriterio::setcomparador(const IOperComparacao value)
{
  //## begin ICriterio::setcomparador%.set preserve=no
  m_comparador = value;
  //## end ICriterio::setcomparador%.set
}

IString ICriterio::argumento()
{
  //## begin ICriterio::argumento%.get preserve=no
  return m_argumento;
  //## end ICriterio::argumento%.get
}

void ICriterio::setargumento(const IString value)
{
  //## begin ICriterio::setargumento%.set preserve=no
  m_argumento = value;
  //## end ICriterio::setargumento%.set
}

bool ICriterio::isArgPrecisaAspas()
{
  //## begin ICriterio::isArgPrecisaAspas%.get preserve=no
  return m_isArgPrecisaAspas;
  //## end ICriterio::isArgPrecisaAspas%.get
}

void ICriterio::setisArgPrecisaAspas(const bool value)
{
  //## begin ICriterio::setisArgPrecisaAspas%.set preserve=no
  m_isArgPrecisaAspas = value;
  //## end ICriterio::setisArgPrecisaAspas%.set
}

IString ICriterio::coluna()
{
  //## begin ICriterio::coluna%.get preserve=no
  return m_coluna;
  //## end ICriterio::coluna%.get
}

void ICriterio::setcoluna(const IString value)
{
  //## begin ICriterio::setcoluna%.set preserve=no
  m_coluna = value;
  //## end ICriterio::setcoluna%.set
}


// Additional Declarations
//## begin ICriterio.declarations preserve=yes
//## end ICriterio.declarations




