class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0||n==0){
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int row=0;row<n;++row){
            for(int col=0;col<m;++col){
                if(row==0 || col==0){
                    dp[row][col]=1;
                }
                else{
                    dp[row][col] = dp[row-1][col]+dp[row][col-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};
