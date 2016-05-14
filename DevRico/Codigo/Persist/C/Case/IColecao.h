//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IColecao; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\devrico\codigo\persist\c\case\icolecao.h


#ifndef IColecao_h
#define IColecao_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes

// IColecaoPersistenteBase
#include "IClcPrss.h"

class IPersistente;

//## begin module.additionalDeclarations preserve=yes

//## end module.additionalDeclarations


//## Class: IColecao; Parameterized Class
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


template <class PersistenteSubClass>
class IColecao : public IColecaoPersistenteBase  //## Inherits: <unnamed>

{
  //## begin IColecao.initialDeclarations preserve=yes
  //## end IColecao.initialDeclarations

  public:
    //## Constructors (generated)
      IColecao();

      IColecao(const IColecao<PersistenteSubClass> &right);

    //## Destructor (generated)
      virtual ~IColecao();


    //## Other Operations (specified)
      //## Operation: createDummy%908340282
      //	retorna um objeto IPersistente por valor, vazio. apenas
      //	para reconhecimento adiantado do mesmo (mapeamento). O
      //	IPersistente necessita possuir um construtor default,
      //	sem nenhum processamento.
      //## Semantics:
      //	talvez crie-se um construtor especial no IPersistente
      //	com um parametro escondido para evitar que o construtor
      //	seja modificado pelas subclasses.
      IPersistente* createDummy();

      //## Operation: releaseDummy%910837610
      void releaseDummy(IPersistente* pNulo);

      //## Operation: ObjectPointer%908407234
      PersistenteSubClass* ObjectPointer();

      //## Operation: ObjectRef%908407233
      PersistenteSubClass& ObjectRef();

      //## Operation: ObjectCopy%908340294
      //	devolve uma cópia do objeto apontado pelo ponteiro de
      //	objetos. vai ter que ser implementado pelas classes
      //	template.
      PersistenteSubClass ObjectCopy();

      //## Operation: crieInstancia%908340292
      //	cria um objeto do tipo mantido pela coleção e guarda-o
      //	no ponteiro InstanciaCorrente. que será deletado a cada
      //	nova chamada de crieInstancia e se a coleção for
      //	destruida. Inicie com NULL.
      IPersistente& crieInstancia();

    // Additional Public Declarations
      //## begin IColecao.public preserve=yes
      //## end IColecao.public


  protected:
    // Additional Protected Declarations
      //## begin IColecao.protected preserve=yes
      //## end IColecao.protected


  private:
    // Additional Private Declarations
      //## begin IColecao.private preserve=yes
      //## end IColecao.private


  private:  //## implementation
    // Data Members for Has Relationships

      //## Documentation IColecao::itens.has
      //## begin IColecao::itens.has preserve=no  implementation: IPersistente { -> 0..nVFO}
      //## end IColecao::itens.has

    // Additional Implementation Declarations
      //## begin IColecao.implementation preserve=yes
#undef class
      //## end IColecao.implementation

};

// Parameterized Class IColecao 





#endif


