/*
    classy2.ch

    Class(y) v2.4 command definitions

    Copyright (c) 1991-1994 Anton van Straaten
*/

#xcommand   CLASS FUNCTION <funcName> [<static: STATIC>] ;
                =>                          ;
                <static> function <funcName>;;
                static self                 ;;
                local metaClass             ;;
                local nScope, initDone      ;;
                if self == NIL              ;;
                    initDone := .f.         ;;
                    nScope := CSY_HIDDEN

#ifndef CSY1

#xcommand   CREATE CLASS <className> [METACLASS <metaClass>] [<static: STATIC>] [FUNCTION <funcName>] ;
				=> ;
				CREATE CLASS <className> INHERIT Object [METACLASS <metaClass>] <static> [FUNCTION <funcName>]

#xcommand   CREATE CLASS <(className)> <sup: INHERIT, FROM> <superClass1> [, <superClassN>] [METACLASS <metaClass>] [<static: STATIC>] [FUNCTION <funcName>] ;
                => ;
                CLASS FUNCTION CSY_OPT([<funcName>,] <className>) <static>  ;;
                self := CSY_OPT([<metaClass>,] Class)():new(<(className)>, { <superClass1>() [, <superClassN>()] } ) ;;
                if !<.metaClass.>                                           ;;
                metaClass := Class():new(<(className)> + " class", { <superClass1>():class [, <superClassN>():class] } ) ;;
                end                                                         ;;
                #include "newclass.ch"

#xcommand   END CLASS [<noinit:NOINIT>] [<tFlat: FLATTEN>] [<fFlat: NOFLAT>] ;
                =>                          ;
                if !<.noinit.>              ;;
                self:makeClass( metaClass, if( <.tFlat.> == <.fFlat.>, NIL, <.tFlat.> ) ) ;;
                self:initClass()            ;;
                end; end; return self       ;;
                #include "endclass.ch"
#endif // !CSY1

#xcommand   ENDCLASS        =>  END CLASS

#define     CSY_EXPORTED            1
#define     CSY_PROTECTED           2
#define     CSY_HIDDEN              4
#define     CSY_ACCESS             16

#command    EXPORTED:       =>      nScope := CSY_EXPORTED
#command    VISIBLE:        =>      nScope := CSY_EXPORTED
#command    HIDDEN:         =>      nScope := CSY_HIDDEN
#command    PROTECTED:      =>      nScope := CSY_PROTECTED


// CSY_VARSCOPE(), CSY_METHSCOPE() and CSY_OPT() are internal translations used in other commands
#xtranslate CSY_VARSCOPE( <in>, <ro> )                =>  if( <in>, nScope, nScope + CSY_ACCESS ), if( <ro>, nScope * 2, nScope )
#xtranslate CSY_VARSCOPE( <in>, <ro>, <assignScope> ) =>  if( <in>, nScope, nScope + CSY_ACCESS ), CSY_ASSIGN <assignScope>

#xtranslate CSY_METHSCOPE( <ac> )    =>  if( <ac>, nScope + CSY_ACCESS, nScope )

#xtranslate CSY_DELEG( <cl>, <tgt> ) =>  if( <cl>, <tgt>():class, <(tgt)> )
#xtranslate CSY_DELEG( <cl> )        =>  if( <cl>, "CLASS", NIL )

#xtranslate CSY_OPT(<a>,<b>)    =>  <a>
#xtranslate CSY_OPT(<a>)        =>  <a>

// do not modify any of the following values
#xtranslate CSY_TYPE Array      =>  {}
#translate  CSY_TYPE Character  =>  ""
#xtranslate CSY_TYPE Block      =>  { || nil }
#xtranslate CSY_TYPE Numeric    =>  0.1
#xtranslate CSY_TYPE Date       =>  CTOD("")
#xtranslate CSY_TYPE Integer    =>  0
#xtranslate CSY_TYPE Logical    => .t.

// abbreviations
#xtranslate CSY_TYPE Num        =>  CSY_TYPE Numeric
#xtranslate CSY_TYPE Int        =>  CSY_TYPE Integer

#translate  CSY_ASSIGN EXPORTED     =>  CSY_EXPORTED
#translate  CSY_ASSIGN VISIBLE      =>  CSY_EXPORTED
#translate  CSY_ASSIGN PROTECTED    =>  CSY_PROTECTED
#translate  CSY_ASSIGN HIDDEN       =>  CSY_HIDDEN


/*
    VAR					Declare instance variable(s)
    VAR...IS [...TO]	Declare new name for variable [or delegated variable]
    VAR...TO			Declare delegated variable(s)
*/

