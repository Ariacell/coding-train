#include <gtest/gtest.h>

#include "solution.h"

TEST(DynamicArray, HandlesOperations) {
  DynamicArray sut(4);
  EXPECT_EQ(sut.getCapacity(), 4);
  sut.pushback(20);
  sut.pushback(40);
  sut.pushback(60);
  sut.pushback(80);
  EXPECT_EQ(sut.getCapacity(), 4);
  sut.pushback(90);
  EXPECT_EQ(sut.get(4), 90);
  EXPECT_EQ(sut.getCapacity(), 8);
}