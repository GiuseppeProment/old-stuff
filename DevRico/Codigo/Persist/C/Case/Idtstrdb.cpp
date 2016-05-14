//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IDataStoreODBC; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: c:\devrico\codigo\persist\c\case\idtstrdb.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IStatement
#include "ISttment.h"
// IQueryStatement
#include "IQrySttm.h"
// IModifyStatement
#include "IMdfyStt.h"
// IDataStoreODBC
#include "IDtStrDB.h"

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class IDataStoreODBC 












IDataStoreODBC::IDataStoreODBC()
  //## begin IDataStoreODBC::IDataStoreODBC%.hasinit preserve=no
      : m_IshConnection(false), m_IshEnvironment(false), m_IsConectado(false), m_IshStatement(false), m_nVersaoODBC(0)
  //## end IDataStoreODBC::IDataStoreODBC%.hasinit
  //## begin IDataStoreODBC::IDataStoreODBC%.initialization preserve=yes
  //## end IDataStoreODBC::IDataStoreODBC%.initialization
{
  //## begin IDataStoreODBC::IDataStoreODBC%.body preserve=yes
  //## end IDataStoreODBC::IDataStoreODBC%.body
}

IDataStoreODBC::IDataStoreODBC(const IDataStoreODBC &right)
  //## begin IDataStoreODBC::IDataStoreODBC%copy.hasinit preserve=no
      : m_IshConnection(false), m_IshEnvironment(false), m_IsConectado(false), m_IshStatement(false), m_nVersaoODBC(0)
  //## end IDataStoreODBC::IDataStoreODBC%copy.hasinit
  //## begin IDataStoreODBC::IDataStoreODBC%copy.initialization preserve=yes
  //## end IDataStoreODBC::IDataStoreODBC%copy.initialization
{
  //## begin IDataStoreODBC::IDataStoreODBC%copy.body preserve=yes
  //## end IDataStoreODBC::IDataStoreODBC%copy.body
}


IDataStoreODBC::~IDataStoreODBC()
{
  //## begin IDataStoreODBC::~IDataStoreODBC%.body preserve=yes
	freeHandles();
  //## end IDataStoreODBC::~IDataStoreODBC%.body
}



//## Other Operations (implementation)
bool IDataStoreODBC::execute(IModifyStatement& setenca)
{
  bool ok;

  //## begin IDataStoreODBC::execute%908596370.body preserve=yes
	SQLRETURN retcode;
  retcode =
		SQLExecDirect(
			m_hStatement,
			(unsigned char*)(char*)setenca.asSentencaSQL(),
			SQL_NTS);
  if (retcode == SQL_ERROR) {
		freeHandles();
		throw(IErro("Erro em execute SQLDirect"));
	}
  //## end IDataStoreODBC::execute%908596370.body

  return ok;
}

bool IDataStoreODBC::execute(IQueryStatement& anQuery)
{
  bool ok;

  //## begin IDataStoreODBC::execute%908596371.body preserve=yes
	SQLRETURN retcode;
	SQLHSTMT  hstmt;

	retcode =
		SQLAllocHandle(
			SQL_HANDLE_STMT,
			m_hConnection,
			&hstmt);

  if (retcode == SQL_ERROR)
	{
		freeHandles();
		throw(IErro("Erro na alocação do Statement Multiplo"));
	}


	// FAZER AJUSTES NA CONEXAO
	if ( IsCursorRolavelSuportado() ) {
		retcode = SQLSetStmtOption(hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_DYNAMIC );
		if (retcode == SQL_ERROR)
		 {	freeHandles();
		  	throw(IErro("Erro SetStmtOption")); 		}
		}
	

  retcode =
		SQLExecDirect(
			hstmt,
			(unsigned char*)(char*)anQuery.asSentencaSQL(),
			SQL_NTS);

  if (retcode == SQL_ERROR)
	{
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt );
		freeHandles();
		throw(IErro("Erro em execute SQLDirect"));
	}


	SQLINTEGER RowCount;
	retcode = SQLRowCount( hstmt, &RowCount );

  if (retcode == SQL_ERROR)
	{
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt );
		freeHandles();
		throw(IErro("Erro em execute SQLDirect"));
	}

	// guarda um ponteiro ao manuseador de statement
	// no Query
	anQuery.m_lowLayerSlot = (void*) hstmt ;
	anQuery.setisFim(false);
	anQuery.setlinhasCount(RowCount);
	// e guarda na nossa lista para controle
	m_queries.adiciona( (void*) hstmt );

	// :-> fazer bind de colunas com theQuery.theValues
	//bindColunasRetorno( anQuery );

	ListaString& theValues = anQuery.theValues();

  int i;
  for (i=1; i<=theValues.count(); i++ )
  {
		SQLBindCol(
			hstmt,
			i,
			SQL_C_CHAR,
			theValues[i],
			theValues[i].len(),
			NULL
		);
  }

	// fazer bind do ID que é a última no Select.
	// i é a última pois saiu do loop acima.
	SQLBindCol(
		hstmt,
		i,
		SQL_C_CHAR,
		anQuery.ValueID(),
		anQuery.ValueID().len(),
		NULL
	);



  //## end IDataStoreODBC::execute%908596371.body

  return ok;
}

