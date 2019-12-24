/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode *mid = head;
        ListNode *end = head;
        while(end!=NULL){
            end=end->next;
            if(end==NULL)
                break;
            end=end->next;
            mid=mid->next;
        }
        TreeNode* root = new TreeNode(mid->val);
        auto left = helper(head,mid);
        auto right = helper(mid->next,end);
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* helper(ListNode* start,ListNode* end){
        if(start==end)
            return NULL;
        ListNode *p,*q;
        p = start;
        q = start;
        while(q!=end){
            q=q->next;
            if(q==end)
                break;
            q=q->next;
            p=p->next;
        }
        TreeNode* root  = new TreeNode(p->val);
        auto left = helper(start,p);
        auto right = helper(p->next,end);
        root->left = left;
        root->right = right;
        return root;
    }
};
