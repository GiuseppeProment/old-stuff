#include <iostream.h>
#include <iomanip.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "offset.h"

class dumy
{
protected:
char charDumy;
int numDumy;
};

class peca :public dumy
{
public:
       peca()
       { numeroUm=2000;
         numeroDois = 2056;
         primeiraLetra='A';
         segundaLetra='Z';
         strcpy(nome,"Giuseppe Enrico Proment");
         pint = new int(1024);
          };

       ~peca() { delete pint; };
private:
       int numeroUm;
       char primeiraLetra;
       void metodoII(int) {};
       char segundaLetra;
       int* pint;
       int numeroDois;
       char nome[30];
public:
       /*
       operator const char* ()
       { char* buffer = "000000000";
         return itoa(numero,buffer,10);
       };
       */
       void ExibeOffSet()
       {
        cout << endl << "=======================================================" << endl;
        cout <<  " teste de offset " << endl;
        cout << "=======================================================" << endl;
        //cout << "offsetof(peca,charDumy) = " << offsetof(peca,charDumy) << endl;
        //cout << "offsetof(peca,numDumy) = " << offsetof(peca,numDumy) << endl;
        cout << "offsetof(peca,numeroUm) = " << offsetof(peca,numeroUm) << endl;
        cout << "offsetof(peca,primeiraLetra) = " << offsetof(peca,primeiraLetra) << endl;
        cout << "offsetof(peca,segundaLetra) = " << offsetof(peca,segundaLetra) << endl;
        cout << "offsetof(peca,pint) = " << offsetof(peca,pint) << endl;
        cout << "offsetof(peca,numeroDois) = " << offsetof(peca,numeroDois) << endl;
        cout << "offsetof(peca,nome) = " << offsetof(peca,nome) << endl;

        //cout << "sizeof(peca::charDumy) = "      << sizeof(peca::charDumy) << endl;
        //cout << "sizeof(peca::numDumy) = "       << sizeof(peca::numDumy) << endl;
        cout << "sizeof(peca::numeroUm) = "      << sizeof(peca::numeroUm) << endl;
        cout << "sizeof(peca::primeiraLetra) = " << sizeof(peca::primeiraLetra) << endl;
        cout << "sizeof(peca::segundaLetra) = "  << sizeof(peca::segundaLetra) << endl;
        cout << "sizeof(peca::pint) = "          << sizeof(peca::pint) << endl;
        cout << "sizeof(peca::numeroDois) = "      << sizeof(peca::numeroDois) << endl;
        cout << "sizeof(peca::nome) = "          << sizeof(peca::nome) << endl;

        char* pEnder = (char*) this;

        cout << endl;
        cout << "valor numeroUm     =" << *( (int*)  (pEnder + offsetof(peca,numeroUm))) << endl;
        cout << "valor numeroDois   =" << *( (int*)  (pEnder + offsetof(peca,numeroDois))) << endl;
        cout << "valor primeiraLetra=" << *( (char*) (pEnder + offsetof(peca,primeiraLetra))) << endl;
        cout << "valor segundaLetra =" << *( (char*) (pEnder + offsetof(peca,segundaLetra))) << endl;
        cout << "valor nome         =" <<  ( (char*) (pEnder + offsetof(peca,nome))) << endl;
        int* ptr = (int*) (* (int*) (pEnder+offsetof(peca,pint)))  ;
        cout << "valor pint         =" << * ptr  << endl;

       };

};

/*
*** IDEIAS PARA IMPLEMENTA€AO ***

addAttribute(  size_t offset,
               int tamanho,
               Char* AtrName,
               AtrType tipo,
               int VarSize=0 )
enum AtrType
 { IsDouble,
   IsFloat,
   IsInt,
   IsShortInt,
   IsChar,
   IsCharArray,
   IsTimestamp,
   IsStringBlob,
   IsStringVar,
   IsStringFix,
   IsUnknow,
   // ponteiros
   IsDoublePointer,
   IsFloatPointer,
   IsIntPointer,
   IsShortIntPointer,
   IsCharPointer,
   IsCharArrayPointer,
   IsTimestampPointer,
   IsStringBlobPointer,
   IsStringVarPointer,
   IsStringFixPointer,
   IsUnknowPointer }

addAttribute(  offset(peca,idade),
               sizeof(peca::idade),
               "idade",
               IsInt );

addAttribute(  AtrInfo(peca,idade),
               "idade",
               IsInt );

addAttribute(  ADI(peca,idade),IsInt );

*/
void main()
{
   peca objeto;
/*
   char* pEnder = (char*) &objeto;
   cout << endl << "=======================================================" << endl;
   cout << "--- tamanho de objeto peca = "<<sizeof(objeto) << endl;
   cout << "--- tamanho de char = "<< sizeof(char) << endl;
   cout << "--- tamanho de char* = "<< sizeof(char*) << endl;
   cout << "--- tamanho de int* = "<< sizeof(int*) << endl;
   cout << "--- tamanho de peca = "<< sizeof(peca) << endl;
   cout << "numeroUm      = " <<  *( (int*) (pEnder + 0)) << endl;
   cout << "primeiraLetra = " <<  *( (char*) (pEnder + sizeof(int) )) << endl;
   cout << "segundaLetra = " <<  *( (char*) (pEnder +  (sizeof(int)+sizeof(char)) )) << endl;
   cout << "numeroDois = " <<  *( (int*) (pEnder +  (sizeof(int)+sizeof(char)+sizeof(char)) )) << endl;
   cout << "nome       = " <<  ( (char*) (pEnder +  (sizeof(int)+sizeof(char)+sizeof(char)+sizeof(int)) )) << endl;
   cout << "*** mudando nome para Carmen ***" << endl;
   strcpy( ( (char*) (pEnder +  (sizeof(int)+sizeof(char)+sizeof(char)+sizeof(int)) )),"Carmen Maria");
   cout << "numeroUm      = " <<  *( (int*) (pEnder + 0)) << endl;
   cout << "primeiraLetra = " <<  *( (char*) (pEnder + sizeof(int) )) << endl;
   cout << "segundaLetra = " <<  *( (char*) (pEnder +  (sizeof(int)+sizeof(char)) )) << endl;
   cout << "numeroDois = " <<  *( (int*) (pEnder +  (sizeof(int)+sizeof(char)+sizeof(char)) )) << endl;
   cout << "nome       = " <<  ( (char*) (pEnder +  (sizeof(int)+sizeof(char)+sizeof(char)+sizeof(int)) )) << endl;
   getch();
*/
   objeto.ExibeOffSet();
   return;
}
