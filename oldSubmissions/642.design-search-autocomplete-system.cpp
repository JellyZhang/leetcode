class Trie{
    vector<Trie*>nxt;
    unordered_map<string,int>times;
    struct Node{
        string str;
        int time;
        friend bool operator<(const Node &x,const Node &y){
            if(x.time==y.time){
                return x.str>y.str;
            }
            return x.time<y.time;
        }
        Node(unordered_map<string,int>::iterator it){
            str = it->first;
            time = it->second;
        }
    };
public:
    Trie(){
        nxt.assign(128,NULL);
        times.clear();
    }
    void insert(string word,int time){
        Trie* cur = this;
        for(char c:word){
            if(cur->nxt[c] == NULL)
                cur->nxt[c] = new Trie();
            cur = cur->nxt[c];
            if(cur->times.count(word)){
                cur->times[word]+=time;
            }
            else
                cur->times[word]=time;
        }
    }
    
    vector<string> searchhot(){
        priority_queue<Node>pq;
        for(auto it = times.begin();it!=times.end();it++){
            Node temp(it);
            pq.push(temp);
        }
        int cnt=3;
        vector<string> ans;
        while(!pq.empty() && cnt){
            Node top = pq.top();pq.pop();
            ans.push_back(top.str);
            cnt--;
        }
        return ans;
    }
    Trie* stepone(char input){
        return nxt[input];
    }
};


class AutocompleteSystem {
    string inputs;
    Trie* records;
    Trie* curr;
    string temp;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        records = new Trie();
        curr = records;
        temp = "";
        for(int i=0;i<sentences.size();++i){
            addstring(sentences[i],times[i]);
        }
        //auto ans = records->searchhot();
        //cout<<ans.size()<<" ";
        //for(auto str:ans){
            //cout<<str<<" ";
        //}
    }
    void addstring(string str, int time){
        records->insert(str,time);
    }
    vector<string> input(char c) {
        if(c=='#'){
            addstring(temp,1);
            temp = "";
            curr = records;
            return {};
        }
        temp+=c;
        if(!curr)
            return {};
        curr = curr->stepone(c);
        if(!curr)
            return {};
        auto ans = curr->searchhot();
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
