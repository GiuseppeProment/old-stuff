//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IDataStoreOracleActivex; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: c:\docume~1\projetos\persist\codigo\casecode\idtstrrc.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IDataStoreOracleActivex
#include "IDtStrrc.h"
// IStatement
#include "ISttment.h"
// IQueryStatement
#include "IQrySttm.h"
// IModifyStatement
#include "IMdfyStt.h"

//## begin module.additionalDeclarations preserve=yes
// Isto esta errado, n„o existe a menor necessidade j· que
// o Cora_b.cpp faz parte do produto.
//#ifdef CBUILDER
//  #include "CORA_B.cpp"
//#endif
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class IDataStoreOracleActivex



IDataStoreOracleActivex::IDataStoreOracleActivex()
  //## begin IDataStoreOracleActivex::IDataStoreOracleActivex%.hasinit preserve=no
  //## end IDataStoreOracleActivex::IDataStoreOracleActivex%.hasinit
  //## begin IDataStoreOracleActivex::IDataStoreOracleActivex%.initialization preserve=yes
  //## end IDataStoreOracleActivex::IDataStoreOracleActivex%.initialization
{
  //## begin IDataStoreOracleActivex::IDataStoreOracleActivex%.body preserve=yes
  //--- StartUp do ambiente Oracle Activex
#ifndef CBUILDER
    OStartup();
#else
    CallOracle_OStartup();
    m_dataBase = CallOracle_ODatabase_new();
#endif
  //## end IDataStoreOracleActivex::IDataStoreOracleActivex%.body
}

IDataStoreOracleActivex::IDataStoreOracleActivex(const IDataStoreOracleActivex &right)
  //## begin IDataStoreOracleActivex::IDataStoreOracleActivex%copy.hasinit preserve=no
  //## end IDataStoreOracleActivex::IDataStoreOracleActivex%copy.hasinit
  //## begin IDataStoreOracleActivex::IDataStoreOracleActivex%copy.initialization preserve=yes
  //## end IDataStoreOracleActivex::IDataStoreOracleActivex%copy.initialization
{
  //## begin IDataStoreOracleActivex::IDataStoreOracleActivex%copy.body preserve=yes
  //## end IDataStoreOracleActivex::IDataStoreOracleActivex%copy.body
}


IDataStoreOracleActivex::~IDataStoreOracleActivex()
{
  //## begin IDataStoreOracleActivex::~IDataStoreOracleActivex%.body preserve=yes
#ifndef CBUILDER
    OShutdown();
#else
    CallOracle_ODatabase_delete(m_dataBase );
    CallOracle_OShutdown();
#endif
  //## end IDataStoreOracleActivex::~IDataStoreOracleActivex%.body
}



//## Other Operations (implementation)
bool IDataStoreOracleActivex::execute(IModifyStatement& setenca)
{
  bool ok;

  //## begin IDataStoreOracleActivex::execute%908596370.body preserve=yes
#ifndef CBUILDER
  if ( m_dataBase.ExecuteSQL( setenca.asSentencaSQL() ) != OSUCCESS )
    throw(IErro("Erro em ODatabase::ExecuteSQL em IDataStoreOracleActivex::execute"));
#else
  if ( CallOracle_ODatabase_ExecuteSQL(m_dataBase,setenca.asSentencaSQL())!= OSUCCESS )
    throw(IErro("Erro em ODatabase::ExecuteSQL em IDataStoreOracleActivex::execute"));
#endif

  //## end IDataStoreOracleActivex::execute%908596370.body

  return ok;
}

