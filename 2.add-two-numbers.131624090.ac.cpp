class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result,*l3 = new ListNode(0);
        result=l3;
        int co=0;
        while(l1!=nullptr || l2!=nullptr){
           int temp=((l1)?l1->val:0)+((l2)?l2->val:0)+co;
           co=0;
           if(temp>9){
            temp-=10;
            co=1;
           }
           if(l1)l1=l1->next;
           if(l2)l2=l2->next;
           l3->val=temp;
           if(l1||l2||co){
            l3->next = new ListNode(0);
            l3=l3->next;
           }
        }
        if(co){
            l3->val=1;
        }
        return result;
    }
};
