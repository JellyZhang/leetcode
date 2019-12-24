class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int dp[55][55][55];
        memset(dp,0,sizeof(dp));
        int n = grid.size();
        dp[0][0][0] = grid[0][0];
        for(int step=1;step<=2*(n-1);++step){
            for(int x1=0;x1<n;x1++){
                int y1 = step-x1;
                if(!(y1>=0 && y1<n))
                    continue;
                for(int x2=0;x2<n;x2++){
                    int y2 = step - x2;
                    if(!(y2>=0 && y2<n))
                        continue;
                    bool canreach = false;
                    int temp_max = -1;
                    if(x1-1>=0 && x2-1>=0 && dp[x1-1][y1][x2-1]!=-1)
                        temp_max = max(temp_max,dp[x1-1][y1][x2-1]);
                    if(x1-1>=0 && y2-1>=0 && dp[x1-1][y1][x2]!=-1)
                        temp_max = max(temp_max,dp[x1-1][y1][x2]);
                    if(y1-1>=0 && y2-1>=0 && dp[x1][y1-1][x2]!=-1)
                        temp_max = max(temp_max,dp[x1][y1-1][x2]);
                    if(y1-1>=0 && x2-1>=0 && dp[x1][y1-1][x2-1]!=-1)
                        temp_max = max(temp_max,dp[x1][y1-1][x2-1]);
                    //cant reach
                    if(temp_max==-1|| grid[x1][y1]==-1 || grid[x2][y2]==-1){
                        dp[x1][y1][x2] = -1;
                        //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" ="<<dp[x1][y1][x2]<<endl;
                        continue;
                    }
                    if(x1==x2 && y1==y2)
                        temp_max+=grid[x1][y1];
                    else
                        temp_max+=grid[x1][y1]+grid[x2][y2];
                    dp[x1][y1][x2] = temp_max;
                    //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" ="<<dp[x1][y1][x2]<<endl;
                }
            }
        }
        return dp[n-1][n-1][n-1]==-1?0:dp[n-1][n-1][n-1];
    }
};
