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
    //[1]
    //[1,1]
    //[1,1,1,2,3]
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode *curr,*pre,*nxt,*dummy;
        dummy = new ListNode(0);
        dummy->next = head;
        curr= head;
        pre = dummy;
        while(curr && curr->next){
            if(curr->next->val == curr->val){
                while(curr->next && curr->next->val==curr->val){
                    curr=curr->next;
                }
                curr = curr->next;
                pre->next = curr;
            }
            else{
                pre = curr;
                curr= curr->next;
            }
        }
        return dummy->next;
    }
};
