# Microsoft Developer Studio Project File - Name="IPersiste" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=IPersiste - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "IPersiste.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "IPersiste.mak" CFG="IPersiste - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "IPersiste - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "IPersiste - Win32 Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "IPersiste - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "C:\Documentos\IFrameWork\HPP" /I "C:\Documentos\Projetos\PERSIST\codigo\CASECODE" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "GERAR_DLL" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD BASE RSC /l 0x416 /d "NDEBUG"
# ADD RSC /l 0x416 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes /map /machine:I386

!ELSEIF  "$(CFG)" == "IPersiste - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /I "e:\meus Documentos\IFrameWork\HPP" /I "e:\meus Documentos\Projetos\PERSIST\codigo\CASECODE" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GERAR_DLL" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD BASE RSC /l 0x416 /d "_DEBUG"
# ADD RSC /l 0x416 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept /libpath:"e:\meus documentos\iframework\import"
# SUBTRACT LINK32 /incremental:no /map

!ENDIF 

# Begin Target

# Name "IPersiste - Win32 Release"
# Name "IPersiste - Win32 Debug"
# Begin Group "Interface"

# PROP Default_Filter "h;hpp"
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iassccao.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iatrbuto.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Ibroker.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Ibsrvdor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iclcprss.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iclssmap.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Icolecao.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Icritrio.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Idltsttm.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Idrcftch.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Idtstore.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Idtstrdb.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\IDtStrrc.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Ierro.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iknwtype.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Imdfystt.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Impclsst.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Imptrcln.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Insrtstt.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Intfcdor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Intfcdrb.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iordem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Ipdtsttm.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\IPersistencia.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iprcmprc.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iprlgcpr.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iprsstid.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iprsstnt.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iqrysttm.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Istdclco.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Istdgnrc.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Istdsttm.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Istring.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Isttment.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\IUtil.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Ivntntfc.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\lista.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\listaPtr.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Lststrng.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Offset.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Typevnto.h
# End Source File
# End Group
# Begin Group "Implementação"

# PROP Default_Filter "cpp;c"
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Funcoes.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iassccao.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iatrbuto.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Ibroker.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Ibsrvdor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iclcprss.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iclssmap.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Icolecao.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Icritrio.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Idltsttm.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Idrcftch.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Idtstore.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Idtstrdb.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Idtstrrc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Ierro.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iknwtype.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Imdfystt.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Impclsst.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Imptrcln.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Insrtstt.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Intfcdor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Intfcdrb.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iordem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Ipdtsttm.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iprcmprc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iprlgcpr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iprsstid.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iprsstnt.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Iqrysttm.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Istdclco.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Istdgnrc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Istdsttm.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Istring.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Isttment.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Ivntntfc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Lststrng.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\template.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Projetos\Persist\codigo\Casecode\Typevnto.cpp
# End Source File
# End Group
# End Target
# End Project
