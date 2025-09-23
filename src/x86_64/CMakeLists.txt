cmake_minimum_required(VERSION 3.17.0)
project(cmod_x86_64 VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
    CompilerFactory.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${td4c_SOURCE_DIR}/include)
