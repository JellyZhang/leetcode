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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==0){
            return head;
        }
        ListNode* dummy;
        dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p=dummy;
        int cnt=0;
        while(k--){
            ++cnt;
            //cout<<k<<" "<<cnt;
            if(p->next){
                p = p->next;
            }
            else{
                p = head;
                //cout<<k<<" "<<cnt<<"=";
                k=k%(cnt-1);
                //cout<<k;
            }
        }
        //cout<<p->val;
        if(p->next==NULL){
            return head;
        }
        while(p->next){
            p = p->next;
            dummy = dummy->next;
        }
        p->next= head;
        ListNode* newhead = dummy->next;
        dummy->next =NULL;
        return newhead;
    }
};
