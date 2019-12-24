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
    ListNode* ReverseListAndReturnFirstnode(ListNode* head,int len){
        if(2==len){
            head->next->next = head;
            return head->next;
        }
        ListNode* pprev = head;
        ListNode* pnow = head->next;
        ListNode* pnext = pnow->next;
        int cnt=0;
        while(cnt<len-1){
            pnow->next = pprev;
            pprev= pnow;
            pnow = pnext;
            if(pnext){
                pnext = pnext->next;
            }
            ++cnt;
        }
        return pprev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(1==k){
            return head;
        }
        ListNode* ans=head;
        ListNode* FirstOfReversed;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* start = head;
        ListNode* j = head;
        while(true){
            //cout<<dummy->val<<";"<<start->val<<".";
            for(int i=0;i<k;i++){
                if(NULL==j){
                    return ans;
                }
                j=j->next;
            }
            FirstOfReversed = ReverseListAndReturnFirstnode(start,k);
            cout<<FirstOfReversed->val<<" ";
            dummy->next = FirstOfReversed;
            start->next = j;
            dummy = start;
            start = j;
            if(head==ans){
                ans =FirstOfReversed;
            }
        }
    }
};
