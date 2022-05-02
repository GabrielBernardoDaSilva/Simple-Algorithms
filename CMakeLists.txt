cmake_minimum_required(VERSION 3.0.0)

project(cpp_algorithms VERSION 0.0.1)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)


set(CMAKE_BUILD_TYPE Release)


include_directories(./include)

file(GLOB SRC src/*.cpp)

add_executable(${PROJECT_NAME} main.cpp ${SRC})