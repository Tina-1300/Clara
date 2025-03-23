@echo off 
:: verifier si le dossier existe et le suprimmer 
if exist ".xmake" (
    rmdir /s /q ".xmake"
    echo Dossier .xmake supprimer.
) else (
    echo Le dossier .xmake n'existe pas.
)

:: vérifier si le dossier existe et le suprimmer
if exist "build" (
    rmdir /s /q "build"
    echo Dossier build supprimer.
) else (
    echo Le dossier build n'existe pas.
)

pause

xmake f -m release

xmake

pause
 