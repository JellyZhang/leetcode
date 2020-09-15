> Find all possible combinations of ***k*** numbers that add up to a number ***n***, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
>
> **Note:**
>
> - All numbers will be positive integers.
> - The solution set must not contain duplicate combinations.
>
> **Example 1:**
>
> ```
> Input: k = 3, n = 7
> Output: [[1,2,4]]
> ```
>
> **Example 2:**
>
> ```
> Input: k = 3, n = 9
> Output: [[1,2,6], [1,3,5], [2,3,4]]
> ```

```cPP
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> selected;
        vector<vector<int>> ans;
        dfs(1, selected, ans, n, k);
        return ans;
        
    }
    void dfs(int cur, vector<int>& selected, vector<vector<int>>& ans, int target, int k){
        if(cur*k > target) return;
        if(k == 0){
            if(target == 0) ans.push_back(selected);
            return;
        }
        for(int i=cur;i*k <= target && i <= 9;++i){
            selected.push_back(i);
            dfs(i+1, selected, ans, target - i, k-1);
            selected.pop_back();
        }
    }
};
```

