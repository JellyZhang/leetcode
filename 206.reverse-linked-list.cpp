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
    ListNode* reverseList(ListNode* head) {
        //ListNode* ans=head;
        //recursively(head,&ans);
        //return ans;
        ListNode *pre = NULL, *cur = head;
        while(cur){
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
    ListNode* recursively(ListNode* head){
        if(!head || !head->next)
            return NULL;
        ListNode* newhead = recursively(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
};
