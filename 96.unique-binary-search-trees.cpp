class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        if(n<=1){
            return 1;
        }
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;++i){
            for(int j=0;j<=(i-1)>>1;++j){
                dp[i]+=2*dp[j]*dp[i-1-j];
            }
            if(i%2==1){
                dp[i]-=dp[i/2]*dp[i/2];
            }
        }
        return dp[n];
    }
};
