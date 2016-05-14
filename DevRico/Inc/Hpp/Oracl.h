/* Copyright (c) Oracle Corporation 1994.  All Rights Reserved */

/*
    This source code is provided as a debugging aid for developers
    who have purchased Oracle Objects for OLE    .  Please see the
    online help for documentation of these classes.
*/

/*
    Oracle Objects for OLE     C++ Classes

    This file is the header for the basic classes.  That is, all the
    classes except OBound and OBinder (which use the obound.h header)

    CREATED    ********   11/22/94
    RWOOLARD	MODIFIED	03/20/95
    			bug#	262914	*ErrorText should return const char *
    					262723	Added overloaded OParameter.Add(..., OValue)
*/

/*
   07.04.99
   Modificado por: Giuseppe E. Proment Jr.
   Motivos :  - Definir WIN32 antes do primeiro uso da constante
              - nao precisa usar _Declspec(dllExport) nao vamos exportar nada
*/


#ifndef ORACL_ORACLE
#define ORACL_ORACLE

#include "windows.h"  // -- por Giuseppe define WIN32

// compiler specific defines
#ifdef WIN32
  #define  __huge
  #define OHUGESP
  #ifdef _MSC_VER
	  #define OEXPORT  __declspec(dllexport)
  #endif	  //	_MSC_VER
  #ifdef __BORLANDC__
     #define OEXPORT _export
  #endif     //	__BORLANDC__
#else     // WIN16
  #define OEXPORT _export
  #define OHUGESP
#endif    //WIN32


#ifndef OEXPORT
#define OEXPORT
#define OHUGESP
#endif

//#include "windows.h"   -- por Giuseppe

#undef OEXPORT          // -- por Giuseppe
#define OEXPORT         // -- por Giuseppe

#ifdef WIN32
# ifdef	ORAANSI
#  include <ole2.h>
#  include <winnls.h>
# endif
#else
# include <ole2.h>
# include <dispatch.h>
# ifdef _CID_MS15
#  define	OLECHAR char
# endif
#endif

// handy boolean type
typedef int oboolean;
// simple success return value
typedef int oresult;

// oresults can have one of the following values
#define OSUCCESS 0
#define OFAILURE 101

// error numbers returned by the ErrorNumber method.

// ----- error numbers
#define OERROR_NONE 0  // there isn't an error

#define OERROR_NOINTER 11  // we couldn't get a needed interface
#define OERROR_MEMORY 12  // memory allocation problem
#define OERROR_BADERR 13  // error in error handling (!)
#define OERROR_INVPARENT 14 // parent object on open is invalid (not open)
#define OERROR_SYSTEM 15     // some system error
#define OERROR_NOTOPEN 16   // attempt to use unopened object
#define OERROR_BADARG 17    // bad argument to routine
#define OERROR_INVRECORD 18 // the current record is invalid
#define OERROR_BADTYPE 19   // invalid operation on an Oracle data type

#define OERROR_ADVISEULINK 4096  // not an advisory connection
#define OERROR_DBCONNECT 4097  // connection not made
#define OERROR_POSITION 4098  // invalid database position
#define OERROR_NOFIELDNAME 4099  // field not found
#define OERROR_NOFIELDINDEX 4100  // invalid field index
#define OERROR_TRANSIP 4101  // transaction already in progress
#define OERROR_SCHEMAERR 4102  // error retreiving table definition
#define OERROR_ORLONERR 4103  // unable to make connection
#define OERROR_TRANSNIPC 4104  // commit when no transaction
#define OERROR_TRANSNIPR 4105 // rollback when no transaction
#define OERROR_NODSET 4106  // no such dynaset attached to connection
#define OERROR_INVROWNUM 4108  // invalid row reference
#define OERROR_TEMPFILE 4109  // error creating temporary file
#define OERROR_DUPSESSION 4110  // duplicate session name
#define OERROR_NOSESSION 4111   // no such session on detach
#define OERROR_NOOBJECTN 4112  // no object with specified name
#define OERROR_DUPCONN 4113  // duplicate connection
#define OERROR_NOCONN 4114  // no such connection on detach
#define OERROR_BFINDEX 4115  // invalid field index
#define OERROR_CURNREADY 4116  // cursor not ready
#define OERROR_NOUPDATES 4117  // updates not allowed
#define OERROR_NOTEDITING 4118  // not currently editing
#define OERROR_DATACHANGE 4119  // data has changed since last read
#define OERROR_NOBUFMEM 4120  // no memory for binding buffers
#define OERROR_INVBKMRK 4121  // invalid bookmark
#define OERROR_BNDVNOEN 4122  // bind variable not enabled
#define OERROR_DUPPARAM 4123  // duplicate parameter name
#define OERROR_INVARGVAL 4124  // invalid argument value
#define OERROR_INVFLDTYPE 4125  // invalid field type
#define OERROR_NOTIMPL 4126  // operation not implemented
#define OERROR_TRANSFORUP 4127  // For Update detected, no transaction
#define OERROR_NOTUPFORUP 4128  // For Update detected, not updatable
#define OERROR_TRANSLOCK 4129		// Commit/Rollback, but trans locked
#define OERROR_CACHEPARM 4130		// Invalid cache parameter
#define OERROR_FLDRQROWID 4131	// Field processing requires ROWID
#define OERROR_OUTOFMEMORY 4132	// Out of Memory
#define OERROR_POINTER 4133		// Invalid pointer
#define OERROR_INVNUMBER 4134		// Invalid number
#define OERROR_MAXSIZE 4135		// Maximum size execeeded.
#define OERROR_INVDIMENSION 4136	// Invalid Dimension
#define OERROR_MAXBUFFER 4137		// Maximum buffer exceeds 32512 bytes.
#define OERROR_ARRAYSIZ 4138		// Array elements not same size

// Find Methods parser errors
#define OERROR_STACK_OVER 4496	// Parser : Stack Overflow
#define OERROR_SYNTAX ERROR 4497	// Parser : Syntax Error near
#define OERROR_MISPLACED_PAREN 4498	// Parser : Misplaced parentheses
#define OERROR_MISPLACED_QUOTE 4499	// Parser : Misplaced quotation marks
#define OERROR_MISSING PAREN 4500	// Parser : WARNING - Missing closing Parenthesis
#define OERROR_EXPECTED_PAREN 4501	// Parser : Usually open parentheses expected
#define OERROR_PARSER_UNKNOWN 4502	// Parser : Unknown parser error condition
#define OERROR_INVALID_FUNCTION 4503	// Parser : Syntax not supported
#define OERROR_INVALID_COLUMN 4504	// Parser : Invalid Column Name
#define OERROR_MAX_TOKEN 4505			// Parser : Maximum Token size exceeded
#define OERROR_PARSER_DATA_TYPE 4506	// Parser : Unsupported data type
#define OERROR_UNEXPECTED_TOKEN 4507	// Parser : Unexpected token found
#define OERROR_END_OF_CLAUSE 4508	// Parser : Unexpected end of clause

