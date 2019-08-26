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
    //what if duplicates exists
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()!=inorder.size())
            return NULL;
        return build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>&preorder,vector<int>& inorder,int sp,int ep,int si,int ei){
        //cout<<sp<<" "<<ep<<" "<<si<<" "<<ei<<endl;
        if(sp>ep||si>ei)
            return NULL;
        int mid = preorder[sp];
        int index;
        for(int i=si;i<=ei;i++)
            if(inorder[i]==mid){
                index=i-si;
                break;
            }
        TreeNode* left = build(preorder,inorder,sp+1,sp+index,si,si+index-1);
        TreeNode* right = build(preorder,inorder,sp+index+1,ep,si+index+1,ei);
        TreeNode* root = new TreeNode(mid);
        root->left = left;
        root->right =right;
        return root;
    }
};
