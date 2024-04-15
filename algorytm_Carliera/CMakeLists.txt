cmake_minimum_required(VERSION 3.24)
project(rp LANGUAGES CXX)

add_library(task src/zadanie.cpp)
target_include_directories(task PRIVATE inc)

add_library(problem_rpq src/problem_rpq.cpp)
target_include_directories(problem_rpq PRIVATE inc)
target_link_libraries(problem_rpq task)


add_executable(rpq src/main.cpp)
target_include_directories(rpq PRIVATE inc)
target_link_libraries(rpq problem_rpq)
