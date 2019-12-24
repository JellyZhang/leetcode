#include <vector>
#include <queue>
using namespace std;


// Definition for singly-linked list.
 //struct ListNode {
     //int val;
     //ListNode *next;
     //ListNode(int x) : val(x), next(NULL) {}
 //};
struct cmp{
    bool operator()(const ListNode* a ,const ListNode* b){
        return b->val<a->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* head=NULL;
        ListNode* tail=head;
        priority_queue<ListNode*,vector<ListNode*>,cmp> q;
        for(int i=0;i<lists.size();i++){
            if(NULL!=lists.at(i)){
                q.push(lists.at(i));
            }
        }
        while(!q.empty()){
            ListNode* top=q.top();
            q.pop();
            if(NULL==head){
                head=top;
                tail=top;
            }
            else{
                tail->next = top;
                tail = top;
            }
            if(NULL!=top->next){
                q.push(top->next);
            }
        }
        return head;
        
        
        
        
    }
};
