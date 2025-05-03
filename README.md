# mechanical_engine
Simple game engine using SDL3

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

## refs:
- https://solhsa.com/gp2/index.html
- https://wiki.libsdl.org/SDL3/README/migration
- https://glusoft.com/sdl3-tutorials/use-opengl-shaders
