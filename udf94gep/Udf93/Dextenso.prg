#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

/*
  DExtenso(xData)
  Tem a Finalidade de Retornar a data por Extenso
  xData - Pode ser a data no formato de data ou character
*/
FUNCTION DEXTENSO(xData)

	Local Mes := {"Janeiro","Fevereiro","Marco","Abril","Maio","Junho",;
					  "Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"}
	If xData = NIL
		xData := Date()
	Else
	  If Valtype(xData) = "C"
		  xData := Ctod(xData)
	  Endif
	Endif
	RETURN(' '+StrZero(Day(xData),2)+" de "+;
					Mes[Month(xData)]+" de "+;
					Str(Year(xData),4)+' ')
// ***
// ***
