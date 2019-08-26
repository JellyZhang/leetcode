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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        helper(q,ans);
        return ans;
    }
    void helper(queue<TreeNode*>q,vector<vector<int>>&ans){
        vector<int>temp;
        queue<TreeNode*>nxt;
        while(!q.empty()){
            TreeNode* cur = q.front();q.pop();
            temp.push_back(cur->val);
            if(cur->left)
                nxt.push(cur->left);
            if(cur->right)
                nxt.push(cur->right);
        }
        if(nxt.size()==0){
            ans.push_back(temp);
        }
        else{
            helper(nxt,ans);
            ans.push_back(temp);
        }
        return;
    }

};
