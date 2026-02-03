#include <gtest/gtest.h>

#include "solution.h"

TEST(Roman, HandlesSimpleCase) {
  Solution sut;
  std::string test_val = "MDCLXVI";
  int value = sut.rtoi(test_val);
  EXPECT_EQ(value, 1666);
}

TEST(Roman, HandlesSimpleCaseWithAllOnes) {
  Solution sut;
  std::string test_val = "III";
  int value = sut.rtoi(test_val);
  EXPECT_EQ(value, 3);
}