// Find Methods runtime errors
#define OERROR_INVALID_INSTR 4516	// Runtime : Internal Error : Invalid Instruction
#define OERROR_STACK_ERROR 4517	// Runtime : Internal Error : Stack over/under-flow
#define OERROR_CONVERT_TYPES 4518	// Runtime : Invalid type conversion
#define OERROR_RUNTIME_DATA_TYPE 4519	// Runtime : Invalid datatype
#define OERROR_INVALID_SQL_ARG 4520	// Runtime : SQL function missing argument"
#define OERROR_INVALID_COMPARE 4521	// Runtime : Invalid comparison
#define OERROR_SELECT_DUAL 4522	// Runtime : Select from dual failed
#define OERROR_DUAL_DATATYPE 4523	// Runtime : Invalid datatype in Select from dual

#define OERROR_ECURSOR 8192  // cannot create cursor
#define OERROR_FETCHERR 8193  // error fetching field
#define OERROR_BINDERR 8194  // output data binding error
#define OERROR_SQLERR 8195  // error in SQL statement
#define OERROR_ESQLEXEC 8196  // SQL execution error
#define OERROR_COMERR 8197  // error during commit
#define OERROR_ROLERR 8198  // error during rollback
#define OERROR_OPTERR 8299  // error setting options
#define OERROR_CONNERR 8200  // unable to make connection
#define OERROR_RDBMSVER 8201		// Database version not available

// server data types
#define OTYPE_VARCHAR2	1
#define OTYPE_NUMBER	2
#define OTYPE_SINT	3
#define OTYPE_FLOAT	4
#define OTYPE_STRING    5
#define OTYPE_LONG	8
#define OTYPE_VARCHAR	9
#define OTYPE_ROWID	11
#define OTYPE_DATE	12
#define OTYPE_RAW	23
#define OTYPE_LONGRAW	24
#define OTYPE_UINT      68
#define OTYPE_CHAR	96
#define OTYPE_CHARZ	97
#define OTYPE_CURSOR    102
#define OTYPE_MSLABEL	106

// edit modes for dynaset
#define ODYNASET_EDIT_NOEDIT 0
#define ODYNASET_EDIT_EDITING 1
#define ODYNASET_EDIT_NEWRECORD 2

// parameter io types
#define OPARAMETER_INVAR 1
#define OPARAMETER_OUTVAR 2
#define OPARAMETER_INOUTVAR 3

// parameter status flags
#define OPARAMETER_STATUS_IN 1
#define OPARAMETER_STATUS_OUT 2
#define OPARAMETER_STATUS_AUTOENABLED 4
#define OPARAMETER_STATUS_ENABLED 8

// Options for creating database
#define ODATABASE_DEFAULT 0
#define ODATABASE_PARTIAL_INSERT 1
#define ODATABASE_ORAMODE 1			//	Same as PARTIAL_INSERT
#define ODATABASE_EDIT_NOWAIT 2
#define ODATABASE_NO_REFETCH	4
#define ODATABASE_NONBLOCK 8

// Options for creating dynaset
#define ODYNASET_DEFAULT 0
#define ODYNASET_NOBIND 1
#define ODYNASET_KEEP_BLANKS 2
#define ODYNASET_READONLY 4
#define ODYNASET_NOCACHE 8
#define ODYNASET_PARTIAL_INSERT 16	// V2DEV - Added
#define ODYNASET_ORAMODE 16			// V2DEV - Added
#define ODYNASET_NO_REFETCH	32
#define ODYNASET_NO_MOVEFIRST	64
#define ODYNASET_DIRTY_WRITE	128
#define	ODYNASET_VIEW_LONG		256 // V2.1 Added

// Options for creating  SqlStmt object
#define  OSQLSTMT_DEFAULT  0
#define  OSQLSTMT_NOBIND   1
// Bug 533086 : Add the option for forcing return on exec errors, for stmt object.
#define OSQLSTMT_FAILEXEC  2

// Threading Model Options
#define OSTARTUP_MULTITHREADED 0
#define OSTARTUP_APARTMENTTHREADED 1

// definitions of actions used in the callback routines
#define OADVISE_MOVE_FIRST 1
#define OADVISE_MOVE_NEXT 2
#define OADVISE_MOVE_PREV 3
#define OADVISE_MOVE_LAST 4
#define OADVISE_FIND_FIRST 5
#define OADVISE_FIND_NEXT 6
#define OADVISE_FIND_PREV 7
#define OADVISE_FIND_LAST 8
#define OADVISE_DELETE 9
#define OADVISE_ADDNEW 10
#define OADVISE_REFRESH 11
#define OADVISE_MOVE_TOMARK 12
#define OADVISE_ROLLBACK 13
//#define OADVISE_CLOSE	14
//#define OADVISE_DATAFIELDCHANGED 15
//#define OADVISE_SAVEDATA	16
//#define OADVISE_READDATA	17
#define OADVISE_UPDATE 18
//#define DATA_UNLOAD 19
#define OADVISE_MOVE_NEXTN 20
#define OADVISE_MOVE_PREVN 21
#define	OADVISE_MOVETO	22

#define OADVISE_FOUNDLAST 151
#define OADVISE_OTHER 99

// definitions for UpdateSource sources
enum	updsrcs {SYSDATE, TIMESTAMP, DATESTAMP, FUNCTION, OTHFIELD, STRLITERAL};

// forward references
class OEXPORT OSession;
class OEXPORT OSessionCollection;
class OEXPORT OClient;
class OEXPORT OConnection;
class OEXPORT OConnectionCollection;
class OEXPORT ODatabase;
class OEXPORT ODynaset;
class OEXPORT ODynasetMark;
class OEXPORT OField;
class OEXPORT OFieldCollection;
class OEXPORT OAdvise;
class OEXPORT OParameter;
class OEXPORT OParamArray;
class OEXPORT OParameterCollection;
class OEXPORT OSqlStmt;
class OOLEvar;


