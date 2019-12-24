class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        if(len==0)
            return {};
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        vector<vector<int>>dp(len,vector<int>());
        for(int i=0;i<len;++i){
            if(dict.find(s.substr(0,i+1))!=dict.end()){
                dp[i].push_back(-1);
            }
            for(int j=0;j<i;j++){
                if(dp[j].size()>=1 && dict.find(s.substr(j+1,i-j))!=dict.end()){
                    dp[i].push_back(j);
                }
            }
        }
        if(dp[len-1].size()==0)
            return {};
        vector<string>ans;
        string selected="";
        dfs(s,dp,len-1,selected,ans);
        return ans;
    }
    void dfs(string&s,vector<vector<int>>&dp,int index,string selected,vector<string>&ans){
        if(index==-1){
            selected.pop_back();
            ans.push_back(selected);
            return;
        }
        for(int i=0;i<dp[index].size();++i){
            string temp;
            if(dp[index][i]==-1){
                temp = s.substr(0,index+1);
            }
            else{
                temp = s.substr(dp[index][i]+1,index-dp[index][i]);
            }
            temp+=" ";
            temp+=selected;
            dfs(s,dp,dp[index][i],temp,ans);
        }
    }
};
