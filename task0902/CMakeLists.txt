cmake_minimum_required(VERSION 2.8.9)
project(task0902)
include_directories(include)
file(GLOB_RECURSE SOURCES "src/*".cpp)
add_executable(main ${SOURCES})
install(TARGETS main DESTINATION /usr/bin)
