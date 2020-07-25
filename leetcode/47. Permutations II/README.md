> Given a collection of numbers that might contain duplicates, return all possible unique permutations.
> 
> **Example:**
> 
> ```
> Input: [1,1,2]
> Output:
> [
>   [1,1,2],
>   [1,2,1],
>   [2,1,1]
> ]
> ```

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> selected;
        vector<bool> visited(nums.size(), false);
        dfs(nums, visited, ans, selected);
        return ans;
    }
    void dfs(vector<int>& nums, vector<bool>& visited, vector<vector<int>>& ans, vector<int>& selected){
        if(selected.size() == nums.size()){
            ans.push_back(selected);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(!visited[i]){
                visited[i] = true;
                selected.push_back(nums[i]);
                dfs(nums, visited, ans, selected);
                selected.pop_back();
                visited[i] = false;
                // two more lines than #46
                while(i+1 < nums.size() && nums[i] == nums[i+1]) {
                    i++;
                }
            }

        }
    }
};
```

just two more lines than #46.

```
while(i+1 < nums.size() && nums[i] == nums[i+1]) {
      i++;
}
```


