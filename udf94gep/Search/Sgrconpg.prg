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
//北北北北北北北北北北北北北北北北北北北北北北北�
//  BROWSE GRUPO DE CONTAS A PAGAR

/*
	 Parametros     : ListaGet,LinhaJanela , ColunaJanela
							Exibir, LinhaExibicao, ColunaExibicao, ComprimentoExibicao,
	 Objetivo       : Escolha e exibicao de Grupo Contas a pagar associado a variavel no get
	 Excessao       :
	 Pre-requisitos : Arquivos GrConPg aberto, chamado somente por valid no get
*/

FUNCTION SearchGrConPg(aGetList,nLinJan,nColJan,lExibir,nLinExib,nColExib,nLenExib)
	Local oGet := GetActive()
	Local sCorAnt := SetColor()
	Local nOrder1 := GrConPg->(IndexOrd())
	Local lRet
	
	GrConPg->(DbSetOrder(1))

	If Empty(oGet:VarGet()) .or. !GrConPg->(DbSeek(oGet:VarGet()))
        wClose( wOpen( WSet( nLinJan, nColJan, nLinJan+15, nColJan+50, WhatColor(1), pSBAR, 3, 0,;
		 "PESQUISA GRUPO CTASPAG"   , pLEFT_JUSTIFIED, { |aWindow| SetColor(WhatColor()),GrConPg->( GrConPgBrowse( aWindow ) ;
		 ) },, pSBAR ) ) )
		SetColor(sCorAnt)
		If LastKey() != pESC
			oGet:VarPut(GrConPg->GrcCodGru)
			oGet:Display()
			lRet:=pTRUE
		else
			lRet:=pFALSE
		endif
	else
		lRet:=pTRUE
	Endif
	GrConPg->(DbSetOrder(nOrder1))
	If lRet==pTRUE .and. lExibir
		If nLenExib!=Nil
			@ nLinExib,nColExib say Substr(GrConPg->GrcDescr,1,nLenExib) color;
			CorGetUnSel()
		else
			@ nLinExib,nColExib say GrConPg->GrcDescr color CorGetUnSel()
		endif
	Endif
	Return lRet

STATIC FUNCTION GrConPgBrowse( aWindow )
	Local oGrConPg, oCol
	Local nKey     := 0,;
			lRet     := pTRUE,;
			sCorAnt  := SetColor()

	If EOF() .or. BOF()
		DbGoTop()
	Endif

	// Cria Objeto TBrowseDB(nLinTop,nColTop,nLinBottom,nColBottom)
	oGrConPg := TBrowseDB(aWindow[1,1],aWindow[1,2],;
							  aWindow[1,3]-01,aWindow[1,4])
	@ aWindow[1,1]+01,aWindow[1,2]-01 Say Chr(198)
	@ aWindow[1,1]+01,aWindow[1,4]+01 Say Chr(181)
	oGrConPg:headSep := Chr(205) + Chr(203) + Chr(205)
	oGrConPg:colSep  := " " + Chr(186) + " "
	oGrConPg:footSep := Chr(196) + Chr(208) + Chr(196)
	// Criar objetos coluna
	oGrConPg:AddColumn( TBcolumnNew( "CD", {|| GrConPg->GrcCodGru } ) )
	oGrConPg:AddColumn( TBcolumnNew( "DESCRICAO", {|| GrConPg->GrcDescr } ) )

	Centra(aWindow[1,3],aWindow[1,2],aWindow[1,4],"F9 DESCRICAO   F10 CODIGO")

	While pTRUE

		If IsStable(oGrConPg)
			If oGrConPg:hitTop .or. oGrConPg:hitBottom
				Tone(3600,.2) ; Tone(3700,.2)
			Endif
			While ( nKey := Inkey() ) == 0       // Nao Espera Tecla
				If oGrConPg:Cargo != NIL          // o Slot Contem Algo,
					Eval( oGrConPg:cargo )         // Execute !
				Endif
			End
		Endif
		If nKey == pESC
			lRet := pFALSE
			Exit
		Endif
		GrConPg->( StdKey( oGrConPg, nKey ) )     // Controle de Teclagem
		Do Case
		  Case nKey == pF9         //Procura Nome
				  GrConPg->( GrcSeekNome(aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
				  Exit
		  Case nKey == pF10        //Procura Codigo
				  GrConPg->( GrcSeekCodigo( aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
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

Static Function GrcSeekNome(nLin,nCol,nColf)
		Local cGrcDescr := GrConPg->(MakeEmpty("GrcDescr"))
		Local GetList:={}
		GrConPg->(DbSetOrder(2))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "DESCRICAO A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get cGrcDescr Pict [@! ] Color WhatColor()
		read
		GrConPg->(DbSeek(cGrcDescr,.t.))
		wClose()
		VOID

Static Function GrcSeekCodigo(nLin,nCol,nColf)
		Local nGrcCodGru := GrConPg->(MakeEmpty("GrcCodGru"))
		Local GetList:={}
		GrConPg->(DbSetOrder(1))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "CODIGO A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get nGrcCodGru Color WhatColor()
		read
		wClose()
		If !(GrConPg->(DbSeek(nGrcCodGru,.t.)))
			Msg("Nao encontrado")
		Endif
		VOID

