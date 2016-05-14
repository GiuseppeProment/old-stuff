//## begin module.cm preserve=no
//	Código adequado para CBuilder (Componente)
//## end module.cm

//## begin module.cp preserve=no
//	(c) 2000 Giuseppe E. Proment Jr.
//## end module.cp

//## Module: IBDataStoreODBC; Package body
//## Subsystem: I++ para CBuilder
//## Source file: g:\devrico\codigo\persist\comp_c\ibdata~2.cpp


//## begin module.additionalIncludes preserve=no
#include <vcl.h>
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#pragma hdrstop
//## end module.includes

// IBDataStoreODBC
#include "IBDATA~2.h"

//## begin module.declarations preserve=no
#pragma option push -pr
#pragma package( smart_init )
static inline void ValidCtrCheck( IBDataStoreODBC * )
{
    new IBDataStoreODBC(NULL);
}
// ------
namespace Ibdatastoreodbc
{
    void __fastcall PACKAGE Register()
     {
        TComponentClass classes[1]=
        {__classid(IBDataStoreODBC)};
        RegisterComponents("I++",classes,0);
     }
}
//---------
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


// Class IBDataStoreODBC 







//## begin IBDataStoreODBC::Revisado.attr preserve=no  public: static TypeEvento {V} "IBDataStoreODBC::Revisado"
TypeEvento IBDataStoreODBC::Revisado = "IBDataStoreODBC::Revisado";
//## end IBDataStoreODBC::Revisado.attr

IBDataStoreODBC::IBDataStoreODBC(TComponent* Dono)
  //## begin IBDataStoreODBC::IBDataStoreODBC%960005300.hasinit preserve=no
      : m_Ativo(false)
  //## end IBDataStoreODBC::IBDataStoreODBC%960005300.hasinit
  //## begin IBDataStoreODBC::IBDataStoreODBC%960005300.initialization preserve=yes
  ,IBDataStore( Dono )
  //## end IBDataStoreODBC::IBDataStoreODBC%960005300.initialization
{
  //## begin IBDataStoreODBC::IBDataStoreODBC%960005300.body preserve=yes
  // adiciona ao broker
  IBroker::addDataStore( m_oODBC );
  // agora pode chamar quantas vezes quiser.
  IBroker::inicialize();
  //## end IBDataStoreODBC::IBDataStoreODBC%960005300.body
}


IBDataStoreODBC::~IBDataStoreODBC()
{
  //## begin IBDataStoreODBC::~IBDataStoreODBC%.body preserve=yes
  m_Ativo=false;
  // remove do broker
  IBroker::removeDataStore( m_oODBC );
  //## end IBDataStoreODBC::~IBDataStoreODBC%.body
}



//## Other Operations (implementation)
void IBDataStoreODBC::setAtivo(bool isLigar)
{
  //## begin IBDataStoreODBC::setAtivo%960005301.body preserve=yes
  if (ComponentState.Contains(csLoading)) // Se esta carregando do Form
    m_Ativo = isLigar;             // somente ajusta a propriedade
  else
  {
    IBUtilitaria::inicioOperacaoLenta();
    try {
        if ( isLigar != m_Ativo ) // se não mudou ignore
          {
            if ( isLigar )
                m_oODBC.ligar();
            else
              m_oODBC.desligar();
            m_Ativo = isLigar;
          }
        }
    catch ( IErro e )
      { IBUtilitaria::mensagemUsuario(e.textError()); };
    IBUtilitaria::finalOperacaoLenta();
  }
  //## end IBDataStoreODBC::setAtivo%960005301.body
}

void IBDataStoreODBC::setNomeConexao(System::AnsiString nome)
{
  //## begin IBDataStoreODBC::setNomeConexao%960005302.body preserve=yes
  if ( mudancaEstadoPermitida() )
    m_oODBC.setnome( nome.c_str() );
  //## end IBDataStoreODBC::setNomeConexao%960005302.body
}

void IBDataStoreODBC::setUsuario(System::AnsiString nome)
{
  //## begin IBDataStoreODBC::setUsuario%960005303.body preserve=yes
  if ( mudancaEstadoPermitida() )
    m_oODBC.setusuario( nome.c_str() );
  //## end IBDataStoreODBC::setUsuario%960005303.body
}

void IBDataStoreODBC::setSenha(System::AnsiString nome)
{
  //## begin IBDataStoreODBC::setSenha%960005304.body preserve=yes
  if ( mudancaEstadoPermitida() )
    m_oODBC.setsenha( nome.c_str()  );
  //## end IBDataStoreODBC::setSenha%960005304.body
}

void IBDataStoreODBC::setNomeDSN(System::AnsiString nome)
{
  //## begin IBDataStoreODBC::setNomeDSN%960005305.body preserve=yes
  if ( mudancaEstadoPermitida() )
    m_oODBC.setDSN( nome.c_str() );
  //## end IBDataStoreODBC::setNomeDSN%960005305.body
}

System::AnsiString IBDataStoreODBC::getNomeConexao()
{
  //## begin IBDataStoreODBC::getNomeConexao%960005306.body preserve=yes
  return (char*)m_oODBC.nome();
  //## end IBDataStoreODBC::getNomeConexao%960005306.body
}

System::AnsiString IBDataStoreODBC::getUsuario()
{
  //## begin IBDataStoreODBC::getUsuario%960005307.body preserve=yes
  return (char*)m_oODBC.usuario( );
  //## end IBDataStoreODBC::getUsuario%960005307.body
}

System::AnsiString IBDataStoreODBC::getSenha()
{
  //## begin IBDataStoreODBC::getSenha%960005308.body preserve=yes
  return (char*)m_oODBC.senha( );
  //## end IBDataStoreODBC::getSenha%960005308.body
}

System::AnsiString IBDataStoreODBC::getNomeDSN()
{
  //## begin IBDataStoreODBC::getNomeDSN%960005309.body preserve=yes
  return (char*)m_oODBC.DSN( );
  //## end IBDataStoreODBC::getNomeDSN%960005309.body
}

void IBDataStoreODBC::fazerRevisao()
{
  //## begin IBDataStoreODBC::fazerRevisao%959658641.body preserve=yes
  // checar propriedades
  if (m_Ativo==true) // se esta ativo então deve ligar
   {
    IBUtilitaria::inicioOperacaoLenta();
    try { m_oODBC.ligar(); }
    catch ( IErro e )
      { IBUtilitaria::mensagemUsuario(e.textError()); };
    IBUtilitaria::finalOperacaoLenta();
   }
  // dispara evento
  // No
  //## end IBDataStoreODBC::fazerRevisao%959658641.body
}

bool IBDataStoreODBC::mudancaEstadoPermitida()
{
  //## begin IBDataStoreODBC::mudancaEstadoPermitida%960005310.body preserve=yes
  if (ComponentState.Contains(csLoading)) // Se esta carregando do Form
    return true;                   // somente ajusta a propriedade
  else
  {
    if ( m_Ativo )
      IBUtilitaria::mensagemUsuario("Desligue o DataStore antes; de mudar esta propriedade");
    return ! m_Ativo;
  }
  //## end IBDataStoreODBC::mudancaEstadoPermitida%960005310.body
}


// Additional Declarations
//## begin IBDataStoreODBC.declarations preserve=yes
#pragma option pop
//## end IBDataStoreODBC.declarations




