> Reverse a singly linked list.
>
> **Example:**
>
> ```
> Input: 1->2->3->4->5->NULL
> Output: 5->4->3->2->1->NULL
> ```
>
> **Follow up:**
>
> A linked list can be reversed either iteratively or recursively. Could you implement both?



```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev = NULL;
        while(head){
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    
    ListNode* recursively(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* p = recursively(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};
```

