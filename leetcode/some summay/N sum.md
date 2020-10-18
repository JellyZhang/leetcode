\1. Two Sum

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();++i){
            if(mp.count(target - nums[i])){
                return {i, mp[target - nums[i]]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
```



\15. 3Sum

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<n;++i){
            if(nums[i] > 0) break;
            if(i-1 >= 0 && nums[i] == nums[i-1]) continue;
            int p = i+1, q = n-1;
            while(p < q){
                if(nums[p] + nums[q] > -nums[i]){
                    q--;
                }else if(nums[p] + nums[q] < -nums[i]){
                    p++;
                }else{
                    ans.push_back({nums[i], nums[p], nums[q]});
                    while(p < q && nums[q] == nums[q-1]) q--;
                    q--;
                    while(p < q && nums[p] == nums[p+1]) p++;
                    p++;
                }
            }
        }
        return ans;
    }
};
```



\16. 3Sum Closest

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = num[0] + nums[1] + nums[2];
        for(int i=0;i<n;++i){
            if(i-1 >= 0 && nums[i] == nums[i-1]) continue;
            int p = i+1, q = n-1;
            while(p < q){
                if(abs(nums[p] + nums[q] + nums[i] - target) < abs(ans - target)){
                    ans = nums[p] + nums[q] + nums[i];
                }
                if(nums[p] + nums[q] > target - nums[i]){
                    q--;
                }else if(nums[p] + nums[q] < target - nums[i]){
                    p++;
                }else{
                    return target;
                }
            }
        }
        return ans;
    }
};
```



\18. 4Sum

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        if(n < 4) return {};
        for(int i=0;i<n;++i){
            if(i-1>=0 && nums[i-1] == nums[i]) continue;
            for(int j=i+1;j<n;++j){
                if(j-1>= i+1 && nums[j-1] == nums[j]) continue;
                int p = j+1, q = n-1;
                while(p < q){
                    if(nums[p] + nums[q] > target - nums[i] - nums[j]){
                        q--;
                    }else if(nums[p] + nums[q] < target - nums[i] - nums[j]){
                        p++;
                    }else{
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        while(p < q && nums[p] == nums[p+1]) p++;
                        p++;
                        while(p < q && nums[q] == nums[q-1]) q--;
                        q--;
                    }
                }
            }
        }
        return ans;
    }
};
```



#### [259. 3Sum Smaller](https://leetcode-cn.com/problems/3sum-smaller/)

```cpp
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 3) return 0;
        int ans = 0;
        for(int i=0;i<n;++i){
            int p = i+1, q = n-1;
            while(p < q){
                if(nums[p] + nums[q] >= target - nums[i]){
                    q--;
                }else{
                    ans += q - p;
                    p++;
                }
            }
        }
        return ans;
    }
};
```

