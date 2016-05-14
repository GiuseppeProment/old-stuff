Request DBFCDX

function main
   local ID
   Use Cadastro new shared via "DBFCDX"
   Cadastro->(OrdSetFocus(1))
   Cadastro->(dbGoTop())
   dbSelectar("Cadastro")
   altd()
   id := Cadastro->ID
   Cadastro->(dbSkip(+1))
   While !eof()
      // checar
      ? cadastro->ID
      if id == Cadastro->ID
         ? "*** ID repetido recno=" + str(recno())
         quit
      endif
      id := Cadastro->ID
      dbSkip(+1)
   enddo
return nil
