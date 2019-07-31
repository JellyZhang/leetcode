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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p,*q;
        p = q = head;
        for(int i=0;i<n;++i){
            q=q->next;
        }
        if(NULL==q){
            return head->next;
        }
        while(NULL!=q->next){
            q = q->next;
            p = p->next;
        }
        p->next = p->next->next;
        return head;
        
    }
};
