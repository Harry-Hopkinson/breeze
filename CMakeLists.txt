cmake_minimum_required(VERSION 3.26.1)
project(breeze)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(APPNAME breeze)
set(OUT bin/breeze.exe)

file(GLOB_RECURSE files src/*.cpp utils/*.cpp src/core/*.cpp src/list/*.cpp)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(${APPNAME} ${files})

target_link_libraries(${APPNAME} ${LDFLAGS})