bool IDataStoreOracleActivex::execute(IQueryStatement& anQuery)
{
  bool ok;

  //## begin IDataStoreOracleActivex::execute%908596371.body preserve=yes

#ifndef CBUILDER
  //-- criar um dynaset
  ODynaset* pDyn = new ODynaset( m_dataBase,anQuery.asSentencaSQL() );
  if ( ! pDyn->IsOpen() )  throw(IErro("Dynaset nao pode ser aberto"));
  //-- guardar no slot
  anQuery.m_lowLayerSlot = (void*) pDyn;
  anQuery.setisFim( pDyn->IsEOF()==1?true:false );
#else

  void* pDyn = CallOracle_ODynaset_new( m_dataBase, anQuery.asSentencaSQL()  );
  if ( ! CallOracle_ODynaset_IsOpen(pDyn) )  throw(IErro("Dynaset nao pode ser aberto"));
  //-- guardar no slot
  anQuery.m_lowLayerSlot = pDyn;
  anQuery.setisFim( CallOracle_ODynaset_IsEOF(pDyn)==1?true:false );

#endif
  //-- obs nao podemos fazer isso, pois exigiria o fetch de todos os
  //   registros do dynaset, devemos fazer um 'select count(condicao)'
  //anQuery.setlinhasCount( pDyn->GetRecordCount() );
  //## end IDataStoreOracleActivex::execute%908596371.body

  return ok;
}

IDataStore& IDataStoreOracleActivex::requisitaDados(IQueryStatement& theQuery, IDirecaoFetch tipo)
{
  //## begin IDataStoreOracleActivex::requisitaDados%908596372.body preserve=yes
  if (theQuery.m_lowLayerSlot == 0)
    throw(IErro("IDataStoreOracleActivex lowlayerSlot vazio."));

#ifndef CBUILDER

  oresult retcode;
  ODynaset* pDyn =(ODynaset*) (theQuery.m_lowLayerSlot);

	switch(tipo)
	{
		case primeiro:
      retcode = pDyn->MoveFirst(); break;
		case ultimo:
      retcode = pDyn->MoveLast(); break;
    case proximo:
      retcode = pDyn->MoveNext(); break;
    case previo:
      retcode = pDyn->MovePrev(); break;
   case reavalia:
      //-- vamos usar moveTo com 0 , n∆o sei se funciona
      retcode = pDyn->MoveTo(0); break;
    default :
			break;
	}

  if (retcode != OSUCCESS) throw(IErro("<IDataStoreOracleActivex> Erro Move"));

  if ( pDyn->IsEOF() || pDyn->IsBOF() )
    theQuery.setisFim(true);
  else
    { theQuery.setisFim(false);
      PegueDados( pDyn,theQuery ); } //-- copiar dados das colunas
#else

  oresult retcode;
  void* pDyn =(theQuery.m_lowLayerSlot);

	switch(tipo)
	{
		case primeiro:
      retcode = CallOracle_ODynaset_MoveFirst(pDyn); break;
		case ultimo:
      retcode = CallOracle_ODynaset_MoveLast(pDyn); break;
    case proximo:
      retcode = CallOracle_ODynaset_MoveNext(pDyn); break;
    case previo:
      retcode = CallOracle_ODynaset_MovePrev(pDyn); break;
   case reavalia:
      //-- vamos usar moveTo com 0 , n∆o sei se funciona
      retcode = CallOracle_ODynaset_MoveTo(pDyn,0); break;
    default :
			break;
	}

  if (retcode != OSUCCESS) throw(IErro("<IDataStoreOracleActivex> Erro Move"));

  if ( CallOracle_ODynaset_IsEOF(pDyn) || CallOracle_ODynaset_IsBOF(pDyn) )
    theQuery.setisFim(true);
  else
    { theQuery.setisFim(false);
      PegueDados( pDyn,theQuery ); } //-- copiar dados das colunas


#endif
  //## end IDataStoreOracleActivex::requisitaDados%908596372.body

  return *this;
}

