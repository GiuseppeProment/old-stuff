#include <string.h>

#include "Estatica.h"
// Implementacao

void
   IPersistente::setClassName( char * value ) {
   strcpy(className,value);
   return;
   }
const char*
   IPersistente::getClassName() {
   return className;
   }
char IPersistente::className[20];

void
   IPersistente::setTableName( char * value ) {
   strcpy(tableName,value);
   return;
   }
const char*
   IPersistente::getTableName() {
   return tableName;
   }
char IPersistente::tableName[20];

