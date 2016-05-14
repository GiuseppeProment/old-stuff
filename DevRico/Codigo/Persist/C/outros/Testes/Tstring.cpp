#include <IString.h>
#include "iostream.h"
#include "iomanip.h"


void main()
{
   IString PessoaA;
   IString PessoaB;
   PessoaA = "Giuseppe Enrico Proment Junior";
   PessoaB=PessoaA;
   cout << PessoaA << endl;
   cout << PessoaB << endl;
   PessoaB="jose mane";
   cout << PessoaB << endl;
   PessoaA=PessoaB;
   cout << PessoaA << endl;
   cout << PessoaB << endl;

  cout << "*** decl ***" << endl;
  IString var1 = "Giuseppe";
  IString var2 = "GiuseppeX";
  cout << "*** if== ***"<< endl;
  if ( var1 == var2 )
    cout << "var1==var2" <<endl;
  cout << "*** if!= ***"<< endl;
  if ( var1 != var2 )
    cout << "var1!=var2" <<endl;
  cout << "*** var1 ***"<< endl;
  if ( var1 == "Giuseppe" )
    cout << "var1=='Giuseppe'" <<endl;

  IString numero(100);
  cout << endl << endl;
  cout << "numero=" << numero << endl;
  numero = "Rico";
  cout << "numero=" << numero << endl;
  numero = 1024;
  cout << "numero=" << numero << endl;
  numero = "a";
  cout << "numero=" << numero << endl;

cout << "*****TESTE DE CONCATENACAO*****" << endl;
{
  IString A("Giuseppe");
  IString B("Enrico");

  A+=B;
  cout << A << endl;
  A+="Proment";
  cout << A << endl;
  A+=1203;
  A+="Final";
  cout << A << endl;
  A="XXX";
  cout << A << endl;

}
cout << "*****TESTE DE Soma a+b+c*****" << endl;
{
  IString A("Giuseppe");
  IString B("Enrico");

  cout << A+B << endl;
  cout << A+B+"rico" << endl;
}
cout << "*****TESTE DE Contatenacao*****" << endl;
{
  IString A;
  A+="'";
  cout << A << endl;
  A+="RUA";
  cout << A << endl;
  A+="'";
  cout << A << endl;
}
cout << "*****TESTE DE short int e int****" << endl;
{
  int xint = 100;
  short int xshort=250;
  IString A=xint;
  cout << A << endl;
  A=xshort;
  cout << A << endl;
}
cout << "*****TESTE DE double/float****" << endl;
{
  IString cStr;
  double v=-5046.56;
  float v1=-5046.56;
  cStr =  IString(v,6);
  cout << cStr << endl;
  cStr =  v1;
  cout << cStr << endl;
/*cStr =  "R$ ";
  cStr += v;
  cout << cStr << endl;*/
}

cout << "*****TESTE DE IsEmpty****" << endl;
{
  IString cStr1;
  cout << "'        '=" << cStr1.IsEmpty() << endl;
  cStr1 = "Rico";
  cout << "Rico      =" << cStr1.IsEmpty() << endl;
  IString cNum = 12.44;
  cout << "12.44     =" << cNum.IsEmpty() << endl;
}

}
