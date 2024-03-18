cmake_minimum_required(VERSION 3.24)
project(rp LANGUAGES CXX)

add_library(task src/task.cpp)
target_include_directories(task PRIVATE inc)

add_library(task_list src/task_list.cpp)
target_include_directories(task_list PRIVATE inc)
target_link_libraries(task_list task)


add_executable(rp src/main.cpp)
target_include_directories(rp PRIVATE inc)
target_link_libraries(rp task_list)
