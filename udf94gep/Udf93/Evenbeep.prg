#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


/*
*/
FUNCTION ERRORBEEP
	Tone(300,1)
	Tone(499,5)
	Tone(700,5)
	RETURN NIL

// ***
// ***

/*
*/
FUNCTION DONEBEEP
	Tone(150,8)
	Tone(130,10)
	RETURN NIL

// ***
// ***

/*
*/
FUNCTION CALLBEEP
	Tone(900,.5)
	RETURN NIL

// ***
// ***