#command    VAR <(name1)> [, <(nameN)>] [CLASS <class>] [TYPE <type>] [<ro: READONLY, RO, NOASSIGN>] [ASSIGN <assignScope>] [<in: INTERNAL>] ;
                => ;
				CsyAddVar( self, CSY_VARSCOPE( <.in.>, <.ro.> [, <assignScope>]  ), [<class>()] [CSY_TYPE <type>],, .f., <(name1)> [, <(nameN)>] )

#command    VAR <(name)> IS <(originalName)> [TO [<cl: CLASS>] [<(subordVar)>]] [<ro: READONLY, RO>] [CLASS <class>] [TYPE <type>] [ASSIGN <assignScope>] [<in: INTERNAL>] ;
                => ;
				CsyAddDeleg( self, CSY_VARSCOPE( <.in.>, <.ro.> [, <assignScope>] ), [<class>()] [CSY_TYPE <type>],, CSY_DELEG( <.cl.> [, <subordVar>] ), <(originalName)>, <(name)> )

#command    VAR <(name1)> [, <(nameN)>] TO [<cl: CLASS>] [<(subordVar)>] [<ro: READONLY, RO>] [ASSIGN <assignScope>] [<in: INTERNAL>] ;
                => ;
				CsyAddDeleg( self, CSY_VARSCOPE( <.in.>, <.ro.> [, <assignScope>] ),,, CSY_DELEG( <.cl.> [, <subordVar>] ),, <(name1)> [, <(nameN)>] )

/*
    CLASS VAR                   Declare class variable(s)
    CLASS VAR...IS [...TO]		Declare new name for class variable [or delegated class variable]
    CLASS VAR...TO              Declare delegated class variable(s)
*/

#xcommand   CLASS VAR <(name1)> [, <(nameN)>] [CLASS <class>] [TYPE <type>] [<ro: READONLY, RO, NOASSIGN>] [ASSIGN <assignScope>] [<sh: SHARED>] [<in: INTERNAL>] ;
                => ;
				CsyAddVar( metaClass, CSY_VARSCOPE( <.in.>, <.ro.> [, <assignScope>] ), [<class>()] [CSY_TYPE <type>],, <.sh.>, <(name1)> [, <(nameN)>] )

#command    CLASS VAR <(name)> IS <(originalName)> [TO [<cl: CLASS>] [<(subordVar)>]] [<ro: READONLY, RO>] [CLASS <class>] [TYPE <type>] [ASSIGN <assignScope>] [<in: INTERNAL>] ;
                => ;
				CsyAddDeleg( metaClass, CSY_VARSCOPE( <.in.>, <.ro.> [, <assignScope>] ), [<class>()] [CSY_TYPE <type>],, CSY_DELEG( <.cl.> [, <subordVar>] ), <(originalName)>, <(name)> )

#command    CLASS VAR <(name1)> [, <(nameN)>] TO [<cl: CLASS>] [<(subordVar)>] [<ro: READONLY, RO>] [ASSIGN <assignScope>] [<in: INTERNAL>] ;
                => ;
				CsyAddDeleg( metaClass, CSY_VARSCOPE( <.in.>, <.ro.> [, <assignScope>] ),,, CSY_DELEG( <.cl.> [, <subordVar>] ),, <(name1)> [, <(nameN)>] )

/*
    METHOD                      Declare method(s)
    METHOD...CONSTRUCTOR        Declare constructor method(s)
    CLASS METHOD                Declare class method(s)

    Note that the METHOD command used to begin the actual definition of a
    method (the method's code) is defined in ENDCLASS.CH.  METHOD is
    translated to DECL_METHOD in NEWCLASS.CH.
*/

#xcommand   DECL_METHOD <method1> [, <methodN>]	[<ac: ACCESS>]  ;
                =>                             	                ;
				CsyAddMeth( self, CSY_METHSCOPE( <.ac.> ), <"method1">, { || <method1>() } [, <"methodN">, { || <methodN>() }] )

#xcommand   METHOD <method1> [, <methodN>] <ct: CONSTRUCTOR, CTOR>  ;
                =>                                                  ;
                METHOD <method1> [, <methodN>]                      ;;
                CLASS MESSAGE <method1> [, <methodN>] IS altNew

#command    CLASS METHOD <method1> [, <methodN>] [<ac: ACCESS>] ;
                =>                                              ;
				CsyAddMeth( metaClass, CSY_METHSCOPE( <.ac.> ), <"method1">, { || <method1>() } [, <"methodN">, { || <methodN>() }] )

/*
    MESSAGE...METHOD                Declare message and corresponding method
    MESSAGE...METHOD CONSTRUCTOR    Declare constructor message & method
    MESSAGE...IS                    Declare new name(s) for existing message
    MESSAGE...TO                    Declare delegated message(s)
    MESSAGE...IS...TO               Declare delegated message
*/

