enable_testing()

add_executable(
  addtwo_test
  tests.cpp
)
target_link_libraries(
  addtwo_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(addtwo_test)
