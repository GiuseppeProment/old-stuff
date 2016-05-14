#pragma once

#ifndef Trace_h
#define Trace_h 1

#ifdef TESTAR

#include <iostream.h>
#include <iomanip.h>
/*
 void IAnsiErro(int x, char* msg="Erro")
{
  if ( x )
  {
    cout << msg << endl;
  }
}
*/
#define IASSERTIVA(expBool,texto) /*IAnsiErro(expBool,texto);*/
#define IRASTRO(texto) cout << "IRastro: " << texto << endl;
#pragma message("*** RASTREAMENTO HABILITADO ***")

#else

#define IASSERTIVA(expBool,texto)
//#ifdef WIN32
//#include <AFX.h>
//#define IRASTRO(texto) TRACE(texto);
//#else
#define IRASTRO(texto)
//#endif

#endif

#endif
