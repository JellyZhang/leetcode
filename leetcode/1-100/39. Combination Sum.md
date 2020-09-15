> Given a **set** of candidate numbers (`candidates`) **(without duplicates)** and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sums to `target`.
>
> The **same** repeated number may be chosen from `candidates` unlimited number of times.
>
> **Note:**
>
> - All numbers (including `target`) will be positive integers.
> - The solution set must not contain duplicate combinations.
>
> **Example 1:**
>
> ```
> Input: candidates = [2,3,6,7], target = 7,
> A solution set is:
> [
>   [7],
>   [2,2,3]
> ]
> ```
>
> **Example 2:**
>
> ```
> Input: candidates = [2,3,5], target = 8,
> A solution set is:
> [
>   [2,2,2,2],
>   [2,3,3],
>   [3,5]
> ]
> ```

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> selected(candidates.size(),0);
        dfs(candidates, target, selected, 0, ans);
        return ans;
        
    }
    void dfs(vector<int>& candidates, int target, vector<int>& selected, int index, vector<vector<int>>& ans){
        if(index == candidates.size()){
            if(target == 0){
                vector<int> temp;
                for(int i=0;i<selected.size();++i){
                    int times = selected[i];
                    while(times--){
                        temp.push_back(candidates[i]);
                    }
                }
                ans.push_back(temp);
            }
            return;
        }
        for(int i=0;i*candidates[index] <= target;++i){
            selected[index] = i;
            dfs(candidates, target - i*candidates[index], selected, index+1, ans);
            selected[index] = 0;
        }
    }
    
};
```

selecte[i]  means how many do we choose to use of candidates[i]