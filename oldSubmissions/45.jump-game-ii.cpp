#include <limits.h>
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1){
            return 0;
        }
        vector<int> dp(len,INT_MAX);
        dp[0]=0;
        for(int i=0;i<len-1;++i){
            for(int step=1;step<=nums[i];++step){
                int nxt = i+step;
                if(nxt>=len){
                    break;
                }
                dp[nxt] = min(dp[nxt],dp[i]+1);
            }
            int max_reach = min(len-1,i+nums[i]);
            while(i+1<len-1 && nums[i+1]+i+1<=max_reach){
                ++i;
            }
        }
        return dp[len-1];
    }
};
