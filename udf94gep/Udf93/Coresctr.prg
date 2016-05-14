#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

FUNCTION CORES
	Local nKey := 0,nCount,nLin,nCol,Y,aKey := {},aKeyBlock := {}
	Local lRet := .f.,nCur := SetCursor(1),lUser := .f.

	// Desliga todos os set keys
	aKey := SetKeyTable() // Nao Pode Atribuir uma matriz p/ outra
	aEval(aKey,{ |aArray| Aadd(aKeyBlock,aArray[2]) })
	For nCount := 1 to Len(aKey)
		aKey[nCount][2] := NIL
	Next
	SetKeyTable(,,,.t.,aKey)

	nLin  := 03 ; nCount := 0 ; nCol := 02
	wOpen(wSet(02,01,19,42,sCorJ,pSBAR,0,5," CORES ",3,,,pSBAR))

	If ! File("Cores.Scr")
		For Y := 0 to 127
			@ nLin,nCol Say " "+Str(Y,3)+" " Color Attributecolor(Y)
			nCount++ ; nCol += 5
			If nCount = 8
			  nLin++ ; nCount := 00 ; nCol   := 02
			Endif
		Next
		fSaveScreen(03,02,18,41,"Cores.Scr")
	Else
		fRestScreen(03,02,18,41,"Cores.Scr")
	Endif

	While nKey # 27
		// Janela
		wOpen(wSet(02,45,14,78,sCorJ,pSBAR,0,5," CODIGOS ",3,,,pSBAR))

		// Fundo da Janela
		SetColor(sCorF)
		Scroll(03,47,13,77,0)

		@ wRow()+00,wCol()+01 Say "Fundo da Tela          :" ;
		  Get nCorF Pict '999' Valid(nCorF >= 0 .and. nCorF <= 127)
		@ wRow()+01,wCol()+01 Say "Janela ou Borda        :" ;
		  Get nCorJ Pict '999' Valid(nCorJ >= 0 .and. nCorJ <= 127)

		@ wRow()+02,wCol()+01 Say "Janela Dois            :" ;
		  Get nCorJ2 Pict '999' Valid(nCorJ2 >= 0 .and. nCorJ2 <= 127)
		@ wRow()+03,wCol()+01 Say "Janela Tres            :" ;
		  Get nCorJ3 Pict '999' Valid(nCorJ3 >= 0 .and. nCorJ3 <= 127)
		@ wRow()+04,wCol()+01 Say "Janela Quatro          :" ;
		  Get nCorJ4 Pict '999' Valid(nCorJ4 >= 0 .and. nCorJ4 <= 127)
		@ wRow()+05,wCol()+01 Say "Janela Cinco           :" ;
		  Get nCorJ5 Pict '999' Valid(nCorJ5 >= 0 .and. nCorJ5 <= 127)

		@ wRow()+06,wCol()+01 Say "Titulo do Menu         :" ;
		  Get nCorT Pict '999' Valid(nCorT >= 0 .and. nCorT <= 127)
		@ wRow()+07,wCol()+01 Say "Letra p/ Escolha Menu  :" ;
		  Get nCorL Pict '999' Valid(nCorL >= 0 .and. nCorL <= 127)
		@ wRow()+08,wCol()+01 Say "Mensagem do Usuario    :" ;
		  Get nCorM Pict '999' Valid(nCorM >= 0 .and. nCorM <= 127)
		@ wRow()+09,wCol()+01 Say "Cursor Selecionado     :" ;
		  Get nCorC Pict '999' Valid(nCorC >= 0 .and. nCorC <= 127)
		@ wRow()+10,wCol()+01 Say "Cursor Nao Selecionado :" ;
		  Get nCorNC Pict '999' Valid(nCorNC >= 0 .and. nCorNC <= 127)
		Read
		If (nKey := LastKey()) # pESC
			If (lRet := Confirma("Confirme a Alteracao",12))
				wCor() // Grava Cores
				SysColor(@sCorF,@sCorJ,@sCorJ2,@sCorJ3,@sCorJ4,@sCorJ5,@sCorT,@sCorL,@sCorM,.f.)
				wClose()
				Exit
			Endif
		Endif
		WClose()
	End
	WClose()
	If (lColor := lRet)
		KeyBoard(Chr(27)+Chr(27)+Chr(27))
	Endif
	SetCursor(nCur)
	// Liga todos os set keys
	For nCount := 1 to Len(aKey)
		aKey[nCount][2] := aKeyBlock[nCount] // Atribui code block
	Next
	SetKeyTable(,,,.t.,aKey)
	RETURN(lRet)

// ***
// ***

FUNCTION WCOR()
	Local sUserName := " "

	// Abrir Arquivo de Cores do Sistema Suprimentos
	Sele 0
    BankUse(pSISTEMA+"Cores",.f.,10)

	If Confirma({"Grava Configuracao","de Uso Exclusivo"},12)
		// Procura Configuracao do Usuario
		sUserName := SubStr(Cn_Who()+Space(15),1,15)
		If Cores->(DbSeek(sUsername))
			Cores->(Rec_Lock(0))
		Else
			Cores->(Add_Rec(0))
			Cores->UserName := Cn_Who()+Space(15)
		Endif
		Cores->Fundo  := nCorF ; Cores->Janela := nCorJ
		Cores->Titulo := nCorT ; Cores->Letra  := nCorL
		Cores->Msg    := nCorM ; Cores->Cursor := nCorC
		Cores->GetNot := nCorNC
		Cores->Janela2:= nCorJ2
		Cores->Janela3:= nCorJ3
		Cores->Janela4:= nCorJ4
		Cores->Janela5:= nCorJ5
	Endif
	Cores->(DbCloseArea())
	VOID


