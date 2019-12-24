/*
 * @lc app=leetcode id=156 lang=cpp
 *
 * [156] Binary Tree Upside Down
 */

// @lc code=start
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root)
            return NULL;
        if(!root->left)
            return root;
        TreeNode* newroot = upsideDownBinaryTree(root->left);
        root->left->right = root;
        root->left->left = root->right;
        root->left = NULL;
        root->right = NULL;
        return newroot;
    }
};
// @lc code=end