#command    MESSAGE <message> METHOD <method> [<ac: ACCESS>] ;
                => ;
				CsyAddMeth( self, CSY_METHSCOPE( <.ac.> ), <"message">, { || <method>() } )

#command    MESSAGE <message> METHOD <method> <ct: CONSTRUCTOR, CTOR>   ;
                =>                                                      ;
                MESSAGE <message> METHOD <method>                       ;;
                CLASS MESSAGE <message> IS altNew

#command    MESSAGE <(name1)> [, <(nameN)>] IS <(originalName)>	[<ac: ACCESS>] ;
                => ;
				CsyAddDeleg( self, CSY_METHSCOPE( <.ac.> ),,,,, <(originalName)>, <(name1)> [, <(nameN)>] )

#command    MESSAGE <(name1)> [, <(nameN)>] TO [<cl: CLASS>] [<(subordVar)>] [<ac: ACCESS>] ;
                => ;
				CsyAddDeleg( self, CSY_METHSCOPE( <.ac.> ),,,, CSY_DELEG( <.cl.> [, <subordVar>] ),, <(name1)> [, <(nameN)>] )

#command    MESSAGE <(name)> IS <(targetName)> TO [<cl: CLASS>] [<(subordVar)>] [<ac: ACCESS>] ;
                => ;
				CsyAddDeleg( self, CSY_METHSCOPE( <.ac.> ),,,, CSY_DELEG( <.cl.> [, <subordVar>] ), <(targetName)>, <(name)> )

/*
    CLASS MESSAGE...METHOD          Declare class message and matching method
    CLASS MESSAGE...IS              Declare new name(s) for class message
    CLASS MESSAGE...TO              Declare delegated class message(s)
    CLASS MESSAGE...IS...TO         Declare delegated class message
*/

#xcommand   CLASS MESSAGE <message> METHOD <method> [<ac: ACCESS>] ;
                => ;
				CsyAddMeth( metaClass, CSY_METHSCOPE( <.ac.> ), <"message">, { || <method>() } )

#xcommand   CLASS MESSAGE <(name1)> [, <(nameN)>] IS <(originalName)> [<ac: ACCESS>] ;
                => ;
				CsyAddDeleg( metaClass, CSY_METHSCOPE( <.ac.> ),,,,, <(originalName)>, <(name1)> [, <(nameN)>] )

#xcommand   CLASS MESSAGE <(name1)> [, <(nameN)>] TO [<cl: CLASS>] [<(subordVar)>] [<ac: ACCESS>] ;
                => ;
				CsyAddDeleg( metaClass, CSY_METHSCOPE( <.ac.> ),,,, CSY_DELEG( <.cl.> [, <subordVar>] ),, <(name1)> [, <(nameN)>] )

#xcommand   CLASS MESSAGE <(name)> IS <(targetName)> TO [<cl: CLASS>] [<(subordVar)>] [<ac: ACCESS>] ;
                => ;
				CsyAddDeleg( metaClass, CSY_METHSCOPE( <.ac.> ),,,, CSY_DELEG( <.cl.> [, <subordVar>] ), <(targetName)>, <(name)> )


// Handle results of unnecessary declaration: METHOD <new | init> CTOR
#xcommand   CLASS MESSAGE <name: new, init> IS altNew    =>


/*
    some valid forms of super-call METHOD command:

        METHOD name, ()
        METHOD name(), ()
        METHOD name(...), ()
        METHOD name(...), (...)
        METHOD name(...), superName(...)
        METHOD name(...), superName()
*/

#xtranslate _CSY_CALLSUPER( <dfltName>([<ignore,...>])[()], [<name>]([<params,...>]) ) ;
                => ;
                qself():super:CSY_OPT([<name>,] <dfltName>)(<params>)

#command    METHOD [<type: PROCEDURE, FUNCTION>] <spec>, <superSpec>    ;
                =>                                                      ;
                __cyMethodType CSY_OPT([<type>,] FUNCTION) <spec>       ;;
                local self := (rastroIn(),_CSY_CALLSUPER( <spec>(), <superSpec> ), qself())

#command    METHOD <type: PROCEDURE, FUNCTION> <name>   ;
                =>                                      ;
                __cyMethodType <type> <name>            ;;
                local self := (rastroIN(),qself())


#define __cyMethodType

/*
    self is a reserved word inside Class(y) methods.
    :: is shorthand for message sends to self.
*/

#translate  ::  =>  self:

#translate  @:<methodName>([<param1>] [, <paramN>]) ;
                =>                                  ;
                <methodName>(_cyPshSelf(<param1>) [, <paramN>])


// eof classy2.ch

