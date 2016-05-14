//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IColecaoPersistenteBase; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: g:\devrico\codigo\persist\c\case\iclcprss.h


#ifndef IClcPrss_h
#define IClcPrss_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes

// IQueryStatement
#include "IQrySttm.h"
// IObservador
#include "Ibsrvdor.h"
// IDirecaoFetch
#include "IDrcFtch.h"
// IEstadoColecao
#include "IstdClco.h"

class IPersistente;
class IOrdem;
class ICriterio;
class IDataStore;
class IBroker;

//## begin module.additionalDeclarations preserve=yes
#ifndef class
#ifdef GERAR_DLL
  #define class class __declspec(dllexport)
#else
  #define class class __declspec(dllimport)
#endif
#endif
//## end module.additionalDeclarations


//## Class: IColecaoPersistenteBase; Abstract
//	Esta classe faz operacoes de Select somente atraves de
//	um criterio opcional.
//	OPEN CURSOR cHandleCursor
//	Select <ID,campo1,...n> FROM <Tabela> [ WHERE [ campon
//	<rel> [campox|valor] [AND | OR] ...] TO cHandleCursor
//	O cursor fica aberto enquanto a instancia existir. e é
//	acessado para obter nova linha :
//	FECTH cHandleCursor
//	Portando a conexao com o meio persistente é igual a dura
//	o da instancia.
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: registra-se em; IBroker { -> F}
//## Uses: <unnamed>; IDirecaoFetch { -> }
//## Uses: <unnamed>; IPersistente { -> F}
//## Uses: <unnamed>; friend IPersistente { -> F}

class IColecaoPersistenteBase : public IObservador  //## Inherits: <unnamed>

{
  //## begin IColecaoPersistenteBase.initialDeclarations preserve=yes
  //## end IColecaoPersistenteBase.initialDeclarations

  public:
    //## Constructors (generated)
      IColecaoPersistenteBase();

      IColecaoPersistenteBase(const IColecaoPersistenteBase &right);

    //## Destructor (generated)
      virtual ~IColecaoPersistenteBase();


    //## Other Operations (specified)
      //## Operation: releaseDummy%910837611
      virtual void releaseDummy(IPersistente* pNulo) = 0;

      //## Operation: createDummy%908340282
      //	retorna um objeto IPersistente por valor, vazio. apenas
      //	para reconhecimento adiantado do mesmo (mapeamento). O
      //	IPersistente necessita possuir um construtor default,
      //	sem nenhum processamento.
      //## Semantics:
      //	talvez crie-se um construtor especial no IPersistente
      //	com um parametro escondido para evitar que o construtor
      //	seja modificado pelas subclasses.
      virtual IPersistente* createDummy() = 0;

      //## Operation: count%908340284
      //	número de objetos disponiveis. defalt é 0
      int count();

      //## Operation: isFim%908340285
      //	retorna true se não houver mais objetos na lista tanto
      //	para cima quanto para baixo.
      bool isFim();

      //## Operation: pronto%908340283
      //## Semantics:
      //	1. não aceita mais modificações
      //	2. processa a coleção
      //	3. muda o estado para executando.
      IColecaoPersistenteBase& pronto();

      //## Operation: goPrimeiro%908340286
      //	coloca o ponteiro de objetos no primeiro da lista.
      IColecaoPersistenteBase& goPrimeiro();

      //## Operation: goUltimo%908340287
      //	coloca o ponteiro de objetos no ultimo da lista.
      IColecaoPersistenteBase& goUltimo();

      //## Operation: goProximo%908340288
      //	avança o ponteiro de objetos para o proximo.
      IColecaoPersistenteBase& goProximo();

      //## Operation: goAnterior%908340289
      //	retrocede o ponteiro de objetos para o anterior.
      IColecaoPersistenteBase& goAnterior();

      //## Operation: ReavalieColecao%908340290
      //	causa o reprocessamento da coleção. count pode mudar.
      IColecaoPersistenteBase& ReavalieColecao();

      //## Operation: ReavaliePointer%908340291
      //	causa a reavaliação do ponteiro de objetos.
      IColecaoPersistenteBase& ReavaliePointer();

