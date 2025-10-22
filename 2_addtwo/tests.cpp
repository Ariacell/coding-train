#include <gtest/gtest.h>

#include "solution.h"

TEST(AddTwoTest, HandlesSameLengthInput) {
  ListNode* l1 = new ListNode(4);
  ListNode* l2 = new ListNode(5, l1);
  ListNode* l3 = new ListNode(9, l2);

  Solution sut;
  ListNode* res = sut.addTwoNumbers(l3, l3);
  EXPECT_EQ(res->val, 8);
  EXPECT_EQ(res->next->val, 1);
  EXPECT_EQ(res->next->next->val, 9);
}

TEST(AddTwoTest, HandlesShorterFirstList) {
  ListNode* l1 = new ListNode(4);
  ListNode* l2 = new ListNode(5, l1);

  ListNode* l3 = new ListNode(9);
  ListNode* l4 = new ListNode(3, l3);
  ListNode* l5 = new ListNode(5, l4);

  Solution sut;
  // [5,4] + [5,3,9] = [0,8,9]
  ListNode* res = sut.addTwoNumbers(l2, l5);
  EXPECT_EQ(res->val, 0);
  EXPECT_EQ(res->next->val, 8);
  EXPECT_EQ(res->next->next->val, 9);
}

TEST(AddTwoTest, HandlesEmptyListWithPopulatedList) {
  ListNode* l1 = new ListNode(4);
  ListNode* l2 = new ListNode(5, l1);

  ListNode* l3 = new ListNode();

  Solution sut;
  // [5,4] + [] = [5,4]
  ListNode* res = sut.addTwoNumbers(l2, l3);
  EXPECT_EQ(res->val, 5);
  EXPECT_EQ(res->next->val, 4);
}

TEST(AddTwoTest, HandlesBothListsEmpty) {
  ListNode* l1 = new ListNode();
  ListNode* l2 = new ListNode();

  Solution sut;
  // [] + [] = []
  ListNode* res = sut.addTwoNumbers(l2, l1);
  EXPECT_EQ(res->val, 0);
  EXPECT_EQ(res->next, nullptr);
}

TEST(AddTwoTest, HandlesLongCarryover) {
  ListNode* g1 = new ListNode(9);
  ListNode* l1 = new ListNode(9);
  ListNode* l2 = new ListNode(9, l1);
  ListNode* l3 = new ListNode(9, l2);
  ListNode* l4 = new ListNode(9, l3);
  ListNode* l5 = new ListNode(9, l4);

  Solution sut;
  // [9] + [9,9,9,9,9] = [8,0,0,0,0,1]
  ListNode* res = sut.addTwoNumbers(g1, l5);
  EXPECT_EQ(res->val, 8);
  EXPECT_EQ(res->next->val, 0);
  EXPECT_EQ(res->next->next->val, 0);
  EXPECT_EQ(res->next->next->next->val, 0);
  EXPECT_EQ(res->next->next->next->next->val, 0);
  EXPECT_EQ(res->next->next->next->next->next->val, 1);
}
