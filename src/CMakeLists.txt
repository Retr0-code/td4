cmake_minimum_required(VERSION 3.17.0)
project(compiler-modules VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

set(COMPILER_MODULES
    td4
    # x86_64
)

foreach(compiler ${COMPILER_MODULES})
    add_subdirectory(${compiler} ${CMAKE_BINARY_DIR}/modules)
endforeach()

