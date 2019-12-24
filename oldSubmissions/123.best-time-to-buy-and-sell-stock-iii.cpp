class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        int k=2;
        vector<vector<int>>dp(k+1,vector<int>(prices.size(),0));
        // dp[0][all]=0
        for(int i=1;i<=k;++i){
            int tmpmax = dp[i-1][0]-prices[0];
            for(int j=1;j<prices.size();++j){
                dp[i][j]=max(dp[i][j-1],prices[j]+tmpmax);
                tmpmax = max(tmpmax,dp[i-1][j]-prices[j]);
            }
        }
        return dp[k][prices.size()-1];
    }
};
