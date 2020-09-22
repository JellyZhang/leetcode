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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        recursive(root, ans);
        return ans;
        return morris(root);
        return iterative(root);
    }
    void recursive(TreeNode* root, vector<int>& ans){
        if(!root) return;
        recursive(root->left, ans);
        recursive(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> iterative(TreeNode* root){
        stack<TreeNode*> stk;
        vector<int> ans;
        TreeNode* pre = NULL;
        while(!stk.empty() || root){
            while(root){
                stk.push(root);
                root = root->left;
            }
            auto cur = stk.top();
            if(cur->right && pre != cur->right){
                root = cur->right;
            }else{
                ans.push_back(cur->val);
                stk.pop();
                pre = cur;            
            }
        }
        return ans;
    }
    vector<int> morris(TreeNode* root){
        vector<int> ans;
        TreeNode* dummy = new TreeNode(0);
        dummy->left = root;
        root = dummy;
        while(root){
            if(root->left){
                TreeNode* pre = root->left;
                while(pre->right != NULL && pre->right != root){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = root;
                    root = root->left;
                }else{
                    morrisReverseAdd(root->left, pre, ans);
                    root = root->right;
                    pre->right = NULL;
                }
            }else{
                root = root->right;
            }
        }
        return ans;
    }
    void morrisReverse(TreeNode* from, TreeNode* to){
        if(from == to) return;
        TreeNode* pre = from, *cur = pre->right;
        while(pre != to){
            TreeNode *nxt = cur->right;
            cur->right = pre;
            pre = cur;
            cur = nxt;
        }
        return;
    }
    void morrisReverseAdd(TreeNode* from, TreeNode* to, vector<int>& ans){
        morrisReverse(from, to);
        TreeNode* cur = to;
        while(cur != from){
            ans.push_back(cur->val);
            cur = cur->right;
        }
        ans.push_back(cur->val);
        morrisReverse(to, from);
    }
};
```

