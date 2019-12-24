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
    //[]
    //[1] pos=0
    bool hasCycle(ListNode *head) {
        if(head==NULL)
            return false;
        ListNode *p,*q;
        p = head;
        q = head;
        while(p && q){
            q = q->next;
            if(!q)
                return false;
            q = q->next;
            p = p->next;
            if(p==q && p!=NULL)
                return true;
        }
        return false;
    }
};
