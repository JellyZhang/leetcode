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
    // [4,3,1,2] 3
    // []
    // [1]3
    // [3]1
    ListNode* partition(ListNode* head, int x) {
        //if(!head)
            //return head;
        //ListNode* dummy;
        //dummy = new ListNode(0);
        //dummy->next = head;
        //ListNode *curr = dummy; // last lower node
        //ListNode *nxt = head; // travel to find a lower node
        //ListNode *pre = dummy; //  always left to nxt node
        //while(nxt){
            //while(nxt && nxt->val>=x){
                //pre = nxt;
                //nxt = nxt->next;
            //}
            //if(nxt == NULL){
                //break;
            //}
            //else if(pre==dummy){
                //curr= nxt;
                //nxt = curr->next;
            //}
            //else{
                //pre->next = nxt->next;
                //nxt->next = curr->next;
                //curr->next = nxt;
                //curr = nxt;
                //nxt = pre->next;
            //}
        //}
        //return dummy->next;
        ListNode* head1 = new ListNode(0);
        ListNode* head2 = new ListNode(0);
        ListNode *p1=head1,*p2=head2;
        while(head){
            if(head->val<x){
                p1->next = head;
                p1 = p1->next;
            }
            else{
                p2->next = head;
                p2 = p2->next;
            }
            head=head->next;
        }
        p1->next = head2->next;
        p2->next = NULL;
        return head1->next;
    }
};
