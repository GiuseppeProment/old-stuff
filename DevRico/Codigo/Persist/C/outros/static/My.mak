.AUTODEPEND

#		*Translator Definitions*
CC = tcc +MY.CFG
TASM = TASM
TLIB = tlib
TLINK = tlink
LIBPATH = F:\LANGUAGE\TC30\LIB
INCLUDEPATH = F:\LANGUAGE\TC30\INCLUDE


#		*Implicit Rules*
.c.obj:
  $(CC) -c {$< }

.cpp.obj:
  $(CC) -c {$< }

#		*List Macros*


EXE_dependencies =  \
 t.obj

#		*Explicit Rules*
my.exe: my.cfg $(EXE_dependencies)
  $(TLINK) /v/x/c/L$(LIBPATH) @&&|
c0s.obj+
t.obj
my
		# no map file
graphics.lib+
emu.lib+
maths.lib+
cs.lib
|


#		*Individual File Dependencies*
t.obj: my.cfg t.cpp 

#		*Compiler Configuration File*
my.cfg: my.mak
  copy &&|
-2
-v
-vi-
-w-ret
-w-nci
-w-inl
-wpin
-wamb
-wamp
-w-par
-wasm
-wcln
-w-cpt
-wdef
-w-dup
-w-pia
-wsig
-wnod
-w-ill
-w-sus
-wstv
-wucp
-wuse
-w-ext
-w-ias
-w-ibc
-w-pre
-w-nst
-I$(INCLUDEPATH)
-L$(LIBPATH)
| my.cfg


