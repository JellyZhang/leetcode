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
    void flatten(TreeNode* root) {
        //morris like preorder
        TreeNode* cur = root;
        while(cur){
            if(cur->left==NULL){
                //visit
                cur = cur->right;
            }
            else{
                TreeNode* temp = cur->left;
                //find right most node
                while(temp->right)
                    temp = temp->right;
                temp ->right = cur->right;
                cur->right = cur->left;
                cur->left =NULL;
            }
        }
        return ;
    }
};
