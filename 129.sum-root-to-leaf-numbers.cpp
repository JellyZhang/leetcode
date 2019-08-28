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
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> q1;
        queue<int> q2;
        q1.push(root);
        q2.push(0);
        int ans=0;
        while(!q1.empty()){
            TreeNode* curNode = q1.front();q1.pop();
            int sum_before = q2.front();q2.pop();
            if(!curNode->left && !curNode->right){
                ans+= sum_before*10+curNode->val;
            }
            else{
                if(curNode->left){
                    q1.push(curNode->left);
                    q2.push(sum_before*10+curNode->val);
                }
                if(curNode->right){
                    q1.push(curNode->right);
                    q2.push(sum_before*10+curNode->val);
                }
            }
        }
        return ans;
    }
};
