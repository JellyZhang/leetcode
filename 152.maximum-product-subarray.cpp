class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        vector<pair<int,int>>dp(len);
        dp[0].first = nums[0];
        dp[0].second = nums[0];
        for(int i=1;i<len;++i){
            if(nums[i]>0){
                dp[i].first = max(nums[i],nums[i]*dp[i-1].first);
                dp[i].second = min(nums[i],nums[i]*dp[i-1].second);
            }
            else{
                dp[i].first = max(nums[i],nums[i]*dp[i-1].second);
                dp[i].second = min(nums[i],nums[i]*dp[i-1].first);
            }
        }
        int ans = nums[0];
        for(int i=1;i<len;++i){
            ans = max(ans,dp[i].first);
        }
        return ans;
    }
};
