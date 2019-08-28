class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<vector<string>>q;
        q.push(vector<string>{beginWord});
        int cnt=1;
        vector<string> visited;
        bool finish = false;
        while(!q.empty()){
            vector<string> curpath = q.front();q.pop();
            //for(string t:curpath){
                //cout<<t<<" ";
            //}
            //cout<<endl;
            for(int i=0;i<beginWord.size();++i){
                for(int j=0;j<26;++j){
                    string temp = curpath.back();
                    temp[i]='a'+j;
                    //cout<<"check"<<temp<<" ";
                    if(s.find(temp)!=s.end()){
                        vector<string> newpath = curpath;
                        newpath.push_back(temp);
                        q.push(newpath);
                        visited.push_back(temp);
                        if(temp==endWord)
                            finish = true;
                    }
                }
            }
            if(--cnt==0){
                if(finish)
                    break;
                for(string to_remove:visited)
                    s.erase(to_remove);
                visited.clear();
                cnt = q.size();
            }
        }
        vector<vector<string>>ans;
        while(!q.empty()){
            vector<string> cur = q.front();q.pop();
            if(cur.back()==endWord){
                ans.push_back(cur);
            }
        }
        return ans;
        
    }
};
