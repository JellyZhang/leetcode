#### 1. Two Sum

> Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.
>
> You may assume that each input would have **exactly** one solution, and you may not use the *same* element twice.

O(n) space to store all elements's pos,  O(1) time to check if exist.

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> pos;
        for(int i=0;i<nums.size();i++){
            if(pos.count(target-nums[i])){
                return vector<int>{i,pos[target-nums[i]]};
            }
            pos[nums[i]] = i;
        }
        // never reach
        return vector<int>{-1,-1};
    }
```

