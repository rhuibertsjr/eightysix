@echo off
setlocal

pushd "%~dp0"

if not exist build mkdir build

pushd build

set common= /I..\src\ /nologo
set output= /Feeightysix.exe

cl %common% %output% ..\src\eightysix.c

popd
