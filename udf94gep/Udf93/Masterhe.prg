#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

FUNCTION MASTERHEAD(Topico,Referencia,Pagina,sEmpresa,sRamoAtiv)
   If sEmpresa == NIL
      sEmpresa := "AMD"
      sRamoAtiv := " - Servi‡os Educacionais S/C Ltda."
	Endif
	If sRamoAtiv == NIL
       sRamoAtiv := " "
	Endif
	If Topico == NIL
        Topico := " "
	Endif
	If Referencia == NIL
        Referencia := " "
	Endif
	If Pagina == NIL
		Pagina := 0
	Endif
	//  3 -> numero total de folhas
	//  4 -> tempo de processo

	@ 01,00 Say p_Doubwid(.t.)+p_Doubhig(.t.)+p_Italic(.t.)+p_Enfa(.t.)+;
				   sEmpresa+p_Doubwid(.f.)+sRamoAtiv+ p_Italic(.f.)+p_Doubhig(.f.)

	 @ 02,00 Say "Sistema "+p_italic(.t.)+" Administrativo "+p_italic(.f.)+p_enfa(.f.)
    @ 03,00 Say dExtenso()+" "+Time()+"  "+Cn_Who()
	@ pRow()+1,0 Say p_Enfa(.t.)+"Topico     : "+Topico
	If ! Empty(Referencia)
		 @ pRow()+1,0 Say "Referencia : "+Referencia+p_Enfa(.f.)
	Endif
	If Empty(Pagina)
        @ pRow()+1,0 Say "Pagina UNICA "
	Else
         @ pRow()+1,0 Say "Pagina :"+strzero(pagina,3)
	Endif
	@ pRow()+1,00 Say p_Enfa(.t.)+Replicate("_",78)+p_Enfa(.f.)
	@ pRow()+2,00 Say " "
	RETURN ""

// ***
