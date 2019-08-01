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
    ListNode* swapPairs(ListNode* head) {
        if(NULL==head){
            return head;
        }
        ListNode* dummy, *i,*j;
        dummy = new ListNode(0);
        dummy->next = head;
        i = dummy;
        j = head;
        while(j && j->next){
            i->next = j->next;
            j->next = j->next->next;
            i->next->next = j;
            i=j;
            j=j->next;
        }
        return dummy->next;
        
    }
};
