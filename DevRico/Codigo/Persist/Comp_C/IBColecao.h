//## begin module.cm preserve=no
//	C�digo adequado para CBuilder (Componente)
//## end module.cm

//## begin module.cp preserve=no
//	(c) 2000 Giuseppe Enrico Proment Junior
//## end module.cp

//## Module: IBColecao; Package specification
//## Subsystem: I++ para CBuilder
//## Source file: g:\devrico\codigo\persist\comp_c\ibcole~1.h


#ifndef IBColcao_h
#define IBColcao_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IComponent
#include "ICompo~1.h"
// IColecaoPersistenteBase
#include "IClcPrss.h"


//## begin module.declarations preserve=no
#pragma option push -pr
#define class class PACKAGE

//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: IClassesNegocio
//	� um enum que lista todas as classes de n�gocio (
//	portanto subclasses de IPersistente ) que a cole��o
//	poder� representar.
//## Category: I++ para CBuilder
//## Subsystem: I++ para CBuilder
//## Persistence: Transient
//## Cardinality/Multiplicity: n


typedef enum {_Indefinida,_Cadastro,_Pessoa,_Titulo,_MovContabil}
 IClassesNegocio;


//## Class: IBColecao
//	Tem por finalidade representar uma cole��o de objetos
//	persistentes, mais precisamente encapsula a Classe
//	IColecao da FrameWork I++, tem por responsabilidade
//	controlar os componentes de interface que sejam seus
//	clientes, enviando notifica��es sobre os diversos
//	estados da colecao.
//## Category: I++ para CBuilder
//## Subsystem: I++ para CBuilder
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>; ColecaoCadastro { -> F}
//## Uses: <unnamed>; ColecaoPessoa { -> F}
//## Uses: <unnamed>; ColecaoTitulo { -> F}

class IBColecao : public IComponente  //## Inherits: <unnamed>

{
  //## begin IBColecao.initialDeclarations preserve=yes
  //## end IBColecao.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IBColecao%959658640
      IBColecao(TComponent* Dono);

    //## Destructor (generated)
      ~IBColecao();


    //## Other Operations (specified)
      //## Operation: fazerRevisao%959658641
      void fazerRevisao();

      //## Operation: isFimObjetos%960001694
      //	retorna true se final de objetos. ( igual fim de fila )
      bool isFimObjetos();

    //## Get and Set Operations for Has Relationships (generated)

      //## Documentation IBColecao::ColecaoBase.has
      //	guarda um objeto do tipo representado, em nosso exemplo
      //	s�o as cole��es de classes de neg�cio Cole��oPessoa,Cole
      //	oTitulo e Cole��oCadastro
      const IColecaoPersistenteBase * getColecaoBase() const;
      void setColecaoBase(IColecaoPersistenteBase *const  value);

      //## Documentation IBColecao::ClasseRepresentada.has
      const IClassesNegocio getClasseRepresentada() const;

    // Data Members for Class Attributes

      //## Attribute: Pronta
      //	indica que a cole��o esta pronta para ser utilizada. J�
      //	resgatou os objetos colecionados.
      //## begin IBColecao::Pronta.attr preserve=no  public: static TypeEvento {V} "IBColecao::Pronta"
      static TypeEvento Pronta;
      //## end IBColecao::Pronta.attr

      //## Attribute: Revisada
      //	indica que a cole��o sofreu uma revis�o, o estado pode
      //	ter mudado.
      //## begin IBColecao::Revisada.attr preserve=no  public: static TypeEvento {V} "IBColecao::Revisada"
      static TypeEvento Revisada;
      //## end IBColecao::Revisada.attr

      //## Attribute: Destruida
      //	indica que cole��o foi destruida. Os componentes que a
      //	referenciam devem eliminar a referencia.
      //## begin IBColecao::Destruida.attr preserve=no  public: static TypeEvento {V} "IBColecao::Destruida"
      static TypeEvento Destruida;
      //## end IBColecao::Destruida.attr

      //## Attribute: Ativa
      //	Disparado quando a cole��o est� em estado ativo.
      //## begin IBColecao::Ativa.attr preserve=no  public: static TypeEvento {V} "IBColecao::Ativa"
      static TypeEvento Ativa;
      //## end IBColecao::Ativa.attr

      //## Attribute: Inativa
      //	Disparado quando a cole��o esta inativa.
      //## begin IBColecao::Inativa.attr preserve=no  public: static TypeEvento {V} "IBColecao::Inativa"
      static TypeEvento Inativa;
      //## end IBColecao::Inativa.attr

    // Additional Public Declarations
      //## begin IBColecao.public preserve=yes
   __published:
      __property IClassesNegocio
          classeObjeto =
          { read=getClasseRepresentada,
            write=setClasseRepresentada,
            default=_Indefinida };

      __property bool
          Ativo =
          { read=m_Ativo, write=setAtivo, default=false};


      //## end IBColecao.public


  protected:
    // Data Members for Has Relationships

      //## begin IBColecao::ColecaoBase.has preserve=no  public: IColecaoPersistenteBase {0 -> 1RO}
      IColecaoPersistenteBase *m_ColecaoBase;
      //## end IBColecao::ColecaoBase.has

      //## begin IBColecao::ClasseRepresentada.has preserve=no  public: IClassesNegocio { -> 1VO}
      IClassesNegocio m_ClasseRepresentada;
      //## end IBColecao::ClasseRepresentada.has

    // Data Members for Class Attributes

      //## Attribute: Ativo
      //	Se ativo indica que a cole��o j� se preparou com os
      //	objetos  selecionados, e esta pronta para ser usada.
      //## begin IBColecao::Ativo.attr preserve=no  private: bool {V} false
      bool m_Ativo;
      //## end IBColecao::Ativo.attr

    // Additional Protected Declarations
      //## begin IBColecao.protected preserve=yes
      //## end IBColecao.protected


  private:

    //## Other Operations (specified)
      //## Operation: setClasseRepresentada%960001692
      void setClasseRepresentada(const IClassesNegocio p_classe);

      //## Operation: setAtivo%960001693
      void setAtivo(bool isLigar);

    // Additional Private Declarations
      //## begin IBColecao.private preserve=yes
      //## end IBColecao.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin IBColecao.implementation preserve=yes
#undef class
#pragma option pop
      //## end IBColecao.implementation

};



// Class IBColecao 





// Class IClassesNegocio 





#endif


