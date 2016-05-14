# ---------------------------------------------------------------------------
VERSION = BCB.01
# ---------------------------------------------------------------------------
!ifndef BCB
BCB = $(MAKEDIR)\..
!endif
# ---------------------------------------------------------------------------
PROJECT = IPersiste_CBuilder.dll
OBJFILES = IPersiste_CBuilder.obj \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Iassccao.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Iatrbuto.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Ibroker.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Ibsrvdor.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Iclcprss.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Iclssmap.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Icolecao.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Icritrio.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Idltsttm.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Idrcftch.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Idtstore.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Idtstrdb.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Idtstrrc.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Ierro.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Iknwtype.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Imdfystt.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Impclsst.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Imptrcln.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Insrtstt.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Intfcdor.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Intfcdrb.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Iordem.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Ipdtsttm.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Iprcmprc.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Iprlgcpr.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Iprsstid.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Iprsstnt.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Iqrysttm.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Istdclco.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Istdgnrc.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Istdsttm.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Istring.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Isttment.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Ivntntfc.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Lststrng.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\template.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Typevnto.obj" \
   "\Meus Documentos\Projetos\PERSIST\codigo\CASECODE\Funcoes.obj"
RESFILES = 
RESDEPEN = $(RESFILES)
LIBFILES = 
DEFFILE = 
# ---------------------------------------------------------------------------
CFLAG1 = -WD -Od -w -k -r- -y -v -vi- -c -a4 -b- -w-par -w-inl -Vx -Ve -x
CFLAG2 = -DCBUILDER;GERAR_DLL \
   -I"e:\meus documentos\projetos\persist\codigo\casecode";"e:\meus Documentos\IFrameWork\Hpp";$(BCB)\include;$(BCB)\include\vcl \
   Documentos\IFrameWork\Hpp;\Meus \
   Documentos\projetos\persist\codigo\casecode;$(BCB)\include;$(BCB)\include\vcl 
PFLAGS = -U"e:\meus documentos\projetos\persist\codigo\casecode";$(BCB)\images\buttons;$(BCB)\projects;"e:\meus Documentos\IFrameWork\Import";$(BCB)\lib\obj;$(BCB)\lib \
   -AWinTypes=Windows;WinProcs=Windows;DbiTypes=BDE;DbiProcs=BDE;DbiErrs=BDE \
   -DCBUILDER;GERAR_DLL \
   -I"e:\meus documentos\projetos\persist\codigo\casecode";"e:\meus Documentos\IFrameWork\Hpp";$(BCB)\include;$(BCB)\include\vcl \
   -v -$Y -$W -$O- Documentos\IFrameWork\Import;\Meus \
   Documentos\projetos\persist\codigo\casecode;$(BCB)\lib\obj;$(BCB)\lib \
   Documentos\IFrameWork\Hpp;\Meus \
   Documentos\projetos\persist\codigo\casecode;$(BCB)\include;$(BCB)\include\vcl \
   -JPHNV -M     
RFLAGS = -DCBUILDER;GERAR_DLL \
   -i"e:\meus documentos\projetos\persist\codigo\casecode";"e:\meus Documentos\IFrameWork\Hpp";$(BCB)\include;$(BCB)\include\vcl \
   Documentos\IFrameWork\Hpp;\Meus \
   Documentos\projetos\persist\codigo\casecode;$(BCB)\include;$(BCB)\include\vcl 
LFLAGS = -L"e:\meus documentos\projetos\persist\codigo\casecode";$(BCB)\images\buttons;$(BCB)\projects;"e:\meus Documentos\IFrameWork\Import";$(BCB)\lib\obj;$(BCB)\lib \
   -aa -Tpd -x -v Documentos\IFrameWork\Import;\Meus \
   Documentos\projetos\persist\codigo\casecode;$(BCB)\lib\obj;$(BCB)\lib -V4.0 
IFLAGS = 
LINKER = ilink32
# ---------------------------------------------------------------------------
ALLOBJ = c0d32.obj $(OBJFILES)
ALLRES = $(RESFILES)
ALLLIB = $(LIBFILES) vcl.lib import32.lib cp32mt.lib 
# ---------------------------------------------------------------------------
.autodepend

$(PROJECT): $(OBJFILES) $(RESDEPEN) $(DEFFILE)
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