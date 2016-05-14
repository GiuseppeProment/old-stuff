#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


Function MataItem(aArray,nPointer)
	Local aNewArray := {}, nAux
	For nAux := 1 to len(aArray)
		If nAux!=nPointer
			aadd(aNewArray,aArray[nAux])
		Endif
	Next
	Return aNewArray

