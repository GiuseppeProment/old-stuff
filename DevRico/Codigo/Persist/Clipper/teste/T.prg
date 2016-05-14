Request DBFCDX
function main()
   local oDs
   local OsCadastros
   local x
   begin sequence
      oDs := INativoDataStore():new()
      oDs:setRddDriver("DBFCDX"):setCaminho(" ")
      IBroker():addDataStore( oDs )
      IBroker():inicialize()
      oDs:ligar()
      for x := 1 to 10000
         Cadastro():new():save()
         ? x
      next
   recover
      Alert( Ibroker():getErro():textError() )
   end sequence
   oDs:Desligar()
return nil



