cmake_minimum_required(VERSION 4.0)
project(td4 VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
    Operands.cpp
    Operators.cpp
    ASTNodeFabric.cpp
)

add_library(td4-${PROJECT_NAME} ${SOURCES})
target_include_directories(td4-${PROJECT_NAME} PUBLIC ${td4c_SOURCE_DIR}/include)