void IDataStoreOracleActivex::PegueDados(ODynaset* pDyn, IQueryStatement& theQuery)
{
  //## begin IDataStoreOracleActivex::PegueDados%923520300.body preserve=yes
  ListaString& theValues = theQuery.theValues();
  int i;
  for (i=1; i<=theValues.count(); i++ ) {
#ifndef CBUILDER
		if ( pDyn->GetFieldValue(i-1, theValues[i], theValues[i].len() ) != OSUCCESS )
#else
    if ( CallOracle_ODynaset_GetFieldValue(pDyn,i-1, theValues[i], theValues[i].len() ) != OSUCCESS )
#endif
      throw(IErro("Erro em GetFieldValue"));
		}

	// pegar o ID que È o ˙ltimo da lista (ie count+1 ou o proprio i)
#ifndef CBUILDER
	if ( pDyn->GetFieldValue(i-1, theQuery.ValueID(), theQuery.ValueID().len() ) != OSUCCESS )
#else
  if ( CallOracle_ODynaset_GetFieldValue(pDyn,i-1, theQuery.ValueID(), theQuery.ValueID().len() ) != OSUCCESS )
#endif
		throw(IErro("Erro em GetFieldValue"));


  //## end IDataStoreOracleActivex::PegueDados%923520300.body
}

bool IDataStoreOracleActivex::isFim(IQueryStatement& theQuery)
{
  bool Final;

  //## begin IDataStoreOracleActivex::isFim%908596373.body preserve=yes
  Final = theQuery.isFim();
  //## end IDataStoreOracleActivex::isFim%908596373.body

  return Final;
}

IDataStore& IDataStoreOracleActivex::libereQuery(IQueryStatement& anQuery)
{
  //## begin IDataStoreOracleActivex::libereQuery%908596374.body preserve=yes
  //-- destruir o dynaset
#ifndef CBUILDER
  delete (ODynaset*) (anQuery.m_lowLayerSlot);
#else

  CallOracle_ODynaset_delete( anQuery.m_lowLayerSlot );

#endif
  //## end IDataStoreOracleActivex::libereQuery%908596374.body

  return *this;
}

IDataStore& IDataStoreOracleActivex::ligar()
{
  //## begin IDataStoreOracleActivex::ligar%910153638.body preserve=yes
    if ( nomeDb().IsEmpty() ) throw(IErro("Erro nomeDb nao pode ser vazio"));
    if ( usuario().IsEmpty() ) throw(IErro("Erro usuario nao pode ser vazio"));
    if ( senha().IsEmpty() ) throw(IErro("Erro senha nao pode ser vazia"));

#ifndef CBUILDER
    if ( m_dataBase.Open(nomeDb(),usuario(),senha()) != OSUCCESS )
      throw(IErro("Erro interno no ODatabase"));
#else

    if ( CallOracle_ODatabase_Open(m_dataBase,nomeDb(),usuario(),senha()) != OSUCCESS )
      throw(IErro("Erro interno no ODatabase"));

#endif

  //## end IDataStoreOracleActivex::ligar%910153638.body

  return *this;
}

IDataStore& IDataStoreOracleActivex::desligar()
{
  //## begin IDataStoreOracleActivex::desligar%910153639.body preserve=yes
#ifndef CBUILDER
  m_dataBase.Close();
#else

  CallOracle_ODatabase_Close(m_dataBase);

#endif

  //## end IDataStoreOracleActivex::desligar%910153639.body

  return *this;
}

//## Get and Set Operations for Class Attributes (implementation)

IString IDataStoreOracleActivex::nomeDb()
{
  //## begin IDataStoreOracleActivex::nomeDb%.get preserve=no
  return m_nomeDb;
  //## end IDataStoreOracleActivex::nomeDb%.get
}

void IDataStoreOracleActivex::setnomeDb(const IString value)
{
  //## begin IDataStoreOracleActivex::setnomeDb%.set preserve=no
  m_nomeDb = value;
  //## end IDataStoreOracleActivex::setnomeDb%.set
}


// Additional Declarations
//## begin IDataStoreOracleActivex.declarations preserve=yes
//## end IDataStoreOracleActivex.declarations




