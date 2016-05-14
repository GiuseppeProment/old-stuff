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
//  BROWSE TIPO DE MADEIRA

/*
	 Parametros     : ListaGet,LinhaJanela , ColunaJanela
							Exibir, LinhaExibicao, ColunaExibicao, ComprimentoExibicao,
	 Objetivo       : Escolha e exibicao de Tipo de mad. associado a variavel no get
	 Excessao       :
	 Pre-requisitos : Arquivos MedMade aberto, chamado somente por valid no get
*/

FUNCTION SearchTipoMade(aGetList,nLinJan,nColJan,lExibir,nLinExib,nColExib,nLenExib)
	Local oGet := GetActive()
	Local sCorAnt := SetColor()
	Local nOrder1 := TipoMad->(IndexOrd())
	Local lRet
	
	TipoMad->(DbSetOrder(1))

	If Empty(oGet:VarGet()) .or. !TipoMad->(DbSeek(oGet:VarGet()))
		wClose( wOpen( WSet( nLinJan, nColJan, nLinJan+14, nColJan+36, WhatColor(1), pSBAR, 3, 0,;
		 "PESQUISA TIPOS MADEIRA"   , pLEFT_JUSTIFIED, { |aWindow| SetColor(WhatColor()),TipoMad->( TipoMadBrowse( aWindow ) ;
		 ) },, pSBAR ) ) )
		SetColor(sCorAnt)
		If LastKey() != pESC
			oGet:VarPut(TipoMad->TmCodigo)
			oGet:Display()
			lRet:=pTRUE
		else
			lRet:=pFALSE
		endif
	else
		lRet:=pTRUE
	Endif
	TipoMad->(DbSetOrder(nOrder1))
	If lRet==pTRUE .and. lExibir
		If nLenExib!=Nil
			@ nLinExib,nColExib say Substr(TipoMad->TmDescrNor,1,nLenExib) color;
			CorGetUnSel()
		else
			@ nLinExib,nColExib say TipoMad->TmDescrNor color CorGetUnSel()
		endif
	Endif
	Return lRet

STATIC FUNCTION TipoMadBrowse( aWindow )
	Local oTipoMade, oCol
	Local nKey     := 0,;
			lRet     := pTRUE,;
			sCorAnt  := SetColor()

	If EOF() .or. BOF()
		DbGoTop()
	Endif

	// Cria Objeto TBrowseDB(nLinTop,nColTop,nLinBottom,nColBottom)
	oTipoMade := TBrowseDB(aWindow[1,1],aWindow[1,2],;
							  aWindow[1,3]-01,aWindow[1,4])
	@ aWindow[1,1]+01,aWindow[1,2]-01 Say Chr(198)
	@ aWindow[1,1]+01,aWindow[1,4]+01 Say Chr(181)
	oTipoMade:headSep := Chr(205) + Chr(203) + Chr(205)
	oTipoMade:colSep  := " " + Chr(186) + " "
	oTipoMade:footSep := Chr(196) + Chr(208) + Chr(196)
	// Criar objetos coluna
	oTipoMade:AddColumn( TBcolumnNew( "CODIGO", {|| TipoMad->TmCodigo } ) )
	oTipoMade:AddColumn( TBcolumnNew( "DESCRICAO", {|| TipoMad->TmDescrNor } ) )
	oTipoMade:AddColumn( TBcolumnNew( "DESCRICAO ABV", {|| TipoMad->TmDescrAbr } ) )

	Centra(aWindow[1,3],aWindow[1,2],aWindow[1,4],"F9 DESCRICAO   F10 CODIGO")

	While pTRUE

		If IsStable(oTipoMade)
			If oTipoMade:hitTop .or. oTipoMade:hitBottom
				Tone(3600,.2) ; Tone(3700,.2)
			Endif
			While ( nKey := Inkey() ) == 0       // Nao Espera Tecla
				If oTipoMade:Cargo != NIL          // o Slot Contem Algo,
					Eval( oTipoMade:cargo )         // Execute !
				Endif
			End
		Endif
		If nKey == pESC
			lRet := pFALSE
			Exit
		Endif
		TipoMad->( StdKey( oTipoMade, nKey ) )     // Controle de Teclagem
		Do Case
		  Case nKey == pF9         //Procura Nome
				  TipoMad->( TmMSeekNome(aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
				  Exit
		  Case nKey == pF10        //Procura Codigo
				  TipoMad->( TmMSeekCodigo( aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
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

Static Function TmMSeekNome(nLin,nCol,nColf)
		Local cTmDescrNor := TipoMad->(MakeEmpty("TmDescrNor"))
		Local GetList:={}
		TipoMad->(DbSetOrder(2))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "DESCRICAO A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get cTmDescrNor Pict [@! ] Color WhatColor()
		read
		TipoMad->(DbSeek(cTmDescrNorm,.t.))
		wClose()
		VOID

Static Function TmMSeekCodigo(nLin,nCol,nColf)
		Local nTmCodigo := TipoMad->(MakeEmpty("TmCodigo"))
		Local GetList:={}
		TipoMad->(DbSetOrder(1))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "CODIGO A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get nTmCodigo Color WhatColor()
		read
		wClose()
		If !(TipoMad->(DbSeek(nTmCodigo,.t.)))
			Msg("Nao encontrado")
		Endif
		VOID

