enable_testing()

add_executable(
  minpathsum
  tests.cpp
)
target_link_libraries(
  minpathsum
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(minpathsum)
