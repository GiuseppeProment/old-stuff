//## begin module.cm preserve=no
//	CÛdigo adequado para CBuilder (Componente)
//## end module.cm

//## begin module.cp preserve=no
//	(c) 2000 Giuseppe E. Proment Jr.
//## end module.cp

//## Module: IBLista; Package body
//## Subsystem: I++ para CBuilder
//## Source file: g:\devrico\codigo\persist\comp_c\iblista.cpp


//## begin module.additionalIncludes preserve=no
#include <vcl.h>
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#pragma hdrstop
//## end module.includes

// IBLista
#include "IBLista.h"

//## begin module.declarations preserve=no
// incluir editores
#include "EditorLista.h"
#pragma option push -pr
#pragma package( smart_init )
static inline void ValidCtrCheck( IBLista * )
{
    new IBLista(NULL);
}
// ------
namespace Iblista
{
    void __fastcall PACKAGE Register()
     {
        TComponentClass classes[1]=
        {__classid(IBLista)};
        RegisterComponents("I++",classes,0);
        RegisterComponentEditor(classes[0],__classid(IBEditorLista));
     }
}
//---------
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


// Class IBLista 




IBLista::IBLista(TComponent* Dono)
  //## begin IBLista::IBLista%960264087.hasinit preserve=no
  //## end IBLista::IBLista%960264087.hasinit
  //## begin IBLista::IBLista%960264087.initialization preserve=yes
  :TCustomListView( Dono )
  //## end IBLista::IBLista%960264087.initialization
{
  //## begin IBLista::IBLista%960264087.body preserve=yes
  // criar o notificador indireto

  //m_ComponenteAgregado = new INotificadorIndireto( this, this->quandoEventoNotificacao );
  // vamos passar nulo, porque vou destrui-lo no destrutor
  // se tiver um dono, Ç destruido quando o dono o Ç.
  // m_ComponenteAgregado = new INotificadorIndireto( Dono );
	
  m_ObservadorInterno = new INotificadorIndireto( this );
  m_ObservadorInterno->setQuandoEvento( this->quandoEventoNotificacao );

  // dar nome
  // m_ComponenteAgregado->Name = "m_ComponenteAgregado";
  m_ColecaoRepresentada = NULL;

	// criar a TCollection m_colunas
	m_colunas = new TCollection( __classid(IColuna) );


  //## end IBLista::IBLista%960264087.body
}


IBLista::~IBLista()
{
  //## begin IBLista::~IBLista%.body preserve=yes
  // destruir o notificador indireto
  // n∆o destruir porque o form Ç dono
  // delete m_ObservadorInterno;
  if ( m_ColecaoRepresentada != NULL )
  {
    // parar de observar, pois vai ser eliminada
    m_ColecaoRepresentada->PararNotificarEventosPara( m_ObservadorInterno );
  }
	delete m_colunas;
   delete m_ObservadorInterno;
  //## end IBLista::~IBLista%.body
}



//## Other Operations (implementation)
void IBLista::CarregarObjetos()
{
  //## begin IBLista::CarregarObjetos%960264088.body preserve=yes
	// deve estar montada
 	TListItem  *ListItem;
 	IColuna *theIColuna;
	IPersistente* objeto;

   // ajustar estilo default
   // ViewStyle = vsReport;

 	// limpar items
 	Items->Clear();

	IColecaoPersistenteBase* colecao =
    const_cast<IColecaoPersistenteBase*>
      ( m_ColecaoRepresentada->getColecaoBase() );


	if ( colecao == NULL  )
		return;

	if ( colecao->estado() != pronta )
		return;

  if ( m_colunas->Count < 1 )
    return;


	try 
	{
		for ( colecao->goPrimeiro(); ! colecao->isFim(); colecao->goProximo() )
		{
			objeto = colecao->InstanciaCorrente();
	    // campo mestre
	    ListItem = Items->Add();
	    theIColuna = (IColuna*)(m_colunas->Items[0]);
	    ListItem->Caption = (char*) objeto->getCampoPorIndice(theIColuna->indexDoAtributo);
	    for (int i=1; i<m_colunas->Count; i++ )
	    {
	 	    theIColuna = (IColuna*)(m_colunas->Items[i]);
	      ListItem->
	        SubItems->
	          Add((char*)objeto->getCampoPorIndice(theIColuna->indexDoAtributo));
	    }
		}
	}
	catch ( IErro &e ) 
	{
		IBUtilitaria::mensagemUsuario( e.textError() );
	}

  //## end IBLista::CarregarObjetos%960264088.body
}

void IBLista::WriteState(TWriter* Writer)
{
  //## begin IBLista::WriteState%960264089.body preserve=yes
	esvaziar();
  TCustomListView::WriteState( Writer );
  //## end IBLista::WriteState%960264089.body
}

