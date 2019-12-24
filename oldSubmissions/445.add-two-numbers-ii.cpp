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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)
            return NULL;
        int len1 = 0;
        int len2 = 0;
        ListNode* p,*q;
        p = l1;
        while(p){
            len1++;
            p = p->next;
        }
        p = l2;
        while(p){
            len2++;
            p = p->next;
        }
        if(len1>=len2){
            p = l1;
            q = l2;
        }
        else{
            p = l2;
            q = l1;
        }
        //p longer
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int diff = abs(len1-len2);
        while(diff--){
            ListNode* temp = new ListNode(p->val);
            cur->next = temp;
            cur = temp;
            p = p->next;
        }
        diff = min(len1,len2);
        bool conti = false;
        while(diff--){
            ListNode* temp = new ListNode(p->val + q->val);
            cur->next = temp;
            cur = temp;
            if(cur->val>=10)
                conti = true;
            p = p->next;
            q = q->next;
        }
        while(conti){
            cur = dummy;
            conti= false;
            while(cur->next){
                ListNode* nxt = cur->next;
                if(nxt->val>=10){
                    cur->val+=1;
                    nxt->val-=10;
                    if(cur->val>=10)
                        conti= true;
                }
                cur = cur->next;
            }
        }
        if(dummy->val)
            return dummy;
        return dummy->next;
    }
};
