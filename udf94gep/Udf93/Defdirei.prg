#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

// ***
// ***


// ***
// ***
FUNCTION DEFINEDIREITOS(aRefe,aItem)
	// Escolha de Usuarios a receber os direitos
    Local aAux := {},aUsuarios := {},nCount := 0,sProcName,nFinal
    Local aKey := {},aKeyBlock := {}, nIx

    Local aMenu     := aClone(aRefe)
    Private aMenuItem := aClone(aItem)

    Private nChoice := 0

	// Desliga Todos os Set Keys
	aKey := SetKeyTable() // Nao Pode Atribuir uma matriz p/ outra
	aEval(aKey,{ |aArray| Aadd(aKeyBlock,aArray[2]) })
	For nCount := 1 to Len(aKey)
		aKey[nCount][2] := NIL
	Next
	SetKeyTable(,,,.t.,aKey)

    aUsuarios := Cn_ObjLst()
    aSort(aUsuarios)

	Tela_Padrao()
	@ 00,04 Say PadC(" "+Chr(175)+" Definicao de Direitos "+Chr(174)+" ",73,"Í") Color sCorJ

	aAux := aList(aUsuarios,{03,11,21,35},"USUARIOS",.t.) // Escolhe Usuarios

    // completa com espacos por causa de busca por indices
    For nIx := 1 to len(aAux)
        aAux[nIx]:=PadR(aAux[nIx],15)
    Next nIx

	If Lastkey() <> pESC


		// Marcar as opcoes as quais o(s) usuario(s) terao aceso
		// Modificando as matrizes para fazer o nosso processo

        for nIx :=1 to len(aMenuItem)

          aEval(aMenuItem[nIx],{ |x| x[12] := ;
			{|aMatriz,nIndice,nLast| QuaisDireitos(aMatriz,nIndice,nLast)},;
			x[03] := Stuff(x[03],21,5,' '+If(Len(aAux) == 1,LeDireitos(aAux[1],x[13]),'....'))})

            aMenu[nIx][12]:= &("{|| Entry( aMenuItem["+Str(nIx,2)+"] ) ,.t. }")

        Next nIx

        MenuModal(aMenu,@nChoice)
		// Gravar os novos direitos, sobrepondo possiveis direitos ja' existentes
		If Confirma('Voce Confirma a Gravacao ?')
            aEval(aAux,{|cUser| Rights->(GravaDireitos(cUser,aMenuItem))})
		Endif
	Endif
	PopFrame()   // Tela Padrao abre uma frame FECHA
	For nCount := 0 to 10
		If "ENTRY" $ ProcName(nCount)
			KeyBoard(Chr(pESC)+Chr(pENTER))
			Exit
		Endif
	Next
	// Liga todos os set keys
	For nCount := 1 to Len(aKey)
		aKey[nCount][2] := aKeyBlock[nCount] // Atribui code block
	Next
	SetKeyTable(,,,.t.,aKey)
	VOID

// ***

