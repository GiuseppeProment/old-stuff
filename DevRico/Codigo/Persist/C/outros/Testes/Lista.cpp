#include <iostream.h>
#include <iomanip.h>
#include <string.h>
#include <lista.h>

void error(char* texto)
{
   cout << texto << endl;
}

int sortString(char*& x,char*& y)
{
   if ( x < y )
      return 1;
   return 0;
}

int sortInt(int& x,int& y)
{
   if ( x < y )
     return 1;
   return 0;
}


void main()
{
   int i;

   Lista<int> theLista;

   int n1,n2,n3,n4,n5;
   n1=105;
   n2=200;
   n3=300;
   n4=400;
   n5=500;

   theLista.adiciona( n1 );
   theLista.adiciona( n2 );
   theLista.adiciona( n3 );
   theLista.adiciona( n4 );
   theLista.adiciona( n5 );
   cout << theLista[1] << endl;
   cout << theLista[2] << endl;
   cout << theLista[3] << endl;
   cout << theLista[4] << endl;
   cout << theLista[5] << endl;


   Lista<char*> theStrings;
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
   Lista<char*> anLista;
   char* x1 = "Aobjeto1";
   char* x2 = "Bobjeto2";
   char* x3 = "Cobjeto3";
   char* x4 = "Dobjeto4";
   anLista.adiciona(x1);
   anLista.adiciona(x2);
   anLista.adiciona(x3);
   anLista.adiciona(x4);


   cout << "-POSICAO------" << endl;
   cout << x1 <<" "<<  anLista.posicaoDe(x1) << endl;
   cout << x2 <<" "<<  anLista.posicaoDe(x2) << endl;
   cout << x3 <<" "<<  anLista.posicaoDe(x3) << endl;
   cout << x4 <<" "<<  anLista.posicaoDe(x4) << endl;
   cout << "count=" << anLista.count() << endl;

   cout << "-removeObjeto1------" << endl;
   anLista.removeObjeto(x1);
   for(i=1;i<=anLista.count();i++)
      cout << anLista[i] << endl;

  cout << "-TESTE SORT---" << endl;
  anLista.ordena(sortString);
  for(i=1;i<=anLista.count();i++)
     cout << anLista[i] << endl;
*/
   {

   Lista<int> theLista;

   int n1,n2,n3,n4,n5;
   n1=100;
   n2=200;
   n3=300;
   n4=400;
   n5=500;

   theLista.adiciona( n1 );
   theLista.adiciona( n2 );
   theLista.adiciona( n3 );
   theLista.adiciona( n4 );
   theLista.adiciona( n5 );
   cout << "-TESTE SORT NUMERICO 100 A 500---" << endl;
   theLista.ordena(sortInt);
   for(i=1;i<=theLista.count();i++)
         cout << theLista[i] << endl;

   }
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



