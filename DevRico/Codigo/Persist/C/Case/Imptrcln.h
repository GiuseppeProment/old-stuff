//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IMapAtrColuna; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: c:\meusdo~1\projetos\persist\codigo\casecode\imptrcln.h


#ifndef IMptrCln_h
#define IMptrCln_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes

// IKnowType
#include "IKnwType.h"

class IPersistente;

//## begin module.additionalDeclarations preserve=yes
#ifndef class
#ifdef GERAR_DLL
  #define class class __declspec(dllexport)
#else
  #define class class __declspec(dllimport)
#endif
#endif
//## end module.additionalDeclarations


//## Class: IMapAtrColuna
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>; IPersistente { -> F}

class IMapAtrColuna
{
  //## begin IMapAtrColuna.initialDeclarations preserve=yes
  //## end IMapAtrColuna.initialDeclarations

  public:
    //## Constructors (generated)
      IMapAtrColuna();

      IMapAtrColuna(const IMapAtrColuna &right);

    //## Destructor (generated)
      ~IMapAtrColuna();


    //## Other Operations (specified)
      //## Operation: asString%908596383
      //	retorna o conteudo do membro como char* transformado,
      //	exemplo : membro é 100.00 devolve '100.00'
      IString asString(IPersistente& anPersist);

      //## Operation: setValue%908596384
      //	copia dado ao membro de anPersist. copyLen indica
      //	comprimento do dado / numero de bytes a serem copiados
      //	até o maximo do tamanho do membro. converte de acordo
      //	com o tipoMembro x tipoColuna. se for do tipo IUnknow
      //	então copia byte a byte até copyLen ou tamanho.
      //	Se copyLen for 0 então copia de acordo com o
      //	tipoMembro/tamanho. usualmente conclui que é tipo de
      //	tamanho fixo (string terminada com \0).
      void setValue(IPersistente& anPersist, char* dado, int copyLen = 0);

      //## Operation: asPuro%908596385
      //	retorna o conteudo do membro como char* puro, nao
      //	transfoma é apenas `cast`
      //	talvez seja usado pelo propria AsString quando verificar
      //	que tipo é um tipo blob.
      //	o que tornará a copia muito custosa e não necessita de
      //	conversao.
      char const* asPuro(IPersistente& anPersist);

    //## Get and Set Operations for Has Relationships (generated)

      //## Documentation IMapAtrColuna::tipoMembro.has
      IKnowType tipoMembro();
      void settipoMembro(const IKnowType value);

      //## Documentation IMapAtrColuna::tipoColuna.has
      //	deve ser preenchido pelo broker
      IKnowType tipoColuna();
      void settipoColuna(const IKnowType value);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: nomeMembro
      IString nomeMembro();
      void setnomeMembro(const IString value);

      //## Attribute: offSet
      unsigned int offSet();
      void setoffSet(const unsigned int value);

      //## Attribute: tamanho
      unsigned int tamanho();
      void settamanho(const unsigned int value);

      //## Attribute: varSizeMax
      unsigned int varSizeMax();
      void setvarSizeMax(const unsigned int value);

      //## Attribute: nomeColuna
      //	se houver definicao no MapClass.Ini, obtem dele, caso
      //	contrario é igual ao nome do membro.
      IString nomeColuna();
      void setnomeColuna(const IString value);

      //## Attribute: isProxy
      bool isProxy();
      void setisProxy(const bool value);

    // Additional Public Declarations
      //## begin IMapAtrColuna.public preserve=yes
      //## end IMapAtrColuna.public


  protected:
    // Additional Protected Declarations
      //## begin IMapAtrColuna.protected preserve=yes
      //## end IMapAtrColuna.protected


  private:
    // Additional Private Declarations
      //## begin IMapAtrColuna.private preserve=yes
      //## end IMapAtrColuna.private


  private:  //## implementation
    // Data Members for Has Relationships

      //## begin IMapAtrColuna::tipoMembro.has preserve=no  public: IKnowType { -> 1VO}
      IKnowType m_tipoMembro;
      //## end IMapAtrColuna::tipoMembro.has

      //## begin IMapAtrColuna::tipoColuna.has preserve=no  public: IKnowType { -> 1VO}
      IKnowType m_tipoColuna;
      //## end IMapAtrColuna::tipoColuna.has

    // Data Members for Class Attributes

      //## begin IMapAtrColuna::nomeMembro.attr preserve=no  public: IString {V}
      IString m_nomeMembro;
      //## end IMapAtrColuna::nomeMembro.attr

      //## begin IMapAtrColuna::offSet.attr preserve=no  public: unsigned int {U}
      unsigned int m_offSet;
      //## end IMapAtrColuna::offSet.attr

      //## begin IMapAtrColuna::tamanho.attr preserve=no  public: unsigned int {U}
      unsigned int m_tamanho;
      //## end IMapAtrColuna::tamanho.attr

      //## begin IMapAtrColuna::varSizeMax.attr preserve=no  public: unsigned int {U} 0
      unsigned int m_varSizeMax;
      //## end IMapAtrColuna::varSizeMax.attr

      //## begin IMapAtrColuna::nomeColuna.attr preserve=no  public: IString {U}
      IString m_nomeColuna;
      //## end IMapAtrColuna::nomeColuna.attr

      //## begin IMapAtrColuna::isProxy.attr preserve=no  public: bool {U} false
      bool m_isProxy;
      //## end IMapAtrColuna::isProxy.attr

    // Additional Implementation Declarations
      //## begin IMapAtrColuna.implementation preserve=yes
#undef class
      //## end IMapAtrColuna.implementation

};

// Class IMapAtrColuna





#endif


