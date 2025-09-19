cmake_minimum_required(VERSION 3.17.0)
project(td4c VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
    src/Exceptions.cpp
    src/AbstractSyntaxTree.cpp
    src/AbstractSyntaxTreeNode.cpp
    src/IOperand.cpp
    src/IOperator.cpp
    src/ASTNodeFactory.cpp
    src/Operands.cpp
    src/Operators.cpp
    src/ArchitectureSelector.cpp
    src/Compiler.cpp
)

add_subdirectory(src)

add_library(${PROJECT_NAME}-ast SHARED ${SOURCES})
target_include_directories(${PROJECT_NAME}-ast PUBLIC include)

add_subdirectory(argparse)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PUBLIC ${argparse_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-ast)
target_link_libraries(${PROJECT_NAME} argparse)
