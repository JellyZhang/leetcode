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
    // []
    // [1,1,1,1,1]
    // [1,1,2,3,3,]
    // [1]
    // [1,2]
    // [1,2,3]
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *now = head;
        ListNode *nxt = head->next;
        while(nxt){
            if(now->val==nxt->val){
                nxt=nxt->next;
                now->next=nxt;
            }
            else{
                now=nxt;
                nxt=now->next;
            }
        }
        return head;
    }
};
