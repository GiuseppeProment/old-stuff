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
//  BROWSE MEDIDA DE MADEIRA

/*
	 Parametros     : ListaGet,LinhaJanela , ColunaJanela
							Exibir, LinhaExibicao, ColunaExibicao, ComprimentoExibicao,
	 Objetivo       : Escolha e exibicao de Medida de mad. associado a variavel no get
	 Excessao       :
	 Pre-requisitos : Arquivos MedMade aberto, chamado somente por valid no get
*/

FUNCTION SearchMedMade(aGetList,nLinJan,nColJan,lExibir,nLinExib,nColExib,nLenExib)
	Local oGet := GetActive()
	Local sCorAnt := SetColor()
	Local nOrder1 := MedMade->(IndexOrd())
	Local lRet
	
    MedMade->(DbSetOrder(1))

	If Empty(oGet:VarGet()) .or. !MedMade->(DbSeek(oGet:VarGet()))
       MedMade->(DbSetOrder(2))
        wClose( wOpen( WSet( nLinJan, nColJan, nLinJan+14, nColJan+36, WhatColor(1), pSBAR, 3, 0,;
		 "PESQUISA MEDIDAS MADEIRA"   , pLEFT_JUSTIFIED, { |aWindow| SetColor(WhatColor()),MedMade->( MedMadeBrowse( aWindow ) ;
		 ) },, pSBAR ) ) )
		SetColor(sCorAnt)
		If LastKey() != pESC
			oGet:VarPut(MedMade->MmCodigo)
			oGet:Display()
			lRet:=pTRUE
		else
			lRet:=pFALSE
		endif
	else
		lRet:=pTRUE
	Endif
	MedMade->(DbSetOrder(nOrder1))
	If lRet==pTRUE .and. lExibir
		If nLenExib!=Nil
			@ nLinExib,nColExib say Substr(MontaMedMade(),1,nLenExib) color;
			CorGetUnSel()
		else
			@ nLinExib,nColExib say MontaMedMade() color CorGetUnSel()
		endif
	Endif
	Return lRet

STATIC FUNCTION MedMadeBrowse( aWindow )
	Local oMedMade, oCol
	Local nKey     := 0,;
			lRet     := pTRUE,;
			sCorAnt  := SetColor()

	If EOF() .or. BOF()
		DbGoTop()
	Endif


	// Cria Objeto TBrowseDB(nLinTop,nColTop,nLinBottom,nColBottom)
	oMedMade := TBrowseDB(aWindow[1,1],aWindow[1,2],;
							  aWindow[1,3]-01,aWindow[1,4])
	@ aWindow[1,1]+01,aWindow[1,2]-01 Say Chr(198)
	@ aWindow[1,1]+01,aWindow[1,4]+01 Say Chr(181)

	oMedMade:headSep := Chr(205) + Chr(203) + Chr(205)
	oMedMade:colSep  := " " + Chr(186) + " "
	oMedMade:footSep := Chr(196) + Chr(208) + Chr(196)

	// Criar objetos coluna
	oMedMade:AddColumn( TBcolumnNew( "CODIGO", {|| MedMade->MmCodigo } ) )
	oCol := TBcolumnNew( "DESCRICAO", {|| MontaMedMade() } )
	oCol:Width := 21
	oMedMade:AddColumn(oCol)

	Centra(aWindow[1,3],aWindow[1,2],aWindow[1,4],"F10 CODIGO")

	While pTRUE

		If IsStable(oMedMade)
			If oMedMade:hitTop .or. oMedMade:hitBottom
				Tone(3600,.2) ; Tone(3700,.2)
			Endif
			While ( nKey := Inkey() ) == 0       // Nao Espera Tecla
				If oMedMade:Cargo != NIL          // o Slot Contem Algo,
					Eval( oMedMade:cargo )         // Execute !
				Endif
			End
		Endif
		If nKey == pESC
			lRet := pFALSE
			Exit
		Endif
		MedMade->( StdKey( oMedMade, nKey ) )     // Controle de Teclagem
		Do Case
		  Case nKey == pF10        //Procura Codigo
			  If MedMade->( MadSeekCodigo( aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
				  Exit
			  Endif
			  oMedMade:RefreshAll()
			  oMedMade:ForceStable()
		  Case nKey == pALT_F10
			  wMove()
			  Exit
		  Case nKey == pENTER
				  lRet:=pFALSE
				  exit
		EndCase
	Enddo  
	RETURN( lRet )

Static Function MadSeekCodigo(nLin,nCol,nColf)
		Local nMmCodigo := MedMade->(MakeEmpty("MmCodigo"))
		Local GetList:={}
		MedMade->(DbSetOrder(1))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "CODIGO A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get nMmCodigo Color WhatColor()
		read
		wClose()
		If !(MedMade->(DbSeek(nMmCodigo,.t.)))
			Msg("Nao encontrado")
		Endif
        MedMade->(DbSetOrder(2))
		Return MedMade->(Found())


