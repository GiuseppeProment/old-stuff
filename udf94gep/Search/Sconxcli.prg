#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Include "Recoma.ch"
#Include "PTWindow.ch"

//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//  BROWSE CLIENTES POR COMISSIONADO ESPECIFICO

/*
	 Parametros     : ListaGet,LinhaJanela , ColunaJanela
							Exibir, LinhaExibicao, ColunaExibicao, ComprimentoExibicao,
                            nCodigoComissionado,lSomenteAtivos
     Objetivo       : Escolha e exibicao Clientes por Comissionado associado a variavel no get
	 Excessao       :
     Pre-requisitos : Arquivos ClixCom e Cliente aberto, chamado somente por valid no get
*/

FUNCTION SearchComxCli(aGetList,nLinJan,nColJan,lExibir,nLinExib,nColExib,nLenExib,;
            nComiss)
	Local oGet := GetActive()
	Local sCorAnt := SetColor()
	Local nOrder1 := ClixCom->(IndexOrd())
    Local nOrder2 := Cliente->(IndexOrd())
	Local lRet
	
    ClixCom->(DbSetOrder(2))
    Cliente->(DbSetOrder(1))

	If Empty(oGet:VarGet()) .or.;
        !ClixCom->(DbSeek( str(nComiss,3)+str(oGet:VarGet(),6) ) .and. VerifyCxC())
        wClose( wOpen( WSet( nLinJan, nColJan, nLinJan+15, nColJan+60, WhatColor(1), pSBAR, 3, 0,;
         "PESQUISA CLIENTES POR COMISSIONADO"   , pLEFT_JUSTIFIED, { |aWindow| SetColor(WhatColor()),ClixCom->;
         ( ClixComBrowse( aWindow,nComiss ) ;
		 ) },, pSBAR ) ) )
		SetColor(sCorAnt)
		If LastKey() != pESC
            oGet:VarPut(ClixCom->CcCodCli)
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
            @ nLinExib,nColExib say Substr(Cliente->ClDescr,1,nLenExib) color;
			CorGetUnSel()
		else
            @ nLinExib,nColExib say Cliente->ClDescr color CorGetUnSel()
		endif
	Endif

	ClixCom->(DbSetOrder(nOrder1))
    Cliente->(DbSetOrder(nOrder2))

	Return lRet

STATIC FUNCTION VerifyCxC
    If !Cliente->(DbSeek(ClixCom->CcCodCli))
        Msg({"Cliente esta na lista",;
              "de relacoes com comissionado"  ,;
			  "porem nao existe no cadastro"})
	Endif
    Return Cliente->(Found())

STATIC FUNCTION ClixComBrowse( aWindow,nComiss )
	Local oClixCom, oCol
	Local nKey     := 0,;
			lRet     := pTRUE,;
			sCorAnt  := SetColor(),;
            bClixCom := { || ClixCom->CcCodCom==nComiss }

	If EOF() .or. BOF()
		DbGoTop()
	Endif

	// Cria Objeto TBrowseDB(nLinTop,nColTop,nLinBottom,nColBottom)
	oClixCom := TBrowseDB(aWindow[1,1],aWindow[1,2],;
							  aWindow[1,3]-01,aWindow[1,4])
	@ aWindow[1,1]+01,aWindow[1,2]-01 Say Chr(198)
	@ aWindow[1,1]+01,aWindow[1,4]+01 Say Chr(181)
	oClixCom:headSep := Chr(205) + Chr(203) + Chr(205)
	oClixCom:colSep  := " " + Chr(186) + " "
	oClixCom:footSep := Chr(196) + Chr(208) + Chr(196)

    // Criar objetos coluna
    oClixCom:AddColumn( TBcolumnNew( "CD", {|| ClixCom->CcCodCli } ) )

    oClixCom:AddColumn( TBcolumnNew( "NOME", {|| Cliente->;
              (If(DbSeek(ClixCom->CcCodCli),Cliente->ClDescr," ** NAO EXISTE **"));
			  } ) )

    @ aWindow[1,3],aWindow[1,2] Say "AUXILIO A BUSCA INVIAVEL"

	// Define Filtros
    oClixCom:GoBottomBlock := {|| OptGoBottom( bClixCom,str(nComiss,3)+Str(999999,6,0) ) }
    oClixCom:GoTopBlock    := {|| OptGoTop( bClixCom,str(nComiss,3)+Str(0,6,0) ) }
	oClixCom:SkipBlock     := {|nRecords| OptSkiper( nRecords, bClixCom, oClixCom,;
                                        str(nComiss)+Str(0,6,0),str(nComiss)+Str(999999,6,0)  ) }
    OptSkiper(0,,oClixCom,str(nComiss)+Str(0,6,0),str(nComiss)+Str(999999,6,0) )   // Seta Variaveis Static's

	While pTRUE

		If IsStable(oClixCom)
			If oClixCom:hitTop .or. oClixCom:hitBottom
				Tone(3600,.2) ; Tone(3700,.2)
			Endif
			While ( nKey := Inkey() ) == 0       // Nao Espera Tecla
				If oClixCom:Cargo != NIL          // o Slot Contem Algo,
					Eval( oClixCom:cargo )         // Execute !
				Endif
			End
		Endif
		If nKey == pESC
			lRet := pFALSE
			Exit
		Endif
		ClixCom->( StdKey( oClixCom, nKey ) )     // Controle de Teclagem
		Do Case
		  Case nKey == pALT_F10
			  wMove()
			  Exit
		  Case nKey == pENTER
                // forca execucao da coluna de nome (pois da' seek no Cliente)
				Eval(oClixCom:GetColumn(2):Block)
				lRet:=pFALSE
				exit
		EndCase
	Enddo  
	RETURN( lRet )


//

