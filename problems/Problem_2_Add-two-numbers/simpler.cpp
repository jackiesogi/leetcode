class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode *temp = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int d1 = l1 ? l1->val : 0;
            int d2 = l2 ? l2->val : 0;

            int digit = d1 + d2 + carry;
            carry = digit / 10;
            digit %= 10;

            temp->next = new ListNode(digit);
            temp = temp->next;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        return dummy.next;
    }
};
