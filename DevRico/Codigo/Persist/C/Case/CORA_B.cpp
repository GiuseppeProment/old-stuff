#include <windows.h>

#pragma package(smart_init)

typedef void* ODatabase;
typedef void ODynaset ;
typedef int oboolean ;
typedef int oresult ;
#define OSUCCESS 0
#define OFAILURE 101

HINSTANCE hDll;

oboolean CallOracle_OStartup()
{
  typedef oboolean (*tipoFuncao) (void);
  tipoFuncao addr;
  //--- carregar a dll
  hDll = LoadLibrary("CORA_VC");
  if ( hDll == NULL )
    MessageBox(NULL,"Erro na carga de CORA_VC.Dll","Erro Grave",MB_OK);
  else {
    addr = (tipoFuncao) GetProcAddress(hDll,"CallOracle_OStartup");
    if ( addr != NULL )
    {
      return (addr)();
      }
    else
      MessageBox(NULL,"chamada CallOracle_OStartup","Erro Grave",MB_OK);
  }
}

void CallOracle_OShutdown()
{
  void (*addr) (void);
  addr = (void (*) (void)) GetProcAddress(hDll,"CallOracle_OShutdown");
  if ( addr != NULL )
    (addr)();
  else
    MessageBox(NULL,"chamada CallOracle_OShutdown","Erro Grave",MB_OK);
  FreeLibrary(hDll);
}

void*
  CallOracle_ODatabase_new()
{
  void* (*addr) (void);
  addr = (void* (*) (void)) GetProcAddress(hDll,"CallOracle_ODatabase_new");
  if ( addr != NULL )
    return (addr)();
  else
    MessageBox(NULL,"chamada CallOracle_ODatabase_new","Erro Grave",MB_OK);
}

void
  CallOracle_ODatabase_delete( void* m_dataBase )
{
  void (*addr) (void*);
  addr = (void (*) (void*)) GetProcAddress(hDll,"CallOracle_ODatabase_delete");
  if ( addr != NULL )
    (addr)(m_dataBase);
  else
    MessageBox(NULL,"chamada CallOracle_ODatabase_delete","Erro Grave",MB_OK);
}


oresult
  CallOracle_ODatabase_ExecuteSQL(void* m_dataBase,char* sentenca)
{
  char* nome = "CallOracle_ODatabase_ExecuteSQL";
  oresult (*addr) (void*,char*);
  addr = (oresult (*) (void*,char*)) GetProcAddress(hDll,nome);
  if ( addr != NULL )
    return (addr)(m_dataBase,sentenca);
  else
    MessageBox(NULL,nome,"Erro chamada",MB_OK);
}

void*
  CallOracle_ODynaset_new( void* m_dataBase, char* sentenca )
{
  char* nome = "CallOracle_ODynaset_new";
  void* (*addr) (void*,char*);
  addr = (void* (*) (void*,char*)) GetProcAddress(hDll,nome);
  if ( addr != NULL )
    return (addr)(m_dataBase,sentenca);
  else
    MessageBox(NULL,nome,"Erro chamada",MB_OK);
}

oresult
  CallOracle_ODynaset_IsOpen(void* pDyn)
{
  char* nome = "CallOracle_ODynaset_IsOpen";
  oresult (*addr) (void*);
  addr = (oresult (*) (void*)) GetProcAddress(hDll,nome);
  if ( addr != NULL )
    return (addr)(pDyn);
  else
    MessageBox(NULL,nome,"Erro chamada",MB_OK);
}

oresult
  CallOracle_ODynaset_IsEOF(void* pDyn)
{
  char* nome = "CallOracle_ODynaset_IsEOF";
  oresult (*addr) (void*);
  addr = (oresult (*) (void*)) GetProcAddress(hDll,nome);
  if ( addr != NULL )
    return (addr)(pDyn);
  else
    MessageBox(NULL,nome,"Erro chamada",MB_OK);
}

oresult
  CallOracle_ODynaset_IsBOF(void* pDyn)
{
  char* nome = "CallOracle_ODynaset_IsBOF";
  oresult (*addr) (void*);
  addr = (oresult (*) (void*)) GetProcAddress(hDll,nome);
  if ( addr != NULL )
    return (addr)(pDyn);
  else
    MessageBox(NULL,nome,"Erro chamada",MB_OK);
}

