Request DBFCDX

function main()
   local oDs
   local oPessoa
   local OsCadastros
   local oErro
   local oTitulo
   local x,nStart,nTempo
   ? "inicio..."
   AltD()

   set decimals to 5

   begin sequence
      oDs := INativoDataStore():new()
      oDs:setRddDriver("DBFCDX"):setCaminho(" ")

      IBroker():addDataStore( oDs )
      IBroker():inicialize()

      oDs:ligar()

      oTitulo := Titulo():new()
      oTitulo:numero = 2504
      oTitulo:save()

      nStart := Seconds()
      for x := 1 to 10000
         oPessoa := Cadastro():new()
         oPessoa:numero = x
         oPessoa:nome = "Pessoa "+str(x)
         oPessoa:save()
         oPessoa:theTitulos:add(oTitulo)
      next
      nTempo := Seconds()-nStart
      ? "컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴"
      ? "  Tempo para 100 transacoes = "+alltrim(str(nTempo))+ "s    "
      ?? alltrim(str(nTempo/100))+" s/transa"
      ? "컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴"

      OsCadastros := IColecao():new( Cadastro() )
      //OsCadastros:addCriterio( ICriterio() )
      //OsCadastros:addOrdem(   )
      OsCadastros:pronto()

      x := 0
      nStart := Seconds()
      OsCadastros:goPrimeiro()
      do while ( OsCadastros:isFim()!= .t. )
         OsCadastros:goProximo()
         x++
      enddo
      nTempo := Seconds()-nStart
      ? "컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴"
      ? "  Tempo para "+alltrim(str(x))+" fetch's    = "+alltrim(str(nTempo))+ "s    "
      ?? alltrim(str(nTempo/x))+" s/fetch"
      ? "컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴"

   recover using oErro
      Alert( oErro:textError() )
   end sequence


   oDs:Desligar()
return nil
