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
//  BROWSE ESTADOS

/*
	 Parametros     : ListaGet,LinhaJanela , ColunaJanela
							Exibir, LinhaExibicao, ColunaExibicao, ComprimentoExibicao,
     Objetivo       : Escolha e exibicao de ESTADOS associado a variavel no get
	 Excessao       :
     Pre-requisitos : Arquivos ESTADO aberto, chamado somente por valid no get
*/

FUNCTION SearchUf(aGetList,nLinJan,nColJan,lExibir,nLinExib,nColExib,nLenExib)
	Local oGet := GetActive()
	Local sCorAnt := SetColor()
    Local nOrder1 := Estado->(IndexOrd())
	Local lRet
	
    Estado->(DbSetOrder(1))

    If Empty(oGet:VarGet()) .or. !Estado->(DbSeek(oGet:VarGet()))
		wClose( wOpen( WSet( nLinJan, nColJan, nLinJan+14, nColJan+36, WhatColor(1), pSBAR, 3, 0,;
         "PESQUISA ESTADOS"   , pLEFT_JUSTIFIED, { |aWindow| SetColor(WhatColor()),Estado->( EstadoBrowse( aWindow ) ;
		 ) },, pSBAR ) ) )
		SetColor(sCorAnt)
		If LastKey() != pESC
            oGet:VarPut(Estado->EstCodSigl)
			oGet:Display()
			lRet:=pTRUE
		else
			lRet:=pFALSE
		endif
	else
		lRet:=pTRUE
	Endif
    Estado->(DbSetOrder(nOrder1))
	If lRet==pTRUE .and. lExibir
		If nLenExib!=Nil
            @ nLinExib,nColExib say Substr(Estado->EstDescr,1,nLenExib) color;
			CorGetUnSel()
		else
            @ nLinExib,nColExib say Estado->EstDescr color CorGetUnSel()
		endif
	Endif
	Return lRet

STATIC FUNCTION EstadoBrowse( aWindow )
    Local oEstado, oCol
	Local nKey     := 0,;
			lRet     := pTRUE,;
			sCorAnt  := SetColor()

	If EOF() .or. BOF()
		DbGoTop()
	Endif

	// Cria Objeto TBrowseDB(nLinTop,nColTop,nLinBottom,nColBottom)
    oEstado := TBrowseDB(aWindow[1,1],aWindow[1,2],;
							  aWindow[1,3]-01,aWindow[1,4])
	@ aWindow[1,1]+01,aWindow[1,2]-01 Say Chr(198)
	@ aWindow[1,1]+01,aWindow[1,4]+01 Say Chr(181)
    oEstado:headSep := Chr(205) + Chr(203) + Chr(205)
    oEstado:colSep  := " " + Chr(186) + " "
    oEstado:footSep := Chr(196) + Chr(208) + Chr(196)

    // Criar objetos coluna

    oEstado:AddColumn( TBcolumnNew( "UF", {|| Estado->EstCodSigl } ) )
    oEstado:AddColumn( TBcolumnNew( "DESCRICAO", {|| Estado->EstDescr } ) )

    Centra(aWindow[1,3],aWindow[1,2],aWindow[1,4],"F9 PESQUISA")

	While pTRUE

        If IsStable(oEstado)
            If oEstado:hitTop .or. oEstado:hitBottom
				Tone(3600,.2) ; Tone(3700,.2)
			Endif
			While ( nKey := Inkey() ) == 0       // Nao Espera Tecla
                If oEstado:Cargo != NIL          // o Slot Contem Algo,
                    Eval( oEstado:cargo )         // Execute !
				Endif
			End
		Endif
		If nKey == pESC
			lRet := pFALSE
			Exit
		Endif
        Estado->( StdKey( oEstado, nKey ) )     // Controle de Teclagem
		Do Case
		  Case nKey == pF9         //Procura Nome
                  Estado->( UfSeekNome(aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
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

Static Function UfSeekNome(nLin,nCol,nColf)
        Local cEstDescr := Estado->(MakeEmpty("EstCodSigl"))
		Local GetList:={}
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
         "ESTADO A PESQUISAR",3)
		wOpen()
        @ wRow(), wCol()+1 Get cEstDescr Pict [@! ] Color WhatColor()
		read
        Estado->(DbSeek(cEstDescr,.t.))
		wClose()
		VOID

