#include <iostream.h>
#include <iomanip.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

class dummy
{
};

class ClassMap :public dummy
{
public:
   ClassMap() {};
   ~ClassMap() {};
private:
   int idade;
public:
   void setIdade( int value) {idade=value;};
   int getIdade( void ) {return idade;};
};


void main()
{

   //ClassMap.addMap( &ClassMap::setIdade,&ClassMap::getIdade,"Coluna");
   //ClassMap::addMap( void (*) (int),&ClassMap::getIdade,"Coluna");

   void (*pFuncTeste) (int) = &ClassMap::setIdade;

   void (ClassMap::*pFunc) (int) = &ClassMap::setIdade;
   ClassMap objeto;
   (objeto.*pFunc)(30);
   cout << objeto.getIdade() << endl;
   getch();
   return;
}

/*
Problema:

necessitamos um modo de associar e pegar valores de um objeto
sendo que esta tarefa seja executada por um objeto externo
os valores estao em membros de dados acessaveis por funcoes-membro
do tipo set/get :

void classe::setMembro( tipo );
tipo classe::getMembro( void );

isto ‚ necessario para nao violar o encapsulamento da classe e
para possibilitar a execucao correta de politicas durante o set/get.

teriamos o seguinte

classe PersistenteManager --set/get---> PersistenteObject


O problema ‚ que os set/get estariam definidos e implementados pela
classe que herda de PersistenteObject e de alguma forma a classe
PersistenteObject necessitaria acesso a esses set/get para entao ser
utilizada pelo PersistenteManager.

Um outro problema ‚ que o conhecimento desses set/get deveria estar
agrupado uma s¢ vez por classe, e nao por objeto.

IDEIAS HIPOTETICAS

poderiamos ter o seguinte :


Template
Class Mapa
{
void (ClasseNegocio::*pSet) (variant)
variant (ClasseNegocio::*pGet) (void),
}

Class PersistenteObject
{
  static Mapa oMapa;
  void setMembro(int numero, variant valor);
  variant getMembro(int numero);
  void addMapaMember(
        void (PersistenteObject::*pSet) (variant),
        variant (PersistenteObject::*pGet) (void),
        );
}
*/




