class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int rtn=1;
        int* dp = new int[nums.size()];
        dp[0]=1;
        for(int i=1;i<nums.size();i++){
            int max=-1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[j]>max){
                    max = dp[j];
                }
            }
            if(max==-1)dp[i]=1;
            else dp[i]=max+1;
            if(dp[i]>rtn)rtn=dp[i];
        }
        return rtn;
    }
};
