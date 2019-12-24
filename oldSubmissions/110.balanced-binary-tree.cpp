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
    bool ans;
    bool isBalanced(TreeNode* root) {
        ans =true;
        getdepth(root);
        return ans;
    }
    int getdepth(TreeNode* root){
        if(root==NULL)
            return 0;
        int ldepth = getdepth(root->left);
        int rdepth = getdepth(root->right);
        if(abs(ldepth-rdepth)>1)
            ans=false;
        return max(ldepth,rdepth)+1;
    }
};
