cmake_minimum_required(VERSION 3.20)

project(day4 LANGUAGES CXX)

add_executable(day4 main.cpp Sensor.cpp)

target_compile_features(day4 PRIVATE cxx_std_23)
set_target_properties(day4 PROPERTIES CXX_STANDARD 23 CXX_STANDARD_REQUIRED ON CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(day4 PRIVATE -Wall -Wextra -Wpedantic)
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

add_course_example(day4_01_procedural 01_procedural.cpp)
add_course_example(day4_02_objects 02_objects.cpp Sensor.cpp)
add_course_example(day4_03_constructor 03_constructor.cpp Sensor.cpp)
add_course_example(day4_04_invariant 04_invariant.cpp Sensor.cpp)
add_course_example(day4_05_const 05_const.cpp Sensor.cpp)
add_course_example(day4_06_copy_lifetime 06_copy_lifetime.cpp Sensor.cpp)

add_course_example(day4_extra_rectangle extra_rectangle.cpp)
