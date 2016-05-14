#pragma once

#ifndef Lista_h
#define Lista_h


//#include <iostream.h>
//#include <iomanip.h>
#include <stdlib.h>
#include "Trace.h"
/*

 guarda somente referencias a objetos
 nao foi feita para guardar objetos.
 templates nao sao possiveis guardar em DLL (obvious...)

*/

// interface

template <class T>
#ifndef class
#ifdef GERAR_DLL
  #define class class __declspec(dllexport)
#else
  #define class class __declspec(dllimport)
#endif
#endif
class Lista
{
private:
  void ** pp;
  int mCount;
  bool deleteObjectsOnExit;
public:
  Lista();
  ~Lista();
  T& operator[](int i);
  int posicaoDe( T& objeto );
  Lista& adiciona( T& objeto );
  Lista& remove( int i );
  Lista& removeObjeto( T& objeto );
  Lista& troca(int x, int y);
  Lista& ordena( int (*pf) ( T &x, T &y ) );
  int count() { return mCount; };
  Lista& setApagueObjetosNaSaida( bool v );
};
// implementacao

#undef class

template <class T> Lista<T>::Lista()
{
  pp = (void**) malloc( sizeof(void*) );
  mCount = 0;
  deleteObjectsOnExit = false;
}

template <class T> Lista<T>::~Lista()
{
  // apagar objetos
  if ( deleteObjectsOnExit==true )
  {
	for (int i=1;i<=count();i++)
		delete (T*) *( pp+(i-1) );
  }
  free(pp);
}

template <class T> T& Lista<T>::operator[](int i)
{
  IASSERTIVA( i>mCount,"INDICE INVALIDO" )
  //return  (T) * (T*) *( pp+(i-1) ) ;
  return  * (T*) *( pp+(i-1) ) ;
}

template <class T> Lista<T>& Lista<T>::adiciona( T& objeto )
{
  // alocar
  mCount++;
  void** ppTmp = (void**) realloc(pp,( sizeof(void*) ) * mCount);
  IASSERTIVA( ppTmp == NULL,"ALOCACAO MEM NEGADA" )
  pp = ppTmp;
  *(pp+mCount-1) = (void*) &objeto;
  return *this;
}

template <class T> Lista<T>& Lista<T>::remove( int i )
{
  // criar tmp -1
  // copiar menos a posicao desejada
  IASSERTIVA( i>mCount || i<=0 ,"INDICE INVALIDO" )
  mCount--;
  void** ppTmp = (void**) malloc( ( sizeof(void*) ) * mCount);
  IASSERTIVA( ppTmp == NULL,"ALOCACAO MEM NEGADA" )
  for (int x=0,y=0;x<mCount+1;x++)
  {
    if ( x != (i-1) )
    {
      *(ppTmp+y) = *(pp+x);
      y++;
    }
  }
  // liberar e fazer troca
  free( pp );
  pp = ppTmp;
  return *this;
}

template <class T> int Lista<T>::posicaoDe( T& objeto )
{
  // varrer comparando
  int posicao=-1;
  for (int i=0;i<mCount && posicao==-1;i++)
    posicao = ( &objeto == (T*) *( pp+(i) ) ? i : -1) ;
  return posicao==-1 ? -1 : ++posicao;
}

template <class T> Lista<T>& Lista<T>::removeObjeto( T& objeto )
{
  remove( posicaoDe(objeto) );
  return *this;
}

template <class T> Lista<T>& Lista<T>::troca(int x, int y)
{
  // testar indices e trocar
  IASSERTIVA( x>mCount||y>mCount,"INDICE INVALIDO" )
  void* ptmp = *( pp+(x-1) );
  *( pp+(x-1) ) = *( pp+(y-1) );
  *( pp+(y-1) ) = ptmp;
  return *this;
}

template <class T> Lista<T>& Lista<T>::setApagueObjetosNaSaida( bool v )
{
  deleteObjectsOnExit=v;
  return *this;
}

template <class T> Lista<T>& Lista<T>::ordena( int (*pf) ( T& x, T& y ) )
{
  int interA,interB;
  for (interA=1;interA<=mCount;interA++)
    for(interB=1;interB<mCount;interB++)
      if ( pf( (T) * (T*) *( pp+(interB-1) ),(T) * (T*) *( pp+(interB) ) ) !=0 )
        troca(interB,interB+1);
  return *this;
}

#endif
