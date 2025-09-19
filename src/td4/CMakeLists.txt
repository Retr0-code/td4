cmake_minimum_required(VERSION 4.0)
project(cmod VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
    CompilerFactory.cpp
)

add_library(${PROJECT_NAME}_td4 SHARED ${SOURCES})
target_include_directories(${PROJECT_NAME}_td4 PUBLIC ${td4c_SOURCE_DIR}/include)
set_target_properties(${PROJECT_NAME}_td4 PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/modules"
)
