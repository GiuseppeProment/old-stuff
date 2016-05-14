# ---------------------------------------------------------------------------
VERSION = BCB.04.04
# ---------------------------------------------------------------------------
!ifndef BCB
BCB = $(MAKEDIR)\..
!endif
# ---------------------------------------------------------------------------
PROJECT = IPersiste_CBuilder.dll
OBJFILES = IPersiste_CBuilder.obj ..\..\Case\Iassccao.obj ..\..\case\Iatrbuto.obj \
  ..\..\case\Ibroker.obj ..\..\case\Ibsrvdor.obj ..\..\case\Iclcprss.obj \
  ..\..\case\Iclssmap.obj ..\..\case\Icolecao.obj ..\..\case\Icritrio.obj \
  ..\..\case\Idltsttm.obj ..\..\case\Idrcftch.obj ..\..\case\Idtstore.obj \
  ..\..\case\Idtstrdb.obj ..\..\case\Idtstrrc.obj ..\..\case\Ierro.obj \
  ..\..\case\Iknwtype.obj ..\..\case\Imdfystt.obj ..\..\case\Impclsst.obj \
  ..\..\case\Imptrcln.obj ..\..\case\Insrtstt.obj ..\..\case\Intfcdor.obj \
  ..\..\case\Intfcdrb.obj ..\..\case\Iordem.obj ..\..\case\Ipdtsttm.obj \
  ..\..\case\Iprcmprc.obj ..\..\case\Iprlgcpr.obj ..\..\case\Iprsstid.obj \
  ..\..\case\Iprsstnt.obj ..\..\case\Iqrysttm.obj ..\..\case\Istdclco.obj \
  ..\..\case\Istdgnrc.obj ..\..\case\Istdsttm.obj ..\..\case\Istring.obj \
  ..\..\case\Isttment.obj ..\..\case\Ivntntfc.obj ..\..\case\Lststrng.obj \
  ..\..\case\template.obj ..\..\case\Typevnto.obj ..\..\case\Funcoes.obj
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
PATHCPP = .;..\..\Case
PATHPAS = .;
PATHRC = .;
DEBUGLIBPATH = $(BCB)\lib\debug
RELEASELIBPATH = $(BCB)\lib\release
SYSDEFINES = NO_STRICT
USERDEFINES = CBUILDER;GERAR_DLL
DEFFILE =
# ---------------------------------------------------------------------------
CFLAG1 = -I..\..\Case;..\..\..\..\..\..;..\..\..\Projetos\PERSIST\codigo\CASECODE;..\..\Hpp;$(BCB)\include;$(BCB)\include\vcl \
  -WD -Od -H=$(BCB)\lib\vcl40.csm -w -Vs -Ve -r- -a4 -5 -k -y -v -vi- \
  -D$(SYSDEFINES);$(USERDEFINES) -c -b- -w-par -w-inl -Vx -tWM \
  Documentos\IFrameWork\Hpp;\Meus \
  Documentos\projetos\persist\codigo\casecode;$(BCB)\include;$(BCB)\include\vcl
CFLAG2 =
CFLAG3 =
IDLCFLAGS = -I..\..\Case -I..\..\..\..\..\.. -I..\..\..\Projetos\PERSIST\codigo\CASECODE \
  -I..\..\Hpp -I$(BCB)\include -I$(BCB)\include\vcl -src_suffixcpp -DCBUILDER \
  -DGERAR_DLL
PFLAGS = -U..\..\Case;..\..\..\..\..\..;..\..\..\Projetos\PERSIST\codigo\CASECODE;$(BCB)\images\buttons;$(BCB)\projects;..\..\Import;$(BCB)\lib\obj;$(BCB)\lib;$(DEBUGLIBPATH) \
  -I..\..\Case;..\..\..\..\..\..;..\..\..\Projetos\PERSIST\codigo\CASECODE;..\..\Hpp;$(BCB)\include;$(BCB)\include\vcl \
  -AWinTypes=Windows;WinProcs=Windows;DbiTypes=BDE;DbiProcs=BDE;DbiErrs=BDE \
  -DCBUILDER;GERAR_DLL -$YD -$W -$R -$Q -$O- -v \
  Documentos\IFrameWork\Import;\Meus Documentos\projetos\persist\codigo\casecode;$(BCB)\lib\obj;$(BCB)\lib \
  Documentos\IFrameWork\Hpp;\Meus \
  Documentos\projetos\persist\codigo\casecode;$(BCB)\include;$(BCB)\include\vcl \
  -JPHNV -M -JPHNE
RFLAGS = -i..\..\Case;..\..\..\..\..\..;..\..\..\Projetos\PERSIST\codigo\CASECODE;..\..\Hpp;$(BCB)\include;$(BCB)\include\vcl \
  -DCBUILDER;GERAR_DLL Documentos\IFrameWork\Hpp;\Meus \
  Documentos\projetos\persist\codigo\casecode;$(BCB)\include;$(BCB)\include\vcl
AFLAGS = /i..\..\..\Projetos\PERSIST\codigo\CASECODE /i..\..\Hpp /i$(BCB)\include \
  /i$(BCB)\include\vcl /dCBUILDER /dGERAR_DLL /mx /w2 /zd
LFLAGS = -L..\..\Case;..\..\..\..\..\..;..\..\..\Projetos\PERSIST\codigo\CASECODE;$(BCB)\images\buttons;$(BCB)\projects;..\..\Import;$(BCB)\lib\obj;$(BCB)\lib;$(DEBUGLIBPATH) \
  -aa -Tpd -x -Gi -v Documentos\IFrameWork\Import;\Meus \
  Documentos\projetos\persist\codigo\casecode;$(BCB)\lib\obj;$(BCB)\lib
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
#-----------------------------------------------------------------------------