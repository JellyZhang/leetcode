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
    //could use Stack
    void reorderList(ListNode* head) {
        if(head==NULL|| head->next==NULL)//[1]
            return;
        //find mid
        ListNode* p,*q;
        p = q = head;
        while(true){
            q=q->next;
            if(!q)
                break;
            q=q->next;
            if(!q)
                break;
            p=p->next;
        }
        ListNode* mid = p;
        //reverse the right half
        ListNode* tail =mid->next;
        while(tail->next){
            ListNode* nxt = tail->next->next;
            tail->next->next= mid->next;
            mid->next = tail->next;
            tail->next =nxt;
        }
        //ListNode* temp = head;
        //while(temp){
            //cout<<temp->val<<" ";
            //temp = temp->next;
        //}
        //reconnect
        p =head;
        q = mid->next;
        while(q && p->next!=q){
            ListNode* nxt = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next;
            q = nxt;
            mid->next = nxt;
        }
        return;
    }
};
