## SFML with CMake Build System

> Project template for SFML development based on CMake build system.

It supports building (via MinGW) and debugging (via gdb) from inside of the VS Code (via C/C++ Extension).

Have two VS Code tasks for debug and release builds respectively.

You can find Bash and Bat script files which used for building in the root of the source tree.

Following environment variables should exist before building;

- SFML_ROOT should point to sfml root directory
- MinGW_LOCATION should point to mingw directory (windows only)

It didn't tested on Linux and any help about the unix-side compability is appreciated.

Tested with:

- SFML 2.5.1
- GCC 7.3.0 (via MinGW on Windows 10)
- CMake 3.12.0-rc1
- VS Code 1.28.2
  - C/C++ for Visual Studio Code: 0.19.0