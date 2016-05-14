//## begin module.cm preserve=no
//	Código adequado para CBuilder (Componente)
//## end module.cm

//## begin module.cp preserve=no
//	(c) 2000 Giuseppe E. Proment Jr.
//## end module.cp

//## Module: IBDataStoreOracleActivex; Package body
//## Subsystem: I++ para CBuilder
//## Source file: g:\devrico\codigo\persist\comp_c\ibdata~1.cpp


//## begin module.additionalIncludes preserve=no
#include <vcl.h>
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#pragma hdrstop
//## end module.includes

// IBDataStoreOracleActivex
#include "IBData~1.h"

//## begin module.declarations preserve=no
#pragma option push -pr
#pragma package( smart_init )
static inline void ValidCtrCheck( IBDataStoreOracleActivex * )
{
    new IBDataStoreOracleActivex(NULL);
}
// ------
namespace Ibdatastoreoracleactivex
{
    void __fastcall PACKAGE Register()
     {
        TComponentClass classes[1]=
        {__classid(IBDataStoreOracleActivex)};
        RegisterComponents("I++",classes,0);
     }
}
//---------
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


// Class IBDataStoreOracleActivex 







//## begin IBDataStoreOracleActivex::Revisado.attr preserve=no  public: static TypeEvento {V} "IBDataStoreOracleActivex::Revisado"
TypeEvento IBDataStoreOracleActivex::Revisado = "IBDataStoreOracleActivex::Revisado";
//## end IBDataStoreOracleActivex::Revisado.attr

IBDataStoreOracleActivex::IBDataStoreOracleActivex(TComponent* Dono)
  //## begin IBDataStoreOracleActivex::IBDataStoreOracleActivex%960005300.hasinit preserve=no
      : m_Ativo(false)
  //## end IBDataStoreOracleActivex::IBDataStoreOracleActivex%960005300.hasinit
  //## begin IBDataStoreOracleActivex::IBDataStoreOracleActivex%960005300.initialization preserve=yes
  ,IBDataStore( Dono )
  //## end IBDataStoreOracleActivex::IBDataStoreOracleActivex%960005300.initialization
{
  //## begin IBDataStoreOracleActivex::IBDataStoreOracleActivex%960005300.body preserve=yes
  // adiciona ao broker
  IBroker::addDataStore( m_oOracle );
  // agora pode chamar quantas vezes quiser.
  IBroker::inicialize();
  //## end IBDataStoreOracleActivex::IBDataStoreOracleActivex%960005300.body
}


IBDataStoreOracleActivex::~IBDataStoreOracleActivex()
{
  //## begin IBDataStoreOracleActivex::~IBDataStoreOracleActivex%.body preserve=yes
  m_Ativo=false;
  // remove do broker
  IBroker::removeDataStore( m_oOracle );
  //## end IBDataStoreOracleActivex::~IBDataStoreOracleActivex%.body
}



//## Other Operations (implementation)
void IBDataStoreOracleActivex::setAtivo(bool isLigar)
{
  //## begin IBDataStoreOracleActivex::setAtivo%960005301.body preserve=yes
  if (ComponentState.Contains(csLoading)) // Se esta carregando do Form
    m_Ativo = isLigar;             // somente ajusta a propriedade
  else
  {
    IBUtilitaria::inicioOperacaoLenta();
    try {
        if ( isLigar != m_Ativo ) // se não mudou ignore
          {
            if ( isLigar )
                m_oOracle.ligar();
            else
              m_oOracle.desligar();
            m_Ativo = isLigar;
          }
        }
    catch ( IErro e )
      { IBUtilitaria::mensagemUsuario(e.textError()); };
    IBUtilitaria::finalOperacaoLenta();
  }
  //## end IBDataStoreOracleActivex::setAtivo%960005301.body
}

