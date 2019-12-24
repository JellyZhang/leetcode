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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q;
        int cnt=1;
        q.push(root);
        vector<vector<int>> ans;
        vector<int> temp;
        while(!q.empty()){
            TreeNode* cur = q.front();q.pop();
            temp.push_back(cur->val);
            if(cur->left){
                q.push(cur->left);
            }
            if(cur->right){
                q.push(cur->right);
            }
            if(--cnt==0){
                ans.push_back(temp);
                temp.clear();
                cnt=q.size();
            }
        }
        for(int i=1;i<ans.size();i+=2){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};
