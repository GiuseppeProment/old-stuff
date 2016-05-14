# ---------------------------------------------------------------------------
VERSION = BCB.04.04
# ---------------------------------------------------------------------------
!ifndef BCB
BCB = $(MAKEDIR)\..
!endif
# ---------------------------------------------------------------------------
PROJECT = IPersiste_CBuilder.dll
OBJFILES = IPersiste_CBuilder.obj ..\..\..\Projetos\PERSIST\codigo\CASECODE\Iassccao.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Iatrbuto.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Ibroker.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Ibsrvdor.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Iclcprss.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Iclssmap.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Icolecao.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Icritrio.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Idltsttm.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Idrcftch.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Idtstore.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Idtstrdb.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Idtstrrc.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Ierro.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Iknwtype.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Imdfystt.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Impclsst.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Imptrcln.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Insrtstt.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Intfcdor.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Intfcdrb.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Iordem.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Ipdtsttm.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Iprcmprc.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Iprlgcpr.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Iprsstid.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Iprsstnt.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Iqrysttm.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Istdclco.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Istdgnrc.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Istdsttm.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Istring.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Isttment.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Ivntntfc.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Lststrng.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\template.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Typevnto.obj \
  ..\..\..\Projetos\PERSIST\codigo\CASECODE\Funcoes.obj
RESFILES =
RESDEPEN = $(RESFILES)
LIBFILES = 
IDLGENFILES =
IDLFILES =
LIBRARIES = vcldbx40.lib vcldb40.lib vclx40.lib vcl40.lib
SPARELIBS = vcl40.lib vclx40.lib vcldb40.lib vcldbx40.lib
PACKAGES = VCL40.bpi VCLX40.bpi bcbsmp40.bpi VCLDB40.bpi ibsmp40.bpi VCLDBX40.bpi \
  QRPT40.bpi TEEUI40.bpi TEEDB40.bpi TEE40.bpi DSS40.bpi VCLMID40.bpi \
  NMFAST40.bpi INETDB40.bpi INET40.bpi dclocx40.bpi
PATHASM = .;
PATHCPP = .;..\..\..\Projetos\PERSIST\codigo\CASECODE
PATHPAS = .;
PATHRC = .;
DEBUGLIBPATH = $(BCB)\lib\debug
RELEASELIBPATH = $(BCB)\lib\release
SYSDEFINES = NO_STRICT
USERDEFINES = CBUILDER;GERAR_DLL
DEFFILE =
# ---------------------------------------------------------------------------
CFLAG1 = -I..\..\..\Projetos\PERSIST\codigo\CASECODE;..\..\Hpp;$(BCB)\include;$(BCB)\include\vcl \
  -WD -Od -w -Ve -r- -p -a4 -5 -k -y -v -vi- -D$(SYSDEFINES);$(USERDEFINES) -c \
  -b- -w-par -w-inl -Vx -tWM meus Documentos\IFrameWork\Hpp
  meus Documentos\projetos\persist\codigo\casecode;$(BCB)\include;$(BCB)\include\vcl
CFLAG2 =
CFLAG3 =
IDLCFLAGS = -I..\..\..\Projetos\PERSIST\codigo\CASECODE -I..\..\Hpp -I$(BCB)\include \
  -I$(BCB)\include\vcl -src_suffixcpp -DCBUILDER -DGERAR_DLL
PFLAGS = -U..\..\..\Projetos\PERSIST\codigo\CASECODE;$(BCB)\images\buttons;$(BCB)\projects;..\..\Import;$(BCB)\lib\obj;$(BCB)\lib;$(DEBUGLIBPATH) \
  -I..\..\..\Projetos\PERSIST\codigo\CASECODE;..\..\Hpp;$(BCB)\include;$(BCB)\include\vcl \
  -AWinTypes=Windows;WinProcs=Windows;DbiTypes=BDE;DbiProcs=BDE;DbiErrs=BDE \
  -DCBUILDER;GERAR_DLL -$YD -$W -$R -$Q -$O- -v \
  meus Documentos\IFrameWork\Import;\Meus Documentos\projetos\persist\codigo\casecode;$(BCB)\lib\obj;$(BCB)\lib \
  meus Documentos\IFrameWork\Hpp;\Meus \
  meus Documentos\projetos\persist\codigo\casecode;$(BCB)\include;$(BCB)\include\vcl \
  -JPHNV -M -JPHNE
RFLAGS = -i..\..\..\Projetos\PERSIST\codigo\CASECODE;..\..\Hpp;$(BCB)\include;$(BCB)\include\vcl \
  -DCBUILDER;GERAR_DLL meus Documentos\IFrameWork\Hpp;\ 
  meus Documentos\projetos\persist\codigo\casecode;$(BCB)\include;$(BCB)\include\vcl
AFLAGS = /i..\..\..\Projetos\PERSIST\codigo\CASECODE \
  /i"e:\meus documentos\projetos\persist\codigo\casecode" \
  /i"e:\meus Documentos\IFrameWork\Hpp" /i$(BCB)\include /i$(BCB)\include\vcl \
  /dCBUILDER /dGERAR_DLL /mx /w2 /zd
LFLAGS = -L..\..\..\Projetos\PERSIST\codigo\CASECODE;$(BCB)\images\buttons;$(BCB)\projects;..\..\Import;$(BCB)\lib\obj;$(BCB)\lib;$(DEBUGLIBPATH) \
  -aa -Tpd -x -Gi -v meus Documentos\IFrameWork\Import;\
  meus Documentos\projetos\persist\codigo\casecode;$(BCB)\lib\obj;$(BCB)\lib
IFLAGS =
LINKER = ilink32
# ---------------------------------------------------------------------------
ALLOBJ = c0d32.obj sysinit.obj $(OBJFILES)
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