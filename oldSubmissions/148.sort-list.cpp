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
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode* p = head;
        ListNode* half = head;
        while(true){
            p=p->next;
            if(!p)
                break;
            p=p->next;
            if(!p)
                break;
            half=half->next;
        }
        ListNode* head2 = half->next;
        half->next = NULL;
        ListNode* newhead1 = sortList(head);
        ListNode* newhead2 = sortList(head2);
        return merge(newhead1, newhead2);

    }
    ListNode* merge(ListNode* start1,ListNode* start2){
        if(!start1)
            return start2;
        if(!start2)
            return start1;
        ListNode* newhead;
        ListNode* newend;
        if(start1->val<start2->val){
            newhead = start1;
            start1=start1->next;
        }
        else{
            newhead = start2;
            start2=start2->next;
        }
        newend =newhead;
        while(start1 && start2){
            if(start1->val<start2->val){
                newend->next = start1;
                start1=start1->next;
            }
            else{
                newend->next = start2;
                start2=start2->next;
            }
            newend = newend->next;
        }
        if(!start1){
            newend->next = start2;
        }
        else{
            newend->next = start1;
        }
        return newhead;
    }
};
