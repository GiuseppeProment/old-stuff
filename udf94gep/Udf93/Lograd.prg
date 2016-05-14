#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

FUNCTION Lograd( cLog, nRow, nCol )

	Local aLogr := {},nOp := 0,aList := Array(05),aRet := {},lRet := .t.
	Local sCorAnt := SetColor()

	SetColor(WhatColor(1))

	aList[1] := { 01, 01, 10, 25 }
	aList[2] := sCorJ
	aList[3] := "LOGRADOUROS"
	aList[4] := pSBAR

	aLogr:={{"[ Avenida ]","AV  "},{"[ Rua     ]","RUA "},{"[ Acesso  ]","ACS "},;
			  {"[ Alameda ]","AL  "},{"[ Estrada ]","ETR "},{"[ Galeria ]","GLR "},;
			  {"[ Jardim  ]","JD  "},{"[ Ladeira ]","LAD "},{"[ Lago    ]","LAG "},;
			  {"[ Largo   ]","LGO "},{"[ Passagem]","PAS "},{"[ Praia   ]","PR  "},;
			  {"[ Parque  ]","PRQ "},{"[ Rodovia ]","RDV "},{"[ Travessa]","TR  "},;
			  {"[ Trevo   ]","TRV "},{"[ Viaduto ]","VD  "},{"[ Viela   ]","VEL "},;
			  {"[ Via     ]","VIA "},{"[ Vila    ]","VL  "},{"[ Bosque  ]","BSQ "},;
			  {"[ Praca   ]","PCA "},{"[ Quadra  ]","QDR "}}

	aSort(aLogr,,,{ |X,Y| X[1] < Y[1] }) // Ordem Alfabetica

	If (nOp := aScan(aLogr,{|X| X[2] == cLog})) == 0
		PushScreen(00,00,23,79) ; Shadow(01,01,10,25,3)
		aRet := AAList(aLogr,aList,{"DESCRICAO","COD."},{12,4})
		PopScreen()
		If LastKey() # pESC
			// Seta Unidade Escolhida
			cDesLog := cLog := aRet[2]
			@ nRow,nCol Say cLog  //Color sCorM
		Else
			lRet := .f.
		Endif
	Else
		@ nRow,nCol Say Upper(aLogr[nOp][2]) //Color sCorM
	Endif
	SetColor(sCorAnt)
	RETURN(lRet)



