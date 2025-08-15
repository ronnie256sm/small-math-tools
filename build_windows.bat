@echo off

if exist "bin\" (
    echo Previous bin directory was found, cleaning up
    rmdir /s /q bin
)
mkdir bin
echo Compiling...

pushd src
for %%f in (*.cpp) do (
    echo Compiling %%f...
    g++ -o ..\bin\%%~nf.exe %%f
    if errorlevel 1 (
        echo Error compiling %%f
    )
)
popd

echo Done.