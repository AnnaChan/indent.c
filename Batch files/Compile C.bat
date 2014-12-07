@ECHO off

cd /D %1

gcc %2.c -o %2.exe

REM %2.exe

ECHO.

PAUSE

@ECHO on