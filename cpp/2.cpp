#include <bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

int main(){
    int n;
    cin>>n;
    ListNode *a,*pa = new ListNode(0);
    a=pa;
    while(n--){
        int v;
        cin>>v;
        pa->val=v;
        if(n){
            pa->next=new ListNode(0);
            pa=pa->next;
        }
    }
    cin>>n;
    ListNode *b,*pb = new ListNode(0);
    b=pb;
    while(n--){
        int v;
        cin>>v;
        pb->val=v;
        if(n){
            pb->next=new ListNode(0);
            pb=pb->next;
        }
    }
    Solution S;
    ListNode *result;
    result =S.addTwoNumbers(a,b);
    while(result){
        cout<<result->val<<endl;
        result=result->next;
    }
    return 0;
}
