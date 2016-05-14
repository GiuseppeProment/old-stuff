#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


function ccpf(xis)
private sm,d1,d2,r1,r2,ok
sm := d1 := d2 := 0

If Empty(Val(xis))
   Return .t.
endif

do while .t.
	if type(subs(xis,1,3)) <> 'N'
		ok = 'N'
		exit
	endif
	if subs(xis,4,1) <> '.'
		ok = 'N'
		exit
	endif
	if type(subs(xis,5,3)) <> 'N'
		ok = 'N'
		exit
	endif
	if subs(xis,8,1) <> '.'
		ok = 'N'
		exit
	endif
	if type(subs(xis,9,3)) <> 'N'
		ok = 'N'
		exit
	endif
	if subs(xis,12,1) <> '-'
		ok = 'N'
		exit
	endif
	if type(subs(xis,13,2)) <> 'N'
		ok = 'N'
		exit
	endif
	if xis = '000.000.000-00'
		ok = 'N'
		exit
	endif
	sm = sm + (val(subs(xis,1,1)) * 1)
	sm = sm + (val(subs(xis,2,1)) * 2)
	sm = sm + (val(subs(xis,3,1)) * 3)
	sm = sm + (val(subs(xis,5,1)) * 4)
	sm = sm + (val(subs(xis,6,1)) * 5)
	sm = sm + (val(subs(xis,7,1)) * 6)
	sm = sm + (val(subs(xis,9,1)) * 7)
	sm = sm + (val(subs(xis,10,1)) * 8)
	sm = sm + (val(subs(xis,11,1)) * 9)
	d1 = mod(sm,11)
	if d1 = 11 .or. d1 = 10
		d1 = 0
	endif
	sm = 0
	sm = sm + (val(subs(xis,1,1)) * 9)
	sm = sm + (val(subs(xis,2,1)) * 8)
	sm = sm + (val(subs(xis,3,1)) * 7)
	sm = sm + (val(subs(xis,5,1)) * 6)
	sm = sm + (val(subs(xis,6,1)) * 5)
	sm = sm + (val(subs(xis,7,1)) * 4)
	sm = sm + (val(subs(xis,9,1)) * 3)
	sm = sm + (val(subs(xis,10,1)) * 2)
	sm = sm + (val(subs(xis,11,1)) * 1)
	d2 = mod(sm,11)
	if d2 = 11 .or. d2 = 10
		d2 = 0
	endif
	ok = 'S'
	if val(subs(xis,13,1)) <> d1
		ok  =  'N'
	endif
	if val(subs(xis,14,1)) <> d2
		ok  =  'N'
	endif
	exit
enddo
if ok = 'N'
	MensInfo('CPF invalido...')
	return(.F.)
endif
return(.T.)

function ccgc(xis)
private sm,d1,d2,r1,r2,ok
sm = 0
d1 = 0
d2 = 0

If Empty(Val(xis))
   Return .t.
Endif

do while .t.
	if type(subs(xis,1,2)) <> 'N'
		ok = 'N'
		exit
	endif
	if subs(xis,3,1) <> '.'
		ok = 'N'
		exit
	endif
	if type(subs(xis,4,3)) <> 'N'
		ok = 'N'
		exit
	endif
	if subs(xis,7,1) <> '.'
		ok = 'N'
		exit
	endif
	if type(subs(xis,8,3)) <> 'N'
		ok = 'N'
		exit
	endif
	if subs(xis,11,1) <> '/'
		ok = 'N'
		exit
	endif
	if type(subs(xis,12,4)) <> 'N'
		ok = 'N'
		exit
	endif
	if subs(xis,16,1) <> '-'
		ok = 'N'
		exit
	endif
	if type(subs(xis,17,2)) <> 'N'
		ok = 'N'
		exit
	endif
	if xis = '00.000.000/0000-00'
		ok = 'N'
		exit
	endif
	sm = sm + (val(subs(xis,1,1)) * 5)
	sm = sm + (val(subs(xis,2,1)) * 4)
	sm = sm + (val(subs(xis,4,1)) * 3)
	sm = sm + (val(subs(xis,5,1)) * 2)
	sm = sm + (val(subs(xis,6,1)) * 9)
	sm = sm + (val(subs(xis,8,1)) * 8)
	sm = sm + (val(subs(xis,9,1)) * 7)
	sm = sm + (val(subs(xis,10,1)) * 6)
	sm = sm + (val(subs(xis,12,1)) * 5)
	sm = sm + (val(subs(xis,13,1)) * 4)
	sm = sm + (val(subs(xis,14,1)) * 3)
	sm = sm + (val(subs(xis,15,1)) * 2)
	r1 = mod(sm,11)
	d1 = 11 - r1
	if d1 = 11 .or. d1 = 10
		d1 = 0
	endif
	sm = 0
	sm = sm + (val(subs(xis,1,1)) * 6)
	sm = sm + (val(subs(xis,2,1)) * 5)
	sm = sm + (val(subs(xis,4,1)) * 4)
	sm = sm + (val(subs(xis,5,1)) * 3)
	sm = sm + (val(subs(xis,6,1)) * 2)
	sm = sm + (val(subs(xis,8,1)) * 9)
	sm = sm + (val(subs(xis,9,1)) * 8)
	sm = sm + (val(subs(xis,10,1)) * 7)
	sm = sm + (val(subs(xis,12,1)) * 6)
	sm = sm + (val(subs(xis,13,1)) * 5)
	sm = sm + (val(subs(xis,14,1)) * 4)
	sm = sm + (val(subs(xis,15,1)) * 3)
	sm = sm + (d1 * 2)
	r2 = mod(sm,11)
	d2 = 11 - r2
	if d2 = 11 .or. d2 = 10
		d2 = 0
	endif
	ok = 'S'
	if val(subs(xis,17,1)) <> d1
		ok  =  'N'
	endif
	if val(subs(xis,18,1)) <> d2
		ok  =  'N'
	endif
	exit
