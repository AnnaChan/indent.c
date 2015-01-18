@ECHO off

cd /D %1

gcc -o %2.exe %2.c

REM %2.exe

ECHO.

PAUSE

@ECHO on