FUNCTION SubDefineDireitos(aRefe01)
	// Escolha de Usuarios a receber os direitos
    Local aAux := {},aUsuarios := {},nCount := 0,sProcName,nIx
    Local aKey := {},aKeyBlock := {}
	Local aMenu01 := aClone(aRefe01)
	Private nChoice := 0

	// Desliga Todos os Set Keys
	aKey := SetKeyTable() // Nao Pode Atribuir uma matriz p/ outra
	aEval(aKey,{ |aArray| Aadd(aKeyBlock,aArray[2]) })
	For nCount := 1 to Len(aKey)
		aKey[nCount][2] := NIL
	Next
	SetKeyTable(,,,.t.,aKey)

    aUsuarios := Cn_ObjLst()
	aSort(aUsuarios)

    // completa com espacos por causa de busca por indices
    For nIx := 1 to len(aAux)
        aAux[nIx]:=PadR(aAux[nIx],15)
    Next nIx

	Save Screen

	@ 00,04 Say PadC(" "+Chr(175)+" Definicao de Direitos "+Chr(174)+" ",73,"Í") Color sCorJ

	aAux := aList(aUsuarios,{03,11,21,35},"USUARIOS",.t.) // Escolhe Usuarios

	If Lastkey() <> pESC


		// Marcar as opcoes as quais o(s) usuario(s) terao aceso
		// Modificando as matrizes para fazer o nosso processo

        aEval(aMenu01,{ |x| x[12] := ;
			{|aMatriz,nIndice,nLast| QuaisDireitos(aMatriz,nIndice,nLast)},;
			x[03] := Stuff(x[03],-5,5,' '+If(Len(aAux) == 1,LeDireitos(aAux[1],x[13]),'....'))})

		While LastKey()!=pESC
			MenuModal(aMenu01,@nChoice)
		End
		// Gravar os novos direitos, sobrepondo possiveis direitos ja' existentes
		If Confirma('Voce Confirma a Gravacao ?')
            aEval(aAux,{|cUser| Rights->(GravaDireitos( cUser, {aMenu01} ))})
		Endif
	Endif
	Restore Screen
	// Liga todos os set keys
	For nCount := 1 to Len(aKey)
		aKey[nCount][2] := aKeyBlock[nCount] // Atribui code block
	Next
	SetKeyTable(,,,.t.,aKey)
	VOID

// ***
// ***

STATIC FUNCTION QUAISDIREITOS(aMatriz,nEscolhido,nLast)
	Local aDireitos := AList(aSort({'Pode Alterar ?  ','Pode Consultar ?','Pode Excluir ?','Pode Incluir ?'}),;
									 {12,24,21,50},"DIREITOS",.t.)
	Local cDireitos
	cDireitos := If(aScan(aDireitos,{ |X| 'Alterar'   $ X }) # 0,'A','.')
	cDireitos += If(aScan(aDireitos,{ |X| 'Consultar' $ X }) # 0,'C','.')
	cDireitos += If(aScan(aDireitos,{ |X| 'Excluir'   $ X }) # 0,'E','.')
	cDireitos += If(aScan(aDireitos,{ |X| 'Incluir'   $ X }) # 0,'I','.')
	// O C(onsultar) e' implicito caso haja algum outro direito
	If ! 'C' $ cDireitos .and. 'A' $ cDireitos .or.;
										'E' $ cDireitos .or. 'I' $ cDireitos
		cDireitos := Stuff(cDireitos,2,1,"C")
	Endif
*  aMatriz[nEscolhido][03] := Stuff(aMatriz[nEscolhido][03],22,4,cDireitos)
	aMatriz[nEscolhido][03] := Stuff(aMatriz[nEscolhido][03],len(aMatriz[nEscolhido][03])-3,4,cDireitos)
	VOID

// ***
// ***

STATIC FUNCTION GRAVADIREITOS(cUser,aMenuItem)
    Local nIx

    For nIx := 1 to len(aMenuItem)

        aEval( aMenuItem[nIx], { |aDireitos| GravaItem(cUser,Right(aDireitos[03],4),aDireitos[13]) } )

    Next nIx

    VOID

// ***
// ***

STATIC FUNCTION GRAVAITEM(cNome,cRights,cProgram)
	cNome := StrTran(cNome,Chr(000)," ")
	If ! Empty(cProgram)
		If cRights # '....'
			If(DbSeek(cNome+cProgram),Rec_lock(0),Add_rec(0))
			Rights->Us_Nome   := cNome+Space(15)
			Rights->Us_Program:= cProgram
			Rights->Us_Rights := cRights
			DbUnlock()
		Else
			If DbSeek(cNome+cProgram)
				Rec_lock(0) ; DbDelete() ; DbUnlock()
			Endif
		Endif
	Endif
	VOID

// ***
// ***

STATIC FUNCTION LEDIREITOS(cNome,cProgram)
	Local sRet := '....'
	cNome := StrTran(cNome,Chr(000)," ")
	If ! Empty(cProgram) .and. Rights->(DbSeek(cNome+cProgram))
		sRet := Rights->Us_Rights
	Endif
	RETURN(sRet)

// ***
// ***

