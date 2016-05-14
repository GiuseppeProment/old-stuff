#include <iostream.h>
#include <iomanip.h>
#include <string.h>
#include <listaPtr.h>

void error(char* texto)
{
   cout << texto << endl;
}

int sortString(char* x,char* y)
{
   if ( x < y )
      return 1;
   return 0;
}



void main()
{
   ListaPointer<char> theStrings;
   char* l1 = "giuseppe";
   char* l2 = "enrico";
   char* l3 = "proment";
   theStrings.adiciona(l1);
   theStrings.adiciona(l2);
   theStrings.adiciona(l3);

   cout << theStrings[1] << endl;
   cout << theStrings[2] << endl;
   cout << theStrings[3] << endl;

   // trocar
   theStrings.troca(1,3);

   cout << "--troca 1 por 3--" << endl;
   cout << theStrings[1] << endl;
   cout << theStrings[2] << endl;
   cout << theStrings[3] << endl;
   // remover 2
   theStrings.remove(2);

   cout << "--remove 2  --------" << endl;
   cout << theStrings[1] << endl;
   cout << theStrings[2] << endl;

   cout << endl << "** Teste de posicoes **"<< endl;
/*
   ListaPointer<char*> anListaPointer;
   char* x1 = "Aobjeto1";
   char* x2 = "Bobjeto2";
   char* x3 = "Cobjeto3";
   char* x4 = "Dobjeto4";
   anListaPointer.adiciona(x1);
   anListaPointer.adiciona(x2);
   anListaPointer.adiciona(x3);
   anListaPointer.adiciona(x4);


   cout << "-POSICAO------" << endl;
   cout << x1 <<" "<<  anListaPointer.posicaoDe(x1) << endl;
   cout << x2 <<" "<<  anListaPointer.posicaoDe(x2) << endl;
   cout << x3 <<" "<<  anListaPointer.posicaoDe(x3) << endl;
   cout << x4 <<" "<<  anListaPointer.posicaoDe(x4) << endl;
   cout << "count=" << anListaPointer.count() << endl;

   cout << "-removeObjeto1------" << endl;
   anListaPointer.removeObjeto(x1);
   for(i=1;i<=anListaPointer.count();i++)
      cout << anListaPointer[i] << endl;

  cout << "-TESTE SORT---" << endl;
  anListaPointer.ordena(sortString);
  for(i=1;i<=anListaPointer.count();i++)
     cout << anListaPointer[i] << endl;
*/
}
/*-----------------30/09/98 20:20-------------------
 OBSERVACOES

a declaracao de tipo

" tipo * & "

deve ser equivalente a

" const tipo *"

porque

" tipo &      "

‚ equivalente a

"const tipo * "

--------------------------------------------------*/



