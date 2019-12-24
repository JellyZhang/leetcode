/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    vector<int> BSTnums;
    int index;
    void inorderTravel(TreeNode* root){
        if(!root)
            return;
        inorderTravel(root->left);
        BSTnums.push_back(root->val);
        inorderTravel(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        inorderTravel(root);
        index = 0;
    }
    
    /** @return the next smallest number */
    int next() {
        return BSTnums[index++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(index == BSTnums.size())
            return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
