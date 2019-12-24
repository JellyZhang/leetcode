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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return NULL;
        ListNode *p,*q;
        p = head;
        q = head;
        while(p && q){
            q = q->next;
            if(!q)
                return NULL;
            q = q->next;
            p = p->next;
            if(p==q && p!=NULL)
                break;
        }
        if(!(p&&q)){
            return NULL;
        }
        int len = 1;
        p = q->next;
        while(p!=q){
            p = p->next;
            len++;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next =head;
        p = dummy;
        q = dummy;
        //cout<<len;
        for(int i=0;i<len-1;++i){
            p = p->next;
        }
        while(p->next!=q){
            p=p->next;
            q=q->next;
        }
        return q;
    }
};
