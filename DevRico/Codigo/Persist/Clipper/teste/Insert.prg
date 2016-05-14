#include "..\Clipper\IPersist.ch"

Request DBFCDX

function main()
   local oDs
   local oPessoa
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
      oPessoa:numero = 1444
      oPessoa:peso = 52
      oPessoa:nome = "Giuseppe"
      oPessoa:endereco = "Sao Paulo"
      oPessoa:save()

      oPessoa := Cadastro():new()
      oPessoa:numero = 0
      oPessoa:peso = 60
      oPessoa:nome = "Carmen"
      oPessoa:endereco = "Atibaia"
      oPessoa:save()

      oPessoa := Cadastro():new()
      oPessoa:numero = 0
      oPessoa:peso = 57
      oPessoa:nome = "Monica"
      oPessoa:endereco = "Sao Paulo"
      oPessoa:save()

      oPessoa := Cadastro():new()
      oPessoa:numero = 0
      oPessoa:peso = 10
      oPessoa:nome = "Caroline"
      oPessoa:endereco = "Atibaia"
      oPessoa:save()

      oPessoa := Cadastro():new()
      oPessoa:numero = 1446
      oPessoa:peso = 80
      oPessoa:nome = "Milton"
      oPessoa:endereco = "Sao Paulo"
      oPessoa:save()

   recover
      Alert( IBroker():getErro():textError() )
   end sequence
   oDs:Desligar()
return nil
