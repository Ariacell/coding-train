cmake_minimum_required(VERSION 3.19)
project(coding_journey)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_program(CLANG_FORMAT_EXECUTABLE clang-format)
if(NOT CLANG_FORMAT_EXECUTABLE)
    message(WARNING "clang-format not found. Code formatting target will not be available.")
endif()
file(GLOB_RECURSE ALL_SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/*.h"
    "${CMAKE_SOURCE_DIR}/include/*.h"
    "${CMAKE_SOURCE_DIR}/*.cpp"
    "${CMAKE_SOURCE_DIR}/*.h"
    "${CMAKE_SOURCE_DIR}/**/*.h"
)
add_custom_target(format
    COMMAND ${CLANG_FORMAT_EXECUTABLE} -i
    ${ALL_SOURCE_FILES}
    COMMENT "Formatting all C++ source files in the project"
)


enable_testing()

add_subdirectory(2_addtwo)
add_subdirectory(8_atoi)
add_subdirectory(13_roman)
add_subdirectory(101_symtree)
add_subdirectory(114_binarytolinkedlist)
add_subdirectory(453_minmovesequal)
add_subdirectory(3190_minopsdivbythree)
add_subdirectory(37_sudoku)