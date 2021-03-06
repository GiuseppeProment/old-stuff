@echo off
rem build.bat -- Build Script for the "Hello, World" Application
rem $Id: build.bat,v 1.4 2000/07/18 00:41:40 craigmcc Exp $

set JAVA_HOME=C:\JAVA\JDK1.3.1
rem set JAVA_HOME=C:\JAVA\JDK1.1.8
set TOMCAT_HOME=C:\servidores\tomcat

if "%TOMCAT_HOME%" == "" goto notomcathome
if "%CLASSPATH%" == "" goto noclasspath

:haveclasspath
set _CLASSPATH=%CLASSPATH%
set CLASSPATH=%CLASSPATH%;%TOMCAT_HOME%\classes
goto restofclasspath

:noclasspath
set _CLASSPATH=
set CLASSPATH=%TOMCAT_HOME%\classes

:restofclasspath
set CLASSPATH=%CLASSPATH%;%TOMCAT_HOME%\lib\ant.jar
set CLASSPATH=%CLASSPATH%;%TOMCAT_HOME%\lib\jasper.jar
set CLASSPATH=%CLASSPATH%;%TOMCAT_HOME%\lib\servlet.jar
set CLASSPATH=%CLASSPATH%;%TOMCAT_HOME%\lib\webserver.jar
set CLASSPATH=%CLASSPATH%;%JAVA_HOME%\lib\tools.jar

rem Execute ANT to perform the requested build target
java org.apache.tools.ant.Main -Dtomcat.home=%TOMCAT_HOME% %1 %2 %3 %4 %5 %6 %7 %8 %9

set CLASSPATH=%_CLASSPATH%
set _CLASSPATH=
goto end
:notomcathome
echo
echo you need to set TOMCAT_HOME to build this app
echo
:end