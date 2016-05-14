//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IAtributo; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\iatrbuto.h


#ifndef IAtrbuto_h
#define IAtrbuto_h 1

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


//## Class: IAtributo; Abstract
//	somente para facilitar operacoes, é opcional
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class IAtributo
{
  //## begin IAtributo.initialDeclarations preserve=yes
  //## end IAtributo.initialDeclarations

  public:
    //## Constructors (generated)
      IAtributo();

      IAtributo(const IAtributo &right);

    //## Destructor (generated)
      ~IAtributo();

    // Additional Public Declarations
      //## begin IAtributo.public preserve=yes
      //## end IAtributo.public


  protected:
    // Additional Protected Declarations
      //## begin IAtributo.protected preserve=yes
      //## end IAtributo.protected


  private:
    // Additional Private Declarations
      //## begin IAtributo.private preserve=yes
      //## end IAtributo.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin IAtributo.implementation preserve=yes
#undef class
      //## end IAtributo.implementation

};

// Class IAtributo





#endif


