/*
 * @lc app=leetcode id=426 lang=cpp
 *
 * [426] Convert Binary Search Tree to Sorted Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root){
        if(!root)
            return NULL;
        Node* first = treeToDoublyListHelper(root);
        Node* last = findRightMost(root);
        last->right  = first;
        first->left = last;
        return first;
    }
    Node* treeToDoublyListHelper(Node* root){
        Node* first = root, *last = root;
        if(root->left){
            first = treeToDoublyListHelper(root->left);
            Node* rightMost = findRightMost(root->left);
            rightMost->right = root;
            root->left = rightMost;
        }
        if(root->right){
            Node* leftMost = treeToDoublyListHelper(root->right);
            root->right = leftMost;
            leftMost->left = root;
        }
        return first;
    }
    Node* findLeftMost(Node* root){
        Node* p = root;
        while(p->left)
            p = p->left;
        return p;
    }
    Node* findRightMost(Node* root){
        Node* p = root;
        while(p->right)
            p = p->right;
        return p;
    }

};
// @lc code=end
