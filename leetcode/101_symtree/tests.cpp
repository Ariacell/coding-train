#include <gtest/gtest.h>

#include "solution.h"

TEST(SymTreeTest, handlesSimpleSymTree) {

  std::vector<int> nodes = {1,2,2};
  auto tree = Tree(nodes);

  Solution sut;
  bool res = sut.isSymmetric(tree.rootNode);
  EXPECT_EQ(res, true);
}
