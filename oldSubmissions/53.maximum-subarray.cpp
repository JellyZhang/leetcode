class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len =nums.size();
        int ans = INT_MIN;
        if(len==0){
            return ans;
        }
        vector<int> dp(len);
        //dp[i] : max sum subarray that ends with nums[i]
        dp[0]=nums[0];
        ans = dp[0];
        for(int i=1;i<len;++i){
            dp[i] = max(nums[i],dp[i-1]+nums[i]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
