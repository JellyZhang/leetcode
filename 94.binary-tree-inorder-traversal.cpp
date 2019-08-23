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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        //inorder(root,ans);
        

        //
        //stack<TreeNode*>s;
        //TreeNode* curr = root;
        //while(curr || !s.empty()){
            ////push all left
            //while(curr){
                //s.push(curr);
                //curr = curr->left;
            //}
            //curr = s.top();
            //s.pop();
            //ans.push_back(curr->val);
            //curr = curr->right;
        //}
     
        //return ans;
        return morris(root);
    }
    void inorder(TreeNode* node,vector<int>&ans){
        if(!node){
            return;
        }
        if(node->left)
            inorder(node->left,ans);
        ans.push_back(node->val);
        if(node->right)
            inorder(node->right,ans);
    }
    vector<int> morris(TreeNode* root){
        vector<int>ans;
        TreeNode* curr = root;
        while(curr){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                //find right most node of curr's left subtree
                TreeNode* pre = curr->left;
                while(pre->right){
                    pre = pre->right;
                }
                pre->right = curr;
                curr = curr->left;
                pre->right->left=NULL;
            }
        }
        return ans;
    }

};
