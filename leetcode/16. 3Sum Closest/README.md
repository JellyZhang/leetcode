#### 16. 3Sum Closest

> Given an array `nums` of *n* integers and an integer `target`, find three integers in `nums` such that the sum is closest to `target`. Return the sum of the three integers. You may assume that each input would have exactly one solution.
>
> **Example:**
>
> ```
> Given array nums = [-1, 2, 1, -4], and target = 1.
> 
> The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
> ```

```c++
int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(),nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for(int i=0;i<nums.size();i++){
            if(i-1 >= 0 && nums[i] == nums[i-1]) continue;
            int p = i+1;
            int q = nums.size()-1;
            int t = target - nums[i];
          // not p <= q
            while(p < q){ 
                if(abs(t - nums[p] - nums[q]) < abs(target - ans)) 
                    ans = nums[i] + nums[p] + nums[q];
                if(nums[p] + nums[q] < t) p++;
                else if(nums[p] + nums[q] > t) q--;
                else break;
            }
        }
        return ans;
    }
```

similar to previous one.

Note : the pick-up of ans is different. And travel i to the end of array.