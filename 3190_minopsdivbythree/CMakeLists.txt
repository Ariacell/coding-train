enable_testing()

add_executable(
  minops_div_by_three
  tests.cpp
)
target_link_libraries(
  minops_div_by_three
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(minops_div_by_three)
