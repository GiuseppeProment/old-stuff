#include "..\Clipper\IPersist.ch"

Request DBFCDX

function main()
   local oDs
   local oPessoa,oTitulo
   local OsCadastros
   local OsTitulos
   local x,nStart,nTempo
   ? "inicio..."
   AltD()
   begin sequence
      oDs := INativoDataStore():new()
      oDs:setRddDriver("DBFCDX"):setCaminho(" ")

      IBroker():addDataStore( oDs )
      IBroker():inicialize()

      oDs:ligar()

      oPessoa := Cadastro():new()
      oPessoa:numero = 1
      oPessoa:peso = 100.10
      oPessoa:nome = "Pessoa 1 Primeira"
      oPessoa:endereco = "Endereco 1"
      oPessoa:save()

      oPessoa:endereco = "Endereco 1 alter* deletado*"
      oPessoa:save()
      oPessoa:erase()

      oPessoa := Cadastro():new()
      oPessoa:numero = 2
      oPessoa:peso = 200.20
      oPessoa:nome = "Pessoa 2"
      oPessoa:endereco = "Endereco 2"
      oPessoa:save()

      oPessoa := Cadastro():new()
      oPessoa:numero = 3
      oPessoa:peso = 300.30
      oPessoa:nome = "Pessoa 3 Ultima"
      oPessoa:endereco = "Endereco 3"
      oPessoa:save()

      /*
      nStart := Seconds()
      for x := 1 to 100
         oPessoa := Cadastro():new()
         oPessoa:numero = x
         oPessoa:nome = "Pessoa "+str(x)
         oPessoa:save()
      next
      nTempo := Seconds()-nStart
      ? "컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴"
      ? "  Tempo para 100 transacoes = "+alltrim(str(nTempo))+ "s"
      ? "컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴"
      */

      __TRACE(.T.)
      OsCadastros := IColecao():new( Cadastro() )
      OsCadastros:addCriterio( ICriterio():new("Peso",MENOR,300) )
      OsCadastros:addCriterio( ICriterio():new(AND) )
      OsCadastros:addCriterio( ICriterio():new("Numero",MAIOR,1) )
      //OsCadastros:addOrdem(   )
      __TRACE(.F.)

      OsCadastros:pronto()

      OsCadastros:goPrimeiro()

      oPessoa := OsCadastros:Object()

      oPessoa:nome := "Pessoa 1 Primeira ALTERADA"
      oPessoa:save()


      OsCadastros:goPrimeiro()

      ?  "** goPrimeiro"
      ? "endereco:"
      ?? OsCadastros:Object():endereco
      ? "numero  :"
      ?? OsCadastros:Object():numero
      ? "peso    :"
      ?? OsCadastros:Object():peso
      ? "nome    :"
      ?? OsCadastros:Object():nome
      ? "-----------------------------------------"

      ? "*** TESTE DE EOF C/ VARREDURA ***"
      OsCadastros:goPrimeiro()
      do while ( OsCadastros:isFim()!= .t. )
         ? OsCadastros:Object:nome
         OsCadastros:goProximo()
      enddo
      OsCadastros:goPrimeiro()
      ? "----- goPrimeiro -----"
      ? "nome    :"
      ?? OsCadastros:Object():nome
      ? "-----------------------------------------"
      OsCadastros:goUltimo()
      ? "----- goUltimo -----"
      ? "nome    :"
      ?? OsCadastros:Object():nome
      ? "-----------------------------------------"
      OsCadastros:goAnterior()
      ? "----- goAnterior -----"
      ? "nome    :"
      ?? OsCadastros:Object():nome
      ? "-----------------------------------------"


      ? "**** TESTE COM TITULO ****"
      oTitulo := Titulo():new()
      oTitulo:numero = 111
      oTitulo:data = date()+1
      oTitulo:save()

      oTitulo := Titulo():new()
      oTitulo:numero = 222
      oTitulo:data = date()+2
      oTitulo:save()

      oTitulo := Titulo():new()
      oTitulo:numero = 333
      oTitulo:data = date()+3
      oTitulo:save()

      OsTitulos := IColecao():new( Titulo() )
      OsTitulos:pronto()
      ? "*** TESTE DE EOF C/ VARREDURA ***"
      OsTitulos:goPrimeiro()
      do while ( OsTitulos:isFim()!= .t. )
         ? OsTitulos:Object:numero
         ?? " "
         ?? OsTitulos:Object:data
         OsTitulos:goProximo()
      enddo

   recover
      Alert( IBroker():getErro():textError() )
   end sequence


   oDs:Desligar()
return nil