oresult
  CallOracle_ODynaset_MoveFirst(void* pDyn)
{
  char* nome = "CallOracle_ODynaset_MoveFirst";
  oresult (*addr) (void*);
  addr = (oresult (*) (void*)) GetProcAddress(hDll,nome);
  if ( addr != NULL )
    return (addr)(pDyn);
  else
    MessageBox(NULL,nome,"Erro chamada",MB_OK);
}

oresult
  CallOracle_ODynaset_MoveLast(void* pDyn)
{
  char* nome = "CallOracle_ODynaset_MoveLast";
  oresult (*addr) (void*);
  addr = (oresult (*) (void*)) GetProcAddress(hDll,nome);
  if ( addr != NULL )
    return (addr)(pDyn);
  else
    MessageBox(NULL,nome,"Erro chamada",MB_OK);
}

oresult
  CallOracle_ODynaset_MoveNext(void* pDyn)
{
  char* nome = "CallOracle_ODynaset_MoveNext";
  oresult (*addr) (void*);
  addr = (oresult (*) (void*)) GetProcAddress(hDll,nome);
  if ( addr != NULL )
    return (addr)(pDyn);
  else
    MessageBox(NULL,nome,"Erro chamada",MB_OK);
}

oresult
  CallOracle_ODynaset_MovePrev(void* pDyn)
{
  char* nome = "CallOracle_ODynaset_MovePrev";
  oresult (*addr) (void*);
  addr = (oresult (*) (void*)) GetProcAddress(hDll,nome);
  if ( addr != NULL )
    return (addr)(pDyn);
  else
    MessageBox(NULL,nome,"Erro chamada",MB_OK);
}

oresult
  CallOracle_ODynaset_MoveTo(void* pDyn,int row)
{
  char* nome = "CallOracle_ODynaset_MoveTo";
  oresult (*addr) (void*,int);
  addr = (oresult (*) (void*,int)) GetProcAddress(hDll,nome);
  if ( addr != NULL )
    return (addr)(pDyn,row);
  else
    MessageBox(NULL,nome,"Erro chamada",MB_OK);
}


oresult
  CallOracle_ODynaset_GetFieldValue(void* pDyn,int i, char* theValues, int theValueslen )
{
  char* nome = "CallOracle_ODynaset_GetFieldValue";
  oresult (*addr) (void*,int,char*,int);
  addr = (oresult (*) (void*,int,char*,int)) GetProcAddress(hDll,nome);
  if ( addr != NULL )
    return (addr)(pDyn,i,theValues,theValueslen);
  else
    MessageBox(NULL,nome,"Erro chamada",MB_OK);
}

void
  CallOracle_ODynaset_delete( void* pDyn )
{
  char* nome = "CallOracle_ODynaset_delete";
  void (*addr) (void*);
  addr = (void (*) (void*)) GetProcAddress(hDll,nome);
  if ( addr != NULL )
    (addr)(pDyn);
  else
    MessageBox(NULL,nome,"Erro chamada",MB_OK);
}

oresult
  CallOracle_ODatabase_Open(
    void* m_dataBase,
    char* nomeDb,
    char* usuario,
    char* senha )
{
  char* nome = "CallOracle_ODatabase_Open";
  oresult (*addr) (void*,char*,char*,char*);
  addr = (oresult (*) (void*,char*,char*,char*)) GetProcAddress(hDll,nome);
  if ( addr != NULL )
    return (addr)(m_dataBase,nomeDb,usuario,senha);
  else
    MessageBox(NULL,nome,"Erro chamada",MB_OK);
}


void
  CallOracle_ODatabase_Close(void* m_dataBase)
{
  char* nome = "CallOracle_ODatabase_Close";
  void (*addr) (void*);
  addr = (void (*) (void*)) GetProcAddress(hDll,nome);
  if ( addr != NULL )
    (addr)(m_dataBase);
  else
    MessageBox(NULL,nome,"Erro chamada",MB_OK);
}
