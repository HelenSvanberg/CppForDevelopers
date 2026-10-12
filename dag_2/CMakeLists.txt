cmake_minimum_required(VERSION 3.20)

project(day2 LANGUAGES CXX)

add_executable(day2 main.cpp)

target_compile_features(day2 PRIVATE cxx_std_23)
set_target_properties(day2 PROPERTIES CXX_STANDARD 23 CXX_STANDARD_REQUIRED ON CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(day2 PRIVATE -Wall -Wextra -Wpedantic)
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

add_course_example(day2_01_types 01_types.cpp)
add_course_example(day2_02_initialization 02_initialization.cpp)
add_course_example(day2_03_division 03_division.cpp)
add_course_example(day2_04_console_io 04_console_io.cpp)
add_course_example(day2_05_conditions 05_conditions.cpp)
add_course_example(day2_06_loops 06_loops.cpp)
add_course_example(day2_07_line_parsing 07_line_parsing.cpp)
add_course_example(day2_08_exceptions 08_exceptions.cpp)

add_course_example(day2_extra_statistics extra_statistics.cpp)
