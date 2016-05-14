FUNCTION DescMedida( nCodMed )

   Local sRet := Space( 18 )

   If nCodMed != MedMade->MmCodigo
      MedMade->(DbSeek(nCodMed))
   Endif

   sRet := MontaMedMade()

   Return( sRet )
