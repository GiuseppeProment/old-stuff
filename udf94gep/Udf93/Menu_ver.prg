#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

/*
FUNCTION Menu_Ver(mtitulo,mat,alt,lin,col,disable)
Local larg,tela,sCorAnt := SetColor()
Larg = max(len(mtitulo),len(mat[1]))
if alt > 17
	alt = 17
endif
If pCount()<5
	col_i=40-(larg+2)/2
Else
	col_i=col
Endif
If pCount()<4
	lin_i=(24)/2-(alt+2)/2
Else
	lin_i=lin
Endif
If pCount()<3
	alt_i=10
Else
	alt_i=alt
Endif

Save Screen to Tela
Wopen(wSet(lin_i,col_i-2,If(Lin_I+Alt+3 > 21,21,Lin_I+Alt+3),col_i+larg+2,;
		WhatColor(1),pSBAR,0,5,mtitulo,3,,,pSBAR))
SetColor(WhatColor())
@ lin_i+2,Col_i-1 to lin_i+2,Col_i+larg+1 Double
@ lin_i+3,Col_i to If(Lin_I+Alt+2 > 20,20,Lin_I+Alt+2),Col_I
@ lin_i+2,Col_i-2 Say "Æ"
@ lin_i+2,Col_i+Larg+2 Say "µ"
*
if pCount() = 6
	op=achoice(lin_I+3,col_i+1,If(Lin_I+Alt+2 > 20,20,Lin_I+Alt+2),col_i+larg,mat,disable,"Ud_Funa")
else
	op=achoice(lin_I+3,col_i+1,If(Lin_I+Alt+2 > 20,20,Lin_I+Alt+2),col_i+larg,mat,"","Ud_Funa")
endif
wClose()
restore screen from tela
SetColor(sCorAnt)
RETURN(op)
*/



FUNCTION menu_ver2(mtitulo,mat,linha,coluna)

Local tamanho,ret,scr,sCorAnt := SetColor(),n
* obter tamanho do maior item
comprimento := Len(mtitulo)+2
tamanho := 0 

For n := 1 to len(Mat)
	 tamanho=tamanho+1
	 If comprimento < Len(mat[tamanho])
		 comprimento = Len(mat[tamanho])
	 EndIf
Next
* impoem limite no tamanho
If  tamanho > 17
	 tamanho = 17
EndIf
* impoem limite no comprimento
If  comprimento > 70
	 comprimento = 70
EndIf
* linha,coluna
If linha == Nil
   linha = 12-((tamanho+2)/2)
endif
If coluna == Nil
   coluna= 40-(comprimento/2)
endif

* desenhar box
save screen to scr
wOpen(wSet(linha,coluna,If(Linha+Tamanho+3 > 21,21,Linha+Tamanho+3),coluna+comprimento+3,;
		WhatColor(1),pSBAR,0,5,mtitulo,3,,,pSBAR))
SetColor(WhatColor())

@ linha+2,coluna+1 to linha+2,coluna+2+comprimento Double
@ linha+3,coluna+2 to If(Linha+Tamanho+2 > 20,20,Linha+Tamanho+2),coluna+2
@ linha+2,coluna Say "Æ"
@ linha+2,coluna+3+comprimento Say "µ"

Ret = Achoice(linha+3,coluna+3,If(Linha+Tamanho+2 > 20,20,Linha+Tamanho+2),coluna+comprimento+2,mat,.T.,"Ud_funa")

wClose()

Restore Screen From scr

SetColor(sCorAnt)

RETURN(Ret)


/*
FUNCTION Menu_Ver3(mtitulo,mat,alt,lin,col,disable)
LOCAL larg,cor:=setColor()
Larg = max(len(mtitulo),len(mat[1]))
if alt > 17
	alt = 17
endif
If pCount()<5
	col_i=40-(larg+2)/2
Else
	col_i=col
Endif
If pCount()<4
	lin_i=(24)/2-(alt+2)/2
Else
	lin_i=lin
Endif
If pCount()<3
	alt_i=10
Else
	alt_i=alt
Endif
NewBox(lin_i,col_i-2,If(Lin_I+Alt+3 > 21,21,Lin_I+Alt+3),col_i+larg+2,7,7,.T.,110,"",1)
Centra(lin_i+1,col_i+1,col_i+larg,mtitulo)
@ lin_i+2,Col_i-1 to lin_i+2,Col_i+larg+1 Double
@ lin_i+3,Col_i to If(Lin_I+Alt+2 > 20,20,Lin_I+Alt+2),Col_I
@ lin_i+2,Col_i-2 Say "Æ"
@ lin_i+2,Col_i+Larg+2 Say "µ"

set Color to ,,,,g/r
if pCount() = 6
	op=achoice(lin_I+3,col_i+1,If(Lin_I+Alt+2 > 20,20,Lin_I+Alt+2),col_i+larg,mat,disable,"Ud_Funa")
else
	op=achoice(lin_I+3,col_i+1,If(Lin_I+Alt+2 > 20,20,Lin_I+Alt+2),col_i+larg,mat,"","Ud_Funa")
endif
setColor(cor)

RETURN(op)
*/
