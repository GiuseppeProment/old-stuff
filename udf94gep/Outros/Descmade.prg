FUNCTION DescMadeira( nCodMade )

	Local sRet := Space( 18 )

	sRet := TipoMad->( DbSetOrder( 1 ), DbSeek( nCodMade ), ;
							 TipoMad->TmDescrNor )

	Return( sRet )

