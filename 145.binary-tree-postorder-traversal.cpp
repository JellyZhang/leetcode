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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int>ans;
        //recursive(root,ans);
        //iterative(root,ans);
        morris(root,ans);
        return ans;
    }
    void recursive(TreeNode* root,vector<int>&ans){
        if(!root)
            return;
        recursive(root->left,ans);
        recursive(root->right,ans);
        ans.push_back(root->val);
        return;
    }
    void iterative(TreeNode* root,vector<int>&ans){
        stack<TreeNode*>s;
        s.push(root);
        deque<int>dq;
        while(!s.empty()){
            TreeNode* cur = s.top();s.pop();
            dq.push_front(cur->val);
            if(cur->left)
                s.push(cur->left);
            if(cur->right)
                s.push(cur->right);
        }
        ans.assign(dq.begin(),dq.end());
    }
    void morris(TreeNode* root,vector<int>&ans){
        TreeNode* dummy = new TreeNode(0);
        dummy->left = root;
        root = dummy;
        while(root){
            if(root->left){
                TreeNode* pre = root->left;
                //find left subtree's right most child
                while(pre->right && pre->right!=root){
                    pre = pre->right;
                }
                if(!pre->right){
                    pre->right = root;
                    root = root->left;
                }
                else{
                    TreeNode* tmp = pre;
                    reverse(root->left,pre);
                    while(tmp!=root->left){
                        //visit
                        ans.push_back(tmp->val);
                        tmp = tmp->right;
                    }
                    ans.push_back(tmp->val);
                    reverse(pre,root->left);
                    pre->right = NULL;
                    root = root->right;
                }
            }
            else{
                root=root->right;
            }
        }
    }
    void reverse(TreeNode* start,TreeNode*end){
        if(start==end)
            return;
        TreeNode* prev = start;
        TreeNode* node = start->right;
        while(prev!=end){
            TreeNode* nxt = node->right;
            node->right = prev;
            prev = node;
            node = nxt;
        }
    }
};
