//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: ICriterio; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\icritrio.h


#ifndef ICritrio_h
#define ICritrio_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes

// IOperComparacao
#include "IprCmprc.h"
// IOperLogicoPrecedencia
#include "IprLgcPr.h"

//## begin module.additionalDeclarations preserve=yes
#ifndef class
#ifdef GERAR_DLL
  #define class class __declspec(dllexport)
#else
  #define class class __declspec(dllimport)
#endif
#endif
//## end module.additionalDeclarations


//## Class: ICriterio
//	Responsavel pela montagem do criterio de selecao
//	(clausula WHERE)
//	cada sentença é montada como :
//	SENTENÇA => <campoValido> <opRelacional>
//	[valorValido|<campoValido>]
//	SENTENÇA [AND|OR] SENTENÇA [AND|OR] ...
//
//	Os críterios devem ser processados para trocar os
//	atributos pelos nomes_colunas reais.
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>; IOperComparacao { -> }
//## Uses: <unnamed>; IOperLogicoPrecedencia { -> }

class ICriterio
{
  //## begin ICriterio.initialDeclarations preserve=yes
  //## end ICriterio.initialDeclarations

  public:
    //## Constructors (generated)
      ICriterio(const ICriterio &right);

    //## Constructors (specified)
      //## Operation: ICriterio%908596363
      ICriterio(IString& atributo, IOperComparacao comparacao, char* argumento);

      //## Operation: ICriterio%908596364
      ICriterio(IString& atributo, IOperComparacao comparacao, int argumento);

      //## Operation: ICriterio%908596365
      ICriterio(IString& atributo, IOperComparacao comparacao, IString& argumento);

      //## Operation: ICriterio%908596366
      //	não necessita traducao
      ICriterio(char* FraseLivre);

      //## Operation: ICriterio%908596367
      //	não necessita traducao.
      ICriterio(IOperLogicoPrecedencia conectorLogico);

    //## Destructor (generated)
      ~ICriterio();


    //## Other Operations (specified)
      //## Operation: asSentencaSQL%908414766
      //## Semantics:
      //	se necessitar traducao monta coluna - comparador -
      //	argumento
      //	senão devolve fraseLivre diretamente.
      char* asSentencaSQL();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: atributo
      IString atributo();
      void setatributo(const IString value);

      //## Attribute: comparador
      IOperComparacao comparador();
      void setcomparador(const IOperComparacao value);

      //## Attribute: argumento
      IString argumento();
      void setargumento(const IString value);

      //## Attribute: isArgPrecisaAspas
      bool isArgPrecisaAspas();
      void setisArgPrecisaAspas(const bool value);

      //## Attribute: coluna
      IString coluna();
      void setcoluna(const IString value);

    // Additional Public Declarations
      //## begin ICriterio.public preserve=yes
      //## end ICriterio.public


  protected:
    // Additional Protected Declarations
      //## begin ICriterio.protected preserve=yes
      //## end ICriterio.protected


  private:
    // Additional Private Declarations
      //## begin ICriterio.private preserve=yes
      //## end ICriterio.private


  private:  //## implementation
    // Data Members for Class Attributes

      //## begin ICriterio::atributo.attr preserve=no  public: IString {U}
      IString m_atributo;
      //## end ICriterio::atributo.attr

      //## begin ICriterio::comparador.attr preserve=no  public: IOperComparacao {U}
      IOperComparacao m_comparador;
      //## end ICriterio::comparador.attr

      //## begin ICriterio::argumento.attr preserve=no  public: IString {U}
      IString m_argumento;
      //## end ICriterio::argumento.attr

      //## Attribute: isNecessitaTraducao
      //	true se o atributo deve ser traduzido para o nome da
      //	coluna.
      //## begin ICriterio::isNecessitaTraducao.attr preserve=no  private: bool {U} false
      bool m_isNecessitaTraducao;
      //## end ICriterio::isNecessitaTraducao.attr

      //## begin ICriterio::isArgPrecisaAspas.attr preserve=no  public: bool {U} true
      bool m_isArgPrecisaAspas;
      //## end ICriterio::isArgPrecisaAspas.attr

      //## begin ICriterio::coluna.attr preserve=no  public: IString {U}
      IString m_coluna;
      //## end ICriterio::coluna.attr

      //## Attribute: fraseLivre
      //	uso interno
      //## begin ICriterio::fraseLivre.attr preserve=no  private: IString {V}
      IString m_fraseLivre;
      //## end ICriterio::fraseLivre.attr

    // Additional Implementation Declarations
      //## begin ICriterio.implementation preserve=yes
#undef class
      //## end ICriterio.implementation

};

// Class ICriterio





#endif


