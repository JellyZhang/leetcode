> Reverse a linked list from position *m* to *n*. Do it in one-pass.
>
> **Note:** 1 ≤ *m* ≤ *n* ≤ length of list.
>
> **Example:**
>
> ```
> Input: 1->2->3->4->5->NULL, m = 2, n = 4
> Output: 1->4->3->2->5->NULL
> ```

```cpp
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        dummy->next = head;
        for(int i=0;i<m-1;++i){
            prev= prev->next;
        }
        ListNode* cur = prev->next;
        for(int i=0;i<n-m;++i){
            ListNode* nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = prev->next;
            prev->next = nxt;
        }
        return dummy->next;
    }
};
```

we declear one area as { already done area }

prev  -> the left one of [already done area]

cur -> tha rightmost node of [already done area]

nxt -> the right node of cur, waiting to be added to [already done area]

