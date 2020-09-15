> Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
>
> **Example:**
>
> ```
> Input: [-2,1,-3,4,-1,2,1,-5,4],
> Output: 6
> Explanation: [4,-1,2,1] has the largest sum = 6.
> ```
>
> **Follow up:**
>
> If you have figured out the O(*n*) solution, try coding another solution using the divide and conquer approach, which is more subtle.



```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        vector<int> dp(n, 0);
        int ans = dp[0] = nums[0];
        for(int i=1;i<n;++i){
            dp[i] = max(dp[i-1], 0) + nums[i];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```

simple dp.

dp[i] --> maxSubString  that ends at nums[i]. 

if dp[i-1] > 0 , which means dp[i] using the maxSubarray before will be greater than only nums[i].