void IBDataStoreOracleActivex::setNomeConexao(System::AnsiString nome)
{
  //## begin IBDataStoreOracleActivex::setNomeConexao%960005302.body preserve=yes
  if ( mudancaEstadoPermitida() )
    m_oOracle.setnome( nome.c_str() );
  //## end IBDataStoreOracleActivex::setNomeConexao%960005302.body
}

void IBDataStoreOracleActivex::setUsuario(System::AnsiString nome)
{
  //## begin IBDataStoreOracleActivex::setUsuario%960005303.body preserve=yes
  if ( mudancaEstadoPermitida() )
    m_oOracle.setusuario( nome.c_str() );
  //## end IBDataStoreOracleActivex::setUsuario%960005303.body
}

void IBDataStoreOracleActivex::setSenha(System::AnsiString nome)
{
  //## begin IBDataStoreOracleActivex::setSenha%960005304.body preserve=yes
  if ( mudancaEstadoPermitida() )
    m_oOracle.setsenha( nome.c_str()  );
  //## end IBDataStoreOracleActivex::setSenha%960005304.body
}

void IBDataStoreOracleActivex::setNomeDB(System::AnsiString nome)
{
  //## begin IBDataStoreOracleActivex::setNomeDB%960005305.body preserve=yes
  if ( mudancaEstadoPermitida() )
    m_oOracle.setnomeDb( nome.c_str() );
  //## end IBDataStoreOracleActivex::setNomeDB%960005305.body
}

System::AnsiString IBDataStoreOracleActivex::getNomeConexao()
{
  //## begin IBDataStoreOracleActivex::getNomeConexao%960005306.body preserve=yes
  return (char*)m_oOracle.nome();
  //## end IBDataStoreOracleActivex::getNomeConexao%960005306.body
}

System::AnsiString IBDataStoreOracleActivex::getUsuario()
{
  //## begin IBDataStoreOracleActivex::getUsuario%960005307.body preserve=yes
  return (char*)m_oOracle.usuario( );
  //## end IBDataStoreOracleActivex::getUsuario%960005307.body
}

System::AnsiString IBDataStoreOracleActivex::getSenha()
{
  //## begin IBDataStoreOracleActivex::getSenha%960005308.body preserve=yes
  return (char*)m_oOracle.senha( );
  //## end IBDataStoreOracleActivex::getSenha%960005308.body
}

System::AnsiString IBDataStoreOracleActivex::getNomeDB()
{
  //## begin IBDataStoreOracleActivex::getNomeDB%960005309.body preserve=yes
  return (char*)m_oOracle.nomeDb( );
  //## end IBDataStoreOracleActivex::getNomeDB%960005309.body
}

void IBDataStoreOracleActivex::fazerRevisao()
{
  //## begin IBDataStoreOracleActivex::fazerRevisao%959658641.body preserve=yes
  // checar propriedades
  if (m_Ativo==true) // se esta ativo então deve ligar
   {
    IBUtilitaria::inicioOperacaoLenta();
    try { m_oOracle.ligar(); }
    catch ( IErro e )
      { IBUtilitaria::mensagemUsuario(e.textError()); };
    IBUtilitaria::finalOperacaoLenta();
   }
  //## end IBDataStoreOracleActivex::fazerRevisao%959658641.body
}

bool IBDataStoreOracleActivex::mudancaEstadoPermitida()
{
  //## begin IBDataStoreOracleActivex::mudancaEstadoPermitida%960005310.body preserve=yes
  if (ComponentState.Contains(csLoading)) // Se esta carregando do Form
    return true;                   // somente ajusta a propriedade
  else
  {
    if ( m_Ativo )
      IBUtilitaria::mensagemUsuario("Desligue o DataStore antes; de mudar esta propriedade");
    return ! m_Ativo;
  }
  //## end IBDataStoreOracleActivex::mudancaEstadoPermitida%960005310.body
}


// Additional Declarations
//## begin IBDataStoreOracleActivex.declarations preserve=yes
#pragma option pop
//## end IBDataStoreOracleActivex.declarations




