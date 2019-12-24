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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size())
            return NULL;
        return build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
        
    }
    TreeNode* build(vector<int>& inorder,vector<int>&postorder,int si,int ei,int sp,int ep){
        if(si>ei||sp>ep)
            return NULL;
        int mid = postorder[ep];
        int index;
        for(int i=si;i<=ei;i++)
            if(inorder[i]==mid){
                index = i-si;
                break;
            }
        TreeNode* left = build(inorder,postorder,si,si+index-1,sp,sp+index-1);
        TreeNode* right = build(inorder,postorder,si+index+1,ei,sp+index,ep-1);
        TreeNode* root = new TreeNode(mid);
        root->left = left;
        root->right = right;
        return root;
    }
};
