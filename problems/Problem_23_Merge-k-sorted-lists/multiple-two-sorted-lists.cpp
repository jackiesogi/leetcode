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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return nullptr;
        }
        if(lists.size() == 1) {
            return lists.at(0);
        }

        vector<ListNode*> result;
        for (int i = 0; i < lists.size(); i += 2) {
            if (i + 1 >= lists.size()) {
                break;
            }
            ListNode *ptr1 = lists.at(i);
            ListNode *ptr2 = lists.at(i + 1);
            ListNode dummy;
            ListNode *last = &dummy;
            
            while (ptr1 != nullptr && ptr2 != nullptr) {
                ListNode *temp = new ListNode();
                if (ptr1->val <= ptr2->val) {
                    temp->val = ptr1->val;
                    ptr1 = ptr1->next;
                } else {
                    temp->val = ptr2->val;
                    ptr2 = ptr2->next;
                }
                last->next = temp;
                last = temp;
            }

            if (ptr1 != nullptr) {
                last->next = ptr1;
            }

            if (ptr2 != nullptr) {
                last->next = ptr2;
            }

            result.push_back(dummy.next);
        }

        if(lists.size() & 1) {
            result.push_back(lists[lists.size() - 1]);
        }
        
        return mergeKLists(result);
    }
};