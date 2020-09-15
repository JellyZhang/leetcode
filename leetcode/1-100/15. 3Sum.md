#### 15. 3Sum

> Given an array `nums` of *n* integers, are there elements *a*, *b*, *c* in `nums` such that *a* + *b* + *c* = 0? Find all unique triplets in the array which gives the sum of zero.
>
> **Note:**
>
> The solution set must not contain duplicate triplets.
>
> **Example:**
>
> ```
> Given array nums = [-1, 0, 1, 2, -1, -4],
> 
> A solution set is:
> [
> [-1, 0, 1],
> [-1, -1, 2]
> ]
> ```

```c++
vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size() && nums[i] <= 0;i++){
            if(i-1 >= 0 && nums[i] == nums[i-1]) continue;
            int p = i+1;
            int q = nums.size()-1;
            int target = -nums[i];
          // not p <= q
            while(p < q){  
                if(nums[p] + nums[q] < target) p++;
                else if(nums[p] + nums[q] > target) q--;
                else{
                    ans.push_back({nums[i],nums[p],nums[q]});
                    while(p < q && nums[p] == nums[p+1]) p++;
                    p++;
                    while(p < q && nums[q] == nums[q-1]) q--;
                    q--;
                }
            }
        }
        return ans;
    }
```

sort and travel  all negative number, assume it number one.

then two pointer. find two number add up to -number one.

Note: avoid duplicate by scanning with next one.