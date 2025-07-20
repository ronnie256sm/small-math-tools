@echo off

if exist "compiled_output\" (
    echo Cleaning up...
    rmdir /s /q compiled_output
    echo Done.
) else (
    echo Could not find the compiled_output directory, quitting.
)