#include <gtest/gtest.h>

#include "solution.h"

TEST(BinaryTreeToLinkedList, HandlesSimpleTree) {
  TreeNode* leaf3 = new TreeNode(3);
  TreeNode* leaf4 = new TreeNode(4);
  TreeNode* leaf6 = new TreeNode(6);
  TreeNode* midNode2 = new TreeNode(2, leaf3, leaf4);
  TreeNode* midNode5 = new TreeNode(5, nullptr, leaf6);
  TreeNode* root1 = new TreeNode(1, midNode2, midNode5);

  Solution sut;
  sut.flatten(root1);

  EXPECT_EQ(root1->val, 1);
  EXPECT_EQ(root1->right->val, 2);
  EXPECT_EQ(root1->right->right->val, 3);
  EXPECT_EQ(root1->right->right->right->val, 4);
  EXPECT_EQ(root1->right->right->right->right->val, 5);
  EXPECT_EQ(root1->right->right->right->right->right->val, 6);
}