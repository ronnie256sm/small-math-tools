@echo off

if exist "bin\" (
    echo Cleaning up...
    rmdir /s /q bin
    echo Done.
) else (
    echo Could not find the bin directory, quitting.
)