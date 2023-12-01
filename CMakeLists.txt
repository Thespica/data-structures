cmake_minimum_required(VERSION 3.16)
project(data_structures C)

set(CMAKE_C_STANDARD 11)

option(BUILD_TESTING "Build the unit tests" ON)
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif ()

set(LIBNAME ${PROJECT_NAME})
file(GLOB_RECURSE SRC_FILES src/*.c)
file(GLOB_RECURSE TEST_FILES test/*.c)

add_library(${LIBNAME} SHARED ${SRC_FILES})
# enable source file to find header file in src directory
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)

if (${BUILD_TESTING})
    macro(add_test_executable name)
        add_executable(${name} test/${name}.c)
        target_link_libraries(${name} ${LIBNAME})
        add_test(NAME ${name} COMMAND ${name})
    endmacro()

    add_test_executable(test_single_linked_list)
    add_test_executable(test_queue)
    add_test_executable(test_stack)
    add_test_executable(test_binary_search_tree)
endif ()