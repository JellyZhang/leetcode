class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp = {1};
        while(rowIndex--){
            dp.push_back(1);
            for(int i=dp.size()-2;i>=1;--i){
                dp[i]+=dp[i-1];
            }
        }
        return dp;
    }
};
