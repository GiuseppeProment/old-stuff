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
//  BROWSE DE ENDERECO DE CLIENTE

/*
	 Parametros     : ListaGet,LinhaJanela , ColunaJanela
							Exibir, LinhaExibicao, ColunaExibicao, ComprimentoExibicao,
							Codigo_cliente (p/ filtragem)
	 Objetivo       : Escolha e exibicao de Cliente associado a variavel no get
	 Excessao       :
	 Pre-requisitos : Arquivos MedMade aberto, chamado somente por valid no get
	 Observacao     : Esta Funcao Trabalha com Indice temporario
*/

FUNCTION SearchEstaCli(aGetList,nLinJan,nColJan,lExibir,nLinExib,nColExib,nLenExib,nClCodigo)
	Local sAlias := Alias()
	Local oGet := GetActive()
	Local sCorAnt := SetColor()
	Local nOrder1 := EstaCli->(IndexOrd())
	Local lRet, nRecord
    Local cNtx1 := NomeTemp()
    Local cNtx2 := NomeTemp()

	EstaCli->(DbSetOrder(1))

	If Empty(oGet:VarGet()) .or. !EstaCli->(DbSeek(str(nClCodigo)+Str(oGet:VarGet())))

		*Criacao de Indices Temporarios
		EstaCli->(CliNtxTmp(nClCodigo,cNtx1,cNtx2))

		wClose( wOpen( WSet( nLinJan, nColJan, nLinJan+14, nColJan+60, WhatColor(1), pSBAR, 3, 0,;
		 "PESQUISA ESTABELECIMENTO CLIENTE"   , pLEFT_JUSTIFIED, { |aWindow| SetColor(WhatColor()),EstaCli->( EstaCliBrowse( aWindow ) ;
		 ) },, pSBAR ) ) )

		nRecord := EstaCli->(RecNo())
		EstaCli->(DbCloseArea())
		fErase(cNtx1)
		fErase(cNtx2)
		BankUse(pDADOS+"EstaCli",.f.,0)
		EstaCli->(DbSetOrder(nOrder1))
		EstaCli->(DbGoTo(nRecord))

		SetColor(sCorAnt)
		If LastKey() != pESC
			oGet:VarPut(EstaCli->EcCodEst)
			oGet:Display()
			lRet:=pTRUE
		else
			lRet:=pFALSE
		endif
	else
		lRet:=pTRUE
	Endif

	EstaCli->(DbSetOrder(nOrder1))
	If lRet==pTRUE .and. lExibir

		If nLenExib!=Nil
			@ nLinExib,nColExib say Substr(IdEstab(EstaCli->EcIdenTest),1,nLenExib) color;
			CorGetUnSel()
		else
			@ nLinExib,nColExib say IdEstab(EstaCli->EcIdenTest) color CorGetUnSel()
		endif

	Endif
	If !Empty(sAlias)
		DbSelectArea(sAlias)
	Endif
	Return lRet

