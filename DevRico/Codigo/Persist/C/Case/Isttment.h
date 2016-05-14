//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IStatement; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\docume~1\projetos\persist\codigo\casecode\isttment.h


#ifndef ISttment_h
#define ISttment_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes

// IBroker
#include "IBroker.h"
// ListaString
#include "LstStrng.h"
// IEstadoStatement
#include "IstdSttm.h"

//## begin module.additionalDeclarations preserve=yes
#ifndef class
#ifdef GERAR_DLL
  #define class class __declspec(dllexport)
#else
  #define class class __declspec(dllimport)
#endif
#endif
//## end module.additionalDeclarations


//## Class: IStatement; Abstract
//	Responsavel pela montagem de sentenças SQL
//	tabela, [ coluna = valor ], [insert|update|delete], id
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>; IBroker { -> }

class IStatement
{
  //## begin IStatement.initialDeclarations preserve=yes
  //## end IStatement.initialDeclarations

  public:
    //## Constructors (generated)
      IStatement();

      IStatement(const IStatement &right);

    //## Destructor (generated)
      ~IStatement();


    //## Other Operations (specified)
      //## Operation: addColuna%908596359
      //	adiciona o nome da coluna na lista theColunas, a ordem
      //	de adição é igual a ordem das colunas na sentença e
      //	equivale aos values na mesma ordem que são adicionados
      //	também neste metodo.
      IStatement& addColuna(IString& nome);

    //## Get and Set Operations for Has Relationships (generated)

      //## Documentation IStatement::theColunas.has
      //	acesso será pelo [] da classe IString
      ListaString & theColunas();
      void settheColunas(const ListaString &value);

      //## Documentation IStatement::theValues.has
      //	usado tanto para escrita quando para leitura.
      //	exemplo Insert / select  o acesso será feito pelo [] da
      //	classe IString.
      ListaString & theValues();
      void settheValues(const ListaString &value);

      //## Documentation IStatement::estado.has
      IEstadoStatement estado();
      void setestado(const IEstadoStatement value);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: linhasCount
      //	total de linhas afetadas/contadas pelo statement.
      //	no caso do select é totalLinhas e no caso de outros
      //	linhasAfetadas.
      int linhasCount();
      void setlinhasCount(const int value);

    // Additional Public Declarations
      //## begin IStatement.public preserve=yes
      //## end IStatement.public


  protected:

    //## Other Operations (specified)
      //## Operation: asSentencaSQL%908596360
      //	retorna a sentenca SQL completa.
      virtual IString asSentencaSQL() = 0;

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: tabelaAlvo
      IString tabelaAlvo();
      void settabelaAlvo(const IString value);

    // Additional Protected Declarations
      //## begin IStatement.protected preserve=yes
      //## end IStatement.protected


  private:
    // Additional Private Declarations
      //## begin IStatement.private preserve=yes
      //## end IStatement.private


  private:  //## implementation
    // Data Members for Has Relationships

      //## begin IStatement::theColunas.has preserve=no  public: ListaString { -> 1VO}
      ListaString m_theColunas;
      //## end IStatement::theColunas.has

      //## begin IStatement::theValues.has preserve=no  public: ListaString { -> 1VO}
      ListaString m_theValues;
      //## end IStatement::theValues.has

      //## begin IStatement::estado.has preserve=no  public: IEstadoStatement { -> 1VO}
      IEstadoStatement m_estado;
      //## end IStatement::estado.has

    // Data Members for Class Attributes

      //## begin IStatement::tabelaAlvo.attr preserve=no  protected: IString {U}
      IString m_tabelaAlvo;
      //## end IStatement::tabelaAlvo.attr

      //## begin IStatement::linhasCount.attr preserve=no  public: int {U} 0
      int m_linhasCount;
      //## end IStatement::linhasCount.attr

    // Additional Implementation Declarations
      //## begin IStatement.implementation preserve=yes
#undef class
      //## end IStatement.implementation

  //## begin IStatement.friends preserve=no
    friend class IDataStore;
    friend class IDataStoreODBC;
    friend class IDataStoreOracleActivex;
    friend class IBroker;
  //## end IStatement.friends
};

// Class IStatement





#endif


