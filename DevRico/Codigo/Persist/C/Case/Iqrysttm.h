//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IQueryStatement; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\docume~1\projetos\persist\codigo\casecode\iqrysttm.h


#ifndef IQrySttm_h
#define IQrySttm_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes

// IStatement
#include "ISttment.h"

class IOrdem;
class ICriterio;

//## begin module.additionalDeclarations preserve=yes
#ifndef class
#ifdef GERAR_DLL
  #define class class __declspec(dllexport)
#else
  #define class class __declspec(dllimport)
#endif
#endif
//## end module.additionalDeclarations


//## Class: IQueryStatement
//	SELECT nomeColuna,... FROM <tabela>
//	[ WHERE where_clausula ]
//	[ ORDER BY nomeColuna,... ]
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class IQueryStatement : public IStatement  //## Inherits: <unnamed>

{
  //## begin IQueryStatement.initialDeclarations preserve=yes
  //## end IQueryStatement.initialDeclarations

  public:
    //## Constructors (generated)
      IQueryStatement();

      IQueryStatement(const IQueryStatement &right);

    //## Destructor (generated)
      ~IQueryStatement();


    //## Other Operations (specified)
      //## Operation: asSentencaSQL%908596354
      IString asSentencaSQL();

    //## Get and Set Operations for Has Relationships (generated)

      //## Documentation IQueryStatement::<m_theIOrdem>.has
      Lista<IOrdem>* theIOrdem();
      void settheIOrdem(Lista<IOrdem>*const  value);

      //## Documentation IQueryStatement::<m_theICriterio>.has
      Lista<ICriterio>* theICriterio();
      void settheICriterio(Lista<ICriterio>*const  value);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: isFim
      //	true se durante alguma movimentação o fim ou inicio das
      //	linhas é alcançado.
      bool isFim();
      void setisFim(const bool value);

      //## Attribute: ValueID
      //	para transferencia do valor do ID
      //	tamanho do ID real. (gravado).
      IString & ValueID();
      void setValueID(const IString &value);

    // Data Members for Class Attributes

      //## Attribute: lowLayerSlot
      //	slot para ser usado pela camada de mais baixo nível
      //	representada pelo IDataStore para guardar informações
      //	sobre o cursor/canal. poder ser desde um handle de OBCD
      //	até uma estrutura que registra tabela,registro,indice no
      //	caso de Xbase puro.
      //## begin IQueryStatement::lowLayerSlot.attr preserve=no  public: void* {UA} NULL
      void* m_lowLayerSlot;
      //## end IQueryStatement::lowLayerSlot.attr

    // Additional Public Declarations
      //## begin IQueryStatement.public preserve=yes
      //## end IQueryStatement.public


  protected:
    // Additional Protected Declarations
      //## begin IQueryStatement.protected preserve=yes
      //## end IQueryStatement.protected


  private:
    // Additional Private Declarations
      //## begin IQueryStatement.private preserve=yes
      //## end IQueryStatement.private


  private:  //## implementation
    // Data Members for Has Relationships

      //## begin IQueryStatement::<m_theIOrdem>.has preserve=no  public: IOrdem { -> nVF}
      Lista<IOrdem>* m_theIOrdem;
      //## end IQueryStatement::<m_theIOrdem>.has

      //## begin IQueryStatement::<m_theICriterio>.has preserve=no  public: ICriterio { -> nVF}
      Lista<ICriterio>* m_theICriterio;
      //## end IQueryStatement::<m_theICriterio>.has

    // Data Members for Class Attributes

      //## begin IQueryStatement::isFim.attr preserve=no  public: bool {U} false
      bool m_isFim;
      //## end IQueryStatement::isFim.attr

      //## begin IQueryStatement::ValueID.attr preserve=no  public: IString {V} 
      IString m_ValueID;
      //## end IQueryStatement::ValueID.attr

    // Additional Implementation Declarations
      //## begin IQueryStatement.implementation preserve=yes
#undef class
      //## end IQueryStatement.implementation

};

// Class IQueryStatement 





#endif


