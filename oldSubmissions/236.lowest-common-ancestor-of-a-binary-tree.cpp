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
    TreeNode* rtn;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        rtn = nullptr;
        hasFind(root,p,q);
        return rtn;
    }
    int hasFind(TreeNode*root,TreeNode*p, TreeNode* q){
        if(!root)
            return 0;
        int ans = 0;
        if(root==p || root==q)
            ans++;
        ans += hasFind(root->left,p,q);
        ans += hasFind(root->right,p,q);
        if(rtn == nullptr && ans==2)
            rtn = root;
        return ans;
    }
};
