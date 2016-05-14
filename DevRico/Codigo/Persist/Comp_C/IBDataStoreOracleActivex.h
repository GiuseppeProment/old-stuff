//## begin module.cm preserve=no
//	Código adequado para CBuilder (Componente)
//## end module.cm

//## begin module.cp preserve=no
//	(c) 2000 Giuseppe Enrico Proment Junior
//## end module.cp

//## Module: IBDataStoreOracleActivex; Package specification
//## Subsystem: I++ para CBuilder
//## Source file: g:\devrico\codigo\persist\comp_c\ibdata~1.h


#ifndef IBDtStrr_h
#define IBDtStrr_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IComponent
#include "ICompo~1.h"
// IDataStoreOracleActivex
#include "IDtStrrc.h"

//## begin module.declarations preserve=no
#pragma option push -pr
#define class class PACKAGE

//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: IBDataStoreOracleActivex
//	Ativo
//	NomeConexao
//	Usuario
//	Senha
//	NomeDB
//## Category: I++ para CBuilder
//## Subsystem: I++ para CBuilder
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class IBDataStoreOracleActivex : public IBDataStore  //## Inherits: <unnamed>

{
  //## begin IBDataStoreOracleActivex.initialDeclarations preserve=yes
  //## end IBDataStoreOracleActivex.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IBDataStoreOracleActivex%960005300
      IBDataStoreOracleActivex(TComponent* Dono);

    //## Destructor (generated)
      ~IBDataStoreOracleActivex();


    //## Other Operations (specified)
      //## Operation: setAtivo%960005301
      void setAtivo(bool isLigar);

      //## Operation: setNomeConexao%960005302
      void setNomeConexao(System::AnsiString nome);

      //## Operation: setUsuario%960005303
      void setUsuario(System::AnsiString nome);

      //## Operation: setSenha%960005304
      void setSenha(System::AnsiString nome);

      //## Operation: setNomeDB%960005305
      void setNomeDB(System::AnsiString nome);

      //## Operation: getNomeConexao%960005306
      System::AnsiString getNomeConexao();

      //## Operation: getUsuario%960005307
      System::AnsiString getUsuario();

      //## Operation: getSenha%960005308
      System::AnsiString getSenha();

      //## Operation: getNomeDB%960005309
      System::AnsiString getNomeDB();

      //## Operation: fazerRevisao%959658641
      void fazerRevisao();

    // Data Members for Class Attributes

      //## Attribute: Revisado
      //## begin IBDataStoreOracleActivex::Revisado.attr preserve=no  public: static TypeEvento {V} "IBDataStoreOracleActivex::Revisado"
      static TypeEvento Revisado;
      //## end IBDataStoreOracleActivex::Revisado.attr

    // Additional Public Declarations
      //## begin IBDataStoreOracleActivex.public preserve=yes
  __published:
	  __property bool
      Ativo = {read=m_Ativo, write=setAtivo, default=false};
    __property System::AnsiString
      NomeConexao = {read=getNomeConexao, write=setNomeConexao};
    __property System::AnsiString
      Usuario = {read=getUsuario,write=setUsuario};
    __property System::AnsiString
      Senha = {read=getSenha,write=setSenha};
    __property System::AnsiString
      NomeDB = {read=getNomeDB,write=setNomeDB};

      //## end IBDataStoreOracleActivex.public


  protected:
    // Data Members for Has Relationships

      //## Documentation IBDataStoreOracleActivex::oOracle.has
      //## begin IBDataStoreOracleActivex::oOracle.has preserve=no  private: IDataStoreOracleActivex { -> 1VO}
      IDataStoreOracleActivex m_oOracle;
      //## end IBDataStoreOracleActivex::oOracle.has

    // Additional Protected Declarations
      //## begin IBDataStoreOracleActivex.protected preserve=yes
      //## end IBDataStoreOracleActivex.protected


  private:

    //## Other Operations (specified)
      //## Operation: mudancaEstadoPermitida%960005310
      //	indica se é permitida a mudança de propriedades (ex: se
      //	está conectado, não pode mudar o nome de usuário ).
      bool mudancaEstadoPermitida();

    // Data Members for Class Attributes

      //## Attribute: Ativo
      //## begin IBDataStoreOracleActivex::Ativo.attr preserve=no  private: bool {V} false
      bool m_Ativo;
      //## end IBDataStoreOracleActivex::Ativo.attr

      //## Attribute: NomeConexao
      //## begin IBDataStoreOracleActivex::NomeConexao.attr preserve=no  private: System::AnsiString {V} 
      //## end IBDataStoreOracleActivex::NomeConexao.attr

      //## Attribute: Usuario
      //## begin IBDataStoreOracleActivex::Usuario.attr preserve=no  private: System::AnsiString {V} 
      //## end IBDataStoreOracleActivex::Usuario.attr

      //## Attribute: Senha
      //## begin IBDataStoreOracleActivex::Senha.attr preserve=no  private: System::AnsiString {V} 
      //## end IBDataStoreOracleActivex::Senha.attr

      //## Attribute: NomeDB
      //## begin IBDataStoreOracleActivex::NomeDB.attr preserve=no  private: System::AnsiString {U} 
      //## end IBDataStoreOracleActivex::NomeDB.attr

    // Additional Private Declarations
      //## begin IBDataStoreOracleActivex.private preserve=yes
      //## end IBDataStoreOracleActivex.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin IBDataStoreOracleActivex.implementation preserve=yes
      #undef class
      #pragma option pop
      //## end IBDataStoreOracleActivex.implementation

};



// Class IBDataStoreOracleActivex 





#endif


