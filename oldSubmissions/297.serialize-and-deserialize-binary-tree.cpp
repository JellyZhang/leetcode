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
    vector<string> my_split(const string &str, char delim){
        stringstream ss(str);
        string token;
        vector<string> out;
        while(getline(ss,token,delim)){
            out.push_back(token);
        }
        return out;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "#";
        return to_string(root->val)+','+serialize(root->left)+','+serialize(root->right);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        //if(data=="#")
            //return NULL;
        return maketree(ss);
    }
    TreeNode* maketree(stringstream& ss){
        string str;
        getline(ss,str,',');
        if(str=="#"){
            return NULL;
        }else{
            TreeNode* root = new TreeNode(stoi(str));
            root->left = maketree(ss);
            root->right = maketree(ss);
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
