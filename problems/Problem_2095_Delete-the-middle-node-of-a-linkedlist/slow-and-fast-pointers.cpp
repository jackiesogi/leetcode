class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode dummy;
        dummy.next = head;

        ListNode* slow = &dummy;
        ListNode* fast = head;

        // Move `fast` twice as fast as `slow` to find the middle node
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // `slow` is now at the node just before the middle node
        ListNode* toDelete = slow->next;
        slow->next = toDelete->next; // Re-link to skip the middle node
        //delete toDelete;             // Free the memory

        return dummy.next; // Return the updated list
    }
};

