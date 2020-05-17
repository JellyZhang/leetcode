#### 23. Merge k Sorted Lists

> Merge *k* sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
>
> **Example:**
>
> ```
> Input:
> [
> 1->4->5,
> 1->3->4,
> 2->6
> ]
> Output: 1->1->2->3->4->4->5->6
> ```

```c++
	struct cmp{
        bool operator()(const ListNode* x, const ListNode *y){
            return x->val > y->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(auto head:lists){
            if(head) pq.push(head);
        }
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        while(!pq.empty()){
            auto cur = pq.top();pq.pop();
            p->next = cur;
            p = p->next;
            if(cur->next){
                pq.push(cur->next);
            }
        }
        return dummy->next;
    }
```

Scan vertically using priority_queue. O(Nlogk) N:total nodes, k: len(lists)