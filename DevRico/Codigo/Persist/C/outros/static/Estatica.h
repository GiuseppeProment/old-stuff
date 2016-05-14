// Interface
class  IPersistente
{
private:
   static char
      className[20],
      tableName[20];
public:
   static void
      setClassName(char * value),
      setTableName(char * value);
   static const char
      * getClassName(),
      * getTableName();
};

typedef IPersistente theBroker;
