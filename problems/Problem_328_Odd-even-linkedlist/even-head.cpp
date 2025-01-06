class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; // No need to rearrange if there are 0 or 1 nodes
        }

        ListNode* odd = head;             // Pointer for odd-indexed nodes
        ListNode* even = head->next;      // Pointer for even-indexed nodes
        ListNode* evenHead = even;        // Store the head of even list

        // Traverse the list, separating odd and even nodes
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;       // Link the next odd node
            odd = odd->next;             // Move odd pointer forward
            even->next = odd->next;      // Link the next even node
            even = even->next;           // Move even pointer forward
        }

        // Link the last odd node to the head of the even list
        odd->next = evenHead;

        return head; // Return the modified list
    }
};

