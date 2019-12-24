/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return head;
        flattenHelper(head);
        return head;
    }
    Node* flattenHelper(Node* head){
        Node* cur = head;
        while(cur->next || cur->child){
            if(cur->child){
                Node* tail = flattenHelper(cur->child);
                if(cur->next){
                    tail->next = cur->next;
                    cur->next->prev = tail;
                }
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = NULL;
                cur = tail;
            }
            else{
                cur = cur->next;
            }
        }
        return cur;
    }
};
// @lc code=end
