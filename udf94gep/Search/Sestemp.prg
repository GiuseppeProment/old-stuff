#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Include "Recoma.ch"
#Include "PTWindow.ch"

#DEFINE EMPRESA_SERVICO "50.996.479"
#DEFINE EMPRESA_VENDA "51.212.348"

MemVar sCorJ,sCorF,sCorT,sCorL,sCorM
MemVar aPict, nTmp

//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//  BROWSE DE FILIAIS DE EMPRESA

/*
	 Parametros     : ListaGet,LinhaJanela , ColunaJanela
							Exibir, LinhaExibicao, ColunaExibicao, ComprimentoExibicao,
							Codigo_empresa (p/ filtragem)
	 Objetivo       : Escolha e exibicao de Filial associado a variavel no get
	 Excessao       :
	 Pre-requisitos : Arquivos Estabel aberto, chamado somente por valid no get
	 Observacao     : Esta Funcao Trabalha com Indice temporario
*/

FUNCTION SearchEstEmp(aGetList,nLinJan,nColJan,lExibir,nLinExib,nColExib,nLenExib,cEpCgc)
	Local sAlias := Alias()
	Local oGet := GetActive()
	Local sCorAnt := SetColor()
	Local nOrder1 := Estabel->(IndexOrd())
	Local lRet, nRecord
    Local cNtx1 := NomeTemp()
    Local cNtx2 := NomeTemp()

	Estabel->(DbSetOrder(1))

	If Empty(oGet:VarGet()) .or. !Estabel->(DbSeek(cEpCgc+oGet:VarGet()))

		*Criacao de Indices Temporarios
		Estabel->(EstNtxTmp(cEpCgc,cNtx1,cNtx2))

		wClose( wOpen( WSet( nLinJan, nColJan, nLinJan+14, nColJan+70, WhatColor(1), pSBAR, 3, 0,;
		 "PESQUISA ESTABELECIMENTO EMPRESA"   , pLEFT_JUSTIFIED, { |aWindow| SetColor(WhatColor()),Estabel->( EstaEmpBrowse(;
		 aWindow,cEpCgc ) ;
		 ) },, pSBAR ) ) )

		nRecord := Estabel->(RecNo())
		Estabel->(DbCloseArea())
		fErase(cNtx1)
		fErase(cNtx2)
		BankUse(pDADOS+"Estabel",.f.,0)
		Estabel->(DbSetOrder(nOrder1))
		Estabel->(DbGoTo(nRecord))

		SetColor(sCorAnt)
		If LastKey() != pESC
			oGet:VarPut(Estabel->EstCompCgc)
			oGet:Display()
			lRet:=pTRUE
		else
			lRet:=pFALSE
		endif
	else
		lRet:=pTRUE
	Endif


	If lRet==pTRUE .and. lExibir

		If nLenExib!=Nil
			@ nLinExib,nColExib say Substr(Estabel->EstUnidade,1,nLenExib) color;
			CorGetUnSel()
		else
			@ nLinExib,nColExib say Estabel->EstUnidade color CorGetUnSel()
		endif

	Endif
	If !Empty(sAlias)
		DbSelectArea(sAlias)
	Endif
	Return lRet

STATIC FUNCTION EstaEmpBrowse( aWindow , cEpCgc)
	Local oEstaEmp, oCol
	Local nKey     := 0,;
			lRet     := pTRUE,;
			sCorAnt  := SetColor()


	If EOF() .or. BOF()
		DbGoTop()
	Endif

	// Cria Objeto TBrowseDB(nLinTop,nColTop,nLinBottom,nColBottom)
	oEstaEmp := TBrowseDB(aWindow[1,1],aWindow[1,2],;
							  aWindow[1,3]-01,aWindow[1,4])
	@ aWindow[1,1]+01,aWindow[1,2]-01 Say Chr(198)
	@ aWindow[1,1]+01,aWindow[1,4]+01 Say Chr(181)
	oEstaEmp:headSep := Chr(205) + Chr(203) + Chr(205)
	oEstaEmp:colSep  := " " + Chr(186) + " "
	oEstaEmp:footSep := Chr(196) + Chr(208) + Chr(196)
	// Criar objetos coluna

	oEstaEmp:AddColumn( TBcolumnNew( "COD.", {|| cEpCgc+"/"+;
	Estabel->EstCompCgc } ) )
	
	oEstaEmp:AddColumn(TBcolumnNew( "TIPO", {|| Estabel->EstUnidade } ))
	oEstaEmp:AddColumn( TBcolumnNew( "LOG.", {|| Estabel->EstTipoLog } ) )
	oEstaEmp:AddColumn( TBcolumnNew( "ENDERECO", {|| Estabel->EstEnderec } ) )
	oEstaEmp:AddColumn( TBcolumnNew( "BAIRRO", {|| Estabel->EstBairro } ) )

	// Define Filtros

	Centra(aWindow[1,3],aWindow[1,2],aWindow[1,4],"F9 TIPO     F10 CODIGO")

	While pTRUE

		If IsStable(oEstaEmp)
			If oEstaEmp:hitTop .or. oEstaEmp:hitBottom
				Tone(3600,.2) ; Tone(3700,.2)
			Endif
			While ( nKey := Inkey() ) == 0       // Nao Espera Tecla
				If oEstaEmp:Cargo != NIL          // o Slot Contem Algo,
					Eval( oEstaEmp:cargo )         // Execute !
				Endif
			End
		Endif
		If nKey == pESC
			lRet := pFALSE
			Exit
		Endif
		Estabel->( StdKey( oEstaEmp, nKey ) )     // Controle de Teclagem
		Do Case
		  Case nKey == pF9         //Procura Nome
				  Estabel->( EEmpSeekNome(aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
				  Exit
		  Case nKey == pF10        //Procura Codigo
				  Estabel->( EEmpSeekCodigo( aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
				  Exit
		  Case nKey == pALT_F10
			  wMove()
			  Exit
		  Case nKey == pENTER
				  lRet:=pFALSE
				  exit
		EndCase
	Enddo  
	RETURN( lRet )

Static Function EEmpSeekNome(nLin,nCol,nColf)
		Local cEstUnidade := Estabel->(MakeEmpty("EstUnidade"))
		Local GetList:={}
		Estabel->(DbSetOrder(2))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "TIPO A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get cEstUnidade Pict wPicture([@! ]) Color WhatColor()
		read
		Estabel->(DbSeek(cEstUnidade,.t.))
		wClose()
		VOID

Static Function EEmpSeekCodigo(nLin,nCol,nColf)
		Local nEstCompCgc := Estabel->(MakeEmpty("EstCompCgc"))
		Local GetList:={}
		Estabel->(DbSetOrder(1))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "CODIGO A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get nEstCompCgc Color WhatColor()
		read
		wClose()
		If !(Estabel->(DbSeek(nEstCompCgc,.t.)))
			Msg("Nao encontrado")
		Endif
		VOID

Static Function EstNtxTmp(cEpCgc,cNtx1,cNtx2)
	// posicionar o primeiro estabelecimento do cliente
	DbSeek( cEpCgc+MakeEmpty("EstCompCgc"),.t. )
	// verificar erro
	If Estabel->EstCgc != cEpCgc
		Msg("Empresa sem Estabelecimentos ! <Quit>")
		Quit
	Endif
	Index on Estabel->EstCompCgc to (cNtx1) While Estabel->EstCgc==cEpCgc
	Index on Estabel->EstUnidade to (cNtx2) While Estabel->EstCgc==cEpCgc
	Set Index to (cNtx1),(cNtx2)
	VOID


