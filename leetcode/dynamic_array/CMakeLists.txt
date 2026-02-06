enable_testing()

add_executable(
  dynamicarrayimpl
  tests.cpp
)
target_link_libraries(
  dynamicarrayimpl
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(dynamicarrayimpl)
