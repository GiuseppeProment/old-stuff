/*
อออออออออPARA DEBUGอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ */
#ifdef iDEBUG
#xcommand IASSERT(<exp>,<text>) => iif(<exp>,,alert(">>> falha IASSERT <<<;;"+<text>) )
#else
#xcommand IASSERT(<exp>,<text>) =>
#endif
/*
อออออออออPARA RASTREAMENTOออออออออออออออออออออออออออออออออออออออออออออออออออออ */
#ifdef iRASTREAR
   #stdout "<> iframework giuseppe (c) rastreamento ativado. link + idebug.obj <<<"
   #stdout "... lembre-se todos os RETURNS em maiusculo para rastreamento       <<<"
   #define RETURN RETORNE
   #include "mdClassy.ch"                        // alterada para dar rastro
   #command RETORNE <dado>   ;
      => rastroOUT()          ;
         ; return ( <dado> )
   #command COMENTE <msg>  => outstd( ":ฤ "+<msg>+chr(13)+chr(10) )
   #command TRACEON  => __trace(.t.)
   #command TRACEOFF => __trace(.f.)
#else
   #include "Class(y).ch"
   #command COMENTE <msg>  =>
   #command TRACEON  =>
   #command TRACEOFF =>
   #command RETORNE <dado>   => return ( <dado> )
#endif

/*
อออออออออDEFINES & COMMANDSอออออออออออออออออออออออออออออออออออออออออออออออออออ */
#define theBroker IBroker()
#xcommand DEFAULT <exp> TO <value> [, <expN> TO <valN> ] => ;
         <exp> := if(( valtype(<exp>)==valtype(<value>) .and. (<exp> != nil)), <exp>, <value>) ;
         [; <expN> := if(( valtype(<expN>)==valtype(<valN>) .and. (<expN> != nil)), <expN>, <valN>) ]

#xcommand THROW <exp> => (IBroker():getErro():settextError(<exp>),outerr(<exp>+chr(13)+chr(10)),Break(nil))
#xcommand SE <expSe> THROW <exp> => iif(<expSe>,(IBroker():getErro():settextError(<exp>),outerr(<exp>+chr(13)+chr(10)),Break(nil)),)
// da ptools
#xtranslate ISPAR( <n1> )                      => empty( <n1> % 2 )
#xtranslate ISIMPAR( <n1> )                    => !empty( <n1> % 2 )

#xcommand PROCESS => while .T.
#xcommand END PROCESS => end

#xcommand REPEAT => while .t.
#xcommand UNTIL <exp> => if <exp> ; exit ; end ; end

#xtranslate (<var> IS <type>)      =>  ( valtype(<var>) = <type> )
#xtranslate (<var> IS NOT <type>)  =>  ( valtype(<var>) != <type> )

/*
อออออออออENUM'Sอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
FAIXA RESERVADA : 1 a 9000
prefixo opcional 'e'
*/
//## Class: IKnowType--------------------
#define IsDouble        1
#define IsFloat         2
#define IsInt           3
#define IsShortInt      4
#define IsChar          5
#define IsCharArray     6
#define IsStringBlob    7
#define IsStringVar     8
#define IsStringFix     9
#define IsTimestamp    10
#define IsUnknow       11
//## Class: IEstadoGenerico-------------
#define gInicial       12
#define gInicializado  13
#define gInativo       14
#define gAtivo         15
#define gFinalizando   16
//## Class: IOperLogicoPrecedencia------
#define AND            17
#define OR             18
//## Class: IDirecaoFetch---------------
#define primeiro       19
#define ultimo         20
#define proximo        21
#define previo         22
#define reavalia       23
//## Class: IEstadoColecao
#define NOVA           24
#define PRONTA         25
#define TERMINADA      26
#define ERRO           27
//## Class: IEstadoStatement
#define novo           28
#define incompleto     29
#define completo       30
#define executando     31
#define executado      32
#define falhou         33
#define terminado      34
//## Class: IOperComparacao    IDX     Ex                       TIPOS
#define MAIOR          35   //  S      f > 2    f>"manteiga"    CND
#define MENOR          36   //  -      f < col  f<"A"           CND
#define MAIOROUIGUAL   37   //  S      f  >= 4                  CND
#define MENOROUIGUAL   38   //  -      f  <= .5                 CND
#define IGUAL          39   //  S      f  = 43                  CNDL
#define DIFERENTE      40   //  -      f != 5   f!="JACA"       CNDL
#define ENTREINCLUSIVO 41   //  S*     f BETWEEN 54,100         CND
#define ENTRE          41   //  S*     f BETWEEN 54,100         CND // sinonimo
#define ENTREEXCLUSIVO 42   //  S*     f BETWEEN 54,100         CND
#define SIMILAR        43   //  -      f LIKE "???NA"           C
#define DENTRO         44   //  -      f IN 32,100,303          CND
#define NONE           0
// lockAction
#define LOCK_TABLE     45
#define LOCK_LINE      46
#define ADD_LINE       47
// eDependencia
#define eFraca         48
#define eForte         49
// eCardinalidade
#define eZeroOuUm      50
#define eMuitos        51
/*
อออออออออWARNING CODEอออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
FAIXA RESERVADA : 10000 a 15000
PREFIXO OBRIGATORIO 'WC_'
EM MAIUSCULAS
*/
//  CLASSE: DEFAULT
#define WC_INDETERMINADO        10000
//  CLASSE: INativoDataStore
#define WC_AGREGADO_JA_EXISTE   10001    //qdo tentar adicionar um agr. a relacao
/*
อออออออออERROR CODE  อออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
FAIXA RESERVADA : 16000 a 20000
PREFIXO OBRIGATORIO 'EC_'
EM MAIUSCULAS
*/
//  CLASSE:
