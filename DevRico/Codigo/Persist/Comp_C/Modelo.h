//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: Modelo; Package specification
//	Classes de negócio definidas aqui.
//## Subsystem:  Classes Negócio
//## Source file: c:\devrico\codigo\persist\comp_c\modelo.h


#ifndef Modelo_h
#define Modelo_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IColecao
#include "IColecao.h"
// IPersistente
#include "IPrsstnt.h"

//## begin module.declarations preserve=no
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: Cadastro
//## Category: Classes Negócio
//## Subsystem:  Classes Negócio
//## Persistence: Persistent
//## Cardinality/Multiplicity: n


class Cadastro : public IPersistente  //## Inherits: <unnamed>

{
  //## begin Cadastro.initialDeclarations preserve=yes
  //## end Cadastro.initialDeclarations

  public:
    //## Constructors (generated)
      Cadastro();

      Cadastro(const Cadastro &right);


    //## Other Operations (specified)
      //## Operation: getNomeClasse%959834143
      char* getNomeClasse();

      //## Operation: OnClassInfo%959834144
      void OnClassInfo();

    // Data Members for Class Attributes

      //## Attribute: numero
      //## begin Cadastro::numero.attr preserve=no  public: int {UA} 
      int numero;
      //## end Cadastro::numero.attr

      //## Attribute: nome
      //## begin Cadastro::nome.attr preserve=no  public: IString {VA} 
      IString nome;
      //## end Cadastro::nome.attr

      //## Attribute: endereco
      //## begin Cadastro::endereco.attr preserve=no  public: IString {VA} 
      IString endereco;
      //## end Cadastro::endereco.attr

      //## Attribute: peso
      //## begin Cadastro::peso.attr preserve=no  public: double {VA} 
      double peso;
      //## end Cadastro::peso.attr

    // Additional Public Declarations
      //## begin Cadastro.public preserve=yes
      //## end Cadastro.public


  protected:
    // Additional Protected Declarations
      //## begin Cadastro.protected preserve=yes
      //## end Cadastro.protected


  private:
    // Additional Private Declarations
      //## begin Cadastro.private preserve=yes
      //## end Cadastro.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin Cadastro.implementation preserve=yes
      //## end Cadastro.implementation

};



//## Class: Pessoa
//## Category: Classes Negócio
//## Subsystem:  Classes Negócio
//## Persistence: Persistent
//## Cardinality/Multiplicity: n


class Pessoa : public IPersistente  //## Inherits: <unnamed>

{
  //## begin Pessoa.initialDeclarations preserve=yes
  //## end Pessoa.initialDeclarations

  public:
    //## Constructors (generated)
      Pessoa();

      Pessoa(const Pessoa &right);


    //## Other Operations (specified)
      //## Operation: getNomeClasse%959834143
      char* getNomeClasse();

      //## Operation: OnClassInfo%959834144
      void OnClassInfo();

    // Data Members for Class Attributes

      //## Attribute: numero
      //## begin Pessoa::numero.attr preserve=no  public: int {VA} 
      int numero;
      //## end Pessoa::numero.attr

      //## Attribute: nome
      //## begin Pessoa::nome.attr preserve=no  public: IString {VA} 
      IString nome;
      //## end Pessoa::nome.attr

      //## Attribute: endereco
      //## begin Pessoa::endereco.attr preserve=no  public: IString {VA} 
      IString endereco;
      //## end Pessoa::endereco.attr

      //## Attribute: peso
      //## begin Pessoa::peso.attr preserve=no  public: double {VA} 
      double peso;
      //## end Pessoa::peso.attr

    // Additional Public Declarations
      //## begin Pessoa.public preserve=yes
      //## end Pessoa.public


  protected:
    // Additional Protected Declarations
      //## begin Pessoa.protected preserve=yes
      //## end Pessoa.protected


  private:
    // Additional Private Declarations
      //## begin Pessoa.private preserve=yes
      //## end Pessoa.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin Pessoa.implementation preserve=yes
      //## end Pessoa.implementation

};



//## Class: Titulo
//## Category: Classes Negócio
//## Subsystem:  Classes Negócio
//## Persistence: Persistent
//## Cardinality/Multiplicity: n


class Titulo : public IPersistente  //## Inherits: <unnamed>

{
  //## begin Titulo.initialDeclarations preserve=yes
  //## end Titulo.initialDeclarations

  public:
    //## Constructors (generated)
      Titulo();

      Titulo(const Titulo &right);


    //## Other Operations (specified)
      //## Operation: getNomeClasse%959834143
      char* getNomeClasse();

      //## Operation: OnClassInfo%959834144
      void OnClassInfo();

    // Data Members for Class Attributes

      //## Attribute: numero
      //## begin Titulo::numero.attr preserve=no  public: int {VA} 
      int numero;
      //## end Titulo::numero.attr

      //## Attribute: data
      //## begin Titulo::data.attr preserve=no  public: IString {VA} 
      IString data;
      //## end Titulo::data.attr

    // Additional Public Declarations
      //## begin Titulo.public preserve=yes
      //## end Titulo.public


  protected:
    // Additional Protected Declarations
      //## begin Titulo.protected preserve=yes
      //## end Titulo.protected


  private:
    // Additional Private Declarations
      //## begin Titulo.private preserve=yes
      //## end Titulo.private


  private:  //## implementation
    // Additional Implementation Declarations
      //## begin Titulo.implementation preserve=yes
      //## end Titulo.implementation

};



//## Class: ColecaoCadastro; Instantiated Class
//	É IColeção<Cadastro>.
//## Category: Classes Negócio
//## Subsystem:  Classes Negócio
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>; Cadastro { -> }

