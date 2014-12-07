@ECHO off

cd /D %1

REM gcc %2.c -o %2.exe

%2.exe < testindentinp.c

ECHO.

PAUSE

@ECHO on