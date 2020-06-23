> Given an array of integers `nums` sorted in ascending order, find the starting and ending position of a given `target` value.
>
> Your algorithm's runtime complexity must be in the order of *O*(log *n*).
>
> If the target is not found in the array, return `[-1, -1]`.
>
> **Example 1:**
>
> ```
> Input: nums = [5,7,7,8,8,10], target = 8
> Output: [3,4]
> ```
>
> **Example 2:**
>
> ```
> Input: nums = [5,7,7,8,8,10], target = 6
> Output: [-1,-1]
> ```

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = lower_bound(nums, target);
        if(low <= -1 || low >= nums.size() || nums[low] != target){
            return {-1, -1};
        }
        return {low, upper_bound(nums, target) -1};
    }
    int lower_bound(vector<int>& nums, int target){
        int lo = 0, hi = nums.size()-1, mid;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] >= target){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        return lo;
    }
    int upper_bound(vector<int>& nums, int target){
        int lo = 0, hi = nums.size()-1, mid;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] > target){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};
```

1. recall lower_bound and upper_bound

2. we find lower_bound first

   - if the number not exist, we can just return {-1, -1}

   - if the number exists, then lower_bound function can find it's lower_bound.

     then we user upper_bound -1 to find the last position of the number.