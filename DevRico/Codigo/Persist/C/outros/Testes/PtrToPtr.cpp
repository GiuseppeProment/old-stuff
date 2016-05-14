#include <iostream.h>
#include <iomanip.h>
#include <string.h>

void main(/*int argc,char **argv*/)
{
  /*
   for(int i=0;i<argc;i++)
      cout << *(argv+i) << endl;

   char linha[80] = "-----------------------------------";
   char nome[10];
   int nPos = 0;

   strcpy(nome,"rico ");
   strncpy((char*)linha+nPos,(const char*)nome,strlen(nome));
   nPos += strlen(nome);

   strcpy(nome,"Maria");
   strncpy((char*)linha+nPos,(const char*)nome,strlen(nome));
   nPos += strlen(nome);

   cout << linha << endl;
  */

  int **teste;
  *(teste+0) = new int(10);
  *(teste+1) = new int(20);
  *(teste+2) = new int(30);
  *(teste+3) = new int(40);
  cout << "sizeof :" << sizeof( teste ) << endl;
  cout << "1-" << **(teste+0) << endl;
  cout << "2-" << **(teste+1) << endl;
  cout << "3-" << **(teste+2) << endl;
  cout << "4-" << **(teste+3) << endl;
}
