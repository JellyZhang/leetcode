class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_map<string,int>dict;
        for(int i=0;i<wordList.size();++i){
            dict[wordList[i]]=1;
        }
        q.push(beginWord);
        int cnt=1;
        int ans=1;
        while(!q.empty()){
            string cur = q.front();q.pop();
            //cout<<cur<<" ";
            if(cur==endWord)
                break;
            for(int i=0;i<beginWord.size();++i){
                for(int j=0;j<26;++j){
                    string temp = cur;
                    temp[i]='a'+j;
                    if(dict.find(temp)!=dict.end()){
                        q.push(temp);
                        dict.erase(temp);
                    }
                }
            }
            if(--cnt==0){
                ans++;
                cnt=q.size();
                if(cnt==0)
                    ans=0;
            }
        }
        return ans;
    }
};
