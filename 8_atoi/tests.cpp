#include <gtest/gtest.h>

#include "solution.h"

TEST(Atoi, HandlesSimpleCase) {
  Solution sut;
  std::string test_val = "1000";
  int value = sut.atoi(test_val);
  EXPECT_EQ(value, 1000);
}

TEST(Atoi, HandlesSimpleNegativeCase) {
  Solution sut;
  std::string test_val = "-12345";
  int value = sut.atoi(test_val);
  EXPECT_EQ(value, -12345);
}

TEST(Atoi, HandlesHugeNegativeCase) {
  Solution sut;
  std::string test_val = "-91283472332";
  int value = sut.atoi(test_val);
  EXPECT_EQ(value, -2147483648);
}

TEST(Atoi, HandlesSimpleExplicitPositiveCase) {
  Solution sut;
  std::string test_val = "12345";
  int value = sut.atoi(test_val);
  EXPECT_EQ(value, 12345);
}

TEST(Atoi, HandlesLeadingWhiteSpace) {
  Solution sut;
  std::string test_val = "   12345";
  int value = sut.atoi(test_val);
  EXPECT_EQ(value, 12345);
}

TEST(Atoi, HandlesMangledString) {
  Solution sut;
  std::string test_val = "   12 r3sd3rr345";
  int value = sut.atoi(test_val);
  EXPECT_EQ(value, 12);
}

TEST(Atoi, HandlesEmptyString) {
  Solution sut;
  std::string test_val = "";
  int value = sut.atoi(test_val);
  EXPECT_EQ(value, 12);
}


TEST(Atoi, HandlesEmptyStringWithSpaces) {
  Solution sut;
  std::string test_val = " ";
  int value = sut.atoi(test_val);
  EXPECT_EQ(value, 12);
}

