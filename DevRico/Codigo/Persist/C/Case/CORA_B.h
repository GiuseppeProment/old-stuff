typedef  void* ODatabase;
typedef void ODynaset;
typedef int oboolean;
typedef int oresult;
#define OSUCCESS 0
#define OFAILURE 101


oboolean
  CallOracle_OStartup();

void
  CallOracle_OShutdown();

void*
  CallOracle_ODatabase_new();


void
  CallOracle_ODatabase_delete( void* m_dataBase );


oresult
  CallOracle_ODatabase_ExecuteSQL(void* m_dataBase,char* sentenca);

void*
  CallOracle_ODynaset_new( void* m_dataBase, char* sentenca );

oresult
  CallOracle_ODynaset_IsOpen(void* pDyn);

oresult
  CallOracle_ODynaset_IsEOF(void* pDyn);

oresult
  CallOracle_ODynaset_IsBOF(void* pDyn);

oresult
  CallOracle_ODynaset_MoveFirst(void* pDyn);

oresult
  CallOracle_ODynaset_MoveLast(void* pDyn);

oresult
  CallOracle_ODynaset_MoveNext(void* pDyn);

oresult
  CallOracle_ODynaset_MovePrev(void* pDyn);

oresult
  CallOracle_ODynaset_MoveTo(void* pDyn,int row);


oresult
  CallOracle_ODynaset_GetFieldValue(void* pDyn,int i, char* theValues, int theValueslen );

void
  CallOracle_ODynaset_delete( void* pDyn );

oresult
  CallOracle_ODatabase_Open(
    void* m_dataBase,
    char* nomeDb,
    char* usuario,
    char* senha );

void
  CallOracle_ODatabase_Close(void* m_dataBase);

