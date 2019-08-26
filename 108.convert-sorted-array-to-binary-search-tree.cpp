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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        return helper(nums,0,nums.size()-1);
    }
    TreeNode* helper(vector<int>& nums,int s,int e){
        //cout<<s<<" "<<e<<" ";
        if(s>e)
            return NULL;
        int mid =(s+e)/2;
        //cout<<mid<<endl;
        auto left = helper(nums,s,mid-1);
        auto right = helper(nums,mid+1,e);
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = left;
        root->right = right;
        return root;
    }
};
