
FUNCTION EXTENSO( VALOR )
LOCAL SVALOR,CENT,CRUZ,MIL,MILH,BILH
SVALOR=STR(VALOR,15,2)
CENT = " "+SUBSTR(SVALOR,-2,2)
CRUZ = SUBSTR(SVALOR,-06,3)
MIL  = SUBSTR(SVALOR,-09,3)
MILH = SUBSTR(SVALOR,-12,3)
BILH = SUBSTR(SVALOR,-15,3)
RETURN;
IF((!EMPTY(BILH)).AND.BILH # "000",UDC(BILH)+IF(SUBSTR(BILH,3,1)="1","bilhao ","bilhoes "),"")+;
IF((!EMPTY(MILH)).AND.MILH # "000",UDC(MILH)+IF(SUBSTR(MILH,3,1)="1","milhao ","milhoes "),"")+;
IF((!EMPTY(MIL)) .AND.MIL  # "000",UDC(MIL )+"mil ","")+;
IF((!EMPTY(BILH).OR.!EMPTY(MILH).OR.!EMPTY(MIL).OR.!EMPTY(CRUZ)).AND.CRUZ # "000",;
IF((!EMPTY(BILH).OR.!EMPTY(MILH).OR.!EMPTY(MIL)),"e ","")+UDC(CRUZ)+" ","")+;
IF(!EMPTY(BILH).OR.!EMPTY(MILH).OR.!EMPTY(MIL).OR.!EMPTY(CRUZ).AND.CRUZ # "  0",;
IF(CRUZ="  1","Real ","Reais "),"")+;
IF(CENT # " 00",IF(EMPTY(INT(VALOR)),"","e ")+UDC(CENT)+IF(CENT=" 01","Centavo.","Centavos."),".")


FUNCTION UDC(SVALOR)
LOCAL UN,DZ,CN
UN = SUBSTR(SVALOR,3,1)
DZ = SUBSTR(SVALOR,2,1)
CN = SUBSTR(SVALOR,1,1)
STORE "" TO CN1,UN1,DZ1
* centenas
if  !empty(cn) .and. cn # "0"
	 do case
		 case  cn = "1"
				 if  un = "0"  .and. dz = "0"
					  cn1 = "Cem"
				 else
					  cn1 = "Cento"
				 endif
		  case  cn = "2"
				  cn1 = "Duzentos"
		  case  cn = "3"
				  cn1 = "Trezentos"
		  case  cn = "4"
				  cn1 = "Quatrocentos"
		  case  cn = "5"
				  cn1 = "Quinhentos"
		  case  cn = "6"
				  cn1 = "Seiscentos"
		  case  cn = "7"
				  cn1 = "Setecentos"
		  case  cn = "8"
				  cn1 = "Oitocentos"
		  case  cn = "9"
				  cn1 = "Novecentos"
		  otherwise
				  cn1 = ""
	 endcase
endif

* dezenas
if  !empty(dz) .and. dz # "0"
	 do case
		 case  dz = "1"
				 do  case
					  case un = "0"
							 dz1 = "Dez"
					  case un = "1"
							 dz1 = "Onze"
					  case un = "2"
							 dz1 = "Doze"
					  case un = "3"
							 dz1 = "Treze"
					  case un = "4"
							 dz1 = "Quatorze"
					  case un = "5"
							 dz1 = "Quinze"
					  case un = "6"
							 dz1 = "Dezeseis"
					  case un = "7"
							 dz1 = "Dezesete"
					  case un = "8"
							 dz1 = "Dezoito"
					  case un = "9"
							 dz1 = "Dezenove"
				 endcase
		  case  dz = "2"
				  dz1 = "Vinte"
		  case  dz = "3"
				  dz1 = "Trinta"
		  case  dz = "4"
				  dz1 = "Quarenta"
		  case  dz = "5"
				  dz1 = "Cincoenta"
		  case  dz = "6"
				  dz1 = "Sessenta"
		  case  dz = "7"
				  dz1 = "Setenta"
		  case  dz = "8"
				  dz1 = "Oitenta"
		  case  dz = "9"
				  dz1 = "Noventa"
		  otherwise
				  dz1 = ""
	 endcase
endif

* unidades
if  !empty(un) .and. un # "0" .and. dz # "1"
	 do  case
		  case  un = "1"
				  un1 = "Um"
		  case  un = "2"
				  un1 = "Dois"
		  case  un = "3"
				  un1 = "Tres"
		  case  un = "4"
				  un1 = "Quatro"
		  case  un = "5"
				  un1 = "Cinco"
		  case  un = "6"
				  un1 = "Seis"
		  case  un = "7"
				  un1 = "Sete"
		  case  un = "8"
				  un1 = "Oito"
		  case  un = "9"
				  un1 = "Nove"
		  otherwise
				  un1 = ""
	 endcase
endif
RETURN;
CN1+IF(EMPTY(DZ1).or.EMPTY(CN1),""," e ")+;
IF(EMPTY(DZ1).AND.(!EMPTY(CN1)).AND.(!EMPTY(UN1))," e ","")+;
DZ1+IF(EMPTY(UN1).or.EMPTY(DZ1),""," e ")+;
UN1+" "

