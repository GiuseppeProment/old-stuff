#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <iomanip.h>

class nada
{
  public:
  nada() {};
  ~nada() {};
};

struct nothing
{
};

void main()
{
   cout << "noth  " << sizeof(nothing ) << endl;
   cout << "nada  " << sizeof(nada ) << endl;
   cout << "int   " << sizeof(int  ) << endl;
   cout << "char  " << sizeof(char ) << endl;
   cout << "long  " << sizeof(long )  << endl;
   cout << "int*  " << sizeof(int* ) << endl;
   cout << "char* " << sizeof(char*) << endl;
   cout << "long* " << sizeof(long*)  << endl;
   cout << "void* " << sizeof(void*)  << endl;
   cout << "************************" << endl;
   cout << "int         " << sizeof( int  ) << endl;
   cout << "short int   " << sizeof(short int  ) << endl;
   cout << "double      " << sizeof(double ) << endl;
   cout << "float       " << sizeof(float )  << endl;
   cout << "long        " << sizeof(long )  << endl;
}
