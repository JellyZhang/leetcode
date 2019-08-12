class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int len_row = obstacleGrid.size();
        if(len_row==0){
            return 0;
        }
        int len_col = obstacleGrid[0].size();
        vector<vector<long long>> dp(len_row,vector<long long>(len_col,1));
        int flag=1;
        for(int i=0;i<len_col;++i){
            if(obstacleGrid[0][i]==1){
                flag=0;
            }
            dp[0][i]=flag;
        }
        flag=1;
        for(int i=0;i<len_row;++i){
            if(obstacleGrid[i][0]==1){
                flag=0;
            }
            dp[i][0]=flag;
        }
        for(int i=1;i<len_row;++i){
            for(int j=1;j<len_col;++j){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=dp[i][j-1]+dp[i-1][j];
                }
            }
        }
        return dp[len_row-1][len_col-1];
        
    }
};
