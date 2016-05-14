//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IOrdem; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\iordem.h


#ifndef IOrdem_h
#define IOrdem_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes


//## begin module.additionalDeclarations preserve=yes
#ifndef class
#ifdef GERAR_DLL
  #define class class __declspec(dllexport)
#else
  #define class class __declspec(dllimport)
#endif
#endif
//## end module.additionalDeclarations


//## Class: IOrdem
//	necessita de tradução
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class IOrdem
{
  //## begin IOrdem.initialDeclarations preserve=yes
  //## end IOrdem.initialDeclarations

  public:
    //## Constructors (generated)
      IOrdem(const IOrdem &right);

    //## Constructors (specified)
      //## Operation: IOrdem%908596358
      IOrdem(IString& atributo, bool isAsc = true);

    //## Destructor (generated)
      ~IOrdem();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: atributo
      IString atributo();
      void setatributo(const IString value);

      //## Attribute: isAsc
      bool isAsc();
      void setisAsc(const bool value);

      //## Attribute: coluna
      IString coluna();
      void setcoluna(const IString value);

    // Additional Public Declarations
      //## begin IOrdem.public preserve=yes
      //## end IOrdem.public


  protected:
    // Additional Protected Declarations
      //## begin IOrdem.protected preserve=yes
      //## end IOrdem.protected


  private:
    // Additional Private Declarations
      //## begin IOrdem.private preserve=yes
      //## end IOrdem.private


  private:  //## implementation
    // Data Members for Class Attributes

      //## begin IOrdem::atributo.attr preserve=no  public: IString {U}
      IString m_atributo;
      //## end IOrdem::atributo.attr

      //## begin IOrdem::isAsc.attr preserve=no  public: bool {U} true
      bool m_isAsc;
      //## end IOrdem::isAsc.attr

      //## begin IOrdem::coluna.attr preserve=no  public: IString {U}
      IString m_coluna;
      //## end IOrdem::coluna.attr

    // Additional Implementation Declarations
      //## begin IOrdem.implementation preserve=yes
#undef class
      //## end IOrdem.implementation

};

// Class IOrdem





#endif


