//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IClassMap; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\devrico\codigo\persist\c\case\iclssmap.h


#ifndef IClssMap_h
#define IClssMap_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes

// IBroker
#include "IBroker.h"
// IKnowType
#include "IKnwType.h"

class IDataStore;
class IPersistente;
class IMapClassTable;

//## begin module.additionalDeclarations preserve=yes
#ifndef class
#ifdef GERAR_DLL
  #define class class __declspec(dllexport)
#else
  #define class class __declspec(dllimport)
#endif
#endif
//## end module.additionalDeclarations


//## Class: IClassMap
//	O mapeamento classe x tabela e membro x coluna pode ser
//	default pelos nomes de classe e membro ou caso exista o
//	arquivo mapClass.Ini, o mesmo sera lido pois tera as
//	correspondentes relacoes. o DataStore especifico de cada
//	classe não é guardado no INI
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>; IKnowType { -> }
//## Uses: <unnamed>; IPersistente { -> F}
//## Uses: <unnamed>; IDataStore { -> F}
//## Uses: <unnamed>; IBroker { -> }

class IClassMap 
{
  //## begin IClassMap.initialDeclarations preserve=yes
  //## end IClassMap.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: registraMembroClasse%907292333
      //	no caso de não especificar o tipo, tipo será StringFixa
      //	de tamanho = tamanho.
      static void registraMembroClasse(IPersistente& anPersistente, char* nomeMembro, unsigned int offset, unsigned int tamanho, IKnowType tipoMembro = IsStringFix, unsigned int varSizeMax = 0, bool isProxy = false);

      //## Operation: getMapaFor%907292334
      static IMapClassTable& getMapaFor(IPersistente &anPersist);

      //## Operation: getMapaFor%966048264
      //	retorna o IMapClassTable de uma classe, dado seu nome
      //	como argumento.
      static IMapClassTable& getMapaFor(char* NomeClasse);

      //## Operation: inicialize%909189394
      //	inicialização.
      static void inicialize();

      //## Operation: asDebug%909716769
      static IString asDebug();

      //## Operation: removeDataStore%958533755
      //	Remove todas as Tabelas de mapeamento que estao usando o
      //	datastore removido.
      static void removeDataStore(IDataStore& dataStore);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: ColunaId
      //	nome da coluna chave primaria que existira em todas
      //	tabelas.
      static IString ColunaId();
      static void setColunaId(const IString value);

    // Additional Public Declarations
      //## begin IClassMap.public preserve=yes
      //## end IClassMap.public


  protected:
    // Additional Protected Declarations
      //## begin IClassMap.protected preserve=yes
      //## end IClassMap.protected


  private:

    //## Other Operations (specified)
      //## Operation: searchClassName%907292335
      //	procura na lista de IMapClassTable pelo objeto igual ao
      //	nome e retorna o indice.
      //	retorna -1 se nao achou
      static int searchClassName(char* nomeClasse);

      //## Operation: insertClassInfoOf%907292336
      //	chamado quando search() retorna -1 para um objeto
      //	anPersist.
      //	chama self.resolveMapa ao final
      //## Semantics:
      //	chama o OnClassInfo no anPersist.
      static void insertClassInfoOf(IPersistente& anPersist);

      //## Operation: resolveMapa%908596388
      //	resolve nome da tabela, colunas e tipos e torna estado
      //	do mapa isComplete true.
      //	processa as informações do MapClass.ini
      static void resolveMapa(void );

      //## Operation: setDataStoreFor%908596387
      //	atualiza o meDatastore para uma subclasse de
      //	IPersistente.
      static void setDataStoreFor(IPersistente& anPersiste, IDataStore& anDataStore);

    //## Get and Set Operations for Has Relationships (generated)

      //## Documentation IClassMap::mapaCorrente.has
      //	somente para trabalho durante operacoes internas,
      //	normalmente esta com NULL.
      static IMapClassTable * mapaCorrente();
      static void setmapaCorrente(IMapClassTable *const  value);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: TabelaRelacao
      static IString TabelaRelacao();
      static void setTabelaRelacao(const IString value);

    // Additional Private Declarations
      //## begin IClassMap.private preserve=yes
      //## end IClassMap.private


  private:  //## implementation
    // Data Members for Has Relationships

      //## Documentation IClassMap::ListaMapClassTable.has
      //## begin IClassMap::ListaMapClassTable.has preserve=no  private: static IMapClassTable { -> nRFO}
      static ListaPointer<IMapClassTable> m_ListaMapClassTable;
      //## end IClassMap::ListaMapClassTable.has

      //## begin IClassMap::mapaCorrente.has preserve=no  private: static IMapClassTable { -> 1RFO}
      static IMapClassTable *m_mapaCorrente;
      //## end IClassMap::mapaCorrente.has

    // Data Members for Class Attributes

      //## begin IClassMap::TabelaRelacao.attr preserve=no  private: static IString {V} "Relacao"
      static IString m_TabelaRelacao;
      //## end IClassMap::TabelaRelacao.attr

      //## begin IClassMap::ColunaId.attr preserve=no  public: static IString {V} "ID"
      static IString m_ColunaId;
      //## end IClassMap::ColunaId.attr

    // Additional Implementation Declarations
      //## begin IClassMap.implementation preserve=yes
#undef class
      //## end IClassMap.implementation

  //## begin IClassMap.friends preserve=no
    friend class IPersistente;
    friend class IBroker;
  //## end IClassMap.friends
};

// Class IClassMap 





#endif


