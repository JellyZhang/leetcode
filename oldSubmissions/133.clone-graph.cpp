/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        //unordered_map<Node*,int>visited;
        ////bfs to double
        //queue<Node*>q;
        //q.push(node);
        //visited[node]=1;
        //while(!q.empty()){
            //Node* cur = q.front();q.pop();
            //Node* newNode = new Node(cur->val,cur->neighbors);
            //cur->neighbors.push_back(newNode);
            //vector<Node*> &neib = cur->neighbors;
            //for(int i=0;i<neib.size()-1;++i){
                //if(visited.find(neib[i])==visited.end()){
                    //visited[neib[i]]=1;
                    ////cout<<"push"<<neib[i]->val;
                    //q.push(neib[i]);
                //}
            //}
        //}
        ////fix neighbors
        //visited.clear();
        //q.push(node->neighbors.back());
        //visited[node->neighbors.back()]=1;
        //while(!q.empty()){
            //Node* cur = q.front();q.pop();
            //auto &neib = cur->neighbors;
            //for(int i=0;i<neib.size();++i){
                //neib[i] = neib[i]->neighbors.back();
                //if(visited.find(neib[i])==visited.end()){
                    //visited[neib[i]]=1;
                    //q.push(neib[i]);
                //}
            //}
        //}
        ////remove connection to double
        //Node* ans = node->neighbors.back();
        //visited.clear();
        //q.push(node);
        //visited[node]=1;
        //while(!q.empty()){
            //Node* cur = q.front();
            //q.pop();
            //cur->neighbors.pop_back();
            ////cout<<cur->val<<" ";
            //for(int i=0;i<cur->neighbors.size();++i){
                //if(visited.find(cur->neighbors[i])==visited.end()){
                    //visited[cur->neighbors[i]]=1;
                    //q.push(cur->neighbors[i]);
                //}
            //}
        //}
        unordered_map<Node*,Node*>m;
        queue<Node*>q;
        q.push(node);
        Node* newNode = new Node(node->val,{});
        m[node]=newNode;
        while(!q.empty()){
            Node* cur = q.front();q.pop();
            for(int i=0;i<cur->neighbors.size();++i){
                if(m.find(cur->neighbors[i])==m.end()){
                    Node* newNode = new Node(cur->neighbors[i]->val,{});
                    m[cur->neighbors[i]]=newNode;
                    q.push(cur->neighbors[i]);
                }
                m[cur]->neighbors.push_back(m[cur->neighbors[i]]);
            }
        }
        return m[node];
    }
};