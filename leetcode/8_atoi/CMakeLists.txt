enable_testing()

add_executable(
  atoi
  tests.cpp
)
target_link_libraries(
  atoi
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(atoi)
