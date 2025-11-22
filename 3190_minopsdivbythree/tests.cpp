#include <gtest/gtest.h>

#include "solution.h"

TEST(MinOpsDivByThree, HandlesSList) {
  Solution sut;
  std::vector<int> values = { 1,2,3,4};
  int ops = sut.minimumOperations(values);
  EXPECT_EQ(ops, 3);
}

TEST(MinOpsDivByThree, Handles8) {
  Solution sut;
  std::vector<int> values = { 8 };
  int ops = sut.minimumOperations(values);
  EXPECT_EQ(ops, 1);
}

TEST(MinOpsDivByThree, HandlesNoopList) {
  Solution sut;
  std::vector<int> values = { 3,6,9 };
  int ops = sut.minimumOperations(values);
  EXPECT_EQ(ops, 0);
}