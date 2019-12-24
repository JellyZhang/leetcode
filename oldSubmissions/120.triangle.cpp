class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0)
            return 0;
        vector<int> dp;
        dp.push_back(triangle[0][0]);
        for(int i=1;i<triangle.size();++i){
            dp.push_back(INT_MAX);
            for(int j=dp.size()-1;j>=1;j--){
                dp[j]=min(dp[j],dp[j-1])+triangle[i][j];
            }
            dp[0]+=triangle[i][0];
        }
        int ans=dp[0];
        for(int i=1;i<dp.size();++i){
            if(dp[i]<ans)
                ans=dp[i];
        }
        return ans;
    }
};
