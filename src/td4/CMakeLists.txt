cmake_minimum_required(VERSION 4.0)
project(cmod_td4 VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
    CompilerFactory.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${td4c_SOURCE_DIR}/include)

# list(APPEND CMODS ${PROJECT_NAME})
# set(CMODS ${CMODS} PARENT_SCOPE)
# # message("td4 module: ${CMODS}")
