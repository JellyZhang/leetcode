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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int>ans;
        //preorder(root,ans);
        //return ans;
        //iterative(root,ans);
        morris(root,ans);
        return ans;
    }
    void preorder(TreeNode* root,vector<int>&ans){
        if(!root)
            return;
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    void iterative(TreeNode* root,vector<int>&ans){
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode* cur = s.top();s.pop();
            ans.push_back(cur->val);
            if(cur->right)
                s.push(cur->right);
            if(cur->left)
                s.push(cur->left);
        }
    }
    void morris(TreeNode* root,vector<int>&ans){
        while(root){
            if(root->left){
                TreeNode* pre = root->left;
                while(pre->right && pre->right!=root){
                    pre=pre->right;
                }
                if(!pre->right){
                    pre->right = root;
                    //visit
                    ans.push_back(root->val);
                    root = root->left;
                }
                else{
                    pre->right = NULL;
                    root = root->right;
                }
            }
            else{
                //visit
                ans.push_back(root->val);
                root=root->right;
            }
        }
    }
};
