//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IErro; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\ierro.h


#ifndef IErro_h
#define IErro_h 1

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


//## Class: IErro
//	Simples classe que será arremesada em caso de erro.
//	throw.
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class IErro
{
  //## begin IErro.initialDeclarations preserve=yes
  //## end IErro.initialDeclarations

  public:
    //## Constructors (generated)
      IErro();

      IErro(const IErro &right);

    //## Constructors (specified)
      //## Operation: IErro%909032152
      IErro(char* texto);

    //## Destructor (generated)
      ~IErro();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: textError
      char* textError();
      void settextError(char*const  value);

    // Additional Public Declarations
      //## begin IErro.public preserve=yes
      //## end IErro.public


  protected:
    // Additional Protected Declarations
      //## begin IErro.protected preserve=yes
      //## end IErro.protected


  private:
    // Additional Private Declarations
      //## begin IErro.private preserve=yes
      //## end IErro.private


  private:  //## implementation
    // Data Members for Class Attributes

      //## begin IErro::textError.attr preserve=no  public: char* {U}
      char* m_textError;
      //## end IErro::textError.attr

    // Additional Implementation Declarations
      //## begin IErro.implementation preserve=yes
#undef class
      //## end IErro.implementation

};

// Class IErro





#endif


