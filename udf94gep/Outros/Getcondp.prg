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
//北北北北北北北北北北北北北北北北北北北北北北北�
//

Function GetCondPgto(aGetList,nLin,nCol,;      // menu em get
							lExib,nlinExib,nColExib,nLenExib)
	Local oGet := GetActive()
    Local aMatriz:={ {"A","A VISTA   "},;
                     {"P","PARCELADA "},;
                     {"E","EXCESSAO  "},;
                     {"C","A COMBINAR"} }
	Local nPos
	nPos:=ascan(aMatriz,{ |cElemento| Upper(oGet:VarGet()) == cElemento[1] } )
	If nPos == 0
        nPos := AAlist(aMatriz,{{nLin,nCol,nLin+5,nCol+14},;
							WhatColor(1),"Condicoes",pSBAR})
		// so' para converter em posicao numerica
		If !Empty(nPos)
			nPos := ascan(aMatriz,{ |cElemento| nPos[1] == cElemento[1] } )
		else
			nPos := 0
		Endif
	Endif
	If nPos != 0
		oGet:VarPut( aMatriz[nPos,1] )
		oGet:Display()
		If lExib
			If nLenExib != Nil
				@ nLinExib,nColExib say Substr(aMatriz[nPos,2],1,nLenExib) color;
				CorGetUnSel()
			else
				@ nLinExib,nColExib say aMatriz[nPos,2] color CorGetUnSel()
			Endif
		Endif
	Endif
	Return nPos!=0

// somente para servico

Function SvGetCondPgto(aGetList,nLin,nCol,;      // menu em get
							lExib,nlinExib,nColExib,nLenExib)
	Local oGet := GetActive()
    Local aMatriz:={ {"M","MEDICAO  "},;
                     {"P","PARCELADA"},;
                     {"C","A COMBINAR"} }
	Local nPos
	nPos:=ascan(aMatriz,{ |cElemento| Upper(oGet:VarGet()) == cElemento[1] } )
	If nPos == 0
        nPos := AAlist(aMatriz,{{nLin,nCol,nLin+5,nCol+14},;
							WhatColor(1),"Condicoes",pSBAR})
		// so' para converter em posicao numerica
		If !Empty(nPos)
			nPos := ascan(aMatriz,{ |cElemento| nPos[1] == cElemento[1] } )
		else
			nPos := 0
		Endif
	Endif
	If nPos != 0
		oGet:VarPut( aMatriz[nPos,1] )
		oGet:Display()
		If lExib
			If nLenExib != Nil
				@ nLinExib,nColExib say Substr(aMatriz[nPos,2],1,nLenExib) color;
				CorGetUnSel()
			else
				@ nLinExib,nColExib say aMatriz[nPos,2] color CorGetUnSel()
			Endif
		Endif
	Endif
    Return nPos!=0
