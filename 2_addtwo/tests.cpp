#include "solution.h"
#include <gtest/gtest.h>

// Test case for Factorial function
// TEST(AddTwoTest, HandlesZeroInput) {
//     EXPECT_EQ(Factorial(0), 1);
// }

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
    // EXPECT_EQ(res->next->next->next->val, 4);
}
