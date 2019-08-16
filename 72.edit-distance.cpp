#include <unordered_map>
class Solution {
public:

    unordered_map<char,vector<int>> exist_pos_2;
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        for(int i=0;i<=len1;++i){
            for(int j=0;j<=len2;++j){
                if(i*j==0){
                    dp[i][j]=i+j;
                }
                else if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                }
            }
        }
        return dp[len1][len2];
    }
};
