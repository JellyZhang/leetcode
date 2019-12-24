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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return recursive(root->left,root->right);
    }
    bool recursive(TreeNode* left,TreeNode* right){
        if(!left && !right)
            return true;
        if(left && !right || right && !left)
            return false;
        return left->val==right->val && recursive(left->left,right->right)&&recursive(left->right,right->right);
    }
};
