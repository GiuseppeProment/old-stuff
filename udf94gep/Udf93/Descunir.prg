#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


FUNCTION DescUniRed( nCod )

	Local cRet
	Do Case
		Case nCod == 11
			cRet:=[UM]
		Case nCod == 12
			cRet:=[AP]
		Case nCod == 13
			cRet:=[CONJ]
		Case nCod == 14
			cRet:=[JOGO]
		Case nCod == 15
			cRet:=[PAR]
		Case nCod == 16
			cRet:=[DZ]
		Case nCod == 17
			cRet:=[CENTO]
		Case nCod == 18
			cRet:=[GROSA]
		Case nCod == 19
			cRet:=[MIL]
		Case nCod == 20
			cRet:=[RESMA]
		Case nCod == 21
			cRet:=[K]
		Case nCod == 22
			cRet:=[GR]
		Case nCod == 23
			cRet:=[KG]
		Case nCod == 24
			cRet:=[ARROBA]
		Case nCod == 25
			cRet:=[T]
		Case nCod == 26
			cRet:=[ESTOJO]
		Case nCod == 27
			cRet:=[FRASCO]
		Case nCod == 28
			cRet:=[TUBO]
		Case nCod == 29
			cRet:=[CARTELA]
		Case nCod == 30
			cRet:=[VIDRO]
		Case nCod == 31
			cRet:=[M]
		Case nCod == 32
			cRet:=[M2]
		Case nCod == 33
			cRet:=[M3]
		Case nCod == 34
			cRet:=[PE]
		Case nCod == 35
			cRet:=[PE2]
		Case nCod == 36
			cRet:=[PE3]
		Case nCod == 37
			cRet:=[CM2]
		Case nCod == 38
			cRet:=[PO]
		Case nCod == 39
			cRet:=[PO2]
		Case nCod == 40
			cRet:=[PO3]
		Case nCod == 41
			cRet:=[G 1/5]
		Case nCod == 42
			cRet:=[G 1/4]
		Case nCod == 43
			cRet:=[G 1/3]
		Case nCod == 44
			cRet:=[G 1/2]
		Case nCod == 45
			cRet:=[L 1/4]
		Case nCod == 46
			cRet:=[L 1/2]
		Case nCod == 47
			cRet:=[Peca]
		Case nCod == 48
			cRet:=[CX]
		Case nCod == 49
			cRet:=[L 1/1]
		Case nCod == 50
			cRet:=[FARDO]
		OtherWise
			cRet:= [?]
	EndCase

Return (cRet)
