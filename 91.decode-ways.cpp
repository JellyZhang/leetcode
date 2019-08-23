class Solution {
public:
    // mind 0
    int numDecodings(string s) {
        int len = s.size();
        if(len==0)
            return 0;
        if(len==1){
            if(s[0]=='0'){
                return 0;
            }
            else
                return 1;
        }
        vector<int> dp(len,0); // way to decode
        if(s[0]-'0'!=0){
            dp[0]=1;
        }
        if(s[0]-'0'==2 && s[1]-'0'<=6 || s[0]-'0'==1)
            dp[1]++;
        if(s[1]-'0'!=0 && s[0]-'0'!=0)
            dp[1]++;
        for(int i=2;i<len;++i){
            if(s[i-1]-'0'==2 && s[i]-'0'<=6 || s[i-1]-'0'==1){
                dp[i]+=dp[i-2];
            }
            if(s[i]-'0'!=0){
                dp[i]+=dp[i-1];
            }
        }
        //for(int i=0;i<len;++i){
            //cout<<dp[i]<<" ";
        //}
        return dp[len-1];
    }
};
