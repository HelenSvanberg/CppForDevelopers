cmake_minimum_required(VERSION 3.20)

project(day5 LANGUAGES CXX)

function(course_example target source)
    add_executable(${target} ${source})
    target_compile_features(${target} PRIVATE cxx_std_23)
    set_target_properties(${target} PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
    )

    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endfunction()

course_example(day5 main.cpp)
course_example(day5_01_inheritance 01_inheritance.cpp)
course_example(day5_02_virtual 02_virtual.cpp)
course_example(day5_03_abstract 03_abstract.cpp)
course_example(day5_04_slicing 04_slicing.cpp)
course_example(day5_05_composition 05_composition.cpp)
