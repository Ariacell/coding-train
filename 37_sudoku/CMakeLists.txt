enable_testing()

add_executable(
  sudoku
  tests.cpp
)
target_link_libraries(
  sudoku
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(sudoku)
