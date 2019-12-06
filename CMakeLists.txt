cmake_minimum_required(VERSION 3.10)
project(MyPlayWithDataStructures)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)

add_executable(test_array  test/test_array.cpp)

add_executable(test_stack  test/test_stack.cpp)

add_executable(test_compare_array_and_loop_queue  test/test_compare_array_and_loop_queue.cpp)


add_executable(test_linked_list  test/test_linked_list.cpp)


add_executable(test_list_stack  test/test_list_stack.cpp)


add_executable(test_list_queue  test/test_list_queue.cpp)