enddo
if ok = 'N'
	Mensinfo('CGC invalido...')
	return(.F.)
endif
return(.T.)
//
//

FUNCTION Valida_Cgc( cTipo, cCgcCpf )

	Local lRet := pTRUE

	If cTipo == "J"

		If !( lRet := cCgc( cCgcCpf ) )           //TestaCgc( cCgcCpf ) )

			MensInfo( "C.G.C. Inv lido !" )

		Endif

	Else

		If !Ccpf( cCgcCpf )

			lRet := pFALSE

		Endif

	Endif
			
	Return( lRet )

//------------------------------------------ 

FUNCTION TestaCgc( cCgc )

	Local D:= { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },;
			Resto1   := 0,;
			Resto2   := 0,;
			nCounter := 0,;
			PriDig   := 0,;
			SegDig   := 0,;
			Df1      := 0,;
			Df2      := 0,;
			Df3      := 0

	Local lRet 

    If Empty(cCgc)
       Return .t.
    endif

	For nCounter := 1 to Len( D )

		D[ nCounter] := Val( Substr( cCgc, nCounter, 1 ) )

	Next

	//-------------- Teste do Primeiro Digito ( Unidade ) -----------

	Df1 := 5 * D[ 01 ] +; 
			 4 * D[ 02 ] +;
			 3 * D[ 03 ] +;
			 2 * D[ 04 ] +;
			 9 * D[ 05 ] +;
			 8 * D[ 06 ] +;
			 7 * D[ 07 ] +;
			 6 * D[ 08 ] +;
			 5 * D[ 09 ] +;
			 4 * D[ 10 ] +;
			 3 * D[ 11 ] +;
			 2 * D[ 12 ]

	Df2 := Df1 / 11

	Df3 := Int( Df2 ) * 11

	Resto1 := Df1 - Df3

	If Resto1 == 0 .or. Resto1 == 1

		PriDig := 0
	Else

		PriDig := 11 - Resto1

	Endif

	//-------------- Teste do Segundo Digito ( Dezena ) -----------

	Df1 := 6 * D[ 01 ] +;
			 5 * D[ 02 ] +;
			 4 * D[ 03 ] +;
			 3 * D[ 04 ] +;
			 2 * D[ 05 ] +;
			 9 * D[ 06 ] +;
			 8 * D[ 07 ] +;
			 7 * D[ 08 ] +;
			 6 * D[ 09 ] +;
			 5 * D[ 10 ] +;
			 4 * D[ 11 ] +;
			 3 * D[ 12 ] +;
			 2 * PriDig

	Df2 := Df1 / 11

	Df3 := Int( Df2 ) * 11

	Resto2 := Df1 - Df3

	If Resto2 == 0 .or. Resto2 == 1

		SegDig := 0
	Else

		SegDig := 11 - Resto2

	Endif
	
	If PriDig != Val( Substr( cCgc, 13, 1 ) ) .or. ;
		SegDig != Val( Substr( cCgc, 14, 1 ) )

		lRet := pFALSE  

	Else

		lRet := pTRUE

	Endif

	Return( lRet ) 

//------------------------------------------

FUNCTION CgcPict( cTipo  )

	MemVar cPict

	If cTipo == "F"

		cPict := "999.999.999/99"

	Else

		cPict := "99.999.999/9999-99"

	Endif

	Return( cPict )

//------------------------------------------

FUNCTION Alt_CgcCpf( oGet, cTipo )

	Local lRet:= pFALSE

	If cTipo == "F"

		oGet:varPut( Space( 14 ) )
		//oGet:Buffer := Space( 14 )
		//oGet:Picture := "@R 999.999.999-99"
		oGet:Picture := "999.999.999-99"
		lRet := pTRUE

	Else

		oGet:varPut( Space( 18 ) )
		//oGet:Buffer := Space( 18 )
		//oGet:Picture := "@R 99.999.999/9999-99"
		oGet:Picture := "99.999.999/9999-99"
		lRet := pTRUE

	Endif 

	Return( lRet )

//------------------------------------------
