#ifndef IString_h
#define IString_h

// interface
#pragma once

#define MAX_DIGITOS 30

struct IStringStruct
{
  char* pBuffer;
};

#ifndef class
#ifdef CBUILDER
  #ifdef GERAR_DLL
    #define class class __declspec(package)
  #else
    #define class class __declspec(package)
  #endif
#else
  #ifdef GERAR_DLL
    #define class class __declspec(dllexport)
  #else
    #define class class __declspec(dllimport)
  #endif
#endif
#endif


class  IString :public IStringStruct
{
public:
	unsigned int len();
	IString& setLenTo( unsigned int pTamanho);
	bool IsEmpty();
/*
อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
*/
  // construtores default
  IString();
  // construtores double/float/short int
  IString( const char* pValue );
  IString( int value );
  IString( short int value );
  IString( double value ,unsigned short int digitos=MAX_DIGITOS);
  IString( float value ,unsigned short int digitos=MAX_DIGITOS);
  // construtor copia
  IString( const IString& pAddress );
  // destrutor
  ~IString();
  // molde
  operator char*() const;
  operator const char*() const;
  // assignment
  IString& operator=( const IString& pAddress );
  IString& operator=( const char* pValue );
  IString& operator=(int value);
  IString& operator=(double value);
  IString& operator=(short int value);
  // soma
  IString& operator+=( const IString& pAddress );
  IString& operator+=( const char* pValue );
  IString& operator+=(int value);
  IString& operator+=(short int value);
  IString& operator+=(double value);
  IString operator+(const IString& pDireita );
  // igualdade
  bool operator==(char* right) const;
  bool operator==(const IString &right) const;
  bool operator!=(char* right) const;
  bool operator!=(const IString &right) const;
private:
	unsigned int tamanho;
  // utilitarias
  void realocar( unsigned int qtde );
  void alocar( unsigned int qtde );
  void liberar();
};

#undef class

#endif
