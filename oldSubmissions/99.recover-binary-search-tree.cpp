class Solution {
public:
//    TreeNode *last,*first,*second;
    void recoverTree(TreeNode* root) {
        if(root==NULL || !root->left && !root->right ){
            return;
        }
        TreeNode *node=root,*first=NULL,*second=NULL,*last=NULL;


        //recursive
        //stack<TreeNode*>sta;
        //while(!sta.empty() || node!=NULL){
            //while(node!=NULL){
                //sta.push(node);
                //node = node->left;
            //}
            //node = sta.top();
            //sta.pop();
            ////visit
            //if(last!=NULL && first==NULL && node->val<last->val){
                //first = last;
            //}
            //if(last!=NULL && first!=NULL && node->val<last->val){
                //second = node;
            //}
            //last = node;
            //node = node->right;
        //}
        //cout<<first->val<<" "<<second->val;
        //
        //
        //morris
        while(node){
            if(node->left==NULL){
                //visit
                if(last!=NULL && node->val<last->val){
                    if(first==NULL){
                        first = last;
                    }
                    second = node;
                }
                last = node;
                //visit over
                node = node->right;
            }
            else{
                TreeNode* tmp = node->left;
                while(tmp->right!=NULL && tmp->right!=node){
                    tmp = tmp->right;
                }
                if(tmp->right==node){
                    //visit
                    if(last!=NULL && node->val<last->val){
                        if(first==NULL){
                            first = last;
                        }
                        second = node;
                    }
                    last = node;
                    //visit over
                    tmp->right = NULL;
                    node = node->right;
                }
                else{
                    tmp->right = node;
                    node = node->left;
                }
            }
        }
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
        return;
    }
    //void inorder(TreeNode* root){
        //if(root->left){
            //inorder(root->left);
        //}
        ////visit
        ////if(last!=NULL){
            ////cout<<"last="<<last->val;
        ////}
        //if(last!=NULL && root->val<last->val){
            //if(first == nullptr){
                //first = last;
                //second = root;
                ////cout<<"first"<<first->val;
            //}
            //else{
                //second = root;
                ////cout<<"second"<<second->val;
            //}
        //}
        //last = root;
        ////cout<<"root"<<root->val;
        //if(root->right){
            //inorder(root->right);
        //}
    //}
};

