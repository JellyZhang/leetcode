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
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans=1;
        int cnt=1;
        while(!q.empty()){
            TreeNode* cur = q.front();q.pop();
            if(!cur->left && !cur->right)
                break;
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            if(--cnt==0){
                cnt = q.size();
                ans++;
            }
        }
        return ans;
        
    }
};
