@echo off

if exist "compiled_output\" (
    echo Previous compiled_output directory was found, cleaning up
    rmdir /s /q compiled_output
)
mkdir compiled_output
echo Compiling...

pushd src
for %%f in (*.cpp) do (
    echo Compiling %%f...
    g++ -o ..\compiled_output\%%~nf.exe %%f
    if errorlevel 1 (
        echo Error compiling %%f
    )
)
popd

echo Done.