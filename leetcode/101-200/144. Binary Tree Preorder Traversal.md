```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        recursive(root, ans);
        return ans;
        return iterative(root);
        return morris(root);
    }
    void recursive(TreeNode* root, vector<int>& ans){
        if(!root) return;
        ans.push_back(root->val);
        recursive(root->left, ans);
        recursive(root->right, ans);
        return;
    }
    vector<int> iterative(TreeNode* root){
        stack<TreeNode*> stk;
        stk.push(root);
        vector<int> ans;
        while(!stk.empty()){
            auto cur = stk.top(); stk.pop();
            ans.push_back(cur->val);
            if(cur->right) stk.push(cur->right);
            if(cur->left) stk.push(cur->left);
        }
        return ans;
    }
    vector<int> morris(TreeNode* root){
        vector<int> ans;
        while(root){
            if(root->left){
                TreeNode* pre = root->left;
                while(pre->right && pre->right != root){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = root;
                    //visit
                    ans.push_back(root->val);
                    root = root->left;
                }else{
                    pre->right = NULL;
                    root = root->right;
                }
            }else{
                //visit
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};
```

