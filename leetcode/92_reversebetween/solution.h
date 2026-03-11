class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy (0);
        dummy.next = head;
        ListNode *prev = &dummy, *curr = dummy.next, *next = nullptr;

        // Step 1: Navigate to position left-1
        for (int i = 0; i < left - 1; i++) {
            prev = curr;
            curr = curr->next;
        }

        // Step 2: Store critical connection points
        ListNode *first = prev, *second = curr;

        // Step 3: Reverse the sublist
        while (left <= right) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;            

            left++;
        }

        // Step 4: Reconnect the pieces
        second->next = curr;
        first->next = prev;

        return dummy.next;
    }
};
