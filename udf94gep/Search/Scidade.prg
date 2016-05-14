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

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//  BROWSE CIDADES

/*
	 Parametros     : ListaGet,LinhaJanela , ColunaJanela
							Exibir, LinhaExibicao, ColunaExibicao, ComprimentoExibicao,
     Objetivo       : Escolha e exibicao de CIDADES associado a variavel no get
	 Excessao       :
     Pre-requisitos : Arquivos Cidade aberto, chamado somente por valid no get
*/

FUNCTION SearchCidade(aGetList,nLinJan,nColJan,lExibir,nLinExib,nColExib,nLenExib)
	Local oGet := GetActive()
	Local sCorAnt := SetColor()
    Local nOrder1 := Cidade->(IndexOrd())
	Local lRet
	
    Cidade->(DbSetOrder(2))

    If Empty(oGet:VarGet()) .or. !Cidade->(DbSeek(oGet:VarGet()))
		wClose( wOpen( WSet( nLinJan, nColJan, nLinJan+14, nColJan+36, WhatColor(1), pSBAR, 3, 0,;
         "PESQUISA CIDADES"   , pLEFT_JUSTIFIED, { |aWindow| SetColor(WhatColor()),Cidade->( CidadeBrowse( aWindow ) ;
		 ) },, pSBAR ) ) )
		SetColor(sCorAnt)
		If LastKey() != pESC
            oGet:VarPut(Cidade->CidCodigo)
			oGet:Display()
			lRet:=pTRUE
		else
			lRet:=pFALSE
		endif
	else
		lRet:=pTRUE
	Endif
    Cidade->(DbSetOrder(nOrder1))
	If lRet==pTRUE .and. lExibir
		If nLenExib!=Nil
            @ nLinExib,nColExib say Substr(Cidade->CidDescr,1,nLenExib) color;
			CorGetUnSel()
		else
            @ nLinExib,nColExib say Cidade->CidDescr color CorGetUnSel()
		endif
	Endif
	Return lRet

STATIC FUNCTION CidadeBrowse( aWindow )
    Local oCidade, oCol
	Local nKey     := 0,;
			lRet     := pTRUE,;
			sCorAnt  := SetColor()

	If EOF() .or. BOF()
		DbGoTop()
	Endif

	// Cria Objeto TBrowseDB(nLinTop,nColTop,nLinBottom,nColBottom)
    oCidade := TBrowseDB(aWindow[1,1],aWindow[1,2],;
							  aWindow[1,3]-01,aWindow[1,4])
	@ aWindow[1,1]+01,aWindow[1,2]-01 Say Chr(198)
	@ aWindow[1,1]+01,aWindow[1,4]+01 Say Chr(181)
    oCidade:headSep := Chr(205) + Chr(203) + Chr(205)
    oCidade:colSep  := " " + Chr(186) + " "
    oCidade:footSep := Chr(196) + Chr(208) + Chr(196)

    // Criar objetos coluna

    oCidade:AddColumn( TBcolumnNew( "DESCRICAO", {|| Cidade->CidDescr } ) )
    oCidade:AddColumn( TBcolumnNew( "CODIGO", {|| Cidade->CidCodigo } ) )

	Centra(aWindow[1,3],aWindow[1,2],aWindow[1,4],"F9 DESCRICAO   F10 CODIGO")

	While pTRUE

        If IsStable(oCidade)
            If oCidade:hitTop .or. oCidade:hitBottom
				Tone(3600,.2) ; Tone(3700,.2)
			Endif
			While ( nKey := Inkey() ) == 0       // Nao Espera Tecla
                If oCidade:Cargo != NIL          // o Slot Contem Algo,
                    Eval( oCidade:cargo )         // Execute !
				Endif
			End
		Endif
		If nKey == pESC
			lRet := pFALSE
			Exit
		Endif
        Cidade->( StdKey( oCidade, nKey ) )     // Controle de Teclagem
		Do Case
		  Case nKey == pF9         //Procura Nome
                  Cidade->( CidSeekNome(aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
				  Exit
		  Case nKey == pF10        //Procura Codigo
                  Cidade->( CidSeekCodigo( aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
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

Static Function CidSeekNome(nLin,nCol,nColf)
        Local cCidDescr := Cidade->(MakeEmpty("CidDescr"))
		Local GetList:={}
        Cidade->(DbSetOrder(2))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "DESCRICAO A PESQUISAR",3)
		wOpen()
        @ wRow(), wCol()+1 Get cCidDescr Pict [@! ] Color WhatColor()
		read
        Cidade->(DbSeek(cCidDescr,.t.))
		wClose()
		VOID

Static Function CidSeekCodigo(nLin,nCol,nColf)
        Local nCidCodigo := Cidade->(MakeEmpty("CidCodigo"))
		Local GetList:={}
        Cidade->(DbSetOrder(1))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "CODIGO A PESQUISAR",3)
		wOpen()
        @ wRow(), wCol()+1 Get nCidCodigo Color WhatColor()
		read
		wClose()
        If !(Cidade->(DbSeek(nCidCodigo,.t.)))
			Msg("Nao encontrado")
		Endif
		VOID





