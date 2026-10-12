cmake_minimum_required(VERSION 3.20)

project(day1 LANGUAGES CXX)

add_executable(day1 main.cpp)

target_compile_features(day1 PRIVATE cxx_std_23)
set_target_properties(day1 PROPERTIES CXX_STANDARD 23 CXX_STANDARD_REQUIRED ON CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(day1 PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Varje delmoment har en egen körfil och en egen main-funktion.
function(add_course_example target)
    add_executable(${target} ${ARGN})

    target_compile_features(${target} PRIVATE cxx_std_23)
    set_target_properties(${target} PROPERTIES CXX_STANDARD 23 CXX_STANDARD_REQUIRED ON CXX_EXTENSIONS OFF)

    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endfunction()

add_course_example(day1_01_hello 01_hello.cpp)
add_course_example(day1_02_exit_status 02_exit_status.cpp)

add_course_example(day1_03_linking 03_linking.cpp greeting.cpp)

add_course_example(day1_losning_logik losning_logik.cpp)

add_course_example(day1_losning_namn losning_namn.cpp)

add_course_example(day1_losning_lankning losning_lankning.cpp)
