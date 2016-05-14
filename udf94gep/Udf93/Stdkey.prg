#Include "FileMan.ch"
#Include "PTFuncs.ch"
#Include "PTinkey.ch"
#Include "PTvalue.ch"
#Include "PTverbs.ch"
#Include "Paths.ch"
#Define   TIME_TO_SAVER 2000

/*
  Checa teclagem feita pelo usuario e executa metodo padrao no objeto
  TBrowse (Tabela)
*/
FUNCTION StdKey(oObj,nKey)
	If      nKey == pUP_ARROW
			  oObj:up()
	Elseif  nKey == pDOWN_ARROW
			  oObj:down()
	Elseif  nKey == pLEFT_ARROW
			  oObj:left()
	Elseif  nKey == pRIGHT_ARROW
			  oObj:right()
	Elseif  nKey == pHOME
			  oObj:home()
	Elseif  nKey == pEND
			  oObj:end()
	Elseif  nKey == pPGUP
			  oObj:pageUp()
	Elseif  nKey == pPGDN
			  oObj:pageDown()
	Elseif  nKey == pCTRL_PGUP
			  oObj:goTop()
	Elseif  nKey == pCTRL_PGDN
			  oObj:goBottom()
	Elseif  nKey == pCTRL_HOME
			  oObj:panHome() // Vai para primeira coluna real
	Elseif  nKey == pCTRL_END
			  oObj:panEnd()  // Vai para ultima coluna real
	Elseif  nKey == pCTRL_LEFT_ARROW
			  oObj:panLeft() // Desloca janela para esquerda
	Elseif  nKey == pCTRL_RIGHT_ARROW
			  oObj:panRight() // Desloca janela para direita
	Endif
	RETURN NIL

