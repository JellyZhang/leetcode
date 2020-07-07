> Given an unsorted integer array, find the smallest missing positive integer.
>
> **Example 1:**
>
> ```
> Input: [1,2,0]
> Output: 3
> ```
>
> **Example 2:**
>
> ```
> Input: [3,4,-1,1]
> Output: 2
> ```
>
> **Example 3:**
>
> ```
> Input: [7,8,9,11,12]
> Output: 1
> ```
>
> **Note:**
>
> Your algorithm should run in *O*(*n*) time and uses constant extra space.

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        while(i <= j){
            if(nums[i] == i+1){
                i++;
            }else if(nums[i] >= i+1 && nums[i]-1 <= j && nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }else{
                swap(nums[i], nums[j]);
                j--;
            }
        }
        return i+1;
    }
};
```

https://leetcode.com/problems/first-missing-positive/discuss/360518/My-cpp-solution-O(n)-time-O(1)-space-easy-to-understand