cmake_minimum_required(VERSION 3.0)

project(Workshops5_6 CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 14)

# the following options prevent compiler-optimization issues that are unwanted in an edu process
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

#### the list of targets ####
add_executable(problem1_name                problem1_name/main.cpp)                 # names
add_executable(problem2_name_with_spaces    problem2_name_with_spaces/main.cpp)     # names 2
add_executable(problem3_list_words          problem3_list_words/main.cpp)           # splic string
add_executable(problem4_type_conversion     problem4_type_conversion/main.cpp)      
add_executable(problem5_split_and_output    problem5_split_and_output/main.cpp)
add_executable(problem6_avgfunc             problem6_avgfunc/main.cpp)              # calculating average of array elements
add_executable(problem7_read_from_stream    problem7_read_from_stream/main.cpp)     # read from stream
add_executable(problem8_files               problem8_files/main.cpp)                # read and write text files


