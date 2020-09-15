> Given a linked list, rotate the list to the right by *k* places, where *k* is non-negative.
>
> **Example 1:**
>
> ```
> Input: 1->2->3->4->5->NULL, k = 2
> Output: 4->5->1->2->3->NULL
> Explanation:
> rotate 1 steps to the right: 5->1->2->3->4->NULL
> rotate 2 steps to the right: 4->5->1->2->3->NULL
> ```
>
> **Example 2:**
>
> ```
> Input: 0->1->2->NULL, k = 4
> Output: 2->0->1->NULL
> Explanation:
> rotate 1 steps to the right: 2->0->1->NULL
> rotate 2 steps to the right: 1->2->0->NULL
> rotate 3 steps to the right: 0->1->2->NULL
> rotate 4 steps to the right: 2->0->1->NULL
> ```

```cpp
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        if(k == 0) return head;
        ListNode *tail = head;
        int len = 1;
        while(tail->next){
            len++;
            tail = tail->next;
        }
        k %= len;
        if(k > 0){
            ListNode* p = head;
            for(int i=0;i<len-k-1;++i){
                p = p->next;
            }
            tail->next = head;
            head = p->next;
            p->next = NULL;
        }
        return head;
    }
};
```

first we get the length of the list, then we precess k.

After that we find the break point to break the list.