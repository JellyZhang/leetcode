class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        if(len1*len2==0)
            return 0;
        long long  dp[len2][len1]={0};
        int temp=0;
        for(int i=0;i<len1;++i){
            if(s[i]==t[0]){
                temp++;
            }
            dp[0][i]=temp;

        }
        for(int i=1;i<len2;++i){
            for(int j=i;j<len1;j++){
                if(s[j]==t[i]){
                    dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[len2-1][len1-1];
        
    }
};
