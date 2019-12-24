/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return makeSerilize(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string temp;
        vector<int> nums;
       // cout<<data<<endl;
        while(getline(ss,temp,',')){
            //cout<<temp<<endl;
            nums.push_back(stoi(temp));
        }
        return makeDeserialize(nums,0,nums.size());
    }
    TreeNode* makeDeserialize(vector<int>& nums,int start,int end){
        if(start==end)
            return NULL;
        TreeNode* root = new TreeNode(nums[start]);
        int i = start + 1;
        while(i<end && nums[i]<nums[start]){
            i++;
        }
        root->left = makeDeserialize(nums,start+1,i);
        root->right = makeDeserialize(nums,i,end);
        return root;
    }
    string makeSerilize(TreeNode* root){
        if(!root)
            return "";
        string ans = to_string(root->val);
        ans += ',';
        ans += makeSerilize(root->left);
        ans += makeSerilize(root->right);
       // ans += ',';
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

