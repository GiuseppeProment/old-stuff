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

Function GetStatComiss( aGetList, nLin, nCol)
	Local aMatriz:={{"N","INATIVO"},{"S"," ATIVO "}}
	Local oGet := GetActive(), nPos
	nPos:=ascan(aMatriz,{ |cElemento| Upper(oGet:VarGet()) == cElemento[1] } )
	If nPos == 0
		nPos := AAlist(aMatriz,{{nLin,nCol,nLin+3,nCol+14},WhatColor(1),"Status",pSBAR})
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
	Endif
	Return nPos!=0

