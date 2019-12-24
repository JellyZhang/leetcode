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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_a = 0;
        int len_b = 0;
        ListNode* p;
        p = headA;
        while(p){
            p = p->next;
            len_a++;
        }
        p = headB;
        while(p){
            p = p->next;
            len_b++;
        }
        if(len_a<len_b)
            return getIntersectionNode(headB,headA);
        len_a-=len_b;
        p = headA;
        ListNode* q = headB;
        while(len_a--){
            p = p->next;
        }
        while(p&&q){
            if(p==q)
                return p;
            else{
                p = p->next;
                q = q->next;
            }
        }
        return NULL;
    }
};
