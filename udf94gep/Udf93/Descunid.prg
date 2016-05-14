#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


FUNCTION DescUnid( nUnid )

	Local cRet

	Do Case
		Case nUnid == 11
			cRet :="Unidade       "
		Case nUnid == 12
			cRet :="Aparelho      "
		Case nUnid == 13
			cRet :="Conjunto      "
		Case nUnid == 14
			cRet :="Jogo          "
		Case nUnid == 15
			cRet :="Par           "
		Case nUnid == 16
			cRet :="Duzia         "
		Case nUnid == 17
			cRet :="Cento         "
		Case nUnid == 18
			cRet :="Grosa         "
		Case nUnid == 19
			cRet :="Milheiro      "
		Case nUnid == 20
			cRet :="Resma         "
		Case nUnid == 21
			cRet :="Quilate       "
		Case nUnid == 22
			cRet :="Grama         "
		Case nUnid == 23
			cRet :="Quilograma    "
		Case nUnid == 24
			cRet :="Arroba        "
		Case nUnid == 25
			cRet :="Tonelada      "
		Case nUnid == 26
			cRet :="Estojo        "
		Case nUnid == 27
			cRet :="Frasco        "
		Case nUnid == 28
			cRet :="Tubo          "
		Case nUnid == 29
			cRet :="Cartela       "
		Case nUnid == 30
			cRet :="Vidro         "
		Case nUnid == 31
			cRet :="Metro Linear  "
		Case nUnid == 32
			cRet :="Metro Quadrado"
		Case nUnid == 33
			cRet :="Metro Cubico  "
		Case nUnid == 34
			cRet :="Pe Linear     "
		Case nUnid == 35
			cRet :="Pe Quadrado   "
		Case nUnid == 36
			cRet :="Pe Cubico     "
		Case nUnid == 37
			cRet :="Centimetro Qua"
		Case nUnid == 38
			cRet :="Polegada Linea"
		Case nUnid == 39
			cRet :="Polegada Quadr"
		Case nUnid == 40
			cRet :="Polegada Cubic"
		Case nUnid == 41
			cRet :="Garrafa 1/5   "
		Case nUnid == 42
			cRet :="Garrafa 1/4   "
		Case nUnid == 43
			cRet :="Garrafa 1/3   "
		Case nUnid == 44
			cRet :="Garrafa 1/2   "
		Case nUnid == 45
			cRet :="Litro 1/4     "
		Case nUnid == 46
			cRet :="Litro 1/2     "
		Case nUnid == 47
			cRet :="Peca          "
		Case nUnid == 48
			cRet :="Caixa         "
		Case nUnid == 49
			cRet :="Litro 1/1     "
		Case nUnid == 50
			cRet :="Fardo         "
		Otherwise
			cRet :="Indefinida    "
	EndCase

	RETURN(cRet)



