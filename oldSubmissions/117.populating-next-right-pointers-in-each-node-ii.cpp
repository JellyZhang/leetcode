/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    // travel level by level with "next ptr"
    Node* connect(Node* root) {
        Node* head =root;
        while(head){
            Node* cur = head;
            head = NULL;
            Node* pre = NULL;
            while(cur){
                if(head==NULL && (cur->left||cur->right)){
                    head = (cur->left)?(cur->left):(cur->right);
                }
                if(cur->left && cur->right){
                    if(pre!=NULL){
                        pre->next = cur->left;
                    }
                    cur->left->next = cur->right;
                    pre = cur->right;
                }
                else if(cur->left || cur->right){
                    Node *temp =(cur->left)?(cur->left):(cur->right); 
                    if(pre!=NULL){
                        pre->next = temp;
                    }
                    pre = temp;
                }
                cur=cur->next;
            }
        }
        return root;
    }
};
