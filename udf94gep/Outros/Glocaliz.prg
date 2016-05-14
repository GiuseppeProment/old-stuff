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
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//

Function GetLocaliz( oGet, nLin, nCol,;      // menu em get
							lExib, nlinExib, nColExib, nLenExib)
	//Local oGet := GetActive()
	Local aMatriz:={ { "B", "BANCO       "},;
                     { "C", "CARTEIRA    "},;
                     { "D", "DEBITO CONTA"} }
	Local nPos
	nPos:=ascan(aMatriz,{ |cElemento| Upper(oGet:VarGet()) == cElemento[1] } )
	If nPos == 0
		nPos := AAlist(aMatriz,{{nLin,nCol,nLin+4,nCol+20},;
							WhatColor(1),"Classificacao",pSBAR})
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
