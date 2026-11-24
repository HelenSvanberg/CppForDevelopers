cmake_minimum_required(VERSION 3.20)
project(day15 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

add_executable(day15_01_future 01_future.cpp)
target_link_libraries(day15_01_future PRIVATE Threads::Threads)

add_executable(day15_02_future_error 02_future_error.cpp)
target_link_libraries(day15_02_future_error PRIVATE Threads::Threads)

add_executable(day15_03_wait_without_lock 03_wait_without_lock.cpp)
target_link_libraries(day15_03_wait_without_lock PRIVATE Threads::Threads)

add_executable(day15 main.cpp)
target_link_libraries(day15 PRIVATE Threads::Threads)
