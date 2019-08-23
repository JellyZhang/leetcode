/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //[1,2,3] 1,3
    // m==n
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL || m==n){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        n-=m;
        m--;
        while(m--){
            p=p->next;
        }
        //ListNode *pre, *curr,*nxt;
        //pre = p->next;
        //curr = pre->next;
        //while(n--){
            //nxt = curr->next;
            //curr->next = pre;
            //pre = curr;
            //curr= nxt;
        //}
        //p->next->next = curr;
        //p->next = pre;
        //
        // 2 pointer
        ListNode *tmp,*tail;
        tail = p->next;
        while(n--){
            tmp = p->next;
            p->next = tail->next;
            tail->next = tail->next->next;
            p->next->next = tmp;
        }
        return dummy->next;
    }
};
