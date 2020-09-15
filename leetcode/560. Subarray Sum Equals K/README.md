> Given an array of integers and an integer **k**, you need to find the total number of continuous subarrays whose sum equals to **k**.
>
> **Example 1:**
>
> ```
> Input:nums = [1,1,1], k = 2
> Output: 2
> ```
>
>  
>
> **Constraints:**
>
> - The length of the array is in range [1, 20,000].
> - The range of numbers in the array is [-1000, 1000] and the range of the integer **k** is [-1e7, 1e7].

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> presumCnt;
        int sum = 0;
        int ans = 0;
        presumCnt[0] = 1;
        for(int i=0;i<nums.size();++i){
            sum += nums[i];
            ans += presumCnt[sum-k];
            presumCnt[sum]++;
        }
        return ans;
    }
};
```

