#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000


FUNCTION NOT_EMPTY(xCampo)
	If Empty(xCampo)
		Msg_Low("Este Campo Nao Pode Ser Vazio")
	Endif
	RETURN(!Empty(xCampo))

