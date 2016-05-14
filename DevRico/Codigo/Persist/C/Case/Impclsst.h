//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IMapClassTable; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\impclsst.h


#ifndef IMpClssT_h
#define IMpClssT_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes

// IMapAtrColuna
#include "IMptrCln.h"

class IDataStore;

//## begin module.additionalDeclarations preserve=yes
#ifndef class
#ifdef GERAR_DLL
  #define class class __declspec(dllexport)
#else
  #define class class __declspec(dllimport)
#endif
#endif
//## end module.additionalDeclarations


//## Class: IMapClassTable
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class IMapClassTable
{
  //## begin IMapClassTable.initialDeclarations preserve=yes
  //## end IMapClassTable.initialDeclarations

  public:
    //## Constructors (generated)
      IMapClassTable();

      IMapClassTable(const IMapClassTable &right);

    //## Destructor (generated)
      ~IMapClassTable();

    //## Get and Set Operations for Has Relationships (generated)

      //## Documentation IMapClassTable::ListaAtributos.has
      ListaPointer<IMapAtrColuna> & ListaAtributos();

      //## Documentation IMapClassTable::DataStore.has
      //	guarda um datastore especifico para a classe mapeada.
      //	não pode ser nulo se o estado do objeto estiver
      //	isComplete
      //	deve ser sempre igual ao
      //	IPersistenteBroker::DefaultDataStore()
      IDataStore * DataStore();
      void setDataStore(IDataStore *const  value);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: nomeClasse
      IString nomeClasse();
      void setnomeClasse(const IString value);

      //## Attribute: nomeTabela
      IString nomeTabela();
      void setnomeTabela(const IString value);

      //## Attribute: isComplete
      //	se torna true quando as informaçoes complementares
      //	estiverem preenchidas (nome da tabela e tipo das colunas)
      bool isComplete();
      void setisComplete(const bool value);

    // Additional Public Declarations
      //## begin IMapClassTable.public preserve=yes
      //## end IMapClassTable.public


  protected:
    // Additional Protected Declarations
      //## begin IMapClassTable.protected preserve=yes
      //## end IMapClassTable.protected


  private:
    // Additional Private Declarations
      //## begin IMapClassTable.private preserve=yes
      //## end IMapClassTable.private


  private:  //## implementation
    // Data Members for Has Relationships

      //## begin IMapClassTable::ListaAtributos.has preserve=no  public: IMapAtrColuna { -> nRO}
      ListaPointer<IMapAtrColuna> m_ListaAtributos;
      //## end IMapClassTable::ListaAtributos.has

      //## begin IMapClassTable::DataStore.has preserve=no  public: IDataStore { -> 1RFO}
      IDataStore *m_DataStore;
      //## end IMapClassTable::DataStore.has

    // Data Members for Class Attributes

      //## begin IMapClassTable::nomeClasse.attr preserve=no  public: IString {U}
      IString m_nomeClasse;
      //## end IMapClassTable::nomeClasse.attr

      //## begin IMapClassTable::nomeTabela.attr preserve=no  public: IString {U}
      IString m_nomeTabela;
      //## end IMapClassTable::nomeTabela.attr

      //## begin IMapClassTable::isComplete.attr preserve=no  public: bool {U} false
      bool m_isComplete;
      //## end IMapClassTable::isComplete.attr

    // Additional Implementation Declarations
      //## begin IMapClassTable.implementation preserve=yes
#undef class
      //## end IMapClassTable.implementation

};

// Class IMapClassTable





#endif


