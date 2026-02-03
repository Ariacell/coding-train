enable_testing()

add_executable(
  roman
  tests.cpp
)
target_link_libraries(
  roman
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(roman)
