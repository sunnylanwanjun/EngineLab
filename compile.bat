cd engine/
call compile-shaders.bat

cd ..

set BUILD_PATH=./build/Win64
cmake -S . -B %BUILD_PATH% -G "Visual Studio 17 2022" -A x64
cmake --build %BUILD_PATH% --target engine --config debug -- /m

cd ./build/Win64/Debug/
engine.exe
