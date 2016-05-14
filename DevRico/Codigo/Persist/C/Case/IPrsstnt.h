//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IPersistente; Pseudo Package specification
//## Subsystem: <Top Level>
//## Source file: g:\devrico\codigo\persist\c\case\iprsstnt.h


#ifndef IPrsstnt_h
#define IPrsstnt_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include <IUtil.h>
//## end module.includes

// IPersistID
#include "IPrsstID.h"
// IKnowType
#include "IKnwType.h"
// INotificador
#include "INtfcdor.h"

class IClassMap;
class IMapClassTable;
class IEventoNotificacao;
class IBroker;

//## begin module.additionalDeclarations preserve=yes
#ifndef class
#ifdef GERAR_DLL
  #define class class __declspec(dllexport)
#else
  #define class class __declspec(dllimport)
#endif
#endif
//## end module.additionalDeclarations


//## Class: IPersistente; Abstract
//	Esta classe faz operações de Insert, Delete, Update e
//	Select pelo ID somente. Insert <campo1,...n> into
//	<Tabela> values <valor1,...n>
//	Delete <Tabela> For ID == <ValorID>
//	Update <campo1,...n> into <Tabela> values <valor1,...n>
//	For ID == <ValorID>
//	Select <campo1,...n> From <Tabela> For ID == <ValorID>
//	portanto a conexao com o meio de persistencia é transit
//	ria e consequentemente somente de uma operacao DML.
//## Category: <Top Level>
//## Subsystem: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: delega fun\7ões a ; IBroker {n -> 1F}
//## Uses: é mapeado por; friend IClassMap {n -> 1F}
//## Uses: <unnamed>; IKnowType { -> }
//## Uses: <unnamed>; IEventoNotificacao { -> F}
//## Uses: <unnamed>; IMapClassTable { -> F}

class IPersistente : public INotificador  //## Inherits: <unnamed>

{
  //## begin IPersistente.initialDeclarations preserve=yes
  //## end IPersistente.initialDeclarations

  public:
    //## Constructors (generated)
      IPersistente();

      IPersistente(const IPersistente &right);

    //## Destructor (generated)
      virtual ~IPersistente();


    //## Other Operations (specified)
      //## Operation: save%906522273
      //	grava o estado do objeto.
      void save();

      //## Operation: erase%906522274
      //	apaga o objeto da base persistente. o que acontece com o
      //	objeto ?
      void erase();

      //## Operation: getNomeClasse%906522275
      //	Retorna o nome da classe, que por default sera o nome da
      //	tabela. deve ser implementado pela subclasse, caso
      //	contrario dispara uma excessao.
      virtual char* getNomeClasse();

      //## Operation: OnClassInfo%908414767
      //	Este metodo sera chamado para obtenção indireta das
      //	informações sobre membros, deve ser implementado pela
      //	subclasse, na implementação deverão ser feitas chamadas
      //	a RegistraMembro() para cada membro a ser persistido
      virtual void OnClassInfo();

      //## Operation: getCampoPorNome%958376567
      //	retorna o conteudo de um campo
      //## Semantics:
      //	retorna uma string vazia se o campo nao existir
      IString getCampoPorNome(char* campo);

      //## Operation: getCampoPorIndice%958376568
      //	retorna conteudo de um campo pela posicao na lista de
      //	campos
      //## Semantics:
      //	retorna string vazia se indice fora de faixa
      IString getCampoPorIndice(int indice);

      //## Operation: quantosCampos%958376569
      //	retorna o total de campos menos o IPersistId ( OUID )
      int quantosCampos();

    //## Get and Set Operations for Has Relationships (generated)

      //## Documentation IPersistente::ID.has
      //	Identificador unico generico
      IPersistID ID();
      void setID(const IPersistID value);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: isPersistido
      //	true se objeto já foi persistido.
      bool isPersistido();
      void setisPersistido(const bool value);

    // Data Members for Class Attributes

      //## Attribute: evtSalvando
      //## begin IPersistente::evtSalvando.attr preserve=no  public: static TypeEvento {V} "IPersistente::Salvando"
      static TypeEvento evtSalvando;
      //## end IPersistente::evtSalvando.attr

    // Additional Public Declarations
      //## begin IPersistente.public preserve=yes
      //## end IPersistente.public


  protected:

    //## Other Operations (specified)
      //## Operation: registraMembro%908414768
      //	adiciona um mapeamento de atributo x coluna, deve
      //	utilizar o IClassMap delegando a funcao de mapeamento.
      //	Caso não especifique o tipo, tipo será StringFixa de
      //	tamanho = tamanho.
      virtual IPersistente& registraMembro(char* nomeMembro, unsigned int offSet, unsigned int tamanho, IKnowType tipoMembro = IsStringFix, unsigned int varSizeMax = 0, bool isProxy = false);

    // Additional Protected Declarations
      //## begin IPersistente.protected preserve=yes
      //## end IPersistente.protected


  private:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: isProxy
      //	true se o objeto foi retirado como "Proxy"
      bool isProxy();
      void setisProxy(const bool value);

    // Additional Private Declarations
      //## begin IPersistente.private preserve=yes
      //## end IPersistente.private


  private:  //## implementation
    // Data Members for Has Relationships

      //## begin IPersistente::ID.has preserve=no  public: IPersistID { -> 1VO}
      IPersistID m_ID;
      //## end IPersistente::ID.has

    // Data Members for Class Attributes

      //## begin IPersistente::isPersistido.attr preserve=no  public: bool {U} false
      bool m_isPersistido;
      //## end IPersistente::isPersistido.attr

      //## begin IPersistente::isProxy.attr preserve=no  private: bool {U} false
      bool m_isProxy;
      //## end IPersistente::isProxy.attr

    // Data Members for Associations

      //## Association: pelas subclasses%360723DB0172
      //## Role: IPersistente::<the_IAssociacao>
      //## begin IPersistente::<the_IAssociacao>.role preserve=no  implementation: IAssociacao {1 -> 0..nUH}
      //## end IPersistente::<the_IAssociacao>.role

    // Additional Implementation Declarations
      //## begin IPersistente.implementation preserve=yes
#undef class
      //## end IPersistente.implementation

  //## begin IPersistente.friends preserve=no
    friend class IColecaoPersistenteBase;
  //## end IPersistente.friends
};

// Class IPersistente 





#endif