// ------------------------------------------------------------
// functions that are not class methods

// routine to initialize library.  Should be called once at startup
//    returns TRUE if successful, FALSE if not
oboolean OEXPORT OStartup(int ThreadingModel = OSTARTUP_APARTMENTTHREADED); // Threading Model Options


// routine to close down the library.  Should be called once
//   at application shutdown
void OEXPORT OShutdown(void);

// ----- OOracleObject -----------------------------------------------
// base object class
//   This class is the base for the OO4W classes.  By itself
//   it provides the error reporting interface and helps with
//   the various copying mechanisms

class OEXPORT OOracleObject
{
public:
    // constructors & destructors
    OOracleObject(void);
    OOracleObject(const OOracleObject &other);
    virtual ~OOracleObject(void);

    // overloaded operators
    OOracleObject &operator=(const OOracleObject &other);
    int operator==(const OOracleObject &other) const;
    int operator!=(const OOracleObject &other) const;

    // properties
    virtual oboolean IsOpen(void) const;

    // Error handling methods
    long  ErrorNumber(void) const; // return error "number"
//BUG #262914
    const char *LookupErrorText(long errnum) const;  // get error text for given error number
    const char *GetErrorText(void) const;  // get description of last error

    // set error information
    void  ErrorReset(void) const;  // reset error state to "no error"
    // SetOtherError and SetInternalError are really for internal use
    void  SetOtherError(void *otheri) const;
    void  SetInternalError(long errnum) const;

    void *Internal(void) const;

protected:
    // copy and cleanup routines (used to implement destructor, constructor, =)
    virtual oresult Copy(const OOracleObject &other);
    virtual oresult Cleanup(void);

    // access to object interface
	 oresult SetObjectInterface(void *obji, oboolean geterror = TRUE);

    oresult ActionStart(void) const;  // start of most of the methods
    oresult ActionGetStart(const OOracleObject *nobj) const;

private:
    void   *m_obji;   // pointer to object interface
    void   *m_erri;   // pointer to error interface of object
    void   *m_errotheri;  // pointer to error interface on other object
    char   *m_lasterrstring;  // last error string we've handled

    int     m_errstate;   // where did the error come from (values in implementation)
	long    m_errno;  // error number (see below, or negative for internal values)
};

// ----- OOracleCollection -----------------------------------------------
// general set class
// This is a base class used for collections of sessions, connections and fields
// It has no utility on its own.  Routines to get items from the collection are
// in the subclasses

class OEXPORT OOracleCollection : public OOracleObject
{
public:

    // constructors & destructors
    OOracleCollection(void);
    OOracleCollection(const OOracleCollection &other);
    ~OOracleCollection(void);

    // Open & Close
    oresult Close(void);   // close the set

    // overloaded operators
    OOracleCollection &operator=(const OOracleCollection &other);

	 // # of items in the set
    long   GetCount(void) const;

protected:
    oresult OpenSetHelper(void *idisp, void *otheri, unsigned char stype);  // finish the work of opening the set
    void  *GetItem(unsigned char stype, int index) const;
    void  *GetItem(oboolean oflag, const char *name) const;

private:
    unsigned char m_settype;

	 // internal helper routines
    oresult Cleanup(void);
	 oresult Copy(const OOracleCollection &other);
}                                                       ;

// ----- OSession -----------------------------------------------

class OEXPORT OSession : public OOracleObject
{
public:
    // construction & destruction
    OSession(void);
    OSession(const OSession &other); // copy constructor
    OSession(const char *sname);     // construct & open (NULL sname means open default session)
	 ~OSession(void);

    // open the session
    oresult Open(void);               // open the default session
    oresult Open(const char *sname);  // open a new session with specific name
    oresult Close(void);

    // Getting other objects
    OConnectionCollection GetConnections(void) const;
    OClient GetClient(void) const;
    static OSession GetNamedSession(const char *sname);

    // overloaded operators
    OSession &operator=(const OSession &other);

    // error handling
    long ServerErrorNumber(void) const;
    const char *GetServerErrorText(void) const;
    oresult ServerErrorReset(void);

    // get properties
    const char       *GetName(void) const;   // returns session name
    const char       *GetVersion(void) const;  // returns version of Oracle Objects

    // transaction operations
    oresult  BeginTransaction(void);  // start a transaction
    oresult  Commit(oboolean startnew = FALSE);   // commit (may start new transaction)
    oresult  Rollback(oboolean startnew = FALSE); // rolls back transaction (may start new transaction)
    oresult  ResetTransaction(void);  // unconditionally rollback (no advisories)

    // function used by other classes to construct OSession objects (don't call this!)
    oresult OpenHelper(void *idisp, void *otheri);

    // Memory Management Routines
    oresult  MemoryManager (int flags = -1);
    oresult  MemoryLog (int flags = -1);

private:
	 char      *m_name;
	 char      *m_errtext;
    char      *m_version;

    // internal helper routines
    oresult Cleanup(void);
    oresult Copy(const OSession &other);

};

// ----- OSessionCollection -----------------------------------------------

class OEXPORT OSessionCollection : public OOracleCollection
{
public:
    OSession GetSession(int index) const;

    // function used by other classes to construct OSessionCollection objects (don't call this!)
    oresult OpenHelper(void *idisp, void *otheri);  // finish the work of opening the set
};

// ----- ODatabase -----------------------------------------------

class OEXPORT ODatabase : public OOracleObject
{
public:
    // construction & destruction
    ODatabase(void);
    ODatabase(const ODatabase &other);
    ~ODatabase(void);

    // construct & open
	 ODatabase(const OSession &dbsess, const char *dbname, const char *username,
					const char *pwd, long options = ODATABASE_DEFAULT);
	 ODatabase(const char *dbname, const char *username, const char *pwd,
					long options = ODATABASE_DEFAULT);

	 // for the Open calls, if pwd is NULL it is assumed that username contains username/password

	 // open a database on a new session (implicitly creates a session)
	 oresult Open(const char *dbname, const char *username, const char *pwd,
						long options = ODATABASE_DEFAULT);
	 // open a database on an existing session
	 oresult Open(const OSession &dbsess, const char *dbname,
						const char *username, const char *pwd,
						long options = ODATABASE_DEFAULT);

	 oresult Close(void);

	 // getting other objects
	 OSession GetSession(void) const;
	 OConnection GetConnection(void) const;
	 OParameterCollection GetParameters(void) const;

