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
    int maxPathSum(TreeNode* root) {
        
        int ans=root->val;
        postorder(root,&ans);
        return ans;
    }
    int postorder(TreeNode* root,int* _global_max){
        int &ans = *_global_max;
        int cur=root->val;
        int left=0;
        int right=0;
        if(root->left){
            left = postorder(root->left,_global_max);
        }
        if(root->right){
            right= postorder(root->right,_global_max);
        }
        left=max(left,0);
        right=max(right,0);
        cur+=max(left,right);
        //visit
        ans=max(ans,root->val+left+right);
        return cur;
    }
};
