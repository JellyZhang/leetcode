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
    bool isValid(TreeNode* root, long long upper_bound, long long lower_bound){
        if(root==nullptr)return true;
        if(root->val>=upper_bound || root->val<=lower_bound)return false;
        return isValid(root->left,root->val,lower_bound) && isValid(root->right,upper_bound,root->val);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root,LONG_MAX,LONG_MIN);
    }
};