    // overloaded operators
    ODatabase &operator=(const ODatabase &other);

    // execute an arbitrary SQL statement
    oresult ExecuteSQL(const char *sqlstmt) const;
    long	GetRowsProcessed(void) const;

	 // properties
    const char *GetName(void) const;     // return database name (from the connection)
    const char *GetConnectString(void) const;  // return connect string (without password)
	 const char *GetRdbmsVersion(void) const;		// V2DEV - returns RDBMS Version
	 long        GetOptions(void) const;

    // error handling
    long ServerErrorNumber(void) const;
    const char *GetServerErrorText(void) const;
    oresult ServerErrorReset(void);
    int ServerErrorSQLPos(void) const;

    // function used by other classes to construct ODatabase objects (don't call this!)
    oresult OpenHelper(void *idisp, void *otheri);

private:
    long	m_numrows;
    char    *m_dbname;
    char    *m_dbconnect;
	 char    *m_errtext;
	 char		*m_version;

    // internal helper routines
    oresult Cleanup(void);
    oresult Copy(const ODatabase &other);
	 oresult GetUserPwd(const char *username, const char *pwd, char **retname);
};

// ----- OValue -----------------------------------------------

class OEXPORT OValue
{
public:
    // construction & destruction
    OValue(void);
    OValue(int intval);       // allows OValue val = 3
    OValue(long longval);     // allows OValue val = 99L;
    OValue(double doubleval); // allows initialization with a double
    OValue(const char *tval); // allows initialization with a string
    OValue(const OValue &other); // copy constructor
	 OValue(short *intval);		// Added for ARRAYINSERT
	 OValue(int *intval);		// Added for ARRAYINSERT
	 OValue(long *longval);		// Added for ARRAYINSERT
	 OValue(double *doubleval);// Added for ARRAYINSERT
	 OValue(char **tval);		// Added for ARRAYINSERT
	 ~OValue(void);

	 OValue &operator=(const OValue &other);
    int operator==(const OValue &other) const;
    int operator!=(const OValue &other) const;

    // setting the data & type
    oresult Clear(void);    // clear the values
    oresult SetValue(const OValue &val);
    oresult SetValue(const char *val); // sets string value (copies text)
    oresult SetValue(int val);     // sets to int value
    oresult SetValue(long val);
    oresult SetValue(double dval); // sets to double value
    // oresult SetValue(const void *longval, long len);  // set to long value (not implemented)
	 oresult SetValue(char **val);		// Added for ARRAYINSERT
	 oresult SetValue(short *val);		// Added for ARRAYINSERT
	 oresult SetValue(int *val);		// Added for ARRAYINSERT
	 oresult SetValue(long *val);		// Added for ARRAYINSERT
	 oresult SetValue(double *dval);	// Added for ARRAYINSERT

    oboolean IsNull(void) const;  // returns TRUE if value is NULL (which includes uninitialized)

    // getting data (overloaded cast operators)
    operator int() const;
    operator long() const;
    operator const char *() const; // returns 0 if instance isn't string (no allocation)
    operator double() const;

    // conversions to implementation-specific representations (used by OField)
    oresult FromLocalType(void *localv);

    // helper routine for implementation of other classes
    void *Internal(void) const;
private:
    OOLEvar  *m_value;  // pointer to data representation
    // helper routines
    oresult Copy(const OValue &other);
    oresult Cleanup(void);
};

// ----- ODynaset -----------------------------------------------

class OEXPORT ODynaset : public OOracleObject
{
public:
    // construction & destruction
    ODynaset(void);
	 ODynaset(const ODynaset &other);
	 ODynaset(const ODatabase &odb, const char *sql_statement,
					long options = ODYNASET_DEFAULT);  // construct & open
//	Added for V2DEV custom dynaset
	ODynaset(const ODatabase &odb, const char *sql_statement,
					unsigned int slicesize, unsigned int perblock,
					unsigned int blocks, unsigned int fetchlimit,
					unsigned int fetchsize, long options = ODYNASET_DEFAULT);

	~ODynaset(void);

	// Open takes an SQL query as an argument.  This constructs a set of records which can
	//    then be accessed.
	oresult Open(const ODatabase &odb, const char *sql_statement,
						long options = ODYNASET_DEFAULT);  // creates a dynaset object
	//	Added for V2DEV custom dynaset
	oresult Open(const ODatabase &odb, const char *sql_statement,
					unsigned int slicesize, unsigned int perblock,
					unsigned int blocks, unsigned int fetchlimit,
					unsigned int fetchsize, long options = ODYNASET_DEFAULT);

	 // The clone of a dynaset is looking at the original data, but has a different navigational
    //    position.  Useful if you want to navigate through a set of data without side-effects
    oresult Close(void);

    // getting other objects
    ODynaset Clone(void) const;  // clone a dynaset
	 ODatabase GetDatabase(void) const;
    OFieldCollection GetFields(void) const;
    OSession GetSession(void) const;
	 OField GetField(int index) const;
    OField GetField(const char *fieldname) const;
	int GetFieldOriginalNameIndex(const char *fieldname) const;
    OConnection GetConnection(void) const;
	 ODynasetMark GetMark(void) const;  // bookmark at current position
    ODynasetMark GetLastModifiedMark(void) const;  // get bookmark at last modified record

	 // overloaded operators
    ODynaset &operator=(const ODynaset &other);

	 // the sql statement of the dynaset
    oresult SetSQL(const char *sql_statement);  // sets new sql statement for the dynaset
    const char *GetSQL(void) const;  // gets sql statement
	 oresult Refresh(void);  // refresh dynaset with current sql statement

    // navigation methods
	 oresult MoveFirst(void);   // go to first record in the set
    oresult MoveLast(void);    // go to last record in the set.  Note that this requires that all the records
                            //    in the query be downloaded from the server.  Can be expensive.

	 // MovePrev and MoveNext take a "gopast" argument.  If it is TRUE we can navigate to an
	 //   invalid record before the first or after the last.  If "gopast" is FALSE, then we won't
    //   go before the first or after the last record.
	 oresult MovePrev(oboolean gopast = TRUE);    // go to previous record
	 oresult MoveNext(oboolean gopast = TRUE);    // go to next record - the most frequently used
//	V2DEV - extra move methods
	 oresult MovePrevN(long rows, oboolean gopast = TRUE);    // go to previous (n) record
	 oresult MoveNextN(long rows, oboolean gopast = TRUE);    // go to next (n) record
	 oresult MoveRel(long rows, oboolean gopast = TRUE);    // go to relative record (n)
	 oresult MoveTo(long rownum, oboolean gopast = TRUE);    // go to record (n)

