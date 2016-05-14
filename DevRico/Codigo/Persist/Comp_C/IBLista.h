//## begin module.cm preserve=no
//	Código adequado para CBuilder (Componente)
//## end module.cm

//## begin module.cp preserve=no
//	(c) 2000 Giuseppe Enrico Proment Junior
//## end module.cp

//## Module: IBLista; Package specification
//## Subsystem: I++ para CBuilder
//## Source file: g:\devrico\codigo\persist\comp_c\iblista.h


#ifndef IBLista_h
#define IBLista_h 1

//## begin module.additionalIncludes preserve=no
#include <ComCtrls.hpp>
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IBColecao
#include "IBCole~1.h"
// Utilitarias
#include "IUtil.h"
// IComponent
#include "ICompo~1.h"
// IPersistente
#include "IPrsstnt.h"

//## begin module.declarations preserve=no
#pragma option push -pr
#define class class PACKAGE
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: IColuna
//## Category: I++ para CBuilder
//## Subsystem: I++ para CBuilder
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class IColuna : public TCollectionItem  //## Inherits: <unnamed>

{
  //## begin IColuna.initialDeclarations preserve=yes
  //## end IColuna.initialDeclarations

  public:
    // Additional Public Declarations
      //## begin IColuna.public preserve=yes
	__published:
      __property
				int indexDoAtributo =
				{ read = m_indexDoAtributo,
					write = m_indexDoAtributo
				};
      __property
				AnsiString descricao =
				{ read = m_descricao,
					write = m_descricao
				};
       __property	
 				int largura =
				{ read = m_largura,
					write = m_largura
				};
      //## end IColuna.public


  protected:
    // Additional Protected Declarations
      //## begin IColuna.protected preserve=yes
      //## end IColuna.protected


  private:
    // Data Members for Class Attributes

      //## Attribute: indexDoAtributo
      //	ordem do atributo obtido da classe representada.
      //## begin IColuna::indexDoAtributo.attr preserve=no  public: int {V} 
      int m_indexDoAtributo;
      //## end IColuna::indexDoAtributo.attr

      //## Attribute: descricao
      //## begin IColuna::descricao.attr preserve=no  public: AnsiString {U} 
      AnsiString m_descricao;
      //## end IColuna::descricao.attr

      //## Attribute: largura
      //	largura em caracteres
      //## begin IColuna::largura.attr preserve=no  public: int {U} 
      int m_largura;
      //## end IColuna::largura.attr

    // Additional Private Declarations
      //## begin IColuna.private preserve=yes
      //## end IColuna.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin IColuna.implementation preserve=yes
      //## end IColuna.implementation

};



//## Class: IBLista
//	Lista de objetos persistentes, observa a coleção que
//	representa, reagindo a mudancas de seu estado.
//## Category: I++ para CBuilder
//## Subsystem: I++ para CBuilder
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: colunas; TCollection {1 -> }
//## Uses: <unnamed>; IColuna { -> }
//## Uses: <unnamed>; IPersistente { -> }

class IBLista : public TCustomListView  //## Inherits: <unnamed>

{
  //## begin IBLista.initialDeclarations preserve=yes
  //## end IBLista.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IBLista%960264087
      IBLista(TComponent* Dono);

    //## Destructor (generated)
      ~IBLista();


    //## Other Operations (specified)
      //## Operation: quandoEventoNotificacao%907215653
      //	Será passado na construção do INotificadorIndireto no
      //	argumento IQuandoEventoClosure.
      void quandoEventoNotificacao(IEventoNotificacaoBuilder& evento);

      //## Operation: montar%976927453
      //	montar colunas
      void montar();

      //## Operation: esvaziar%976927454
      //	elimina os objetos
      void esvaziar();

    //## Get and Set Operations for Has Relationships (generated)

      //## Documentation IBLista::colunas.has
      const TCollection * getcolunas() const;
      void setcolunas(TCollection *const  value);

    // Additional Public Declarations
      //## begin IBLista.public preserve=yes
  __published:
      __property
				TCollection* colunas =
				{
					read = getcolunas,
					write = setcolunas
				};
      __property
        IBColecao* ColecaoRepresentada =
          { read = getColecaoRepresentada,
            write = setColecaoRepresentada
          };
      __property ViewStyle;
      __property Columns;
      //## end IBLista.public


  protected:

    //## Other Operations (specified)
      //## Operation: WriteState%960264089
      virtual void WriteState(TWriter* Writer);

      //## Operation: Loaded%959306787
      //	método herdado do TComponent que é chamado quando o
      //	componente acabou de ser lido da fila ( arquivo...) e
      //	teve suas propriedades 'property' escritas.
      virtual void Loaded();

    // Data Members for Has Relationships

      //## begin IBLista::ObservadorInterno.has preserve=no  private: INotificadorIndireto { -> 1RO}
      INotificadorIndireto *m_ObservadorInterno;
      //## end IBLista::ObservadorInterno.has

      //## begin IBLista::ColecaoRepresentada.has preserve=no  private: IBColecao { -> 0..1RO}
      IBColecao *m_ColecaoRepresentada;
      //## end IBLista::ColecaoRepresentada.has

      //## begin IBLista::colunas.has preserve=no  public: TCollection { -> 1RO}
      TCollection *m_colunas;
      //## end IBLista::colunas.has

    // Additional Protected Declarations
      //## begin IBLista.protected preserve=yes
      //## end IBLista.protected


  private:

    //## Other Operations (specified)
      //## Operation: CarregarObjetos%960264088
      //	Carrega os objetos da coleção como itens da lista.
      void CarregarObjetos();

      //## Operation: setColecaoRepresentada%960521281
      void setColecaoRepresentada(IBColecao* colecao);

    //## Get and Set Operations for Has Relationships (generated)

      //## Documentation IBLista::ObservadorInterno.has
      //	Utilizado para receber e enviar eventos.
      const INotificadorIndireto * getObservadorInterno() const;
      void setObservadorInterno(INotificadorIndireto *const  value);

      //## Documentation IBLista::ColecaoRepresentada.has
      //	É a coleção de onde a lista solicitará objetos para
      //	exibir ao usuário.
      IBColecao * getColecaoRepresentada();

    // Additional Private Declarations
      //## begin IBLista.private preserve=yes
      //## end IBLista.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin IBLista.implementation preserve=yes
#undef class
#pragma option pop
      //## end IBLista.implementation

};



// Class IBLista 





// Class IColuna 





#endif


