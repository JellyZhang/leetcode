/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return head;
        Node* p = head;
        //double node
        while(p){
            Node* temp = new Node(p->val,p->next,p->random);
            p->next = temp;
            p = temp->next;
        }
        //fix random
        p = head;
        while(p){
            p=p->next;
            if(p->random){
                p->random = p->random->next;
            }
            p=p->next;
        }
        //split
        p=head;
        Node* q = head->next;
        Node* rtn = head->next;
        while(p){
            q = p->next;
            p->next = q->next;
            p = p->next;
            if(p)
                q->next = p->next;
        }
        return rtn;
    }
};
