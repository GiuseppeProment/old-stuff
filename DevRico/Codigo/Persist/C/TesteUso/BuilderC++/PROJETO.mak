# ---------------------------------------------------------------------------
VERSION = BCB.04.04
# ---------------------------------------------------------------------------
!ifndef BCB
BCB = $(MAKEDIR)\..
!endif
# ---------------------------------------------------------------------------
PROJECT = PROJETO.exe
OBJFILES = PROJETO.obj UnitTela1.obj UnitAboutBox.obj UnitMaisInfo.obj cadastro.obj \
  UnitEdicao.obj
RESFILES = Projeto.res Rico.res
RESDEPEN = $(RESFILES) UnitTela1.dfm UnitAboutBox.dfm UnitMaisInfo.dfm UnitEdicao.dfm
LIBFILES = F:\Ferramentas\CBuilder4\Lib\bcbmm.lib
IDLGENFILES =
IDLFILES =
LIBRARIES = vcldbx40.lib vcldb40.lib vclx40.lib vcl40.lib
SPARELIBS = vcl40.lib vclx40.lib vcldb40.lib vcldbx40.lib
PACKAGES = VCL40.bpi VCLX40.bpi bcbsmp40.bpi VCLDB40.bpi ibsmp40.bpi VCLDBX40.bpi \
  QRPT40.bpi TEEUI40.bpi TEEDB40.bpi TEE40.bpi DSS40.bpi VCLMID40.bpi \
  NMFAST40.bpi INETDB40.bpi INET40.bpi dclocx40.bpi
PATHASM = .;
PATHCPP = .;
PATHPAS = .;
PATHRC = .;
DEBUGLIBPATH = $(BCB)\lib\debug
RELEASELIBPATH = $(BCB)\lib\release
SYSDEFINES = NO_STRICT
USERDEFINES = CBUILDER
DEFFILE =
# ---------------------------------------------------------------------------
CFLAG1 = -I"F:\Ferramentas\Borland Shared\Images\Buttons\";F:\Ferramentas\CBuilder4\Projects\;"..\..\Documentos\Testes Persistencia em VC\TesteVisual";.;"E:\Meus Documentos\IFrameWork\Import\";$(BCB)\projects;$(BCB)\include;$(BCB)\include\vcl;"E:\meus Documentos\Projetos\PERSIST\codigo\CASECODE\" \
  -O2 -H=$(BCB)\lib\vcl40.csm -w -Ve -r- -a4 -5 -k -y -v -vi- \
  -D$(SYSDEFINES);$(USERDEFINES) -c -b- -w-par -w-inl -Vx -tWM
CFLAG2 =
CFLAG3 =
IDLCFLAGS = -I"F:\Ferramentas\Borland Shared\Images\Buttons\" \
  -I"F:\Ferramentas\CBuilder4\Projects\" \
  -I"..\..\Documentos\Testes Persistencia em VC\TesteVisual" -I. \
  -I"E:\Meus Documentos\IFrameWork\Import\" -I$(BCB)\projects -I$(BCB)\include \
  -I$(BCB)\include\vcl -I"E:\meus Documentos\Projetos\PERSIST\codigo\CASECODE\" \
  -src_suffixcpp -DCBUILDER
PFLAGS = -U"F:\Ferramentas\Borland Shared\Images\Buttons\";F:\Ferramentas\CBuilder4\Projects\;"..\..\Documentos\Testes Persistencia em VC\TesteVisual";.;"E:\Meus Documentos\IFrameWork\Import\";$(BCB)\projects;$(BCB)\lib\obj;$(BCB)\lib;$(DEBUGLIBPATH) \
  -I"F:\Ferramentas\Borland Shared\Images\Buttons\";F:\Ferramentas\CBuilder4\Projects\;"..\..\Documentos\Testes Persistencia em VC\TesteVisual";.;"E:\Meus Documentos\IFrameWork\Import\";$(BCB)\projects;$(BCB)\include;$(BCB)\include\vcl;"E:\meus Documentos\Projetos\PERSIST\codigo\CASECODE\" \
  -AWinTypes=Windows;WinProcs=Windows;DbiTypes=BDE;DbiProcs=BDE;DbiErrs=BDE \
  -DCBUILDER -$YD -$W -$R -$Q -$O- -v -VF -JPHNV -M -JPHNE
RFLAGS = -i"F:\Ferramentas\Borland Shared\Images\Buttons\";F:\Ferramentas\CBuilder4\Projects\;"..\..\Documentos\Testes Persistencia em VC\TesteVisual";.;"E:\Meus Documentos\IFrameWork\Import\";$(BCB)\projects;$(BCB)\include;$(BCB)\include\vcl;"E:\meus Documentos\Projetos\PERSIST\codigo\CASECODE\" \
  -DCBUILDER -VF
AFLAGS = /i"F:\Ferramentas\Borland Shared\Images\Buttons" \
  /iF:\Ferramentas\CBuilder4\Projects \
  /i"..\..\Documentos\Testes Persistencia em VC\TesteVisual" /i. \
  /i"E:\Meus Documentos\IFrameWork\Import\" /i$(BCB)\projects /i$(BCB)\include \
  /i$(BCB)\include\vcl /i"E:\meus Documentos\Projetos\PERSIST\codigo\CASECODE\" \
  /dCBUILDER /mx /w2 /zd
