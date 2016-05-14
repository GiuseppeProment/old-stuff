//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IDataStore; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\idtstore.h


#ifndef IDtStore_h
#define IDtStore_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes

// IDirecaoFetch
#include "IDrcFtch.h"

class IQueryStatement;
class IModifyStatement;
class IStatement;

//## begin module.additionalDeclarations preserve=yes
#ifndef class
#ifdef GERAR_DLL
  #define class class __declspec(dllexport)
#else
  #define class class __declspec(dllimport)
#endif
#endif
//## end module.additionalDeclarations


//## Class: IDataStore; Abstract
//	responsável pela implementação específica para cada tipo
//	de meio.
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>; friend IStatement { -> F}
//## Uses: <unnamed>; IDirecaoFetch { -> }
//## Uses: <unnamed>; IModifyStatement { -> F}
//## Uses: <unnamed>; IQueryStatement { -> F}

class IDataStore
{
  //## begin IDataStore.initialDeclarations preserve=yes
  //## end IDataStore.initialDeclarations

  public:
    //## Constructors (generated)
      IDataStore();

      IDataStore(const IDataStore &right);

    //## Destructor (generated)
      ~IDataStore();


    //## Other Operations (specified)
      //## Operation: execute%908596370
      //	deve afetar somente 1 linha, senão é merda.
      virtual bool execute(IModifyStatement& setenca);

      //## Operation: execute%908596371
      virtual bool execute(IQueryStatement& anQuery);

      //## Operation: requisitaDados%908596372
      //## Semantics:
      //	utiliza o lowLayerSlot :
      //	1. checa se não é 0
      //	2. checa o estado do Statement
      //	3. obtem os dados de canal do lowLayerSlot que são
      //	dependentes da implementação.
      //	4. copia os dados do canal para o theValues no IQuery
      //	5. se não há dados (eof/bof) ajusta isFim do Query para
      //	true. não muda os dados.
      virtual IDataStore& requisitaDados(IQueryStatement& theQuery, IDirecaoFetch tipo = proximo);

      //## Operation: isFim%908596373
      //	retorna true se a operação de moveCursor encontra o
      //	inicio ou fim dos dados.
      virtual bool isFim(IQueryStatement& theQuery);

      //## Operation: libereQuery%908596374
      //	libera alocações que estão guardadas no
      //	IQueryStatement.lowLayerSlot
      virtual IDataStore& libereQuery(IQueryStatement& anQuery);

      //## Operation: ligar%910153638
      //	conecta ao banco ou prepara-se para servir.
      virtual IDataStore& ligar();

      //## Operation: desligar%910153639
      virtual IDataStore& desligar();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: nome
      //	nome da datastore.
      IString nome();
      void setnome(const IString value);

      //## Attribute: usuario
      IString usuario();
      void setusuario(const IString value);

      //## Attribute: senha
      IString senha();
      void setsenha(const IString value);

    // Additional Public Declarations
      //## begin IDataStore.public preserve=yes
      //## end IDataStore.public


  protected:
    // Additional Protected Declarations
      //## begin IDataStore.protected preserve=yes
      //## end IDataStore.protected


  private:
    // Additional Private Declarations
      //## begin IDataStore.private preserve=yes
      //## end IDataStore.private


  private:  //## implementation
    // Data Members for Class Attributes

      //## begin IDataStore::nome.attr preserve=no  public: IString {U} "DEFAULT"
      IString m_nome;
      //## end IDataStore::nome.attr

      //## begin IDataStore::usuario.attr preserve=no  public: IString {V}
      IString m_usuario;
      //## end IDataStore::usuario.attr

      //## begin IDataStore::senha.attr preserve=no  public: IString {V}
      IString m_senha;
      //## end IDataStore::senha.attr

    // Additional Implementation Declarations
      //## begin IDataStore.implementation preserve=yes
#undef class
      //## end IDataStore.implementation

};

// Class IDataStore





#endif


