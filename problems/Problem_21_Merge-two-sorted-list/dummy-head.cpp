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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *lptr1 = list1;
        ListNode *lptr2 = list2;
        ListNode dummy;
        ListNode *last = &dummy;

        while (lptr1 != NULL && lptr2 != NULL) {
            ListNode *temp = new ListNode();
            if (lptr1->val <= lptr2->val) {
                temp->val = lptr1->val;
                lptr1 = lptr1->next;
            } else {
                temp->val = lptr2->val;
                lptr2 = lptr2->next;
            }
            last->next = temp;
            last = temp;
        }

        /* Connect list1 */
        if (lptr1 != NULL) {
            last->next = lptr1;
            /*Without movig LAST to actual last ptr*/
        }

        /* Connect list2 */
        if (lptr2 != NULL) {
            last->next = lptr2;
        }

        return dummy.next;
    }
};