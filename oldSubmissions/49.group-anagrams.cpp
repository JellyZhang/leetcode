class Solution {
public:
    struct Node{
        string str;
        int index;
        Node(string _str,int _index){
            str=_str;
            index=_index;
        }
    };
    struct cmp{
        bool operator()(Node a,Node b){
            return a.str<b.str;
        }
    };
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<Node> Nodes;
        vector<vector<string>> ans;
        if(strs.empty()){
            return ans;
        }
        for(int i=0;i<strs.size();++i){
            Node temp(strs[i],i);
            sort(temp.str.begin(),temp.str.end());
            Nodes.push_back(temp);
        }
        sort(Nodes.begin(),Nodes.end(),[](const Node& a,const Node& b){return a.str<b.str;});
        //for(int i=0;i<Nodes.size();++i){
            //cout<<"|"<<Nodes[i].str<<" "<<Nodes[i].index;
        //}
        int now =0;
        vector<string> sum;
        sum.push_back(strs[Nodes[now].index]);
        for(int i=1;i<Nodes.size();++i){
            if(Nodes[i].str==Nodes[now].str){
                sum.push_back(strs[Nodes[i].index]);
            }
            else{
                ans.push_back(sum);
                sum.clear();
                now = i;
                sum.push_back(strs[Nodes[now].index]);
            }
        }
        if(!sum.empty()){
            ans.push_back(sum);
        }
        return ans;
        
    }
};
