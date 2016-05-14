//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IPersistID; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\docume~1\projetos\persist\codigo\casecode\iprsstid.h


#ifndef IPrsstID_h
#define IPrsstID_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
#include <time.h>
#include <sys\timeb.h>
#include <math.h>
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


//## Class: IPersistID
//	Identificador unico dos objetos persistentes.
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class IPersistID 
{
  //## begin IPersistID.initialDeclarations preserve=yes
  //## end IPersistID.initialDeclarations

  public:
    //## Constructors (generated)
      IPersistID();

      IPersistID(const IPersistID &right);

    //## Destructor (generated)
      ~IPersistID();

    //## Assignment Operation (generated)
      const IPersistID & operator=(const IPersistID &right);


    //## Other Operations (specified)
      //## Operation: generate%909013228
      //	gera um id novo.
      IPersistID& generate();

      //## Operation: asString%908596369
      //	retorna o valor do id como string. pode ser algo como
      //	"12FC:3423A:FECD"
      char* asString();

      //## Operation: setValue%909013229
      //	para operações de leitura de um persistente o set deve
      //	receber o valor do id persistido.
      IPersistID& setValue(char* valor);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: CRAE
      //	Chave de Resolução de Ambiguidade Externa
      //	valores válidos 0 a 128.
      static int CRAE();
      static void setCRAE(const int value);

      //## Attribute: RAP
      //	Resolução de Ambiguidade em Processo
      //	valores validos 0 a 32
      static void setRAP(const int value);

    // Additional Public Declarations
      //## begin IPersistID.public preserve=yes
      //## end IPersistID.public


  protected:

    //## Other Operations (specified)
      //## Operation: RAP%924574177
      static int RAP();

    // Additional Protected Declarations
      //## begin IPersistID.protected preserve=yes
      //## end IPersistID.protected


  private:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: sequencial
      static int sequencial();
      static void setsequencial(const int value);

    // Additional Private Declarations
      //## begin IPersistID.private preserve=yes
      //## end IPersistID.private


  private:  //## implementation
    // Data Members for Class Attributes

      //## Attribute: id
      //## begin IPersistID::id.attr preserve=no  private: IString {U} 
      IString m_id;
      //## end IPersistID::id.attr

      //## begin IPersistID::sequencial.attr preserve=no  private: static int {V} 0
      static int m_sequencial;
      //## end IPersistID::sequencial.attr

      //## begin IPersistID::CRAE.attr preserve=no  public: static int {V} 0
      static int m_CRAE;
      //## end IPersistID::CRAE.attr

      //## begin IPersistID::RAP.attr preserve=no  public: static int {V} 0
      static int m_RAP;
      //## end IPersistID::RAP.attr

    // Additional Implementation Declarations
      //## begin IPersistID.implementation preserve=yes
#undef class
      //## end IPersistID.implementation

};

// Class IPersistID 





#endif


