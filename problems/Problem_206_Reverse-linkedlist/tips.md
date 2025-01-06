## Reverse Linked List

#### Iterative
- Need 2 main pointers, `current` and `prev`, for swapping.
- Need a `nextNode` pointer for iterating.
```cpp
ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr;
    ListNode *current = head;

    while (current != nullptr) {
        ListNode *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}


#### Recursive
```cpp
newHead = reverseList(head->next);
head->next->next = head;
head->next = nullptr;
```
