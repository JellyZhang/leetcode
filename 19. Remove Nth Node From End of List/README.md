#### 19. Remove Nth Node From End of List

> Given a linked list, remove the *n*-th node from the end of list and return its head.
>
> **Example:**
>
> ```
> Given linked list: 1->2->3->4->5, and n = 2.
> 
> After removing the second node from the end, the linked list becomes 1->2->3->5.
> ```
>
> **Note:**
>
> Given *n* will always be valid.
>
> **Follow up:**
>
> Could you do this in one pass?



```c++
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *p = dummy;
        ListNode *q = head;
        while(n--) q = q->next;
        while(q){
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        return dummy->next;
        
    }
```

Slow and fast pointer.

Dummy head to avoid edge case.