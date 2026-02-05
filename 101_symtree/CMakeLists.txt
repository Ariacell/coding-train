enable_testing()

add_executable(
  symtree
  tests.cpp
)
target_link_libraries(
  symtree
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(symtree)
