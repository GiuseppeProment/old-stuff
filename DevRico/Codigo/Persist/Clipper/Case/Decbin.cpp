#include <stdio.h>
#include <iomanip.h>
#include <iostream.h>







function DecToBin( nNumber,size )

  local cRetValue := ""
  local lSign
  local lOddNumber
  local nStart

   if size==nil
      size:=8
   endif

    lSign      := (nNumber < 0 )
    lOddNumber := !( nNumber / 2 = INT( nNumber / 2) )
    nStart     := 1

    nNumber := abs(nNumber)

    while (nStart * 2) <= nNumber
      nStart *= 2
    enddo

    while nStart > 1.00

      if nNumber >= nStart
        cRetValue    += "1"
        nNumber -= nStart

      else
        cRetValue += "0"

      endif
      nStart /= 2

    enddo

    cRetValue := ;
      if(lSign, "-", "") + ;
      padL( cRetValue + if(lOddNumber, "1", "0"),size,"0")

RETURN ( cRetValue )


/* CREDITOS DA FUNCAO ABAIXO PARA
   "POWER TOOLS FOR CLIPPER 5.2" */
static function BinToDec( cNumber )
   local nRetValue := 0
   local lSign
   local nPower
   local nBase
   lSign   := "-" $ cNumber
   cNumber := strtran(cNumber, "-", "")
   nPower  := 2 ^ (len(cNumber)-1)
   nBase   := 0
   while nPower > 1
      nBase   += ( val( left( cNumber, 1)) ) * nPower
      nPower  /= 2
      cNumber := substr(cNumber, 2)
   enddo
   nRetValue := int( (nBase + ( ( val(left(cNumber, 1)) ) * nPower )) * ;
      if(lSign, -1, 1))
RETURN( nRetValue )

