> Given a collection of **distinct** integers, return all possible permutations.
>
> **Example:**
>
> ```
> Input: [1,2,3]
> Output:
> [
>   [1,2,3],
>   [1,3,2],
>   [2,1,3],
>   [2,3,1],
>   [3,1,2],
>   [3,2,1]
> ]
> ```

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
            }
        }
    }
};
```



simple dfs.