#include "oracl.h"
#pragma comment(lib,"oraclm32")

typedef void* voidPointer;

extern "C" {

oboolean __declspec(dllexport)
  CallOracle_OStartup()
{
  return OStartup();
}


voidPointer __declspec(dllexport) CallOracle_ODatabase_new()
{
  return (void*) new ODatabase();
}

void __declspec(dllexport)
  CallOracle_OShutdown()
{
    OShutdown();
}

void __declspec(dllexport)
  CallOracle_ODatabase_delete( void* m_dataBase )
{
    delete (ODatabase*) m_dataBase;
}


oresult  __declspec(dllexport)
  CallOracle_ODatabase_ExecuteSQL(void* m_dataBase,char* sentenca)
{
 return  ( (ODatabase*)m_dataBase)->ExecuteSQL( sentenca );
}

voidPointer  __declspec(dllexport) CallOracle_ODynaset_new( void* m_dataBase, char* sentenca )
{
  return (void*) new ODynaset( *( (ODatabase*)m_dataBase ), sentenca);
}

oresult  __declspec(dllexport)
  CallOracle_ODynaset_IsOpen(void* pDyn)
{
  return ( (ODynaset*)pDyn )->IsOpen();
}

oresult  __declspec(dllexport)
  CallOracle_ODynaset_IsEOF(void* pDyn)
{
  return ( (ODynaset*)pDyn )->IsEOF();
}

oresult  __declspec(dllexport)
  CallOracle_ODynaset_IsBOF(void* pDyn)
{
  return ( (ODynaset*)pDyn )->IsBOF();
}

oresult  __declspec(dllexport)
  CallOracle_ODynaset_MoveFirst(void* pDyn)
{
  return ( (ODynaset*)pDyn )->MoveFirst();
}

oresult  __declspec(dllexport)
  CallOracle_ODynaset_MoveLast(void* pDyn)
{
  return ( (ODynaset*)pDyn )->MoveLast();
}

oresult  __declspec(dllexport)
  CallOracle_ODynaset_MoveNext(void* pDyn)
{
  return ( (ODynaset*)pDyn )->MoveNext();
}

oresult  __declspec(dllexport)
  CallOracle_ODynaset_MovePrev(void* pDyn)
{
  return ( (ODynaset*)pDyn )->MovePrev();
}

oresult  __declspec(dllexport)
  CallOracle_ODynaset_MoveTo(void* pDyn,int row)
{
  return ( (ODynaset*)pDyn )->MoveTo( row );
}


oresult  __declspec(dllexport)
  CallOracle_ODynaset_GetFieldValue(void* pDyn,int i, char* theValues, int theValueslen )
{
  return
    ( (ODynaset*) pDyn )->
      GetFieldValue(i, theValues, theValueslen ) ;
}

void  __declspec(dllexport)
  CallOracle_ODynaset_delete( void* pDyn )
{
    delete (ODynaset*) pDyn;
}

oresult  __declspec(dllexport)
  CallOracle_ODatabase_Open(
    void* m_dataBase,
    char* nomeDb,
    char* usuario,
    char* senha )
{
  return ( (ODatabase*)m_dataBase)->Open(nomeDb,usuario,senha);
}

void  __declspec(dllexport)
  CallOracle_ODatabase_Close(void* m_dataBase)
{
  ( (ODatabase*)m_dataBase )->Close();
}

}