IDataStore& IDataStoreODBC::requisitaDados(IQueryStatement& theQuery, IDirecaoFetch tipo)
{
  //## begin IDataStoreODBC::requisitaDados%908596372.body preserve=yes

      //	utiliza o lowLayerSlot :
      //	1. checa se não é 0
      //	2. checa o estado do Statement
      //	3. obtem os dados de canal do lowLayerSlot que são
      //	dependentes da implementação.
      //	4. copia os dados do canal para o theValues no IQuery
      //	5. se não há dados (eof/bof) ajusta isFim do Query para
      //	true. não muda os dados.


	if (theQuery.m_lowLayerSlot == 0)
		throw(IErro("IDataStoreODBC lowlayerSlot vazio."));

	SQLRETURN retcode = 0;
	SQLHSTMT hstmt = theQuery.m_lowLayerSlot;

	// ação diferente para drivers sem scroll
	if ( IsCursorRolavelSuportado()==false )
		{
		switch(tipo)
		{
			case primeiro:
#pragma message(":) .primeiro Reconstruir Query para cursor forward only")
				// reconstruir query
				break;
			case ultimo:
				// varredura
#pragma message(":) .ultimo Fazer Varredura ")
				break;
			case proximo:
				retcode = SQLFetch(hstmt);
				break;
			case previo:
				// não suportado
				break;
			case reavalia:
				break;
				// não suportado
			default :
				break;
		}
		}
	else {
		switch(tipo)
		{
			case primeiro:
				retcode = SQLExtendedFetch(hstmt, SQL_FETCH_FIRST, 0, NULL, NULL );
				break;
			case ultimo:
				retcode = SQLExtendedFetch(hstmt, SQL_FETCH_LAST, 0, NULL, NULL );
				break;
			case proximo:
				retcode = SQLExtendedFetch(hstmt, SQL_FETCH_NEXT, 0, NULL, NULL );
				break;
			case previo:
				retcode = SQLExtendedFetch(hstmt, SQL_FETCH_PRIOR, 0, NULL, NULL );
				break;
			case reavalia:
				retcode = SQLExtendedFetch(hstmt, SQL_FETCH_RELATIVE, 0, NULL, NULL );
				break;
			default :
				break;
		}
	}

  if (retcode == SQL_ERROR) {
		freeHandles();
		throw(IErro("Erro em SQLExtendedFetch"));
	}

	if (retcode == SQL_NO_DATA_FOUND)
		theQuery.setisFim(true);
	else
		theQuery.setisFim(false);

  //## end IDataStoreODBC::requisitaDados%908596372.body

  return *this;
}

bool IDataStoreODBC::isFim(IQueryStatement& theQuery)
{
  bool Final;

  //## begin IDataStoreODBC::isFim%908596373.body preserve=yes
  Final = theQuery.isFim();
  //## end IDataStoreODBC::isFim%908596373.body

  return Final;
}

IDataStore& IDataStoreODBC::libereQuery(IQueryStatement& anQuery)
{
  //## begin IDataStoreODBC::libereQuery%908596374.body preserve=yes

	// procura em nossa lista de controle
	SQLHSTMT hstmt = (SQLHSTMT) anQuery.m_lowLayerSlot;
	int i = m_queries.posicaoDe( (void*) hstmt );
	if ( i != -1 )
		{
			SQLFreeHandle(SQL_HANDLE_STMT, (SQLHSTMT) anQuery.m_lowLayerSlot);
			m_queries.remove(i);
		}

  //## end IDataStoreODBC::libereQuery%908596374.body

  return *this;
}

IDataStore& IDataStoreODBC::ligar()
{
  //## begin IDataStoreODBC::ligar%910153638.body preserve=yes
	// DSN não pode ser vazio
	if ( m_DSN.IsEmpty() ) {
		freeHandles();
		throw(IErro("Erro DSN não pode ser vazio"));
	}

	aloqueENV();
	aloqueDBC();
	conectar();


	// Descobrir 1 a versao do odbc
	// e se possui capacidade de rolagem
	UDWORD	value;
	SWORD	cbData;

	::SQLGetInfo(m_hConnection,SQL_FETCH_DIRECTION,
		(PTR)&value,4,&cbData);

	if (( value & SQL_FD_FETCH_NEXT ) && ( value & SQL_FD_FETCH_PRIOR ))
		// se nao faz next, é só para frente
		setIsCursorRolavelSuportado(true);
	else                               
		setIsCursorRolavelSuportado(false);

	aloqueStatementUmaLinha();
  //## end IDataStoreODBC::ligar%910153638.body

  return *this;
}

IDataStore& IDataStoreODBC::desligar()
{
  //## begin IDataStoreODBC::desligar%910153639.body preserve=yes
	freeHandles();
  //## end IDataStoreODBC::desligar%910153639.body

  return *this;
}

