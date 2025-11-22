enable_testing()

add_executable(
  binary_to_list
  tests.cpp
)
target_link_libraries(
  binary_to_list
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(binary_to_list)
