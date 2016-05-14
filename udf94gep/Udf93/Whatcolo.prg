#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

// ***
// ***

/*
	Parametros     : Nil
	Objetivo       : Retornar a cor para a janela
	Excessao       :
	Pre-requisitos : Variaveis de cor devem estar setadas
*/

FUNCTION WhatColor(xPlus)
	Local nJanelaAtiva
	Local sRet
	If xPlus==Nil
		xPlus:=0
	endif
	nJanelaAtiva := wSeek()+xPlus
	Do Case
		Case nJanelaAtiva == 1
			sRet := sCorJ
		Case nJanelaAtiva == 2
			sRet := sCorJ2
		Case nJanelaAtiva == 3
			sRet := sCorJ3
		Case nJanelaAtiva == 4
			sRet := sCorJ4
		Case nJanelaAtiva == 5
			sRet := sCorJ5
		Case nJanelaAtiva == 6
			sRet := sCorJ
		Case nJanelaAtiva == 7
			sRet := sCorJ2
		Case nJanelaAtiva == 8
			sRet := sCorJ3
		Case nJanelaAtiva == 9
			sRet := sCorJ4
		Case nJanelaAtiva == 10
			sRet := sCorJ5
	EndCase
	Return sRet
	
