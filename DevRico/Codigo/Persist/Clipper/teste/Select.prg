#include "..\Clipper\IPersist.ch"

Request DBFCDX

function main()
   local oDs
   local oPessoa
   local OsCadastros
   local x,nStart,nTempo
   ? "inicio..."
   AltD()
   begin sequence
      oDs := INativoDataStore():new()
      oDs:setRddDriver("DBFCDX"):setCaminho(" ")

      IBroker():addDataStore( oDs )
      IBroker():inicialize()

      oDs:ligar()

      //__TRACE(.T.)
      OsCadastros := IColecao():new( Cadastro() )
      /*
      OsCadastros:addCriterio( ICriterio():new("Peso",MENOR,300) )
      OsCadastros:addCriterio( ICriterio():new(AND) )
      OsCadastros:addCriterio( ICriterio():new("Numero",MAIOR,1) )
      */
      /*
      OsCadastros:addCriterio( ICriterio():new("Numero",IGUAL,1) )
      */
      OsCadastros:addCriterio( ICriterio():new("Endereco",IGUAL,"Sao Paulo") )
      OsCadastros:addCriterio( ICriterio():new(AND) )
      OsCadastros:addCriterio( ICriterio():new("Peso",MENOR,80) )

      //OsCadastros:addOrdem(   )
      //__TRACE(.F.)

      OsCadastros:pronto()

      ? "*** TESTE DE EOF C/ VARREDURA ***"
      ? "Criterio-->" + extraiCriterio(OsCadastros)
      OsCadastros:goPrimeiro()
      do while ( OsCadastros:isFim()!= .t. )
         ? OsCadastros:Object:numero
         ?? OsCadastros:Object:peso
         ?? OsCadastros:Object:endereco
         ?? Substr(OsCadastros:Object:nome,1,20)
         OsCadastros:goProximo()
      enddo
   recover
      Alert( IBroker():getErro():textError() )
   end sequence
   oDs:Desligar()
return nil

static function extraiCriterio(OsCadastros)
   local i,s
   s := " "
   for  i := 1 to OsCadastros:ListaCriterio():Count()
      s+=OsCadastros:ListaCriterio():subscript(i):asSentencaSQL()
   next
return s

