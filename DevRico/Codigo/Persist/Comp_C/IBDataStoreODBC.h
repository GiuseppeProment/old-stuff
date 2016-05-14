//## begin module.cm preserve=no
//	Código adequado para CBuilder (Componente)
//## end module.cm

//## begin module.cp preserve=no
//	(c) 2000 Giuseppe Enrico Proment Junior
//## end module.cp

//## Module: IBDataStoreODBC; Package specification
//## Subsystem: I++ para CBuilder
//## Source file: g:\devrico\codigo\persist\comp_c\ibdata~2.h


#ifndef IBDtStrD_h
#define IBDtStrD_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IComponent
#include "ICompo~1.h"
// IDataStoreODBC
#include "IDtStrDB.h"

//## begin module.declarations preserve=no
#pragma option push -pr
#define class class PACKAGE

//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: IBDataStoreODBC
//## Category: I++ para CBuilder
//## Subsystem: I++ para CBuilder
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class IBDataStoreODBC : public IBDataStore  //## Inherits: <unnamed>

{
  //## begin IBDataStoreODBC.initialDeclarations preserve=yes
  //## end IBDataStoreODBC.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IBDataStoreODBC%960005300
      IBDataStoreODBC(TComponent* Dono);

    //## Destructor (generated)
      ~IBDataStoreODBC();


    //## Other Operations (specified)
      //## Operation: setAtivo%960005301
      void setAtivo(bool isLigar);

      //## Operation: setNomeConexao%960005302
      void setNomeConexao(System::AnsiString nome);

      //## Operation: setUsuario%960005303
      void setUsuario(System::AnsiString nome);

      //## Operation: setSenha%960005304
      void setSenha(System::AnsiString nome);

      //## Operation: setNomeDSN%960005305
      void setNomeDSN(System::AnsiString nome);

      //## Operation: getNomeConexao%960005306
      System::AnsiString getNomeConexao();

      //## Operation: getUsuario%960005307
      System::AnsiString getUsuario();

      //## Operation: getSenha%960005308
      System::AnsiString getSenha();

      //## Operation: getNomeDSN%960005309
      System::AnsiString getNomeDSN();

      //## Operation: fazerRevisao%959658641
      void fazerRevisao();

    // Data Members for Class Attributes

      //## Attribute: Revisado
      //## begin IBDataStoreODBC::Revisado.attr preserve=no  public: static TypeEvento {V} "IBDataStoreODBC::Revisado"
      static TypeEvento Revisado;
      //## end IBDataStoreODBC::Revisado.attr

    // Additional Public Declarations
      //## begin IBDataStoreODBC.public preserve=yes
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
    DSN = {read=getNomeDSN,write=setNomeDSN};

      //## end IBDataStoreODBC.public


  protected:
    // Data Members for Has Relationships

      //## Documentation IBDataStoreODBC::oODBC.has
      //## begin IBDataStoreODBC::oODBC.has preserve=no  private: IDataStoreODBC { -> 1VO}
      IDataStoreODBC m_oODBC;
      //## end IBDataStoreODBC::oODBC.has

    // Additional Protected Declarations
      //## begin IBDataStoreODBC.protected preserve=yes
      //## end IBDataStoreODBC.protected


  private:

    //## Other Operations (specified)
      //## Operation: mudancaEstadoPermitida%960005310
      //	indica se é permitida a mudança de propriedades (ex: se
      //	está conectado, não pode mudar o nome de usuário ).
      bool mudancaEstadoPermitida();

    // Data Members for Class Attributes

      //## Attribute: Ativo
      //## begin IBDataStoreODBC::Ativo.attr preserve=no  private: bool {V} false
      bool m_Ativo;
      //## end IBDataStoreODBC::Ativo.attr

      //## Attribute: NomeConexao
      //## begin IBDataStoreODBC::NomeConexao.attr preserve=no  private: System::AnsiString {U} 
      //## end IBDataStoreODBC::NomeConexao.attr

      //## Attribute: Usuario
      //## begin IBDataStoreODBC::Usuario.attr preserve=no  private: System::AnsiString {U} 
      //## end IBDataStoreODBC::Usuario.attr

      //## Attribute: Senha
      //## begin IBDataStoreODBC::Senha.attr preserve=no  private: System::AnsiString {U} 
      //## end IBDataStoreODBC::Senha.attr

      //## Attribute: NomeDSN
      //## begin IBDataStoreODBC::NomeDSN.attr preserve=no  private: System::AnsiString {U} 
      //## end IBDataStoreODBC::NomeDSN.attr

    // Additional Private Declarations
      //## begin IBDataStoreODBC.private preserve=yes
      //## end IBDataStoreODBC.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin IBDataStoreODBC.implementation preserve=yes
#undef class
#pragma option pop
      //## end IBDataStoreODBC.implementation

};



// Class IBDataStoreODBC 





#endif


