cmake_minimum_required(VERSION 3.20)

project(day3 LANGUAGES CXX)

add_executable(day3 main.cpp sensor.cpp)

target_compile_features(day3 PRIVATE cxx_std_23)
set_target_properties(day3 PROPERTIES CXX_STANDARD 23 CXX_STANDARD_REQUIRED ON CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(day3 PRIVATE -Wall -Wextra -Wpedantic)
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

add_course_example(day3_01_functions 01_functions.cpp)
add_course_example(day3_02_parameters 02_parameters.cpp)
add_course_example(day3_03_scope 03_scope.cpp)
add_course_example(day3_04_overloading 04_overloading.cpp)
add_course_example(day3_05_modules 05_modules.cpp sensor.cpp)
