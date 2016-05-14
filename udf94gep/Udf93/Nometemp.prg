#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

FUNCTION NOMETEMP
	Static nLetter:=64
	If ++nLetter = 91; nLetter:=65; Endif
	 RETURN pRASCUNHO+SubStr(Cn_Who(),1,3)+;
			 Substr( StrZero( Seconds(),12,2 ) ,-2,2) +;
			 StrZero(Randomize(99),2)+Chr(nLetter)+".TMP"
	

// ***
// ***
