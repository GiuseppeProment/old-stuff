@echo off
rem
rem Root of Visual Developer Studio installed files.
rem
set MSDevDir=E:\Arquivos de programas\DevStudio\SharedIDE

rem
rem Root of Visual C++ installed files.
rem
set MSVCDir=E:\Arquivos de programas\DevStudio\VC

rem
rem Root of Giuseppe Files
rem
set GiuseppeDir=G:\DevRico\Inc\


rem
rem Root of Visual C++ files on cd-rom.
rem Remove "set vcsource=" if you don't want include cdrom in Visual C++ environment.
rem
rem **** set vcsource=H:\DEVSTUDIO

rem
rem VcOsDir is used to help create either a Windows 95 or Windows NT specific path.
rem
set VcOsDir=WIN95
if "%OS%" == "Windows_NT" set VcOsDir=WINNT

rem
rem echo Setting environment for using Microsoft Visual C++ tools.
echo 旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커
echo 쿌mbiente preparado para Visual C++�
echo 읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸
rem
if "%vcsource%" == "" goto main
rem
rem Include cdrom files in environment.
rem
if "%OS%" == "Windows_NT" set PATH=%PATH%;%vcsource%\VC\BIN;%vcsource%\VC\BIN\%VcOsDir%
if "%OS%" == "" set PATH=%PATH%;"%vcsource%\VC\BIN";"%vcsource%\VC\BIN\%VcOsDir%"
set INCLUDE=%INCLUDE%;%vcsource%\VC\INCLUDE;%vcsource%\VC\MFC\INCLUDE;%vcsource%\VC\ATL\INCLUDE
set LIB=%LIB%;%vcsource%\VC\LIB;%vcsource%\VC\MFC\LIB
set vcsource=

:main
if "%OS%" == "Windows_NT" set PATH=%MSDevDir%\BIN;%MSVCDir%\BIN;%MSVCDir%\BIN\%VcOsDir%;%PATH%
if "%OS%" == "" set PATH="%GiuseppeDir%Lib";"%MSDevDir%\BIN;%MSVCDir%\BIN";"%MSVCDir%\BIN\%VcOsDir%";%PATH%
set INCLUDE=%GiuseppeDir%Hpp;%MSVCDir%\INCLUDE;%MSVCDir%\MFC\INCLUDE;%MSVCDir%\ATL\INCLUDE;%INCLUDE%
set LIB=%GiuseppeDir%Lib;%MSVCDir%\LIB;%MSVCDir%\MFC\LIB;%LIB%

set VcOsDir=