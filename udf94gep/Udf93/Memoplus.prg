#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


FUNCTION MEMOPLUS(sFileName,sMsg)
	Local aOpcao,aFiles,nOpcao,nMinimo,sCorAnt := SetColor()
   Local sTela,sCor

	If ! File(sFileName)
		Msg("O Arquivo Selecionado Nao Existe",13,"W+/R+")
		VOID
	Endif

	aFiles := Directory(sFileName)
	nMinimo := (aFiles[1,2]/1024)

	aOpcao := {"Ver Listagem na Tela","Imprimir a Listagem"}
	nOpcao := 1

	Set wrap on
	sCor := SetColor("GR+/B+")

	While nOpcao # 0
		//nOpcao := aList(aOpcao,{08,15,14,35},PadC("OPCOES",20))

      sTela := SaveScreen(09,19,12,41)
      DispBox(09,19,12,41,pSBAR)
		nOpcao := achoice(10,20,11,40,aOpcao,.t.)
      RestScreen(09,19,12,41,sTela)

		If LastKey() == pLEFT_ARROW .or. LastKey() == pRIGHT_ARROW
			nOpcao := 1
			Loop
		ElseIf LastKey() == pESC
			SetColor( sCorAnt )
			exit
		Endif

		Do Case
		Case nOpcao = 1
         If nMinimo > 50
				Msg("Nao Ha Memoria Disponivel p/ Visualizacao",13,"W+/R+")
				Loop
			Endif
			sTela := SaveScreen(02,00,24,79)
			DispBox(04,02,21,78,pSBAR)
			Centra(23,12,78,"Teclas Permitidas   :   PgDw   PgUp   "+Chr(24)+"   "+Chr(25)+"   ESC")
			MemoEdit( MemoRead( sFileName ), 06, 04, 20, 77,.f.,"", 700, 3, 1, 1, 0, 0 )
			RestScreen(02,00,24,79,sTela)
		Case nOpcao = 2
			sTela := SaveScreen( 23,02,23,78 )
			nCopia := 1
			@ 23,02 Say "Quantidade de Copias: " Get nCopia Pict "99"
			Read
			If Lastkey() = pESC
				Loop
			Endif
			If Confirma("Confirma a Impressao")
				Scroll( 23,02,23,78,0 )
				Set Console off
				@ 23,02 say "Imprimindo..."
				Set Print On
				Set( _SET_DEVICE, "PRINTER" )
				For nCounter := 1 to nCopia
					Type (sFileName) to Print
					Eject
				Next
				Set Console on
				Set Print off
				Set( _SET_DEVICE, "SCREEN" )
            MsgBox("Impressao OK")
			Endif
            RestScreen( 23,02,23,78, sTela )
		EndCase
	Enddo
	fErase(sFileName)
	VOID
