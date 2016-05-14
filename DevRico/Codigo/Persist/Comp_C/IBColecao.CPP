//## begin module.cm preserve=no
//	Código adequado para CBuilder (Componente)
//## end module.cm

//## begin module.cp preserve=no
//	(c) 2000 Giuseppe E. Proment Jr.
//## end module.cp

//## Module: IBColecao; Package body
//## Subsystem: I++ para CBuilder
//## Source file: g:\devrico\codigo\persist\comp_c\ibcole~1.cpp


//## begin module.additionalIncludes preserve=no
#include <vcl.h>
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#pragma hdrstop
//## end module.includes

// Modelo
#include "Modelo.h"
// IBColecao
#include "IBCole~1.h"

//## begin module.declarations preserve=no
#pragma option push -pr
#pragma package( smart_init )
static inline void ValidCtrCheck( IBColecao*)
{
    new IBColecao(NULL);
}
// ------
namespace Ibcolecao
{
    void __fastcall PACKAGE Register()
     {
        TComponentClass classes[1]=
        {__classid(IBColecao)};
        RegisterComponents("I++",classes,0);
     }
}
//---------
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


// Class IBColecao 




//## begin IBColecao::Pronta.attr preserve=no  public: static TypeEvento {V} "IBColecao::Pronta"
TypeEvento IBColecao::Pronta = "IBColecao::Pronta";
//## end IBColecao::Pronta.attr

//## begin IBColecao::Revisada.attr preserve=no  public: static TypeEvento {V} "IBColecao::Revisada"
TypeEvento IBColecao::Revisada = "IBColecao::Revisada";
//## end IBColecao::Revisada.attr

//## begin IBColecao::Destruida.attr preserve=no  public: static TypeEvento {V} "IBColecao::Destruida"
TypeEvento IBColecao::Destruida = "IBColecao::Destruida";
//## end IBColecao::Destruida.attr

//## begin IBColecao::Ativa.attr preserve=no  public: static TypeEvento {V} "IBColecao::Ativa"
TypeEvento IBColecao::Ativa = "IBColecao::Ativa";
//## end IBColecao::Ativa.attr

//## begin IBColecao::Inativa.attr preserve=no  public: static TypeEvento {V} "IBColecao::Inativa"
TypeEvento IBColecao::Inativa = "IBColecao::Inativa";
//## end IBColecao::Inativa.attr

IBColecao::IBColecao(TComponent* Dono)
  //## begin IBColecao::IBColecao%959658640.hasinit preserve=no
      : m_Ativo(false)
  //## end IBColecao::IBColecao%959658640.hasinit
  //## begin IBColecao::IBColecao%959658640.initialization preserve=yes
  ,IComponente( Dono )
  //## end IBColecao::IBColecao%959658640.initialization
{
  //## begin IBColecao::IBColecao%959658640.body preserve=yes
  m_ColecaoBase = NULL;
  //## end IBColecao::IBColecao%959658640.body
}


IBColecao::~IBColecao()
{
  //## begin IBColecao::~IBColecao%.body preserve=yes
  if (m_ColecaoBase != NULL )
    delete m_ColecaoBase;
  m_ColecaoBase = NULL;

  notificarObservadores(
    IEventoNotificacaoBuilder(
                this,
                IBColecao::Destruida) );

  //## end IBColecao::~IBColecao%.body
}



//## Other Operations (implementation)
void IBColecao::fazerRevisao()
{
  //## begin IBColecao::fazerRevisao%959658641.body preserve=yes

  // chamada refazer
  setClasseRepresentada( m_ClasseRepresentada );

  if (m_Ativo==true) // refazer chamada
  {
    m_Ativo = false;
    setAtivo( true );
  }
  //## end IBColecao::fazerRevisao%959658641.body
}

void IBColecao::setClasseRepresentada(const IClassesNegocio p_classe)
{
  //## begin IBColecao::setClasseRepresentada%960001692.body preserve=yes
  m_ClasseRepresentada = p_classe;
  // criar o template
  if ( ! ComponentState.Contains(csLoading))
  {
    try {
          if (m_ColecaoBase != NULL )
            delete m_ColecaoBase;
          m_ColecaoBase = NULL;
          switch ( m_ClasseRepresentada )
          {
            case  _Cadastro:
                m_ColecaoBase = new ColecaoCadastro;
                break;
            case  _Pessoa:
                m_ColecaoBase = new ColecaoPessoa;
                break;
            case _Titulo:
                m_ColecaoBase = new ColecaoTitulo;
                break;
            default :
                IBUtilitaria::mensagemUsuario("IBColecao: Classe representada é nula");
          }

          notificarObservadores(
            IEventoNotificacaoBuilder(
                  this,
                  IBColecao::Revisada) );

          // refaz chamada a setAtivo
          Ativo = Ativo;

    } catch ( IErro e )
    { IBUtilitaria::mensagemUsuario(e.textError());
      // deu erro vamos zerar o ponteiro para colecao
      m_ColecaoBase = NULL;
			m_ClasseRepresentada = _Indefinida;
    }
    catch ( ... )
    { IBUtilitaria::mensagemUsuario("Erro ... capturado");
      // deu erro vamos zerar o ponteiro para colecao
      m_ColecaoBase = NULL;
		m_ClasseRepresentada = _Indefinida;
    }
  }
  //## end IBColecao::setClasseRepresentada%960001692.body
}

void IBColecao::setAtivo(bool isLigar)
{
  //## begin IBColecao::setAtivo%960001693.body preserve=yes
  if ( ComponentState.Contains(csLoading))
    m_Ativo = isLigar;
  else
  {
    IBUtilitaria::inicioOperacaoLenta();
    try {
         if ( isLigar )
         {
           // verifica se j  esta pronta
           if ( m_ColecaoBase != NULL )
           {
            if ( m_ColecaoBase->estado()!=pronta )
            {
               m_ColecaoBase->pronto();
            }
            notificarObservadores(
               IEventoNotificacaoBuilder(
                  this,
                  IBColecao::Pronta ) );
           }
           else
           {
             IBUtilitaria::mensagemUsuario("Defina o tipo classe de negócio a ser representado antes de ativar");
             isLigar = false;
           }
          }
          m_Ativo = isLigar;
        }
    catch ( IErro e )
      { IBUtilitaria::mensagemUsuario(e.textError()); };
    IBUtilitaria::finalOperacaoLenta();
  }
  //## end IBColecao::setAtivo%960001693.body
}

bool IBColecao::isFimObjetos()
{
  //## begin IBColecao::isFimObjetos%960001694.body preserve=yes
  return m_ColecaoBase->isFim();
  //## end IBColecao::isFimObjetos%960001694.body
}

//## Get and Set Operations for Has Relationships (implementation)

const IColecaoPersistenteBase * IBColecao::getColecaoBase() const
{
  //## begin IBColecao::getColecaoBase%.get preserve=no
  return m_ColecaoBase;
  //## end IBColecao::getColecaoBase%.get
}

void IBColecao::setColecaoBase(IColecaoPersistenteBase *const  value)
{
  //## begin IBColecao::setColecaoBase%.set preserve=no
  m_ColecaoBase = value;
  //## end IBColecao::setColecaoBase%.set
}

const IClassesNegocio IBColecao::getClasseRepresentada() const
{
  //## begin IBColecao::getClasseRepresentada%.get preserve=no
  return m_ClasseRepresentada;
  //## end IBColecao::getClasseRepresentada%.get
}


// Additional Declarations
//## begin IBColecao.declarations preserve=yes
#pragma option pop
//## end IBColecao.declarations


// Class IClassesNegocio 



