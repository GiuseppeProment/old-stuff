# ---------------------------------------------------------------------------
VERSION = BCB.01
# ---------------------------------------------------------------------------
!ifndef BCB
BCB = $(MAKEDIR)\..
!endif
# ---------------------------------------------------------------------------
PROJECT = SDIAPP.exe
OBJFILES = SDIAPP.obj SDIMain.obj UnitMaisInfo.obj UnitAboutBox.obj \
   cadastro.obj UnitDialogoLogin.obj UnitDialogoEdicao.obj
RESFILES = sdiapp.res Rico.res
RESDEPEN = $(RESFILES) SDIMain.dfm UnitMaisInfo.dfm UnitAboutBox.dfm \
   UnitDialogoLogin.dfm UnitDialogoEdicao.dfm
LIBFILES = 
# ---------------------------------------------------------------------------
CFLAG1 = -Od -Hc -w -k -r- -y -v -vi- -c -a4 -b- -w-par -w-inl -Vx -Ve -x -WE 
CFLAG2 = -DCBUILDER \
   -I$(BCB)\images\buttons;$(BCB)\projects;C:\Documentos\IFrameWork\Import;$(BCB)\include;$(BCB)\include\vcl;C:\Documentos\Projetos\PERSIST\codigo\CASECODE \
   -H=$(BCB)\lib\vcld.csm 
PFLAGS = -AWinTypes=Windows;WinProcs=Windows;DbiTypes=BDE;DbiProcs=BDE;DbiErrs=BDE \
   -DCBUILDER \
   -U$(BCB)\images\buttons;$(BCB)\projects;C:\Documentos\IFrameWork\Import;$(BCB)\lib\obj;$(BCB)\lib \
   -I$(BCB)\images\buttons;$(BCB)\projects;C:\Documentos\IFrameWork\Import;$(BCB)\include;$(BCB)\include\vcl;C:\Documentos\Projetos\PERSIST\codigo\CASECODE \
   -v -$Y -$W -$O- -JPHNV -M     
RFLAGS = -DCBUILDER \
   -i$(BCB)\images\buttons;$(BCB)\projects;C:\Documentos\IFrameWork\Import;$(BCB)\include;$(BCB)\include\vcl;C:\Documentos\Projetos\PERSIST\codigo\CASECODE 
LFLAGS = -L$(BCB)\images\buttons;$(BCB)\projects;C:\Documentos\IFrameWork\Import;$(BCB)\lib\obj;$(BCB)\lib \
   -aa -Tpe -x -v -V4.0
IFLAGS = 
LINKER = ilink32
# ---------------------------------------------------------------------------
ALLOBJ = c0w32.obj $(OBJFILES)
ALLRES = $(RESFILES)
ALLLIB = $(LIBFILES) vcl.lib import32.lib cp32mt.lib 
# ---------------------------------------------------------------------------
.autodepend

$(PROJECT): $(OBJFILES) $(RESDEPEN)
    $(BCB)\BIN\$(LINKER) @&&!
    $(LFLAGS) +
    $(ALLOBJ), +
    $(PROJECT),, +
    $(ALLLIB),, +
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
