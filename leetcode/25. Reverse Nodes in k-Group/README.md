#### 25. Reverse Nodes in k-Group

> Given a linked list, reverse the nodes of a linked list *k* at a time and return its modified list.
>
> *k* is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of *k* then left-out nodes in the end should remain as it is.
>
> 
>
> **Example:**
>
> Given this linked list: `1->2->3->4->5`
>
> For *k* = 2, you should return: `2->1->4->3->5`
>
> For *k* = 3, you should return: `3->2->1->4->5`
>
> **Note:**
>
> - Only constant extra memory is allowed.
> - You may not alter the values in the list's nodes, only nodes itself may be changed.



```c++
ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy;
        while(true){
            ListNode *end = p;
            for(int i=0;i<k && end;++i){
                end = end->next;
            }
            if(!end) break;
            ListNode* newp = p->next;
            end = end->next;
            ListNode *prev = end;
            ListNode *cur = p->next;
            while(cur != end){
                ListNode *nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
            }
            p->next = prev;
            p = newp;
        }
        return dummy->next;
    }
```

#### 