LFLAGS = -L"F:\Ferramentas\Borland Shared\Images\Buttons\";F:\Ferramentas\CBuilder4\Projects\;"..\..\Documentos\Testes Persistencia em VC\TesteVisual";.;"E:\Meus Documentos\IFrameWork\Import\";$(BCB)\projects;$(BCB)\lib\obj;$(BCB)\lib;$(DEBUGLIBPATH) \
  -aa -Tpe -x -w -v
IFLAGS =
LINKER = ilink32
# ---------------------------------------------------------------------------
ALLOBJ = c0w32.obj sysinit.obj $(OBJFILES)
ALLRES = $(RESFILES)
ALLLIB = $(LIBFILES) $(LIBRARIES) import32.lib cp32mt.lib
# ---------------------------------------------------------------------------
.autodepend

!ifdef IDEOPTIONS

[Version Info]
IncludeVerInfo=0
AutoIncBuild=0
MajorVer=1
MinorVer=0
Release=0
Build=0
Debug=0
PreRelease=0
Special=0
Private=0
DLL=0
Locale=1046
CodePage=1252

[Version Info Keys]
FileVersion=1.0.0.0

[HistoryLists\hlIncludePath]
Count=12
Item0=F:\Ferramentas\Borland Shared\Images\Buttons;F:\Ferramentas\CBuilder4\Projects;..\..\Documentos\Testes Persistencia em VC\TesteVisual;.;E:\Meus Documentos\IFrameWork\Import\;$(BCB)\projects;$(BCB)\include;$(BCB)\include\vcl;E:\meus Documentos\Projetos\PERSIST\codigo\CASECODE\
Item1=..\..\Documentos\Testes Persistencia em VC\TesteVisual;.;E:\Meus Documentos\IFrameWork\Import\;$(BCB)\projects;$(BCB)\include;$(BCB)\include\vcl;E:\meus Documentos\Projetos\PERSIST\codigo\CASECODEItem1=..\..\Documentos\Testes Persistencia em VC\TesteVisual;.;E:\Meus Documentos\IFrameWork\Import\;$(BCB)\projects;$(BCB)\include;$(BCB)\include\vcl;E:\meus Documentos\Projetos\PERSIST\codigo\CASECODEItem1=..\..\Documentos\Testes Persistencia em VC\TesteVisual;.;E:\Meus Documentos\IFrameWork\Import\;$(BCB)\projects;$(BCB)\include;$(BCB)\include\vcl;E:\meus Documentos\Projetos\PERSIST\codigo\CASECODEItem1=..\..\Documentos\Testes Persistencia em VC\TesteVisual;.;E:\Meus Documentos\IFrameWork\Import\;$(BCB)\projects;$(BCB)\include;$(BCB)\include\vcl;E:\meus Documentos\Projetos\PERSIST\codigo\CASECODEItem1=..\..\Documentos\Testes Persistencia em VC\TesteVisual;.;E:\Meus Documentos\IFrameWork\Import\;$(BCB)\projects;$(BCB)\include;$(BCB)\include\vcl;E:\meus Documentos\Projetos\PERSIST\codigo\CASECODEItem1=..\..\Do
Item2=
Item3=
Item4=
Item5=
Item6=
Item7=
Item8=
Item9=
Item10=
Item11=

[HistoryLists\hlLibraryPath]
Count=4
Item0=F:\Ferramentas\Borland Shared\Images\Buttons;F:\Ferramentas\CBuilder4\Projects;..\..\Documentos\Testes Persistencia em VC\TesteVisual;.;E:\Meus Documentos\IFrameWork\Import\;$(BCB)\projects;$(BCB)\lib\obj;$(BCB)\lib
Item1=..\..\Documentos\Testes Persistencia em VC\TesteVisual;.;E:\Meus Documentos\IFrameWork\Import\;$(BCB)\projects;$(BCB)\lib\obj;$(BCB)\lib
Item2=.;E:\Meus Documentos\IFrameWork\Import\;.;$(BCB)\projects;$(BCB)\lib\obj;$(BCB)\lib
Item3=E:\Meus Documentos\IFrameWork\Import;.;$(BCB)\projects;$(BCB)\lib\obj;$(BCB)\lib

[HistoryLists\hlConditionals]
Count=1
Item0=CBUILDER

[HistoryLists\hlUnitAliases]
Count=1
Item0=WinTypes=Windows;WinProcs=Windows;DbiTypes=BDE;DbiProcs=BDE;DbiErrs=BDE

[Debugging]
DebugSourceDirs=

[Parameters]
RunParams=
HostApplication=
RemoteHost=
RemotePath=
RemoteDebug=0

[Compiler]
InMemoryExe=0
ShowInfoMsgs=0

[CORBA]
AddServerUnit=1
AddClientUnit=1
PrecompiledHeaders=1

!endif

$(PROJECT): $(IDLGENFILES) $(OBJFILES) $(RESDEPEN) $(DEFFILE)
    $(BCB)\BIN\$(LINKER) @&&!
    $(LFLAGS) +
    $(ALLOBJ), +
    $(PROJECT),, +
    $(ALLLIB), +
    $(DEFFILE), +
    $(ALLRES)
!

.pas.hpp:
    $(BCB)\BIN\dcc32 $(PFLAGS) { $** }

.pas.obj:
    $(BCB)\BIN\dcc32 $(PFLAGS) { $** }

.cpp.obj:
    $(BCB)\BIN\bcc32 $(CFLAG1) $(CFLAG2) -o$* $* 

.c.obj:
    $(BCB)\BIN\bcc32 $(CFLAG1) $(CFLAG2) -o$* $**

.rc.res:
    $(BCB)\BIN\brcc32 $(RFLAGS) $<
#-----------------------------------------------------------------------------
