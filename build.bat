@echo off

if not exist "P:\eightysix\bin\" mkdir "P:\eightysix\bin"

pushd .\bin

gcc -g -std=c99 -Wall -Wextra ..\src\eightysix.c -o eightysix.exe ^
-DEIGHTYSIX_DEBUG=1 -DEIGHTYSIX_LOGGING=1 -DEIGHTYSIX_ASSERT=1

popd .\bin