	 oresult MoveToMark(const ODynasetMark &odmark);  // repositions to mark (see ODynasetMark class)
    oboolean IsEOF(void) const;  // true if at end of dynaset.  Set to TRUE when you have tried to go
                                //     beyond the end
	 oboolean IsBOF(void) const;  // true if at begin of dynaset
    oboolean IsValidRecord(void) const;  // true if current row is valid

	 // editing
    oboolean CanTransact(void) const;  // returns TRUE if transaction processing is enabled
    oboolean CanUpdate(void) const;  // returns TRUE if this dynaset is updatable
	 int GetEditMode(void) const;  // returns current edit mode: ODYNASET_EDIT_*
	 oresult StartEdit(void);  // starts edit operation
	 oresult CancelEdit(void); // cancels edit operation
    oresult Update(void);     // finishes editing
	 oresult DuplicateRecord(void);  // copy the current record, adds a new record, sets field to copied values

	 // V2DEV -	Find methods
	 oresult FindFirst(const char *sql);
	 oresult FindNext(const char *sql = 0);
	 oresult FindPrevious(const char *sql = 0);
	 oresult FindLast(const char *sql);
	 oboolean NoMatch(void);							// TRUE if find failed

	 // V2DEV - Tunable cache and fetch parameters
	 unsigned int GetCacheSliceSize (void);
	 unsigned int GetCacheSlicePerBlock (void);
	 unsigned int GetCacheBlocks (void);
	 unsigned int GetFetchLimit (void);
	 unsigned int GetFetchSize (void);
	 void SetCacheSliceSize (unsigned int slice);
	 void SetCacheSlicePerBlock (unsigned int perblock);
	 void SetCacheBlocks (unsigned int blocks);
	 void SetFetchLimit (unsigned int flimit);
	 void SetFetchSize (unsigned int fsize);
	 oboolean IsCacheChanged(void);	// TRUE if cache or fetch parameters changed

	 // V2.1 dev - paste to clipboard functions
	 oresult PlsqlOpen(const ODatabase &odb, const char *sqlst,
							const char *CursorName, long options);
	 oresult PlsqlOpen(const ODatabase &odb, const char *sqlst, const char *CursorName,
					unsigned int slicesize, unsigned int perblock,
					unsigned int blocks, unsigned int fetchlimit,
					unsigned int fetchsize, long options);

	 // others
	 oboolean CanRefresh(void) const;  // our dynasets can always requery
    oboolean CanScroll(void) const;    // always scrollable
	 oboolean CanMark(void) const;

    long GetOptions(void) const;

    // record manipulation
    oresult AddNewRecord(void);
	 oresult DeleteRecord(void);

    // record access
	 int GetFieldCount(void) const;  // returns # of fields in a record
    long GetRecordCount(void) const;  // (dangerous!) gets total number of records in dynaset
                         // this routine downloads the entire dynaset to the client
	 int GetFieldIndex(const char *fieldname) const;  // gets the index of a field by name

	 // all the Get and Set methods can refer to a column either by index (column position in the
    //    query) or by fieldname (the name of the column as specified in the query).  GetFieldIndex
	 //    can be used to find the index of columns - which is more efficient
    short GetFieldServerType(int index) const;
    short GetFieldServerType(const char *fieldname) const;
	 short GetFieldPrecision(int index) const;
    short GetFieldPrecision(const char *fieldname) const;
    short GetFieldScale(int index) const;
	 short GetFieldScale(const char *fieldname) const;
    oboolean IsFieldNullOK(int index) const;
    oboolean IsFieldNullOK(const char *fieldname) const;

    long GetFieldSize(int index) const;
    long GetFieldSize(const char *fieldname) const;
	 long GetFieldServerSize(int index) const;
    long GetFieldServerSize(const char *fieldname) const;
	 oboolean IsFieldTruncated(int index) const;
	 oboolean IsFieldTruncated(const char *fieldname) const;

	 // get data from a field, either by name or index
    oresult GetFieldValue(int index, OValue *val) const;
	 oresult GetFieldValue(const char *fieldname, OValue *val) const;
    oresult GetFieldValue(int index, int *val) const;
	 oresult GetFieldValue(const char *fieldname, int *val) const;
    oresult GetFieldValue(int index, long *val) const;
	 oresult GetFieldValue(const char *fieldname, long *val) const;
    oresult GetFieldValue(int index, double *val) const;
	 oresult GetFieldValue(const char *fieldname, double *val) const;
	 oresult GetFieldValue(int index, char *val, unsigned short maxlen) const;
	 oresult GetFieldValue(const char *fieldname, char *val, unsigned short maxlen) const;
	 oresult GetFieldValue(int index, void __huge *longval, long len, long *readlen) const;
    oresult GetFieldValue(const char *fieldname, void __huge *longval, long len, long *readlen) const;
	 oresult GetFieldChunk(int index, void *chunkp, long offset, unsigned short len) const;
	 oresult GetFieldChunk(const char *fieldname, void *chunkp, long offset,
								unsigned short len) const;
	 oresult GetFieldChunk(int index, void *chunkp, long offset,
								unsigned short len, unsigned short *bytesread) const;
	 oresult GetFieldChunk(const char *fieldname, void *chunkp, long offset,
								unsigned short len, unsigned short *bytesread) const;

    // set data in a field, either by name or index
	 oresult SetFieldValue(int index, const OValue &val);
    oresult SetFieldValue(const char *fieldname, const OValue &val);
	 oresult SetFieldValue(int index, int val);
    oresult SetFieldValue(const char *fieldname, int val);
	 oresult SetFieldValue(int index, long val);
    oresult SetFieldValue(const char *fieldname, long val);
	 oresult SetFieldValue(int index, double val);
    oresult SetFieldValue(const char *fieldname, double val);
	 oresult SetFieldValue(int index, const char *val);
	 oresult SetFieldValue(const char *fieldname, const char *val);
	 oresult SetFieldValue(int index, const void __huge *longval, long len);
	 oresult SetFieldValue(const char *fieldname, const void __huge *longval, long len);
	 oresult AppendFieldChunk(int index, const void *chunkp, unsigned short len);
	 oresult AppendFieldChunk(const char *fieldname, const void *chunkp, unsigned short len);

