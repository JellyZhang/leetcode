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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        recursive(root, ans);
        return ans;
        return morris(root);
        return iterative(root);
    }
    void recursive(TreeNode* root, vector<int>& ans){
        if(!root) return;
        recursive(root->left, ans);
        ans.push_back(root->val);
        recursive(root->right, ans);
        return;
    }
    vector<int> iterative(TreeNode* root){
        stack<TreeNode*> stk;
        vector<int> ans;
        while(!stk.empty() || root){
            while(root){
                stk.push(root);
                root = root->left;
            }
            auto cur = stk.top(); stk.pop();
            ans.push_back(cur->val);
            if(cur->right){
                root = cur->right;
            }
        }
        return ans;
    }
    vector<int> morris(TreeNode* root){
        vector<int> ans;
        while(root){
            if(root->left){
                TreeNode *pre = root->left;
                while(pre->right && pre->right != root){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = root;
                    root = root->left;
                }else{
                    pre->right = NULL;
                    //visit
                    ans.push_back(root->val);
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

