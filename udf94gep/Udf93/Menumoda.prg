#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

FUNCTION MENUMODAL( aList, nStart, aDisplay )
	Local nKey,nCounter,bBlock,nVal,bMess,cScreen
	Local lEvalValue,nCursor := SetCursor(0)
	Local cGetColor := aColor()[2]  // Get the second set
	Local cLetter   := aColor()[2]  // Consiste Letra Colorida
	Local cSayColor := aColor()[1]  // Get the first set
	Local bDisplay  := {|cColor| ;
							  DevPos( aList[nStart,1],aList[nStart,2]),;
							  DevOut( aList[nStart,3],cColor), ;
							  DevPos( aList[nStart,1],aList[nStart,2]+aList[nStart,5]-1),;
							  DevOut( aList[nStart,4],;
							  If(cColor # cLetter,aList[nStart,6],cColor)) }

	bMess := {|| If(Empty(aList[nStart,7]),NIL,If(Empty(aList[nStart,8] ),NIL,;
						 (DevPos(aList[nStart,8],aList[nStart,9]),;
						 DevOut(aList[nStart,7],aList[nStart,10])))) }




	If nStart IS NOT pNUMERIC
		nStart := 1
	Endif

	If ! Empty( aList )
		If nStart > Len( aList )
			nStart := Len( aList )
		Endif
		If nStart < 1
			nStart := 1
		Endif

		DispBegin()
		For nCounter := 1 to Len( aList ) // This is only for clarity!
			// The prompt stuff!
			DevPos(aList[nCounter,1],aList[nCounter,2])
			DevOut(alist[nCounter,3],cSayColor)

			// The Highlight stuff!
			DevPos(aList[nCounter,1],aList[nCounter,2] + ;
											 aList[nCounter,5] - 1 )
			DevOut(aList[nCounter,4],aList[nCounter,6])
		Next
		DispEnd()

		While .t.
			cScreen := If(Empty(aList[nStart,7]),;
							  NIL,;
							  SaveScreen(aList[nStart,8],;
											 aList[nStart,9],;
											 aList[nStart,8],;
											 aList[nStart,9]+Len(aList[nStart,7])))
			eVal(bDisplay,cGetColor)
			eVal(bMess)

			nKey := 0

			While (nKey := Inkey()) = 0
				If aDisplay # NIL ; eVal(aDisplay[1]) ; Endif
			End

			If cScreen != NIL
				RestScreen(aList[nStart,8],aList[nStart,9], ;
							  aList[nStart,8],;
							  aList[nStart,9] + Len(aList[nStart,7]),cScreen)
			Endif

			If (bBlock := SetKey(nKey)) # NIL
				eVal(bBlock,nKey,aList,@nStart )
			Else
				eVal( bDisplay, cSayColor )
				// Scan from this point on!
				If aScan(aList, {|x| Upper(x[4]) == Upper(Chr(nKey))} ) == nStart
					nVal := aScan(aList, {|x| Upper(x[4]) == Upper(Chr(nKey))}, nStart+1)
				Else
					nVal := aScan(aList, {|x| Upper(x[4]) == Upper(Chr(nKey))} )
				Endif

				If ! Empty(nVal)
					nStart := nVal
					If ! Set(pCONFIRM)  // If confirm is on, wait for another key
						eVal(bDisplay,cGetColor) // Turn on selection
						Exit
					Endif
				Else
					Do Case

                    Case nKey == pRIGHT_ARROW .or. nKey == 32 .or. nKey == pTAB
                        // A new special case
                        If ++nStart > Len( aList )
                            nStart := If(Set( 35 ), 1, Len( aList ) )
                        Endif

                    Case nKey == pLEFT_ARROW   // A new special nase
                        If --nStart < 1
                            nStart := If(Set( 35 ), Len( aList ), 1 )
                        Endif

                    Case nKey == pESC
						nStart := 0
						Exit
					Case nKey == pUP_ARROW
						If --nStart < 1
							nStart := If(Set( 35 ), Len( aList ), 1 )
						Endif
					Case nKey == pDOWN_ARROW
						If ++nStart > len( aList )
							nStart := If(Set( 35 ), 1, Len( aList ) )
						Endif
					Case nKey == pENTER
                        // Turn on selection!
						eVal( bDisplay, cGetColor )
						// Now, evaluate the operational block passing to it
						// the list of menu items, the numeric position of
						// the selection (by reference), and the ascii value
						// of the last key pressed.

						// If the value of the code block should return a logical
						// false then the value of eVal() will be false which will
						// tell the subsystem that it should NOT continue!

						lEvalValue := eVal( aList[nStart, 12 ], aList, @nStart, nKey )

						// Now that a return value has been received, it may NOT be a
						// logical value in which case, it must be converted to the
						// appropriate data type before being tested!
						DEFAULT lEvalValue TO pFALSE
						If ! lEvalValue
							Exit
						Else // re-test the parameters to see If still in range
							If nStart < 1 .or. nStart > len( aList )
								nStart := 1  // Re-Set to the beginning!
							Endif
						Endif
                    Case nKey == pHOME
						nStart := 1
					Case nKey == pEND
						nStart := Len(aList)
					Endcase
				Endif
			Endif
		End
	Endif
	SetCursor(nCursor)
	RETURN(LastKey() # pESC )

// ***
// ***