void IBLista::quandoEventoNotificacao(IEventoNotificacaoBuilder& evento)
{
  //## begin IBLista::quandoEventoNotificacao%907215653.body preserve=yes
  if ( evento.evento == IBColecao::Destruida )
  {
		// somente em Design-Time
  	if ( ComponentState.Contains(csDesigning) ) {
			esvaziar();
			Columns->Clear();
         colunas->Clear();
			m_ColecaoRepresentada = NULL;
         IBUtilitaria::mensagemUsuario( "coleÁ„o destruida" );
			}

  } else if ( evento.evento == IBColecao::Revisada )
  {
  	if ( ComponentState.Contains(csDesigning) ) {
			esvaziar();
			Columns->Clear();
    	colunas->Clear();
		}
  } else if ( evento.evento ==  IBColecao::Pronta )
  {
    CarregarObjetos();
  } else
    IBUtilitaria::mensagemUsuario( evento.evento );
  //## end IBLista::quandoEventoNotificacao%907215653.body
}

void IBLista::setColecaoRepresentada(IBColecao* colecao)
{
  //## begin IBLista::setColecaoRepresentada%960521281.body preserve=yes
  if ( m_ColecaoRepresentada != NULL )
  {
    // parar de observar, pois vai ser trocada
    m_ColecaoRepresentada->PararNotificarEventosPara( m_ObservadorInterno );
  }
  // guardar a referencia a nova colecao
  m_ColecaoRepresentada = colecao;

  // pedir para observar seus eventos
  m_ColecaoRepresentada->NotificarEventosPara( m_ObservadorInterno );

	// esvaziar e limpar
	esvaziar();
	Columns->Clear();
  colunas->Clear();


  //## end IBLista::setColecaoRepresentada%960521281.body
}

void IBLista::montar()
{
  //## begin IBLista::montar%976927453.body preserve=yes
	// construir as colunas do listView
 TListColumn  *NovaColuna;
 IColuna *theIColuna;

 // limpar items
 Items->Clear();
 // limpar Colunas
 Columns->Clear();

 ViewStyle = vsReport;

 for (int i=0; i<m_colunas->Count; i++ )
 {
 	theIColuna = (IColuna*)(m_colunas->Items[i]);
 	NovaColuna = Columns->Add();
 	NovaColuna->Caption = theIColuna->descricao;
	NovaColuna->AutoSize = false;
	NovaColuna->Width = (Canvas->TextWidth("A"))*theIColuna->largura;
 }
 CarregarObjetos();
  //## end IBLista::montar%976927453.body
}

void IBLista::esvaziar()
{
  //## begin IBLista::esvaziar%976927454.body preserve=yes
  Items->Clear();
  //## end IBLista::esvaziar%976927454.body
}

void IBLista::Loaded()
{
  //## begin IBLista::Loaded%959306787.body preserve=yes
  TCustomListView::Loaded();

  if ( ColecaoRepresentada != NULL )
   // verificar se a coleÁ„o esta pronta
   if ( ColecaoRepresentada->IsPronto )
   {
      //montar(); nao precisa j· È gravado com as colunas
      //CarregarObjetos(); n∆o precisa Ç acionado por evento
   };

  //## end IBLista::Loaded%959306787.body
}

//## Get and Set Operations for Has Relationships (implementation)

const INotificadorIndireto * IBLista::getObservadorInterno() const
{
  //## begin IBLista::getObservadorInterno%.get preserve=no
  return m_ObservadorInterno;
  //## end IBLista::getObservadorInterno%.get
}

void IBLista::setObservadorInterno(INotificadorIndireto *const  value)
{
  //## begin IBLista::setObservadorInterno%.set preserve=no
  m_ObservadorInterno = value;
  //## end IBLista::setObservadorInterno%.set
}

IBColecao * IBLista::getColecaoRepresentada()
{
  //## begin IBLista::getColecaoRepresentada%.get preserve=no
  return m_ColecaoRepresentada;
  //## end IBLista::getColecaoRepresentada%.get
}

const TCollection * IBLista::getcolunas() const
{
  //## begin IBLista::getcolunas%.get preserve=no
  return m_colunas;
  //## end IBLista::getcolunas%.get
}

void IBLista::setcolunas(TCollection *const  value)
{
  //## begin IBLista::setcolunas%.set preserve=no
  m_colunas = value;
  //## end IBLista::setcolunas%.set
}


// Additional Declarations
//## begin IBLista.declarations preserve=yes
#pragma option pop
//## end IBLista.declarations


// Class IColuna 





// Additional Declarations
//## begin IColuna.declarations preserve=yes
//## end IColuna.declarations