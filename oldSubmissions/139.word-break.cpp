class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        int len = s.size();
        if(len==0)
            return false;
        vector<int>dp(len,0);
        for(int i=0;i<len;++i){
            if(dict.find(s.substr(0,i+1))!=dict.end()){
                dp[i]=1;
                continue;
            }
            for(int j=0;j<i;j++){
                if(dp[j]==1 && dict.find(s.substr(j+1,i-j))!=dict.end()){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[len-1];
    }
};
