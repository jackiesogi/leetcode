/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *current = head;
        
        while (current != nullptr && current->next != nullptr) {
            ListNode *next = current->next;
            ListNode *temp = next->next;

            // Swap the pair
            current->next = temp;
            next->next = current;
            prev->next = next;

            // Move to the next pair
            prev = current;
            current = temp;
        }

        return dummy.next;
    }
};
