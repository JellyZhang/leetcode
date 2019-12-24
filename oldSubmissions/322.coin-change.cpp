class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        //for(int j=0;j<=amount;++j){
            //if(j%coins[0]==0){
                //dp[0][j]=j/coins[0];
            //}
        //}
        //for(int i=1;i<coins.size();++i){
            //for(int j=0;j<=amount;++j){
                //int k =0;
                //int temp_min = INT_MAX;
                ////if(i==1)
                    ////cout<<"j="<<j<<" ";
                //while(j-k*coins[i]>=0){
                    ////if(i==1){
                        //////cout<<k<<" ";
                    ////}
                    //if(dp[i-1][j-k*coins[i]]!=-1){
                        //temp_min = min(temp_min,dp[i-1][j-k*coins[i]]+k);
                    //}
                    //k++;
                //}
                //if(temp_min==INT_MAX)
                    //dp[i][j]=-1;
                //else
                    //dp[i][j] = temp_min;
            //}
        //}
        ////for(int i=0;i<coins.size();++i){
            ////for(int j=0;j<=amount;++j){
                ////if(dp[i][j]==INT_MAX)
                    ////cout<<"-1"<<" ";
                ////else
                    ////cout<<dp[i][j]<<" ";
            ////}
            ////cout<<endl;
        ////}
        //n^3
        //return dp[coins.size()-1][amount];
        vector<int>dp(amount+1,amount+1);//if only coin is 1, then max is amount, so amount+1 is impossible
        dp[0] = 0;
        for(int i=1;i<=amount;++i){
            for(int j=0;j<coins.size();++j){
                if(i-coins[j]>=0){
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        //n^2
        return (dp[amount]==amount+1)?(-1):(dp[amount]);
    }
};
