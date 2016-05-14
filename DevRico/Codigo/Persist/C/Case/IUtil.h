#pragma warning( disable : 4251 )
#pragma once


//#include <trace.h>


#include <string.h>
#include <IString.h>
#include <Lista.h>
#include <ListaPtr.h>
#include <IStdGnRc.h>
#include <Typevnto.h>
#include <IErro.h>
#include <offset.h>




char* DecToBin(unsigned int nNumber, char*buffer, int);
char BinToByte(const char * cNumber, int);

// instanciação forçada
/*
class ICriterio;
class IOrdem;
class IObservador;
class IMapAtrColuna;
// IColecaoPersistenteBase
#include "IClcPrss.h"
// IMapClassTable
#include "IMpClssT.h"
// IDataStore
#include "IDtStore.h"
template class Lista<IDataStore>;
template class ListaPointer<IColecaoPersistenteBase>;
template class Lista<IString>;
template class Lista<ICriterio>;
template class Lista<IOrdem>;
template class ListaPointer<IObservador>;
template class ListaPointer<IMapAtrColuna>;
template class ListaPointer<IMapClassTable>;
*/

//#pragma comment(lib,"Util.lib")
//#pragma comment(linker,"")
//#pragma message("mensagem")

