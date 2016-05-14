#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Include "Recoma.ch"
#Include "PTWindow.ch"

//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//  BROWSE COMISSIONADOS

/*
	 Parametros     : ListaGet,LinhaJanela , ColunaJanela
                            Exibir, LinhaExibicao, ColunaExibicao, ComprimentoExibicao
     Objetivo       : Escolha e exibicao Comissionados associado a variavel no get
	 Excessao       :
     Pre-requisitos : Arquivo Comissi aberto, chamado somente por valid no get
*/

FUNCTION SearchComiss(aGetList,nLinJan,nColJan,lExibir,nLinExib,nColExib,nLenExib)
	Local oGet := GetActive()
	Local sCorAnt := SetColor()
    Local nOrder1 := Comissi->(IndexOrd())
	Local lRet
	
	Comissi->(DbSetOrder(1))

	If Empty(oGet:VarGet()) .or.;
        !Comissi->(DbSeek( oGet:VarGet()) )
        wClose( wOpen( WSet( nLinJan, nColJan, nLinJan+14, nColJan+40, WhatColor(1), pSBAR, 3, 0,;
         "PESQUISA COMISSIONADOS"   , pLEFT_JUSTIFIED, { |aWindow| SetColor(WhatColor()),Comissi->;
         ( ComissiBrowse( aWindow ) ;
		 ) },, pSBAR ) ) )
		SetColor(sCorAnt)
		If LastKey() != pESC
            oGet:VarPut(Comissi->CsCodigo)
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
			@ nLinExib,nColExib say Substr(Comissi->CsNome,1,nLenExib) color;
			CorGetUnSel()
		else
			@ nLinExib,nColExib say Comissi->CsNome color CorGetUnSel()
		endif
	Endif

    Comissi->(DbSetOrder(nOrder1))

	Return lRet

STATIC FUNCTION ComissiBrowse( aWindow )
    Local oComissi, oCol
	Local nKey     := 0,;
			lRet     := pTRUE,;
            sCorAnt  := SetColor()

	If EOF() .or. BOF()
		DbGoTop()
	Endif

	// Cria Objeto TBrowseDB(nLinTop,nColTop,nLinBottom,nColBottom)
    oComissi := TBrowseDB(aWindow[1,1],aWindow[1,2],;
							  aWindow[1,3]-01,aWindow[1,4])
	@ aWindow[1,1]+01,aWindow[1,2]-01 Say Chr(198)
	@ aWindow[1,1]+01,aWindow[1,4]+01 Say Chr(181)
    oComissi:headSep := Chr(205) + Chr(203) + Chr(205)
    oComissi:colSep  := " " + Chr(186) + " "
    oComissi:footSep := Chr(196) + Chr(208) + Chr(196)
	// Criar objetos coluna
    oComissi:AddColumn( TBcolumnNew( "CD", {|| Comissi->CsCodigo } ) )

    oComissi:AddColumn( TBcolumnNew( "NOME", {|| Comissi->CsNome} ) )

    oComissi:AddColumn( TBcolumnNew( "TIPO", {|| Comissi->CsCatego}) )

	While pTRUE

        If IsStable(oComissi)
            If oComissi:hitTop .or. oComissi:hitBottom
				Tone(3600,.2) ; Tone(3700,.2)
			Endif
			While ( nKey := Inkey() ) == 0       // Nao Espera Tecla
                If oComissi:Cargo != NIL          // o Slot Contem Algo,
                    Eval( oComissi:cargo )         // Execute !
				Endif
			End
		Endif
		If nKey == pESC
			lRet := pFALSE
			Exit
		Endif
        Comissi->( StdKey( oComissi, nKey ) )     // Controle de Teclagem
		Do Case
		  Case nKey == pALT_F10
			  wMove()
			  Exit
		  Case nKey == pENTER
				lRet:=pFALSE
				exit
		EndCase
	Enddo  
	RETURN( lRet )


//
