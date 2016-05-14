#include <windows.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>

#include <string.h>
#include <iostream.h>
#include <iomanip.h>

#pragma comment(lib,"odbc32.lib")

void
 ExibaDados(SQLHSTMT &hstmt),
 showErroConnection( SQLHDBC   &hdbc,
                     SQLRETURN &retcode );
void
showErroExec(SQLHSTMT &hstmt,SQLRETURN &retcode);


void main(int argc,char **argv)
{

/*
   for(int i=0;i<argc;i++)
      cout << *(argv+i) << endl;
*/


SQLHENV    henv;
SQLHDBC    hdbc;
SQLHSTMT   hstmt;
SQLRETURN  retcode;
SQLSMALLINT Count;
SQLCHAR linha[300];

// copiar para linha
strcpy( (char*) linha , *(argv+1) );

/*Allocate environment handle */
retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);

if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
   /* Set the ODBC version environment attribute */
   retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3,
             0);

   if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
      /* Allocate connection handle */

      retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);

      if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
         /* Set login timeout to 5 seconds. */
         //SQLSetConnectAttr(hdbc, (void*)SQL_LOGIN_TIMEOUT, 5, 0);

         /* Connect to data source */
         retcode = SQLConnect(hdbc, (SQLCHAR*) "OracleOdbc", SQL_NTS,
                                    (SQLCHAR*) "Gproment", SQL_NTS,
                                    (SQLCHAR*) "quark", SQL_NTS);

         showErroConnection(hdbc,retcode);

         if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO){

            /* Allocate statement handle */
            retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

            if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
            /* Process data */

               cout << "executando-->" << linha << endl;

               retcode = SQLExecDirect(hstmt,/*(SQLCHAR*)*/ linha , SQL_NTS);

               //retcode = SQLFetch( hstmt );
               showErroExec(hstmt,retcode);

               ExibaDados(hstmt);

               SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
            }
            SQLDisconnect(hdbc);
         }
         SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
      }
   }
   SQLFreeHandle(SQL_HANDLE_ENV, henv);

}

}

// 
// 
void
showErroConnection( SQLHDBC   &hdbc,
                    SQLRETURN &retcode )
{
   SQLCHAR    SqlState[6],Msg[SQL_MAX_MESSAGE_LENGTH];
   SQLINTEGER NativeError;
   SQLSMALLINT i, MsgLen;

   if ((retcode == SQL_SUCCESS_WITH_INFO) || (retcode == SQL_ERROR)) {
      // Get the status records.
      i = 1;
      while ((retcode = SQLGetDiagRec(SQL_HANDLE_DBC, hdbc, i, SqlState, &NativeError,Msg, sizeof(Msg), &MsgLen)) != SQL_NO_DATA) {
         //DisplayError(SqlState,NativeError,Msg,MsgLen);
         cout << SqlState << " - " << Msg << endl;
         i++;
      }

   }
   return;
}

void
showErroExec( SQLHSTMT   &hstmt,
                    SQLRETURN &retcode )
{
   SQLCHAR    SqlState[6],Msg[SQL_MAX_MESSAGE_LENGTH];
   SQLINTEGER NativeError;
   SQLSMALLINT i, MsgLen;

   if ((retcode == SQL_SUCCESS_WITH_INFO) || (retcode == SQL_ERROR)) {
      // Get the status records.
      i = 1;
      while ((retcode = SQLGetDiagRec(SQL_HANDLE_STMT, hstmt, i, SqlState, &NativeError,Msg, sizeof(Msg), &MsgLen)) != SQL_NO_DATA) {
         //DisplayError(SqlState,NativeError,Msg,MsgLen);
         cout << SqlState << " - " << Msg << endl;
         i++;
      }

   }
   return;
}

void ExibaDados(SQLHSTMT &hstmt)
{
   // exibir os dados em forma de linhas
   // exibir cabecalho
   // montar linha e exibir
   SQLSMALLINT Count;
   SQLUINTEGER colSize;
   SQLCHAR nomeColuna[20];
   SQLCHAR linha[512];
   SQLCHAR cabecalho[512];
   SQLUINTEGER nPos = 0;
   SQLRETURN  retcode;
   SQLUINTEGER max;
   #define MAXCOL 30
   #define MAXLEN 50
   SQLCHAR matriz[MAXCOL][50];
   unsigned int tamanhos[MAXCOL];

   //strnset((char*)linha,' ',90);
   //strnset((char*)cabecalho,' ',90);

   // numero de colunas
   SQLNumResultCols(hstmt,&Count);

   Count = Count>MAXCOL?MAXCOL:Count;

   for(SQLSMALLINT i=1;i<=Count;i++) {
      // montar cabecalho
      SQLDescribeCol(
         hstmt,
         i,
         nomeColuna,
         sizeof(nomeColuna),
         NULL,
         NULL,
         &colSize,
         NULL,
         NULL
      );
      // fazer bind de colunas
      if ( nPos < 512 ) {

         //strncpy((char*)cabecalho+nPos,(const char*)nomeColuna,nCopiar);

         max = colSize>MAXLEN?MAXLEN:colSize;

         int nTam = strlen((char*)nomeColuna);

         for(int x=0;x < max;x++)
	            if (x<nTam)
               *(cabecalho+nPos+x) = nomeColuna[x];
            else
               *(cabecalho+nPos+x) = ' ';
         nPos += max;
       }


       SQLBindCol(
            hstmt,
            i,
            SQL_C_CHAR,
            matriz[i-1],
            max,
            NULL
       );

       tamanhos[i-1]=max;

   }


   // fazer fetch
   cout << cabecalho << endl;
   while (TRUE) {
      retcode = SQLFetch(hstmt);
      if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO){

         for(SQLSMALLINT i=1;i<=Count;i++)
            cout << setw(tamanhos[i-1]) << matriz[i-1];
         cout << endl;

      } else {
         break;
      }
   }
}


/*
SQLRETURN SQLBindCol(
   SQLHSTMT       StatementHandle,
   SQLUSMALLINT   ColumnNumber,
   SQLSMALLINT    TargetType,
   SQLPOINTER     TargetValuePtr,
   SQLINTEGER     BufferLength,
   SQLINTEGER *      StrLen_or_IndPtr);
*/



/*
SQLRETURN SQLDescribeCol(
1  SQLHSTMT       StatementHandle,
2  SQLSMALLINT    ColumnNumber,
3  SQLCHAR *         ColumnName,
4  SQLSMALLINT    BufferLength,
5  SQLSMALLINT *  NameLengthPtr,
6  SQLSMALLINT *  DataTypePtr,
7  SQLUINTEGER *  ColumnSizePtr,
8  SQLSMALLINT *  DecimalDigitsPtr,
9  SQLSMALLINT *  NullablePtr);
*/

