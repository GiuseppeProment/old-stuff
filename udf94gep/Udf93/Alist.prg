#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

/*
  aArray  // Matriz p/ TBROWSE Unidimensional obrigatorio
  aWin    // Coordenadas da janela
  sCab    // Cabecalho
  lTag    // Marca item retorna um matriz com os itens selecionado
  lScript // Retorna o conteudo
*/
FUNCTION ALIST(aArray,aWin,sCab,lTag,lScript)
	Local sCorAnt := SetColor(),oArray,oColuna,aTag := {},xRet,nCount := 1
	Private aTab    := TabNew(aWin[1],aWin[4],aWin[3],sCorJ,1)
	Private nWinTot := Len(aArray),nWinPos := 1

	nRowArr := 1 // Inicializa Var Static

	If lTag = NIL
		lTag := .f.
	Endif
	If lScript = NIL
		lScript := .f.
	Endif

	If Len(aArray) = 0
		If lScript .and. ! lTag
			RETURN("")
		Else
			RETURN(Array(0))
		Endif
	Endif

	wOpen(wSet(aWin[1],aWin[2],aWin[3],aWin[4],sCorJ,pSBAR,0,5,;
		  ,,,,pSBAR))
	aWindow := wGet()
	oArray  := TBrowseNew(aWindow[1,1],aWindow[1,2],aWindow[1,3]-01,aWindow[1,4])
	TabDisplay(aTab)
	TabModal(aTab,nRowArr,nWinTot,.t.)
	If lTag
		@ aWindow[1,3],aWindow[1,2]+01 Say Equaliza('ENTER MARCA / F10 FIM',wDepth())
	Else
		@ aWindow[1,3],aWindow[1,2]+01 Say Equaliza('ENTER SELECIONA / F10 FIM',wDepth())
	Endif

	oArray:headSep   := Chr(205) + Chr(203) + Chr(205)
	oArray:colSep    := " " + Chr(186) + " "
	oArray:footSep   := Chr(196) + Chr(208) + Chr(196)
	oArray:ColorSpec := sCorJ

	If lTag
		aTag    := Array(Len(aArray)) ; Afill(aTag,"  ")
		oColuna := TBColumnNew("OK",{|| aTag[nRowArr] })
		oArray:addColumn(oColuna)
	Endif

	oColuna := TBColumnNew(sCab,{|| aArray[nRowArr] })
	oArray:addColumn(oColuna)

	oArray:goTopBlock    := { || nRowArr := 1 }
	oArray:goBottomBlock := { || nRowArr := Len(aArray) }
	oArray:skipBlock     := { |nToJump| SkipperArr( nToJump,aArray ) }

	// Borda Mouse
*  #IFNDEF NAOMOUSE
*     BordaMouse(aWindow)
*     oArray:Cargo := { || WinBrowse(aWindow) }
*  #ELSE
*     oArray:Cargo := { || DevPos(24,69),DevOut(Time(),ColorSet(24,69))}
*  #ENDIF

	While .t.
		 While (!oArray:Stabilize())
			 nKey := Inkey()
			 If nKey <> 0    // Tecla pressionada durante estabilizacao
				 Exit         // Abandone estabilizacao p/ processar tecla
			 Endif
		 End

		 If oArray:stable
			While (nKey := Inkey()) == 0   // nao espera tecla
				If oArray:Cargo != NIL   // o slot contem algo,
					eVal(oArray:Cargo)    // execute !
				Endif
			End
			If oArray:hitTop
				oArray:goBottom() ; oArray:RefreshAll()
			Endif
			If oArray:hitBottom
				oArray:goTop()    ; oArray:RefreshAll()
			Endif
		Endif

		StdKey(oArray,nKey)

		If nKey = pENTER
			If lTag // e para marcar
				If (aTag[nRowArr] == Chr(16)+" ")
					aTag[nRowArr] := "  "
				Else
					aTag[nRowArr] := Chr(16)+" "
				Endif
				oArray:RefreshCurrent()
			Else
				Exit
			Endif
		Endif
		If nKey = pF10 .or. nKey = pESC
			Exit
		Endif
	End
	If nKey # pESC
		If lTag
			xRet := {}
			For nCount := 1 to Len(aTag)
				If (!Empty(aTag[nCount]))
					Aadd(xRet,aArray[nCount])
				Endif
			Next
		Else
			xRet := aArray[nRowArr]
		Endif
	Endif
	WClose()
	SetColor(sCorAnt)
	RETURN(xRet)

// ***
// ***

