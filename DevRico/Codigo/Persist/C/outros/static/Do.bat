@Echo off
Tcc  -c -L\language\tc30\lib -I..\include %1.CPP
Tlink /c/L\language\tc30\lib c0s.obj+%1.obj ,%1,,emu maths cs estatica
@Echo on
