#include <gtest/gtest.h>

#include "solution.h"

TEST(SymTreeTest, handlesSimpleSymTree) {

  auto tree = Tree([ 1, 2, 2, 3, 2, 3, 2 ]);

  Solution sut;
  bool res = sut.isSymmetric(tree.rootNode);
  EXPECT_EQ(res, true);
}