	 // function used by other classes to construct ODynaset objects (don't call this!)
	 oresult OpenHelper(void *idisp, void *otheri);

	oboolean IsFirst(void) const;
	oboolean IsLast(void) const;

    oboolean IsFieldUpdatable(int index) const;
    oboolean IsFieldUpdatable(const char *fieldname) const;
    oresult SetFieldUpdatable(int index, oboolean update) const;
    oresult SetFieldUpdatable(const char *fieldname, oboolean update) const;

	// V2.1 dev - Original Column name and update source
	oresult GetOrigFieldIndex(const char *fieldname) const;
	const char * GetFieldName(int index) const;
	const char * GetFieldOriginalName(int index) const;
 	oresult UpdateSource(int index, updsrcs updsrc, const char *source=NULL);
	oresult UpdateSource(const char *fieldname, updsrcs updsrc, const char *source=NULL);
	oresult CopyToClipboard(long NumOfRows);
	oresult CopyToClipboard(long NumOfRows, char colsep, char rowsep);

private:
	 char *m_sqlstmt;  // the sql statement that creates the dynaset

	 // internal helper routines
	 oresult Copy(const ODynaset &other);
	 oresult Cleanup(void);
};

// ----- ODynasetMark -----------------------------------------------

class OEXPORT ODynasetMark : public OOracleObject
{
public:
	 // construction & destruction
    ODynasetMark(void); 
	 ODynasetMark(const ODynasetMark &other);
	 ~ODynasetMark(void);
    
    // overloaded operators
	 ODynasetMark &operator=(const ODynasetMark &other);
	 int operator==(const ODynasetMark &other) const;
    int operator!=(const ODynasetMark &other) const;

    
    oresult Close(void);
    oboolean IsOpen(void) const;
    
    // function used by other classes to construct ODynasetMark objects (don't call this!)
    oresult OpenHelper(void *idisp, void *otheri);
    
    char *Internal(void) const;

private:
    char  *m_markdata;  // holds data for bookmark
    
    oresult Cleanup(void);
};

// ----- OField -----------------------------------------------

class OEXPORT OField : public OOracleObject
{
public:
    // construction & destruction
    OField(void);
    OField(const OField &other);
    ~OField(void);              
    
    oresult Close(void);
    
    // overloaded operators
    OField &operator=(const OField &other);
    
    // other objects
    ODynaset GetDynaset(void) const;
    
    // properties
    const char *GetName(void) const; // returns name of field (user doesn't need to free)
    long GetSize(void) const;  // returns length of field
    long GetServerSize(void) const;  // returns length of a field (in server)
    short GetServerType(void) const;
    short GetPrecision(void) const;
    short GetScale(void) const;
    oboolean IsNullOK(void) const;
	 oboolean IsTruncated(void) const;
	 // V2DEV - Added
	 oboolean IsUpdatable(void) const;
	 oresult SetUpdatable(oboolean upd = TRUE);

    // field value
    oresult GetValue(OValue *val) const;  // returns value of field in val
    oresult GetValue(int *val) const;
    oresult GetValue(long *val) const;
    oresult GetValue(double *val) const;
    oresult GetValue(const char **val) const;
    oresult GetValue(void __huge *longval, long len, long *readlen) const;
    oresult SetValue(const OValue &val);  // sets the field to new value
    oresult SetValue(int val);
    oresult SetValue(long val);
    oresult SetValue(double val);
    oresult SetValue(const char *val);
    oresult SetValue(const void __huge *longval, long len); 
    
    // for long fields
    oresult AppendChunk(const void *chunkp, unsigned short numbytes);
	oresult GetChunk(const char **chunkp, long offset, unsigned short numbytes) const;
	// V2DEV - Added
	oresult GetChunk(const char **chunkp, long offset, unsigned short numbytes,
														unsigned short *bytesread) const;
	// Added for testing
	oresult GetChunk(const void **chunkp, long offset, unsigned short numbytes,
														unsigned short *bytesread) const;
	oresult AppendChunk(const char *chunkp, unsigned short numbytes);

    // getting data (overloaded cast operators)
    operator int() const;
    operator long() const;
    operator double() const;
    operator const char *() const;

    // function used by other classes to construct OField objects (don't call this!)
    oresult OpenHelper(void *idisp, void *otheri);

	// V2.1 dev - Original field name
	const char	*GetOriginalName (void) const;
	int			GetIndex () {return m_index;}
	oresult		UpdateSource(updsrcs updsrc, const char *source=NULL);

private:
    short  m_index;
    char  *m_name;
    char  *m_data;

    // internal helper routines
    oresult Copy(const OField &other);
    oresult Cleanup(void);   
};

// ----- OFieldCollection -----------------------------------------------

class OEXPORT OFieldCollection : public OOracleCollection
{
public:
    OField GetField(int index) const;
	OField GetField(const char *name) const;
	OField GetFieldOname(const char *oname) const;
     OField GetFieldByOriginalName(const char *oname) const;
    // function used by other classes to construct OFieldCollection objects (don't call this!)
    oresult OpenHelper(void *idisp, void *otheri);  // finish the work of opening the set
};

// ----- OClient -----------------------------------------------

class OEXPORT OClient : public OOracleObject
{
public:
    // construction & destruction
    OClient(void);
    OClient(const OClient &other);
    ~OClient(void);
    
    // use OSession::GetClient to open a client object
    oresult Close(void);

    // Getting other objects
    OSessionCollection GetSessions(void) const;  // get set of sessions

    // overloaded operators
    OClient &operator=(const OClient &other);
    
    // get properties
    const char        *GetName(void) const;        // returns client name.
    
    // function used by other classes to construct OSession objects (don't call this!)
    oresult OpenHelper(void *idisp, void *otheri);

private:
    char *m_name;

    // internal helper routines
    oresult Copy(const OClient &other);
    oresult Cleanup(void);   
};

// ----- OConnection -----------------------------------------------

class OEXPORT OConnection : public OOracleObject
{
public:
    // construction & destruction
    OConnection(void);
    OConnection(const OConnection &other);
    ~OConnection(void);
    
    oresult Close(void);
    
    // getting other objects
    OSession GetSession(void) const;   

    // overloaded operators
    OConnection &operator=(const OConnection &other);
    
    // properties
    const char  *GetConnectString(void) const;  // returns connect string
    const char  *GetDatabaseName(void) const;  // returns database name for this connection

