cmake_minimum_required (VERSION 3.1)
project (CDataFrame)

SET(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_C_COMPILER "gcc")


include_directories(${PROJECT_SOURCE_DIR}/inc)

add_library(DataFrame SHARED lib/DataFrame.cpp)

link_directories(${PROJECT_SOURCE_DIR}/build)

add_executable(TestDataFrame bin/TestDataFrame.cpp)
target_link_libraries(TestDataFrame DataFrame)


