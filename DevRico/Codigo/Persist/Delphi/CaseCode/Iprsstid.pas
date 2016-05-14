unit IPersistIDUnit;

interface

uses IUtil,Enums;

var
  m_sequencial:int;
  m_CRAE:int;
  m_RAP:int;

type
  IPersistID = class
  public
      constructor Create; overload;virtual;
      constructor Create(const right:IPersistID );overload;virtual;
      destructor Destroy;override;
      {const IPersistID & operator=(const IPersistID &right);}
      function assign( const right:IPersistID ):IPersistID;
      function generate:IPersistID;
      //	retorna o valor do id como string. pode ser algo como
      //	"12FC:3423A:FECD"
      function asString:string;
      //	para operações de leitura de um persistente o set deve
      //	receber o valor do id persistido.
      function setValue(valor:string):IPersistID;
      //	Chave de Resolução de Ambiguidade Externa
      //	valores válidos 0 a 128.
      class function CRAE:int ;
      class procedure setCRAE(const value:int );
      //## Attribute: RAP
      //	Resolução de Ambiguidade em Processo
      //	valores validos 0 a 32
      class procedure setRAP(const value:int);
  protected
      class function RAP:int;
  private
      class function sequencial:int;
      class procedure setsequencial(const value:int);
  private  //## implementation
      m_id:String;
      { static int m_sequencial; }
      { static int m_CRAE;       }
      { static int m_RAP;        }
end;

implementation

end.
