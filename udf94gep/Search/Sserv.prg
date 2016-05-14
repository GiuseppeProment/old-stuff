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
//    BROWSE SERVICO DE VENDA


/*
	 Parametros     : ListaGet,LinhaJanela , ColunaJanela
							Exibir, LinhaExibicao, ColunaExibicao, ComprimentoExibicao,
	 Objetivo       : Escolha e exibicao de servico venda, associado a variavel no get
	 Excessao       :
	 Pre-requisitos : Arquivos ServVen aberto, chamado somente por valid no get
*/

FUNCTION SearchSerV(aGetList,nLinJan,nColJan,lExibir,nLinExib,nColExib,nLenExib)
	Local oGet := GetActive()
	Local sCorAnt := SetColor()
	Local nOrder  := ServVen->(IndexOrd())
	Local lRet
	
	If Empty(oGet:VarGet()) .or. !(ServVen->(DbSeek(oGet:VarGet()),Found()))
		wClose( wOpen( WSet( nLinJan, nColJan, nLinJan+14, nColJan+70, WhatColor(1), pSBAR, 3, 0,;
		 "PESQUISA SERVICO VENDA"   , pLEFT_JUSTIFIED, { |aWindow| SetColor(WhatColor()),ServVen->( SerVBrowse( aWindow ) ;
		 ) },, pSBAR ) ) )
		 SetColor(sCorAnt)
		If LastKey() != pESC
			oGet:VarPut(ServVen->SvCodigo)
			oGet:Display()
			lRet:=pTRUE
		else
			lRet:=pFALSE
		endif
	else
		If ServVen->(Found()) .and. ServVen->SvStatus != "A"
			Msg("Servi‡o Inativo")
		Endif
		ServVen->(DbSetOrder(1))
		lRet := pTRUE
	Endif
	ServVen->(DbSetOrder(nOrder))
	If lRet==pTRUE .and. lExibir
		If nLenExib!=Nil
			@ nLinExib,nColExib say Substr(ServVen->SvDescr,1,nLenExib) color;
			CorGetUnSel()
		else
			@ nLinExib,nColExib say ServVen->SvDescr color CorGetUnSel()
		endif
	Endif
	Return lRet

STATIC FUNCTION SerVBrowse( aWindow )
	Local oEstoque, oCol
	Local nKey     := 0,;
			lRet     := pTRUE,;
			sCorAnt  := SetColor()

	If EOF() .or. BOF()
		DbGoTop()
	Endif


	// Cria Objeto TBrowseDB(nLinTop,nColTop,nLinBottom,nColBottom)
	oEstoque := TBrowseDB(aWindow[1,1],aWindow[1,2],;
							  aWindow[1,3]-01,aWindow[1,4])
	@ aWindow[1,1]+01,aWindow[1,2]-01 Say Chr(198)
	@ aWindow[1,1]+01,aWindow[1,4]+01 Say Chr(181)
	oEstoque:headSep := Chr(205) + Chr(203) + Chr(205)
	oEstoque:colSep  := " " + Chr(186) + " "
	oEstoque:footSep := Chr(196) + Chr(208) + Chr(196)
	// Criar objetos coluna

	oCol:=TBcolumnNew( "DESCRICAO",{||ServVen->SvDescr } )
	oCol:Width := 50
	oEstoque:AddColumn(oCol)

	oCol:=TBcolumnNew( "Cod.",{||ServVen->SvCodigo } )
	oEstoque:AddColumn(oCol)

	// Define Filtros
	Centra(aWindow[1,3],aWindow[1,2],aWindow[1,4],"F9 DESCRICAO  F10 CODIGO")

	While pTRUE

		If IsStable(oEstoque)
			If oEstoque:hitTop .or. oEstoque:hitBottom
				Tone(3600,.2) ; Tone(3700,.2)
			Endif
			While ( nKey := Inkey() ) == 0       // Nao Espera Tecla
				If oEstoque:Cargo != NIL          // o Slot Contem Algo,
					Eval( oEstoque:cargo )         // Execute !
				Endif
			End
		Endif
		If nKey == pESC
			lRet := pFALSE
			Exit
		Endif
		ServVen->( StdKey( oEstoque, nKey ) )     // Controle de Teclagem

		Do Case
		  Case nKey == pF9         //Procura Nome
				  ServVen->( SerVSeekNome(aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
				  Exit
		  Case nKey == pF10        //Procura Codigo
				  ServVen->( SerVSeekCodigo( aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
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

Static Function SerVSeekNome(nLin,nCol,nColf)
		Local cEqDescNor := ServVen->(MakeEmpty("SvDescr"))
		Local GetList:={}
		ServVen->(DbSetOrder(2))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "DESCRICAO A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get cEqDescNor Pict [@! ] Color WhatColor()
		read
		ServVen->(DbSeek(cEqDescNorm,.t.))
		If ServVen->(Eof())
			ServVen->(DbSkip(-1))
		Endif
		wClose()
		VOID

Static Function SerVSeekCodigo(nLin,nCol,nColf)
		Local nMmCodigo := ServVen->(MakeEmpty("SvCodigo"))
		Local GetList:={}
		ServVen->(DbSetOrder(1))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "CODIGO A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get nMmCodigo Color WhatColor()
		read
		wClose()
		If !(ServVen->(DbSeek(nMmCodigo,.t.)))
			Msg("Nao encontrado")
		Endif
		Return ServVen->(Found())

