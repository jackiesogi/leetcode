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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode();
        ListNode *temp = result;
        temp->next = nullptr;
        int carry = 0;
        int digit = 0;
        
        while (l1 || l2 || carry) {

            int d1 = (l1) ? l1->val : 0;
            int d2 = (l2) ? l2->val : 0;
            if ((digit = d1 + d2 + carry) >= 10) {
                carry = 1;
                digit %= 10;
            } else {
                carry = 0;
            }

            temp->val = digit;
            
            l1 = (l1) ? l1->next : nullptr;
            l2 = (l2) ? l2->next : nullptr;

            if (l1 || l2 || carry) {
                temp->next = new ListNode();
                temp = temp->next;
            }
        }
        return result;
    }
};