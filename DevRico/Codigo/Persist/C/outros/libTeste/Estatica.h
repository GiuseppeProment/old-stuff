// Interface
class  /*__declspec(dllexport)*/ IPersistente
{
private:
      static char
      className[20];
      static char
      tableName[20];
public:
   static void
      setClassName(char * value);
   static void
      setTableName(char * value);
   static const char
      * getClassName();
   static const char
      * getTableName();
};

typedef IPersistente theBroker;
