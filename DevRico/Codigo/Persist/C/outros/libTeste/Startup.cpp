#include <iostream.h>
#include <iomanip.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "Estatica.h"

// Startup Code

void main()
{
  theBroker::setClassName( "Giuseppe" );

  cout << theBroker::getClassName();

  theBroker::setClassName( "Novo nome" );

  cout << theBroker::getClassName() << endl;

  theBroker::setTableName( "Nome Tabela" );

  cout << theBroker::getTableName();

  theBroker::setTableName( "Nova Tabela" );

  cout << theBroker::getTableName() << endl;

}
