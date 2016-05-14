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


FUNCTION SearchFunc(aGetList,nLinJan,nColJan,lExibir,nLinExib,nColExib,nLenExib)
	Local oGet := GetActive()
	Local sCorAnt := SetColor()
	Local lRet
	
	If Empty(oGet:VarGet()) .or. !(Funcion->(DbSeek(oGet:VarGet())))
		wClose( wOpen( WSet( nLinJan, nColJan, nLinJan+14, nColJan+60, WhatColor(1), pSBAR, 3, 5,;
		 "PESQUISA FUNCIONARIOS", pLEFT_JUSTIFIED,{|aWindow| SetColor(WhatColor()),Funcion->( FuncBrowse( aWindow ) ;
		 ) },, pSBAR ) ) )
		 SetColor(sCorAnt)
		If LastKey() != pESC
			oGet:VarPut(Funcion->FuCodigo)
			oGet:Display()
			lRet:=pTRUE
		else
			lRet:=pFALSE
		endif
	else
		lRet := pTRUE
	Endif
	If lRet==pTRUE .and. lExibir
		If nLenExib!=Nil
			@ nLinExib,nColExib say Substr(Funcion->FuNome,1,nLenExib) Color CorGetUnSel()
		else
			@ nLinExib,nColExib say Funcion->FuNome Color CorGetUnSel()
		endif
	Endif
	Return lRet

STATIC FUNCTION FuncBrowse( aWindow )
	Local oFuncion, oCol
	Local nKey     := 0,;
			lRet     := pTRUE,;
			sCorAnt  := SetColor()

	If EOF() .or. BOF()
		DbGoTop()
	Endif


	// Cria Objeto TBrowseDB(nLinTop,nColTop,nLinBottom,nColBottom)
	oFuncion := TBrowseDB(aWindow[1,1],aWindow[1,2],;
							  aWindow[1,3]-01,aWindow[1,4])
	@ aWindow[1,1]+01,aWindow[1,2]-01 Say Chr(198)
	@ aWindow[1,1]+01,aWindow[1,4]+01 Say Chr(181)
	oFuncion:headSep := Chr(205) + Chr(203) + Chr(205)
	oFuncion:colSep  := " " + Chr(186) + " "
	oFuncion:footSep := Chr(196) + Chr(208) + Chr(196)

	// Criar objetos coluna
	oCol:= TBcolumnNew( "Codigo",{ || Str(Funcion->FuCodigo,3) } )
	oFuncion:AddColumn(oCol)

	oCol:= TBcolumnNew( "Nome",{ || Funcion->FuNome } )
	oFuncion:AddColumn(oCol)

	oCol:= TBcolumnNew( "Cargo",{ || Funcion->FuFuncao } )
	oFuncion:AddColumn(oCol)

	// Define Filtros

	Centra(aWindow[1,3],aWindow[1,2],aWindow[1,4],"F9 DESCRICAO  F10 CODIGO")

	While pTRUE

		If IsStable(oFuncion)
			If oFuncion:hitTop .or. oFuncion:hitBottom
				Tone(3600,.2) ; Tone(3700,.2)
			Endif
			While ( nKey := Inkey() ) == 0       // Nao Espera Tecla
				If oFuncion:Cargo != NIL          // o Slot Contem Algo,
					Eval( oFuncion:cargo )         // Execute !
				Endif
			End
		Endif
		If nKey == pESC
			lRet := pFALSE
			Exit
		Endif
		Funcion->( StdKey( oFuncion, nKey ) )     // Controle de Teclagem
		Do Case
		  Case nKey == pF9         //Procura Nome
				  Funcion->( FuncSeekNome(aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
				  Exit
		  Case nKey == pF10        //Procura Codigo
				  Funcion->( FuncSeekCodigo( aWindow[1,3]-1,aWindow[1,2],aWindow[1,4] ) )
				  Exit
		  Case nKey == pALT_F10
			  wMove()
			  Exit
		  Case nKey == pENTER
			  If !Empty( Eval(oFuncion:GetColumn(2):Block) )
				  lRet:=pFALSE
				  exit
			  endif
		EndCase
	Enddo  
	RETURN( lRet )

Static Function FuncSeekNome(nLin,nCol,nColf)
		Local cFuNome := Funcion->(MakeEmpty("FuNome"))
		Local GetList:={}
		Funcion->(DbSetOrder(2))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "NOME A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get cFuNome Pict [@! ] Color WhatColor()
		read
		Funcion->(DbSeek(cFuNome,.t.))
		If Funcion->(Eof())
			Funcion->(DbSkip(-1))
		Endif
		wClose()
		VOID

Static Function FuncSeekCodigo(nLin,nCol,nColf)
		Local nFuCodigo := Funcion->(MakeEmpty("FuCodigo"))
		Local GetList:={}
		Local nOrder1 := Funcion->(IndexOrd())
		Funcion->(DbSetOrder(1))
		wSet( nLin,nCol,nLin+2,nColf, WhatColor(1), pSBAR, 3, 5,;
		 "CODIGO A PESQUISAR",3)
		wOpen()
		@ wRow(), wCol()+1 Get nFuCodigo Pict [999] Color WhatColor()
		read
		wClose()
		If !(Funcion->(DbSeek(nFuCodigo)))
			Msg("Nao encontrado")
		Endif
		Funcion->(DbSetOrder(nOrder1))
		VOID

