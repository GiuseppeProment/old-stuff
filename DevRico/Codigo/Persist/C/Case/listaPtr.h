#pragma once

#ifndef ListaPointer_h
#define ListaPointer_h


//#include <iostream.h>
//#include <iomanip.h>
#include <stdlib.h>
#include "Trace.h"
/*

 guarda somente ponteiros

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
class  ListaPointer
{
private:
  void ** pp;
  int mCount;
  bool deleteObjectsOnExit;
public:
  __cdecl ListaPointer();
  __cdecl ~ListaPointer();
  T* __cdecl operator[](const int i) const;
  int __cdecl posicaoDe( T* objeto );
  ListaPointer& __cdecl adiciona( T* objeto );
  ListaPointer& __cdecl remove( int i );
  ListaPointer& __cdecl removeObjeto( T* objeto );
  ListaPointer& __cdecl troca(int x, int y);
  ListaPointer& __cdecl ordena( int __cdecl (*pf) ( T *x, T *y ) );
  int __cdecl count() { return mCount; };
  ListaPointer& __cdecl setApagueObjetosNaSaida( bool v );
};
// implementacao
#undef class

template <class T> __cdecl ListaPointer<T>::ListaPointer()
{
  pp = (void**) malloc( sizeof(void*) );
  mCount = 0;
  deleteObjectsOnExit = false;
}

template <class T> __cdecl ListaPointer<T>::~ListaPointer()
{
  // apagar objetos
  if ( deleteObjectsOnExit==true )
  {
	for (int i=1;i<=count();i++)
		delete (T*) *( pp+(i-1) );
  }
  free(pp);
}

template <class T> T* __cdecl ListaPointer<T>::operator[](const int i) const
{
  IASSERTIVA( i>mCount,"INDICE INVALIDO" )
//  return  (const T) * (T*) *( pp+(i-1) ) ;
    return  (T*) *( pp+(i-1) ) ;
}

template <class T> ListaPointer<T>& __cdecl ListaPointer<T>::adiciona( T* objeto )
{
  // alocar
  mCount++;
  void** ppTmp = (void**) realloc(pp,( sizeof(void*) ) * mCount);
  IASSERTIVA( ppTmp == NULL,"ALOCACAO MEM NEGADA" )
  pp = ppTmp;
  *(pp+mCount-1) = (void*) objeto;
  return *this;
}

template <class T> ListaPointer<T>& __cdecl ListaPointer<T>::remove( int i )
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

template <class T> int __cdecl ListaPointer<T>::posicaoDe( T* objeto )
{
  // varrer comparando
  int posicao=-1;
  for (int i=0;i<mCount && posicao==-1;i++)
    posicao = ( objeto == (T*) *( pp+(i) ) ? i : -1) ;
  return posicao==-1 ? -1 : ++posicao;
}

template <class T> ListaPointer<T>& __cdecl ListaPointer<T>::removeObjeto( T* objeto )
{
  remove( posicaoDe(objeto) );
  return *this;
}

template <class T> ListaPointer<T>& __cdecl ListaPointer<T>::troca(int x, int y)
{
  // testar indices e trocar
  IASSERTIVA( x>mCount||y>mCount,"INDICE INVALIDO" )
  void* ptmp = *( pp+(x-1) );
  *( pp+(x-1) ) = *( pp+(y-1) );
  *( pp+(y-1) ) = ptmp;
  return *this;
}

template <class T> ListaPointer<T>& __cdecl ListaPointer<T>::setApagueObjetosNaSaida( bool v )
{
  deleteObjectsOnExit=v;
  return *this;
}



template <class T> ListaPointer<T>& __cdecl ListaPointer<T>::ordena( int __cdecl (*pf) ( T *x, T *y ) )
{
  int interA,interB;
  for (interA=1;interA<=mCount;interA++)
    for(interB=1;interB<mCount;interB++)
      if ( pf( (T*) *( pp+(interB-1) ),(T*) *( pp+(interB) ) ) !=0 )
        troca(interB,interB+1);
  return *this;
}



#endif