STATIC FUNCTION EstaCliBrowse( aWindow )
	Local oEstaCli, oCol
	Local nKey     := 0,;
			lRet     := pTRUE,;
			sCorAnt  := SetColor()


	If EOF() .or. BOF()
		DbGoTop()
	Endif

	// Cria Objeto TBrowseDB(nLinTop,nColTop,nLinBottom,nColBottom)
	oEstaCli := TBrowseDB(aWindow[1,1],aWindow[1,2],;
							  aWindow[1,3]-01,aWindow[1,4])
	@ aWindow[1,1]+01,aWindow[1,2]-01 Say Chr(198)
	@ aWindow[1,1]+01,aWindow[1,4]+01 Say Chr(181)
	oEstaCli:headSep := Chr(205) + Chr(203) + Chr(205)
	oEstaCli:colSep  := " " + Chr(186) + " "
	oEstaCli:footSep := Chr(196) + Chr(208) + Chr(196)
	// Criar objetos coluna
	oEstaCli:AddColumn( TBcolumnNew( "COD.", {|| EstaCli->EcCodEst } ) )

	oCol := TBcolumnNew( "TIPO", {|| IdEstab(EstaCli->EcIdenTest) } )
	oCol:Width:=12
	oEstaCli:AddColumn(oCol)

	oEstaCli:AddColumn( TBcolumnNew( "LOG.", {|| EstaCli->EcTipoLog } ) )
	oEstaCli:AddColumn( TBcolumnNew( "ENDERECO", {|| EstaCli->EcEnder } ) )
	oEstaCli:AddColumn( TBcolumnNew( "BAIRRO", {|| EstaCli->EcBairro } ) )

	Centra(aWindow[1,3],aWindow[1,2],aWindow[1,4],"F9 ENDERECO   F10 CODIGO")

	While pTRUE

		If IsStable(oEstaCli)
			If oEstaCli:hitTop .or. oEstaCli:hitBottom
				Tone(3600,.2) ; Tone(3700,.2)
			Endif
			While ( nKey := Inkey() ) == 0       // Nao Espera Tecla
				If oEstaCli:Cargo != NIL          // o Slot Contem Algo,
					Eval( oEstaCli:cargo )         // Execute !
				Endif
			End
		Endif
		If nKey == pESC
			lRet := pFALSE
			Exit
		Endif
		EstaCli->( StdKey( oEstaCli, nKey ) )     // Controle de Teclagem
		Do Case
		  Case nKey == pF9         //Procura Nome
				  EstaCli->( ECliSeekNome(aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
				  Exit
		  Case nKey == pF10        //Procura Codigo
				  EstaCli->( ECliSeekCodigo( aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
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

Static Function ECliSeekNome(nLin,nCol,nColf)
		Local cEcEnder := EstaCli->(MakeEmpty("EcEnder"))
		Local GetList:={}
		EstaCli->(DbSetOrder(2))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "ENDERECO A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get cEcEnder Pict wPicture([@! ]) Color WhatColor()
		read
		EstaCli->(DbSeek(cEcEnder,.t.))
		wClose()
		VOID

Static Function ECliSeekCodigo(nLin,nCol,nColf)
		Local nEcCodEst := EstaCli->(MakeEmpty("EcCodEst"))
		Local GetList:={}
		EstaCli->(DbSetOrder(1))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "CODIGO A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get nEcCodEst Color WhatColor()
		read
		wClose()
		If !(EstaCli->(DbSeek(nEcCodEst,.t.)))
			Msg("Nao encontrado")
		Endif
		VOID

Static Function CliNtxTmp(nClCodigo,cNtx1,cNtx2)
	// posicionar o primeiro estabelecimento do cliente
	DbSeek( Str(nClCodigo)+Str(MakeEmpty("EcCodEst")),.t. )
	// verificar erro
	If EstaCli->EcCodCli != nClCodigo
		Msg("Cliente sem Estabelecimentos ! <Quit>")
		Quit
	Endif
	Index on EstaCli->EcCodEst to (cNtx1) While EstaCli->EcCodCli==nClCodigo
	Index on EstaCli->EcEnder  to (cNtx2) While EstaCli->EcCodCli==nClCodigo
	Set Index to (cNtx1),(cNtx2)
	VOID


Static Function IdEstab(nEcIdenTest)
	Local cRet
	Do Case
		Case nEcIdenTest == 01 ; cRet := "SEDE       "
		Case nEcIdenTest == 02 ; cRet := "FATURAMENTO"
		Case nEcIdenTest == 03 ; cRet := "ENTREGA    "
		Case nEcIdenTest == 04 ; cRet := "COBRANCA   "
		Case nEcIdenTest == 05 ; cRet := "OBRA       "
		Case nEcIdenTest == 06 ; cRet := "OUTROS     "
		OtherWise
			cRet := "  ? "
	EndCase
	Return cRet

