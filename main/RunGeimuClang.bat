@echo off

chcp 65001 > nul

if exist "Geimu.exe" (
    GeimuClang.exe
) else (
    echo error!
)

pause