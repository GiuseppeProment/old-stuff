#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <iomanip.h>

void main()
{
/*
   int ** ppInt;
   // alocar 10 ponteiros
   ppInt = (int**) malloc( 10 * sizeof( int* ) );

   for (int i=0;i<10;i++) *(ppInt+i) = new int(i*100);

   for (i=0;i<10;i++) cout << **(ppInt+i) << endl;


   // adicionar mais 5
   ppInt = (int**) realloc( ppInt ,15 * sizeof( int* ) );

   for (i=9;i<14;i++) *(ppInt+i) = new int(i*1000);

   for (i=9;i<14;i++) cout << **(ppInt+i) << endl;

   // destruir

   for (i=0;i<14;i++) delete *(ppInt+i);

   free(ppInt);
*/
   int * ppInt;
   // alocar 10 ponteiros
   ppInt = (int*) malloc( 10 * sizeof( int* ) );

   for (int i=0;i<10;i++) *(ppInt+i) = i*100;

   for (i=0;i<10;i++) cout << *(ppInt+i) << endl;


   // adicionar mais 5
   ppInt = (int*) realloc( ppInt ,15 * sizeof( int* ) );

   for (i=9;i<14;i++) *(ppInt+i) = i*1000;

   for (i=9;i<14;i++) cout << *(ppInt+i) << endl;

   // destruir

   free(ppInt);


}
