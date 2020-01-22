cmake_minimum_required(VERSION 3.15)

project(PROJ VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
 SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread") 

find_package(PythonLibs 2.7)

add_executable(main myproject.cpp implementations/Ensemble.cpp implementations/RandomGenerator.cpp headers/RandomGenerator.hpp implementations/Cluster.cpp headers/Cluster.hpp headers/Algorithme.cpp headers/Algorithme.hpp )
target_include_directories(main PRIVATE ./headers)

add_definitions(-DWITHOUT_NUMPY)
# python
target_include_directories(main PRIVATE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(main ${PYTHON_LIBRARIES})
# the -I flag in gcc
include_directories(	
  ${PROJECT_SOURCE_DIR}/headers/
)