      //## Operation: addCriterio%908581620
      //	adiciona um criterio a lista theCriterio
      //## Semantics:
      //	somente no estado NOVO
      IColecaoPersistenteBase& addCriterio(ICriterio umCriterio);

      //## Operation: addOrdem%908581621
      //	adiciona objeto ordenador a lista de ordenacao.
      //## Semantics:
      //	somente no estado NOVO
      IColecaoPersistenteBase& addOrdem(IOrdem umaOrdem);

      //## Operation: crieInstancia%908340292
      //	cria um objeto do tipo mantido pela coleção e guarda-o
      //	no ponteiro InstanciaCorrente. que será deletado a cada
      //	nova chamada de crieInstancia e se a coleção for
      //	destruida. Inicie com NULL.
      virtual IPersistente& crieInstancia();

    //## Get and Set Operations for Has Relationships (generated)

      //## Documentation IColecaoPersistenteBase::theDataStore.has
      //	guarda o datastore do IPersistente para agilizar as
      //	chamadas.
      IDataStore * theDataStore();
      void settheDataStore(IDataStore *const  value);

      //## Documentation IColecaoPersistenteBase::theQuery.has
      //	guarda o query montado pelo broker para a coleção
      IQueryStatement & theQuery();
      void settheQuery(const IQueryStatement &value);

      //## Documentation IColecaoPersistenteBase::estado.has
      //	dependendo do estado, diversas operações devem ser
      //	recusadas.
      IEstadoColecao estado();
      void setestado(const IEstadoColecao value);

      //## Documentation IColecaoPersistenteBase::ListaCriterio.has
      Lista<ICriterio> & ListaCriterio();

      //## Documentation IColecaoPersistenteBase::ListaOrdem.has
      Lista<IOrdem> & ListaOrdem();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: InstanciaCorrente
      //	guarda o objeto corrente mantido pela coleção.
      IPersistente * InstanciaCorrente();

    // Additional Public Declarations
      //## begin IColecaoPersistenteBase.public preserve=yes
      //## end IColecaoPersistenteBase.public


  protected:

    //## Other Operations (specified)
      //## Operation: movePointer%908340293
      //	causa o ponteiro ser movimentado.
      IColecaoPersistenteBase& movePointer(IDirecaoFetch direcao = proximo);

    // Data Members for Class Attributes

      //## begin IColecaoPersistenteBase::InstanciaCorrente.attr preserve=no  public: IPersistente {R} 
      IPersistente *m_InstanciaCorrente;
      //## end IColecaoPersistenteBase::InstanciaCorrente.attr

    // Additional Protected Declarations
      //## begin IColecaoPersistenteBase.protected preserve=yes
      //## end IColecaoPersistenteBase.protected


  private:
    // Additional Private Declarations
      //## begin IColecaoPersistenteBase.private preserve=yes
      //## end IColecaoPersistenteBase.private


  private:  //## implementation
    // Data Members for Has Relationships

      //## begin IColecaoPersistenteBase::theDataStore.has preserve=no  public: IDataStore { -> 1RFO}
      IDataStore *m_theDataStore;
      //## end IColecaoPersistenteBase::theDataStore.has

      //## begin IColecaoPersistenteBase::theQuery.has preserve=no  public: IQueryStatement { -> 1VO}
      IQueryStatement m_theQuery;
      //## end IColecaoPersistenteBase::theQuery.has

      //## begin IColecaoPersistenteBase::estado.has preserve=no  public: IEstadoColecao { -> 1VO}
      IEstadoColecao m_estado;
      //## end IColecaoPersistenteBase::estado.has

      //## begin IColecaoPersistenteBase::ListaCriterio.has preserve=no  public: ICriterio { -> nVFO}
      Lista<ICriterio> m_ListaCriterio;
      //## end IColecaoPersistenteBase::ListaCriterio.has

      //## begin IColecaoPersistenteBase::ListaOrdem.has preserve=no  public: IOrdem { -> nVFO}
      Lista<IOrdem> m_ListaOrdem;
      //## end IColecaoPersistenteBase::ListaOrdem.has

    // Additional Implementation Declarations
      //## begin IColecaoPersistenteBase.implementation preserve=yes
#undef class
      //## end IColecaoPersistenteBase.implementation

};

// Class IColecaoPersistenteBase 





#endif


