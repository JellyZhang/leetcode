/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        int curNodes = 1;
        int nxtNodes = 0;
        vector<int> ans;
        while(!q.empty()){
            TreeNode* cur = q.front();q.pop();
            if(cur->left){
                q.push(cur->left);
                nxtNodes++;
            }
            if(cur->right){
                q.push(cur->right);
                nxtNodes++;
            }
            curNodes--;
            if(0 == curNodes){
                ans.push_back(cur->val);
                curNodes = nxtNodes;
                nxtNodes = 0;
            }
        }
        return ans;
    }
};
// @lc code=end
