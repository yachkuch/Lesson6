cmake_minimum_required(VERSION 3.0.0)
project(Matrix VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

SET(HEAD  /matrix/Matrix.h)
SET (SOURCES 
    main.cpp 
    /matrix/Matrix.cpp)

add_executable(Matrix main.cpp)
target_include_directories(Matrix PRIVATE matrix)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
