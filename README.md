# mechanical_engine
Simple game engine using SDL

## Features
- Editor: vscode
- Build tool: CMAKE
- Compiler: clang (using C++20)
- Debug: lldb
- Ident: clang-format (file: .clang-format)
- libs: SDL

## To build:

Execute:
```sh
mkdir build
cd build
cmake ../ -DCMAKE_TOOLCHAIN_FILE=./toolchain/clang.cmake
make
# or
# cmake -B build -DCMAKE_TOOLCHAIN_FILE=./toolchain/clang.cmake
```
