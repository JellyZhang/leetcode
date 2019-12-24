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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*>q;
        int cnt=1;
        int ans=0;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();q.pop();
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            if(--cnt==0){
                ans++;
                cnt = q.size();
            }
        }
        return ans;
    }
};
