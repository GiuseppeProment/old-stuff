#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>
#include <string.h>
//#include <trace.h>

#include "IString.h"

#define IRASTROSTRING(texto)
#pragma package(smart_init)
/*
��� Destrutor �����������������������������������������������������������������
*/
IString::~IString()
{
  IRASTROSTRING("IString::~IString()\n")
  liberar();
}
/*
�� Construtor default ���������������������������������������������������������
*/
IString::IString()
{
  IRASTROSTRING("IString::IString()\n")
  alocar(sizeof(NULL));
  *(pBuffer+0)=NULL;
}
/*
�� Construtores Conversao �����������������������������������������������������
*/
IString::IString( const char* pValue )
{
  IRASTROSTRING("IString::IString( const char* pValue  )\n")
  int len = strlen( pValue );
  alocar(len);
  strcpy(pBuffer,pValue);
}
IString::IString( int value )
{
  char pValue[MAX_DIGITOS];
    #ifdef CBUILDER
	itoa(value,pValue,10);
    #else
	_itoa(value,pValue,10);
    #endif
	unsigned int len = strlen( pValue );
	alocar(len);
	strcpy(pBuffer,pValue);
}
IString::IString( short int value )
{
  char pValue[MAX_DIGITOS];
    #ifdef CBUILDER
	itoa(value,pValue,10);
    #else
	_itoa(value,pValue,10);
    #endif
	unsigned int len = strlen( pValue );
	alocar(len);
	strcpy(pBuffer,pValue);
}
IString::IString( double value, unsigned short int digitos )
{
  char pValue[MAX_DIGITOS];
  _gcvt(value,digitos,pValue);
	unsigned int len = strlen( pValue );
	alocar(len);
	strcpy(pBuffer,pValue);
}
IString::IString( float value , unsigned short int digitos )
{
  char pValue[MAX_DIGITOS];
  _gcvt(value,digitos,pValue);
	unsigned int len = strlen( pValue );
	alocar(len);
	strcpy(pBuffer,pValue);
}
/*
��� Construtor Copia ����������������������������������������������������������
*/
IString::IString( const IString& pAddress )
{
  IRASTROSTRING("IString::IString( IString& pAddress  )\n")
  int len = strlen( pAddress.pBuffer );
  alocar(len);
  strcpy(pBuffer,pAddress.pBuffer);
}
/*
��� Molde ���������������������������������������������������������������������
*/
IString::operator const char* () const
{
  IRASTROSTRING("IString::operator const char*()\n")
  return pBuffer;
}

IString::operator char* () const
{
  IRASTROSTRING("IString::operator const char*()\n")
  return pBuffer;
}
/*
�� Assignment �����������������������������������������������������������������
*/
IString& IString::operator=( const IString& pAddress )
{
  IRASTROSTRING("IString::operator=( const IString& pAddress )\n")
  unsigned int len = strlen( pAddress.pBuffer );
  if ( len > strlen(pBuffer) )
  {
    realocar(len);
  }
  strcpy(pBuffer,pAddress.pBuffer);
  return *this;
}
IString& IString::operator =( const char* pValue )
{
  IRASTROSTRING("IString::operator =( const char* pValue )\n")
  unsigned int len = strlen( pValue );
  if ( len > strlen(pBuffer) )
  {
    realocar(len);
  }
  strcpy(pBuffer,pValue);
  return *this;
}
IString& IString::operator =(int value)
{
  IString cTemp(value);
  *this = cTemp;
  return *this;
}
IString& IString::operator =(short int value)
{
  IString cTemp(value);
  *this = cTemp;
  return *this;
}
IString& IString::operator =(double value)
{
  IString cTemp(value);
  *this = cTemp;
  return *this;
}
/*
��� Concatena��o ��������������������������������������������������������������
*/
IString& IString::operator+=( const IString& pAddress )
{
	unsigned int len = strlen(pBuffer);
	unsigned int lenSrc = strlen(pAddress.pBuffer);
	realocar(len+lenSrc);
	strcpy(pBuffer+len,pAddress.pBuffer);
	return *this;
}
IString& IString::operator+=( const char* pValue )
{
	unsigned int len = strlen(pBuffer);
	unsigned int lenSrc = strlen(pValue);
	realocar(len+lenSrc);
	strcpy(pBuffer+len,pValue);
	return *this;
}
IString& IString::operator+=(int value)
{
	*this+= IString(value);
	return *this;
}
IString& IString::operator+=(short int value)
{
	*this+= IString(value);
	return *this;
}
IString& IString::operator+=(double value)
{
	*this+= IString(value);
	return *this;
}
IString IString::operator+(const IString& pDireita )
{
	IString oCopia( *this );
	oCopia += pDireita;
	return oCopia;
}
/*
��� Relacao �������������������������������������������������������������������
*/
bool IString::operator==(const IString &right) const
{
  IRASTROSTRING("IString::operator==(const IString &right)\n")
  if ( strcmp( right.pBuffer,pBuffer ) == 0 )
    return true;
  return false;
}
bool IString::operator!=(const IString &right) const
{
  IRASTROSTRING("IString::operator!=(const IString &right)\n")
  if ( strcmp( right.pBuffer,pBuffer ) != 0 )
    return true;
  return false;
}
bool IString::operator==(char* right) const
{
  IRASTROSTRING("IString::operator==(char* right)\n")
  return *this==IString(right);
}
bool IString::operator!=(char* right) const
{
  IRASTROSTRING("IString::operator=!(char* right)\n")
  return *this!=IString(right);
}
/*
��� UTILITARIAS ���������������������������������������������������������������
*/
void IString::realocar( unsigned int qtde )
{
  IRASTROSTRING("IString::realocar( unsigned int qtde )\n")
   if ((pBuffer =  (char *) realloc(pBuffer,qtde+1)) == NULL)
      cout << "Erro de realocacao" << endl;
	 tamanho = qtde;
}

void IString::alocar( unsigned int qtde )
{
  IRASTROSTRING("IString::alocar( unsigned int qtde )\n")
   if ((pBuffer = (char *) malloc(qtde+1)) == NULL)
      cout << "Erro de alocacao" << endl;
	 tamanho = qtde;
}

void IString::liberar()
{
  IRASTROSTRING("IString::liberar()\n");
   free( pBuffer );
}

bool IString::IsEmpty()
{
	int i=0;
	while (*(pBuffer+i)) {
		if ( *(pBuffer+i) != ' ' ) return false;
		i++;
	}
	return true;
}

IString& IString::setLenTo(unsigned int pTamanho)
{
	// ajustar para o tamanho solicitado
	realocar( pTamanho );
	//*(pBuffer+pTamanho) = NULL;
	return *this;
}

unsigned int IString::len()
{
	return tamanho;
}
