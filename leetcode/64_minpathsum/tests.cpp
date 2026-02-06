#include <gtest/gtest.h>
#include <vector>
#include "solution.h"

TEST(MinPathSum, handlesSimplePath) {
    std::vector<std::vector<int>> grid {
      {1,3,1},
      {1,5,1},
      {4,2,1}
    };
    Solution sut;
    EXPECT_EQ(sut.minPathSum(grid), 7);
}
