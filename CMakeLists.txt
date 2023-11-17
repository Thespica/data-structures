cmake_minimum_required(VERSION 3.16)
project(data_structures C)

set(CMAKE_C_STANDARD 11)

file(GLOB HEADER_FILES include/*.h)
file(GLOB SRC_FILES src/*.c)
file(GLOB TEST_FILES test/*.c)

add_library(${PROJECT_NAME} SHARED ${SRC_FILES})
# enable source file to find header file in include directory
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(test_single_linked_list test/test_single_linked_list.c)
target_link_libraries(test_single_linked_list ${PROJECT_NAME})