void IDataStoreODBC::aloqueENV()
{
  //## begin IDataStoreODBC::aloqueENV%910153640.body preserve=yes
	SQLRETURN retcode;

	retcode =
		SQLAllocHandle(	SQL_HANDLE_ENV,
										SQL_NULL_HANDLE,
										&m_hEnvironment);

  if (retcode == SQL_ERROR) {
		freeHandles();
		throw(IErro("Erro na Alocacao de ENV"));
	}

	m_IshEnvironment = true;

	retcode =
		SQLSetEnvAttr(m_hEnvironment,
									SQL_ATTR_ODBC_VERSION,
									(void*)SQL_OV_ODBC2,0);

  if (retcode == SQL_ERROR) {
		freeHandles();
		throw(IErro("Erro no set da versao."));
	}


  //## end IDataStoreODBC::aloqueENV%910153640.body
}

void IDataStoreODBC::aloqueDBC()
{
  //## begin IDataStoreODBC::aloqueDBC%910153641.body preserve=yes
	SQLRETURN retcode;

	retcode =
		SQLAllocHandle(	SQL_HANDLE_DBC,
										m_hEnvironment,
										&m_hConnection);

  if (retcode == SQL_ERROR) {
		freeHandles();
		throw(IErro("Erro na Alocacao de DBC"));
	}
	m_IshConnection = true;
  //## end IDataStoreODBC::aloqueDBC%910153641.body
}

void IDataStoreODBC::conectar()
{
  //## begin IDataStoreODBC::conectar%910153642.body preserve=yes
	SQLRETURN retcode;

	retcode =
		SQLConnect(	m_hConnection,
								(unsigned char*)(char*)m_DSN, SQL_NTS,
								(SQLCHAR*) "gproment", SQL_NTS,
                (SQLCHAR*) "quark", SQL_NTS);

  if (retcode == SQL_ERROR) {
		freeHandles();
		throw(IErro("Erro na conexao"));
	}

	m_IsConectado = true;
  //## end IDataStoreODBC::conectar%910153642.body
}

void IDataStoreODBC::freeHandles()
{
  //## begin IDataStoreODBC::freeHandles%910153643.body preserve=yes


	// liberar statements alocados para queries
  for (int i=1; i<=m_queries.count(); i++ )	{
		SQLFreeHandle(SQL_HANDLE_STMT, (SQLHSTMT) m_queries[i] );
		m_queries.remove(i);
	}


	if (m_IshStatement)
		SQLFreeHandle(SQL_HANDLE_STMT, m_hStatement);

	if (m_IsConectado)
		SQLDisconnect(m_hConnection);

	if (m_IshConnection)
		SQLFreeHandle(SQL_HANDLE_DBC, m_hConnection);

	if (m_IshEnvironment)
		SQLFreeHandle(SQL_HANDLE_ENV, m_hEnvironment);


	m_IshStatement=m_IsConectado=m_IshConnection=m_IshEnvironment=false;
  //## end IDataStoreODBC::freeHandles%910153643.body
}

void IDataStoreODBC::aloqueStatementUmaLinha()
{
  //## begin IDataStoreODBC::aloqueStatementUmaLinha%910153640.body preserve=yes
	SQLRETURN retcode;

	retcode =
		SQLAllocHandle(SQL_HANDLE_STMT, m_hConnection, &m_hStatement);

  if (retcode == SQL_ERROR) {
		freeHandles();
		throw(IErro("Erro na alocação do Statemente Unário"));
	}

	m_IshStatement = true;

  //## end IDataStoreODBC::aloqueStatementUmaLinha%910153640.body
}

//## Get and Set Operations for Class Attributes (implementation)

IString IDataStoreODBC::DSN()
{
  //## begin IDataStoreODBC::DSN%.get preserve=no
  return m_DSN;
  //## end IDataStoreODBC::DSN%.get
}

void IDataStoreODBC::setDSN(const IString value)
{
  //## begin IDataStoreODBC::setDSN%.set preserve=no
  m_DSN = value;
  //## end IDataStoreODBC::setDSN%.set
}

int IDataStoreODBC::nVersaoODBC()
{
  //## begin IDataStoreODBC::nVersaoODBC%.get preserve=no
  return m_nVersaoODBC;
  //## end IDataStoreODBC::nVersaoODBC%.get
}

void IDataStoreODBC::setnVersaoODBC(const int value)
{
  //## begin IDataStoreODBC::setnVersaoODBC%.set preserve=no
  m_nVersaoODBC = value;
  //## end IDataStoreODBC::setnVersaoODBC%.set
}

bool IDataStoreODBC::IsCursorRolavelSuportado()
{
  //## begin IDataStoreODBC::IsCursorRolavelSuportado%.get preserve=no
  return m_IsCursorRolavelSuportado;
  //## end IDataStoreODBC::IsCursorRolavelSuportado%.get
}

void IDataStoreODBC::setIsCursorRolavelSuportado(const bool value)
{
  //## begin IDataStoreODBC::setIsCursorRolavelSuportado%.set preserve=no
  m_IsCursorRolavelSuportado = value;
  //## end IDataStoreODBC::setIsCursorRolavelSuportado%.set
}


// Additional Declarations
//## begin IDataStoreODBC.declarations preserve=yes
//## end IDataStoreODBC.declarations



