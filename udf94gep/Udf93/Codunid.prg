#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000



FUNCTION CodUnid( nCod, nRow, nCol )

	Local aUnid := {},nOp := 0,aList := Array(05),aRet := {},lRet := .t.
	Local sCorAnt := SetColor()

	SetColor(WhatColor(1))

	aList[1] := { 01, 01, 10, 42 }
	aList[2] := sCorJ
	aList[3] := "UNIDADES"
	aList[4] := pSBAR

	aUnid := {{"Unidade             [ UM      ]","11"},{"Aparelho            [ AP      ]","12"},;
				 {"Conjunto            [ CONJ    ]","13"},{"Jogo                [ JOGO    ]","14"},;
				 {"Par                 [ PAR     ]","15"},{"Duzia               [ DZ      ]","16"},;
				 {"Cento               [ CENTO   ]","17"},{"Grosa               [ GROSA   ]","18"},;
				 {"Milheiro            [ MIL     ]","19"},{"Resma               [ RESMA   ]","20"},;
				 {"Quilate             [ K       ]","21"},{"Grama               [ GR      ]","22"},;
				 {"Quilograma          [ KG      ]","23"},{"Arroba              [ ARROBA  ]","24"},;
				 {"Tonelada            [ T       ]","25"},{"Estojo              [ ESTOJO  ]","26"},;
				 {"Frasco              [ FRASCO  ]","27"},{"Tubo                [ TUBO    ]","28"},;
				 {"Cartela             [ CARTELA ]","29"},{"Vidro               [ VIDRO   ]","30"},;
				 {"Metro Linear        [ M       ]","31"},{"Metro Quadrado      [ M2      ]","32"},;
				 {"Metro Cubico        [ M3      ]","33"},{"Pe Linear           [ PE      ]","34"},;
				 {"Pe Quadrado         [ PE2     ]","35"},{"Pe Cubico           [ PE3     ]","36"},;
				 {"Centimetro Quadrado [ CM2     ]","37"},{"Polegada Linear     [ PO      ]","38"},;
				 {"Polegada Quadrada   [ PO2     ]","39"},{"Polegada Cubica     [ PO3     ]","40"},;
				 {"Garrafa 1/5         [ G 1/5   ]","41"},{"Garrafa 1/4         [ G 1/4   ]","42"},;
				 {"Garrafa 1/3         [ G 1/3   ]","43"},{"Garrafa 1/2         [ G 1/2   ]","44"},;
				 {"Litro 1/4           [ L 1/4   ]","45"},{"Litro 1/2           [ L 1/2   ]","46"},;
				 {"Peca                [ Peca    ]","47"},{"Caixa               [ CX      ]","48"},;
				 {"Litro 1/1           [ L 1/1   ]","49"},{"Fardo               [ FARDO   ]","50"}}

	aSort(aUnid,,,{ |X,Y| X[1] < Y[1] }) // Ordem Alfabetica

	If (nOp := aScan(aUnid,{|X| Val(X[2]) == nCod})) == 0
		PushScreen(00,00,23,79)
		Shadow(01,01,10,42,3)
		aRet := AAList(aUnid,aList,{"DESCRICAO","COD."},{31,4})
		PopScreen()
		If LastKey() # pESC
			// Seta Unidade Escolhida
			nScUnidade := nCod := Val(aRet[2])
			@ nRow,nCol Say Upper(SubStr(aRet[1],1,20)) //Color sCorM
		Else
			lRet := .f.
		Endif
	Else
		@ nRow,nCol Say Upper(SubStr(aUnid[nOp][1],1,20)) //Color sCorM
	Endif
	SetColor(sCorAnt)
	RETURN(lRet)

