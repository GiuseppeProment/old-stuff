#include "..\clipper\IPersist.ch"

function main()
   local oCriterio
   begin sequence
      ? ICriterio():new("codigo",MAIOR,10):asSentencaSQL()
      ? ICriterio():new("nome",IGUAL,"Rico"):asSentencaSQL()
      ? ICriterio():new("nome",ENTRE,"Beatriz","Mariana"):asSentencaSQL()
      ? ICriterio():new("Quitado",ENTRE,.t.,.f.):asSentencaSQL()
   recover
      Alert( IBroker():getErro():textError() )
   end sequence
return nil