typedef IColecao<Cadastro> ColecaoCadastro;


//## Class: ColecaoPessoa; Instantiated Class
//## Category: Classes Negócio
//## Subsystem:  Classes Negócio
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>; Pessoa { -> }

typedef IColecao<Pessoa> ColecaoPessoa;


//## Class: ColecaoTitulo; Instantiated Class
//## Category: Classes Negócio
//## Subsystem:  Classes Negócio
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>; Titulo { -> }

typedef IColecao<Titulo> ColecaoTitulo;


// Class Cadastro 

inline Cadastro::Cadastro()
  //## begin Cadastro::Cadastro%.hasinit preserve=no
  //## end Cadastro::Cadastro%.hasinit
  //## begin Cadastro::Cadastro%.initialization preserve=yes
  //## end Cadastro::Cadastro%.initialization
{
  //## begin Cadastro::Cadastro%.body preserve=yes
  //## end Cadastro::Cadastro%.body
}

inline Cadastro::Cadastro(const Cadastro &right)
  //## begin Cadastro::Cadastro%copy.hasinit preserve=no
  //## end Cadastro::Cadastro%copy.hasinit
  //## begin Cadastro::Cadastro%copy.initialization preserve=yes
  : IPersistente( right )
  //## end Cadastro::Cadastro%copy.initialization
{
  //## begin Cadastro::Cadastro%copy.body preserve=yes
  numero = right.numero;
  endereco = right.endereco;
  nome = right.nome;
  peso = right.peso;
  //## end Cadastro::Cadastro%copy.body
}



//## Other Operations (inline)
inline char* Cadastro::getNomeClasse()
{
  //## begin Cadastro::getNomeClasse%959834143.body preserve=yes
  //## end Cadastro::getNomeClasse%959834143.body

  return "Cadastro";
}

inline void Cadastro::OnClassInfo()
{
  //## begin Cadastro::OnClassInfo%959834144.body preserve=yes
  registraMembro( ADI( Cadastro,numero ) ,IsInt);
	registraMembro( ADI( Cadastro,endereco ),IsStringFix);
	registraMembro( ADI( Cadastro,nome ),IsStringFix);
	registraMembro( ADI( Cadastro,peso ),IsDouble);
  //## end Cadastro::OnClassInfo%959834144.body
}





// Class Pessoa 

inline Pessoa::Pessoa()
  //## begin Pessoa::Pessoa%.hasinit preserve=no
  //## end Pessoa::Pessoa%.hasinit
  //## begin Pessoa::Pessoa%.initialization preserve=yes
  //## end Pessoa::Pessoa%.initialization
{
  //## begin Pessoa::Pessoa%.body preserve=yes
  //## end Pessoa::Pessoa%.body
}

inline Pessoa::Pessoa(const Pessoa &right)
  //## begin Pessoa::Pessoa%copy.hasinit preserve=no
  //## end Pessoa::Pessoa%copy.hasinit
  //## begin Pessoa::Pessoa%copy.initialization preserve=yes
  : IPersistente( right )
  //## end Pessoa::Pessoa%copy.initialization
{
  //## begin Pessoa::Pessoa%copy.body preserve=yes
  numero = right.numero;
  endereco = right.endereco;
  nome = right.nome;
  peso = right.peso;
  //## end Pessoa::Pessoa%copy.body
}



//## Other Operations (inline)
inline char* Pessoa::getNomeClasse()
{
  //## begin Pessoa::getNomeClasse%959834143.body preserve=yes
  //## end Pessoa::getNomeClasse%959834143.body

  return "Pessoa";
}

inline void Pessoa::OnClassInfo()
{
  //## begin Pessoa::OnClassInfo%959834144.body preserve=yes
  registraMembro( ADI( Pessoa,numero ) ,IsInt);
  registraMembro( ADI( Pessoa,endereco ),IsStringFix);
  registraMembro( ADI( Pessoa,nome ),IsStringFix);
  registraMembro( ADI( Pessoa,peso ),IsDouble);
  //## end Pessoa::OnClassInfo%959834144.body
}





// Class Titulo 

inline Titulo::Titulo()
  //## begin Titulo::Titulo%.hasinit preserve=no
  //## end Titulo::Titulo%.hasinit
  //## begin Titulo::Titulo%.initialization preserve=yes
  //## end Titulo::Titulo%.initialization
{
  //## begin Titulo::Titulo%.body preserve=yes
  //## end Titulo::Titulo%.body
}

inline Titulo::Titulo(const Titulo &right)
  //## begin Titulo::Titulo%copy.hasinit preserve=no
  //## end Titulo::Titulo%copy.hasinit
  //## begin Titulo::Titulo%copy.initialization preserve=yes
  //## end Titulo::Titulo%copy.initialization
{
  //## begin Titulo::Titulo%copy.body preserve=yes
  //## end Titulo::Titulo%copy.body
}



//## Other Operations (inline)
inline char* Titulo::getNomeClasse()
{
  //## begin Titulo::getNomeClasse%959834143.body preserve=yes
  //## end Titulo::getNomeClasse%959834143.body

  return "Titulo";
}

inline void Titulo::OnClassInfo()
{
  //## begin Titulo::OnClassInfo%959834144.body preserve=yes
  registraMembro( ADI( Titulo,numero ) ,IsInt);
  registraMembro( ADI( Titulo,data ),IsStringFix);
  //## end Titulo::OnClassInfo%959834144.body
}





// Instantiated Class ColecaoCadastro 





// Instantiated Class ColecaoPessoa 





// Instantiated Class ColecaoTitulo 





#endif