 	// V2.1 dev - transactions on database
	oresult  BeginTransaction(void);  // start a transaction
    oresult  Commit(oboolean startnew = FALSE);   // commit (may start new transaction)
    oresult  Rollback(oboolean startnew = FALSE); // rolls back transaction (may start new transaction)
    oresult  ResetTransaction(void);  // unconditionally rollback (no advisories)
    
    // function used by other classes to construct OConnection objects (don't call this!)
    oresult OpenHelper(void *idisp, void *otheri);

private:
    char *m_dbname;
    char *m_dbconnect;

    // internal helper routines
    oresult Copy(const OConnection &other);
    oresult Cleanup(void);   
};
 
// ----- OConnectionCollection -----------------------------------------------

class OEXPORT OConnectionCollection : public OOracleCollection
{
public:
    OConnection GetConnection(int index) const;

    // function used by other classes to construct OConnectionCollection objects (don't call this!)
    oresult OpenHelper(void *idisp, void *otheri);  // finish the work of opening the set
};

// ----- OAdvise -----------------------------------------------
 
class OEXPORT OAdvise : public OOracleObject
{
public:
    OAdvise(void);
    OAdvise(const OAdvise &other);
    OAdvise(const ODynaset &odyn);  // construct & open
    virtual ~OAdvise(void);
    
    virtual oresult Open(const ODynaset &odyn);
    virtual oresult Close(void);  // stop the advisory sink
    
    // getting other objects
    ODynaset GetDynaset(void) const;
    
    // overloaded operators
    OAdvise &operator=(const OAdvise &other);
    
    // called before an action takes place
    virtual oboolean ActionRequest(int movekind);  // returns TRUE if action is allowed, FALSE to cancel
    
    // routines called to to notify that action occured
    virtual void ActionNotify(int movekind); 
    
    // routine called on status change
    virtual void StatusChange(int statuskind);
    
private:
    ODynaset  m_oDyn;    // the dynaset we're getting notices from
    
    // private helper routines
    oresult Cleanup(void);
	 oresult Copy(const OAdvise &other);
};

// ----- OParameter -----------------------------------------------

class OEXPORT OParameter : public OOracleObject
{
public:
    OParameter(void);
    OParameter(const OParameter &other);
    ~OParameter(void);
    
    oresult Close(void);
    
    // overloaded operators
    OParameter &operator=(const OParameter &other);
    
    // parameter name
    const char *GetName(void) const;

    short GetServerType(void) const;    

    const char *GetLastErrorText(void ) ;
    
    // parameter value
	 oresult GetValue(OValue *val) const;
	 oresult GetValue(int *val) const;
	 oresult GetValue(long *val) const;
	 oresult GetValue(double *val) const;
	 oresult GetValue(const char **val) const;

	 //V2.2 development , multiple cursor return
	 oresult GetValue(ODynaset *odyn) const;

    int	    Count (void);
    
    oresult Clear(void);
	 oresult SetValue(const OValue &val);
	 oresult SetValue(int val);
	 oresult SetValue(long val);
	 oresult SetValue(double val);
	 oresult SetValue(const char *val);
    oresult MinimumSize (long size);
    long    MinimumSize (void);

    // getting data (overloaded cast operators)
    operator int() const;
    operator long() const;
    operator double() const;
    operator const char *() const;

    // other status information
    int GetStatus(void) const;
    
    // enabling
    oresult AutoEnable(oboolean enable);

    // function used by other classes to construct OParameter objects (don't call this!)
    oresult OpenHelper(void *idisp, void *otheri);  // finish the work of opening the object

	// PL/SQL cursor return options
	void SetDynasetOption(long options);
	void SetDynasetCacheParams(long SliceSize, long perblock, long Blocks, long FetchLimit, long FetchSize) ;

private:
    char *m_name; 
    char *m_data;

    // internal helper routines
    oresult Copy(const OParameter &other);
	 oresult Cleanup(void);
	 oresult HelpGetValue(OOLEvar *tempv) const;
};

// ----- OParameterCollection -----------------------------------------------

class OEXPORT OParameterCollection : public OOracleObject
{
public:
    OParameterCollection(void);
    OParameterCollection(const OParameterCollection &other);
    ~OParameterCollection(void);
    
    oresult Close(void);
    
    // overloaded operators
    OParameterCollection &operator=(const OParameterCollection &other);
    
    // getting other objects
    OParameter GetParameter(int index) const;
    OParameter GetParameter(const char *pname) const;
	 OParamArray GetParamArray(int index) const;
	 OParamArray GetParamArray(const char *pname) const;

    // adding a new parameter
    OParameter Add(const char *name, int value, int iotype, int serverType);
    OParameter Add(const char *name, long value, int iotype, int serverType);
    OParameter Add(const char *name, double value, int iotype, int serverType);
    OParameter Add(const char *name, const char *value, int iotype, int serverType);     
//BUG #262723
    OParameter Add(const char *name, const OValue &value, int iotype, int serverType);     

// PL/SQL table parameter
	 OParamArray AddTable(const char *name, int iotype, int serverType, int Dimension, int Size=0 );
    
    // removing a parameter
    oresult Remove(int index);
    oresult Remove(const char *name);

    // getting # of parameters
	 long GetCount(void) const;

    // function used by other classes to construct OParameterCollection objects (don't call this!)
    oresult OpenHelper(void *idisp, void *otheri);  // finish the work of opening the set

private:
    // internal helper routines
	 int m_arraysize ;	// ARRAYINSERT
	 oresult Copy(const OParameterCollection &other);
    oresult Cleanup(void);   
	 OParameter AddHelp(const char *name, const OValue &val, int iotype, int serverType);
};

// V2DEV -- New classes
// ----- OSqlStmt -----------------------------------------------

class OEXPORT OSqlStmt : public OOracleObject
{
public:
    // construction & destruction
	 OSqlStmt(void);
	 OSqlStmt(const OSqlStmt &other);
	 OSqlStmt(const ODatabase &odb, const char *sql_statement,
					long options = OSQLSTMT_DEFAULT);  // construct & open
	 ~OSqlStmt(void);

	 // Open takes an SQL query as an argument.  This constructs a set of records which can
	 //    then be accessed.
	 oresult Open(const ODatabase &odb, const char *sql_statement,
						long options = OSQLSTMT_DEFAULT);  // creates a dynaset object
	 oresult Close(void);

