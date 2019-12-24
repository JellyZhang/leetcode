class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        if(len1*len2==0){
            return 0;
        }
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        for(int i=0;i<=len1;++i){
            for(int j=0;j<=len2;++j){
                if(i*j==0){
                    dp[i][j]=0;
                }
                else if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[len1][len2];
        
    }
};
