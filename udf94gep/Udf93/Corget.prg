#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000



FUNCTION CorGetUnSel()
	 Return Substr(SetColor(),Rat(",",SetColor())+1)

FUNCTION CorGetSel()
	 Local pos1 := at(",",SetColor())+1
	 Local cStr := Substr(SetColor(),pos1)
	 pos1 := at(",",cStr)-1
	 Return Substr(cStr,1,pos1)

