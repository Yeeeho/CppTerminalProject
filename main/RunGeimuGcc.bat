@echo off

chcp 65001 > nul

if exist "Geimu.exe" (
    Geimu.exe
) else (
    echo error! no such file as Geimu.exe
)

pause