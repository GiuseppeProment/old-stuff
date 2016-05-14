#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

FUNCTION SKIPPERARR(nToJump,aArray)
	Local nJumped := 0
	If nRowArr + nToJump < 1
		nJumped := -nRowArr + 1
		nRowArr := 1
	Elseif nRowArr + nToJump > Len(aArray)
		nJumped := Len(aArray) - nRowArr
		nRowArr := Len(aArray)
	Else
		nJumped := nToJump
		nRowArr += nToJump
	Endif
	nWinPos := nRowArr
	RETURN(nJumped)

// ***
// ***