    // getting other objects
	 ODatabase GetDatabase(void) const;
	 OSession GetSession(void) const;
	 OConnection GetConnection(void) const;

	 // overloaded operators
	 OSqlStmt &operator=(const OSqlStmt &other);
    
	 // the sql statement of the object
	 oresult SetSQL(const char *sql_statement);  // sets new sql statement
    const char *GetSQL(void) const;  // gets sql statement
	 oresult Refresh(void);  // refresh with current sql statement

	 // editing
	 oboolean CanTransact(void) const;  // returns TRUE if transaction processing is enabled
	 // others
	 oboolean CanRefresh(void) const;  // our sql statement can always requery

	 long GetOptions(void) const;
	 long GetRecordCount(void) const;

	 // function used by other classes to construct ODynaset objects (don't call this!)
	 oresult OpenHelper(void *idisp, void *otheri);

private:
	 char *m_sqlstmt;  // the sql statement that creates the dynaset

	 // internal helper routines
	 oresult Copy(const OSqlStmt &other);
	 oresult Cleanup(void);
};

// ----- OParamArray -----------------------------------------------

class OEXPORT OParamArray : public OOracleObject
{
public:
	 OParamArray(void);
	 OParamArray(const OParamArray &other);
	 ~OParamArray(void);
    
    oresult Close(void);
    
    // overloaded operators
	 OParamArray &operator=(const OParamArray &other);
    
    // parameter name
    const char *GetName(void) const;

    short GetServerType(void) const;    

	 const char *GetLastErrorText(void ) ;
    
    // parameter value
	 oresult GetValue(OValue *val, int index) const;
	 oresult GetValue(int *val, int index) const;
	 oresult GetValue(long *val, int index) const;
	 oresult GetValue(double *val, int index) const;
	 oresult GetValue(const char **val, int index) const;

	 oresult Clear(void);
	 oresult SetValue(const OValue &val, int index);
	 oresult SetValue(int val, int index);
	 oresult SetValue(long val, int index);
	 oresult SetValue(double val, int index);
	 oresult SetValue(const char *val, int index);
    oresult MinimumSize (long size);
    long    MinimumSize (void);

    // other status information
    int GetStatus(void) const;
	 const char *GetLastError(void);		// V2DEV - PL/SQL table parameters
	 int GetArraySize(void);

	 // enabling
    oresult AutoEnable(oboolean enable);

    // function used by other classes to construct OParameter objects (don't call this!)
    oresult OpenHelper(void *idisp, void *otheri);  // finish the work of opening the object

private:
    char *m_name; 
    char **m_data;
    char *m_errtext;

    // internal helper routines
	 oresult Copy(const OParamArray &other);
    oresult Cleanup(void);
	 oresult HelpGetValue(OOLEvar *tempv, unsigned int index) const;
};

#ifdef ORAANSI
typedef char FAR* BSTRA;
typedef BSTRA * LPBSTRA;

typedef struct FARSTRUCT tagVARIANTA  VARIANTA;
typedef struct FARSTRUCT tagVARIANTA FAR * LPVARIANTA;
typedef struct FARSTRUCT tagVARIANTA VARIANTARGA;
typedef struct FARSTRUCT tagVARIANTA FAR * LPVARIANTARGA;

struct FARSTRUCT tagVARIANTA{
	VARTYPE vt;
	unsigned short wReserved1;
	unsigned short wReserved2;
	unsigned short wReserved3;
	union {
	  unsigned char bVal;              /* VT_UI1                */
	  short    iVal;              /* VT_I2                */
	  long     lVal;              /* VT_I4                */
	  float    fltVal;            /* VT_R4                */
	  double       dblVal;            /* VT_R8                */
	  VARIANT_BOOL boolvar;              /* VT_BOOL              */
	  SCODE    scode;             /* VT_ERROR             */
	  CY       cyVal;             /* VT_CY                */
	  DATE     date;              /* VT_DATE              */
	  BSTRA    bstrVal;           /* VT_BSTR              */
	  IUnknown     FAR* punkVal;      /* VT_UNKNOWN           */
	  IDispatch  FAR* pdispVal;     /* VT_DISPATCH          */
	  SAFEARRAY   FAR* parray;       /* VT_ARRAY|*           */

	  unsigned char    FAR* pbVal;        /* VT_BYREF|VT_UI1       */
	  short    FAR* piVal;        /* VT_BYREF|VT_I2       */
	  long     FAR* plVal;        /* VT_BYREF|VT_I4       */
	  float    FAR* pfltVal;      /* VT_BYREF|VT_R4       */
	  double       FAR* pdblVal;      /* VT_BYREF|VT_R8       */
	  VARIANT_BOOL FAR* pbool;        /* VT_BYREF|VT_BOOL     */
	  SCODE    FAR* pscode;       /* VT_BYREF|VT_ERROR    */
	  CY       FAR* pcyVal;       /* VT_BYREF|VT_CY       */
	  DATE     FAR* pdate;        /* VT_BYREF|VT_DATE     */
	  BSTRA    FAR* pbstrVal;     /* VT_BYREF|VT_BSTR     */
	  IUnknown   FAR* FAR* ppunkVal;  /* VT_BYREF|VT_UNKNOWN  */
	  IDispatch FAR* FAR* ppdispVal; /* VT_BYREF|VT_DISPATCH */
	  SAFEARRAY FAR* FAR* pparray;   /* VT_BYREF|VT_ARRAY|*  */
	  VARIANT    FAR* pvarVal;      /* VT_BYREF|VT_VARIANT  */

	  void     FAR* byref;        /* Generic ByRef        */
	}
#if defined(NONAMELESSUNION) || (defined(_MAC) && !defined(__cplusplus) && !defined(_CID_MS20))
	u
#endif
	;
};


STDAPI_(BSTRA) SysAllocStringA(const char FAR*);
#define SysAllocStringLenA	SysAllocStringByteLen
inline void SysFreeStringA(BSTRA bstr) { SysFreeString((BSTR)bstr); }
STDAPI_(int)   SysReAllocStringLenA(BSTRA FAR*, const char FAR*, unsigned int);
HRESULT ConvertVariantToA(LPVARIANTA);
HRESULT ConvertVariantToW(LPVARIANT);

STDAPI  VariantChangeTypeA(	VARIANTARGA FAR* pvargDest,VARIANTARGA FAR* pvarSrc,unsigned short wFlags,VARTYPE vt);


#endif // WRAPPER
#endif // ORACL_ORACLE

