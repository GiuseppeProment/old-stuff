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
      IBroker():addDataStore( oDs:=INativoDataStore():new():setRddDriver("DBFCDX"):setCaminho(" ") )
      IBroker():inicialize()
      oDs:ligar()

      // criar 1 pessoa
      oPessoa := Cadastro():new()
      oPessoa:numero := 111
      oPessoa:nome   := "Pessoa 1 que tem titulos"
      oPessoa:save()

      // criar 1. titulo para a pessoa
      oTitulo := Titulo():new()
      oTitulo:numero = 111
      oTitulo:save()
      // dar o titulo para pessoa guardar
      oPessoa:theTitulos:add(oTitulo)

      // criar 2. titulo para a pessoa
      oTitulo := Titulo():new()
      oTitulo:numero = 222
      oTitulo:save()
      // dar o titulo para pessoa guardar
      oPessoa:theTitulos:add(oTitulo)
      // erro dup.
      oPessoa:theTitulos:add(oTitulo)
      if IBroker():IsWarning()
         x := IBroker():getWarning()
         Alert( x:text()+";enviado por "+x:senderName()+";Code="+str(x:Code()) )
      endif

      ? "A Pessoa de codigo "+str(oPessoa:numero)+" possui os titulos:"
      oPessoa:theTitulos:goPrimeiro()
      while ! oPessoa:theTitulos:isFim()
         ?  oPessoa:theTitulos:object():numero
         ?? "  "
         ?? oPessoa:theTitulos:object():data
         oPessoa:theTitulos:goProximo()
      enddo

      // criar 2 pessoa
      oPessoa := Cadastro():new()
      oPessoa:numero := 222
      oPessoa:nome   := "Pessoa 2 que tem titulos"
      oPessoa:save()

      // criar 1. titulo para a pessoa
      oTitulo := Titulo():new()
      oTitulo:numero = 111
      oTitulo:save()
      // dar o titulo para pessoa guardar
      oPessoa:theTitulos:add(oTitulo)

      // criar 2. titulo para a pessoa
      oTitulo := Titulo():new()
      oTitulo:numero = 222
      oTitulo:save()
      // dar o titulo para pessoa guardar
      oPessoa:theTitulos:add(oTitulo)

      ? "A Pessoa de codigo "+str(oPessoa:numero)+" possui os titulos:"
      oPessoa:theTitulos:goPrimeiro()
      while ! oPessoa:theTitulos:isFim()
         ?  oPessoa:theTitulos:object():numero
         ?? "  "
         ?? oPessoa:theTitulos:object():data
         oPessoa:theTitulos:goProximo()
      enddo

      // remocao
      oPessoa:theTitulos:remove(oTitulo)

      ? "A Pessoa de codigo "+str(oPessoa:numero)+" possui os titulos:"
      oPessoa:theTitulos:goPrimeiro()
      while ! oPessoa:theTitulos:isFim()
         ?  oPessoa:theTitulos:object():numero
         ?? "  "
         ?? oPessoa:theTitulos:object():data
         oPessoa:theTitulos:goProximo()
      enddo

   recover
      Alert( IBroker():getErro():textError() )
   end sequence


   oDs:Desligar()
return nil

