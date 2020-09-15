 #### 2. Add Two Numbers 

> You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order** and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
>
> You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Note: carry || l1 || l2

```cpp
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        int carry = 0;
        while(l1 || l2 || carry){
            int newVal = carry + (l1?(l1->val):0) + (l2?(l2->val):0);
            cur -> next = new ListNode(newVal%10);
            cur = cur -> next;
            if(l1) l1 = l1 -> next;
            if(l2) l2 = l2 -> next;
            carry = newVal/10;
        }
        return dummy->next;
    }
```

