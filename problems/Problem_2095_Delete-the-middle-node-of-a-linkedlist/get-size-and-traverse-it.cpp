class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode dummy;
        dummy.next = head;

        ListNode *current = &dummy;
        int count = 0;

        // Count the total number of nodes
        for (ListNode *node = head; node != nullptr; node = node->next) {
            ++count;
        }

        // Calculate the index of the middle node
        int mid = count / 2; // Integer division

        // Traverse the list to the node just before the middle node
        while (mid > 0) {
            current = current->next;
            --mid;
        }

        // Delete the middle node
        ListNode *toDelete = current->next;
        current->next = toDelete->next; // Re-link the list
        //delete toDelete;                // Free the memory

        return dummy.next; // Return the updated list
    }
};

