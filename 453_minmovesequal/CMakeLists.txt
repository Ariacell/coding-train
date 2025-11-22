enable_testing()

add_executable(
  minmovesequal
  tests.cpp
)
target_link_libraries(
  minmovesequal
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(minmovesequal)
