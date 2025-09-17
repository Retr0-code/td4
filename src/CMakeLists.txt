cmake_minimum_required(VERSION 4.0)
project(compiler-modules VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)

set(COMPILER_MODULES
    td4
    # x86_64
)

foreach(compiler ${COMPILER_MODULES})
    add_subdirectory(${compiler})
endforeach()

