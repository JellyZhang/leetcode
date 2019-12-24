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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        head = dummy;
        ListNode* end = head ->next;
        while(end->next){
            end = insertonce(head,end,end->next);
        }
        return head->next;
    }
    ListNode* insertonce(ListNode* head,ListNode* end,ListNode* target){ 
        //return newend
        ListNode* p =head;
        while(p!=end && target->val>p->next->val){
            p = p->next;
        }
        //p = end || target<=p->next->val
        ListNode* newend = end;
        if(p==end){
            newend = target;
        }
        else{
            end->next = target->next;
            target->next = p->next;
            p->next = target;
        }
        return newend;
    }
};
