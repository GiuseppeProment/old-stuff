//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IAssociacao; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\iassccao.h


#ifndef IAssccao_h
#define IAssccao_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes

// IColecaoPersistenteBase
#include "IClcPrss.h"

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: IAssociacao; Parameterized Class
//	Faz a associacao entre dois IPersistentes, é um tipo de
//	IColecaoPersistenteBase, porem restrita, necessita
//	conhecer o ASSOCIADO, pois vai cria-los, do ASSOCIANDO
//	somente precisa conhecer IPersistente que possui o ID.
//	ASSOCIANDO.ID X ASSOCIADO.ID
//	Necessita da tabela de associacao que sempre sera
//	constituida de duas colunas IDAssociado,IDAssociando
//	sua clausula SQL sera sempre
//	SELECT IDAssociado FROM <tabela> WHERE IDAssociando =
//	ASSOCIANDO.ID
//	VAMOS TER QUE TRABALHAR COM BUFFERIZAÇÃO DE OBJETOS,
//	COISA QUE A COLEÇÃO NORMAL, NÃO VAI TER.
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


template <class PersistenteSubClass>
class IAssociacao : public IColecaoPersistenteBase  //## Inherits: <unnamed>

{
  //## begin IAssociacao.initialDeclarations preserve=yes
  //## end IAssociacao.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IAssociacao%908414769
      //	construtor unico. deve apresentar-se como observadora do
      //	persistente.
      //	Dono.NotificarEventosPara( *this );
      //	adiciona um criterio em si propria :
      //	"ID in ( Select AgregadoID from Broker::TabelaRelacao
      //	where AgregandoID = <Dono.ID> )"
      IAssociacao(IPersistente& Dono);

    //## Destructor (specified)
      //## Operation: ~IAssociacao%908596386
      //	Dono.PararNotificarEventosPara( *this );
      ~IAssociacao();

    // Additional Public Declarations
      //## begin IAssociacao.public preserve=yes
      //## end IAssociacao.public


  protected:
    // Additional Protected Declarations
      //## begin IAssociacao.protected preserve=yes
      //## end IAssociacao.protected


  private:
    // Additional Private Declarations
      //## begin IAssociacao.private preserve=yes
      //## end IAssociacao.private


  private:  //## implementation
    // Data Members for Associations

      //## Association: pelas subclasses%360723DB0172
      //## Role: IAssociacao::<the_IPersistente>
      //## begin IAssociacao::<the_IPersistente>.role preserve=no  public: IPersistente {0..n -> 1UH}
      //## end IAssociacao::<the_IPersistente>.role

    // Additional Implementation Declarations
      //## begin IAssociacao.implementation preserve=yes
      //## end IAssociacao.implementation

};

// Parameterized Class IAssociacao





#endif


