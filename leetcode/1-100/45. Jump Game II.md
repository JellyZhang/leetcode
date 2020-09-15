> Given an array of non-negative integers, you are initially positioned at the first index of the array.
>
> Each element in the array represents your maximum jump length at that position.
>
> Your goal is to reach the last index in the minimum number of jumps.
>
> **Example:**
>
> ```
> Input: [2,3,1,1,4]
> Output: 2
> Explanation: The minimum number of jumps to reach the last index is 2.
>     Jump 1 step from index 0 to 1, then 3 steps to the last index.
> ```
>
> **Note:**
>
> You can assume that you can always reach the last index.



```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int cur_max = 0;
        int nxt_max = 0;
        for(int i=0;i<nums.size();++i){        
            if(i > cur_max){
                // we have checked all the possisble pos we can reach with this min step.
	            // now we have to step++ to go farther.
                step++;
                cur_max = nxt_max;
            }
            nxt_max = max(nxt_max, i+nums[i]);
            if(i == nums.size()-1) return step;
        }
        return step;
    }
};
```

first we traval all possible poses we can reach with only 1 step, and while doing this, record the farthest pos we can get if we take the 2ed step.