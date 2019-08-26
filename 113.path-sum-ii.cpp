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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return {};
        vector<int>selected;
        vector<vector<int>> ans;
        selected.push_back(root->val);
        dfs(root,sum-(root->val),selected,ans);
        return ans;
    }
    void dfs(TreeNode* root,int sum,vector<int>&selected,vector<vector<int>>&ans){
        if(!root->left && !root->right && sum==0){
            ans.push_back(selected);
            return;
        }
        if(root->left){
            selected.push_back(root->left->val);
            dfs(root->left,sum-(root->left->val),selected,ans);
            selected.pop_back();
        }
        if(root->right){
            selected.push_back(root->right->val);
            dfs(root->right,sum-(root->right->val),selected,ans);
            selected.pop_back();
        }
    }
};
