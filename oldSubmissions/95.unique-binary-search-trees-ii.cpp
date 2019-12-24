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
    vector<TreeNode*> generateTrees(int n) {
        if(!n)
            return {};
        vector<vector<vector<TreeNode*>>> memo(n,vector<vector<TreeNode*>>(n));
        return getTree(1,n,memo);
    }
    vector<TreeNode*> getTree(int start,int end,vector<vector<vector<TreeNode*>>>& memo){
        vector<TreeNode*> ans;
        if(start>end){
            return {NULL};
        }
        if(start==end){
            return {new TreeNode(start)};
        }
        if(!memo[start-1][end-1].empty()){
            return memo[start-1][end-1];
        }
        for(int i=start;i<=end;++i){
            auto lnodes = getTree(start,i-1,memo);
            auto rnodes = getTree(i+1,end,memo);
            for(TreeNode* l:lnodes)
                for(TreeNode* r:rnodes){
                    TreeNode* newroot = new TreeNode(i);
                    newroot->left = l;
                    newroot->right = r;
                    ans.push_back(newroot);
                }
        }
        memo[start-1][end-1] = ans;
        return ans;
    }
};
