cmake_minimum_required(VERSION 4.0)
project(td4c VERSION 0.1)

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
)

# add_subdirectory(src)

add_library(${PROJECT_NAME}-ast ${SOURCES})
target_include_directories(${PROJECT_NAME}-ast PUBLIC include)

add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-ast)
