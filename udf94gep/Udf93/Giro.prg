#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

FUNCTION GIRO()
	STATIC nSegue := 0
	If ++nSegue == 5 ; nSegue := 1 ; End
	Do Case
	Case nSegue == 1 ; @ 23,77 Say "Ä" Color ColorSet(23,77)
	Case nSegue == 2 ; @ 23,77 Say "\" Color ColorSet(23,77)
	Case nSegue == 3 ; @ 23,77 Say "|" Color ColorSet(23,77)
	Case nSegue == 4 ; @ 23,77 Say "/" Color ColorSet(23,77)
	EndCase
	RETURN .t.

