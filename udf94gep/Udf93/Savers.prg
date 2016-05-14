#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

//
// FIM DA UDF
//

FUNCTION ScreenSaver()
 * Static count:=0
 * if Inkey()==0
 *    if ++count > TIME_TO_SAVER
 *       PushScreen()
 *       !Recoma //Saver()
 *       PopScreen()
 *       count := 0
 *    endif
 * else
 *    count := 0
 * endif
 * DevPos(MaxRow(),68)
 * DevOut(" "+Time()+" ",ColorSet(MaxRow(),68))
	Void

FUNCTION ScrSaverGet()
  *Static count:=0
  *if Inkey()==0
  *   if ++count > TIME_TO_SAVER
  *      PushScreen()
  *      !Recoma //Saver()
  *      PopScreen()
  *      count := 0
  *   endif
  *else
  *   count := 0
  *endif
  *DevPos(MaxRow(),68)
  *DevOut(" "+Time()+" ",ColorSet(MaxRow(),68))
	Void


FUNCTION Saver()
	Local nLoop,lSai:=.f.,Getlist:={},__ggg:=Space(10)
	Save Screen
	Cls
	Do while !lSai
			 @ 22,0 say;
	"         MENSAGEM INDEFINIDA - MENSAGEM INDEFINIDA - MENSAGEM INDEFINIDA       "
			 @ 24,0 say;
	"                          DESENVOLVIMENTO DE SISTEMAS  "
		for nLoop:=0 to 25
			 Scroll(0,0,25,79,1)
			 IF INKEY(.3)!=0
				 lSai:=.t.
				 Exit
			 ENDIF
		next
	Enddo
	// Pedir Senha
	Cls
	@ 10,10 say "Senha para Voltar: " Get __ggg
	Read
	Restore Screen
	Void
	
