> Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sums to `target`.
>
> Each number in `candidates` may only be used **once** in the combination.
>
> **Note:**
>
> - All numbers (including `target`) will be positive integers.
> - The solution set must not contain duplicate combinations.
>
> **Example 1:**
>
> ```
> Input: candidates = [10,1,2,7,6,1,5], target = 8,
> A solution set is:
> [
>   [1, 7],
>   [1, 2, 5],
>   [2, 6],
>   [1, 1, 6]
> ]
> ```
>
> **Example 2:**
>
> ```
> Input: candidates = [2,5,2,1,2], target = 5,
> A solution set is:
> [
>   [1,2,2],
>   [5]
> ]
> ```

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> selected;
        vector<vector<int>> ans;
        dfs(candidates, 0, selected, target, ans);
        return ans;
        
    }
    void dfs(vector<int>& candidates, int index, vector<int>& selected, int target, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(selected);
            return;
        }
        for(int i=index;i<candidates.size();++i){
            if(candidates[i] > target) break;
            if(i-1 >= 0 && candidates[i] == candidates[i-1] && i > index) continue;
            selected.push_back(candidates[i]);
            dfs(candidates, i+1, selected, target-candidates[i], ans);
            selected.pop_back();
        }
    }
};
```

为了避免重复的答案，dfs每次的语意为：组合中的第1个、组合中的第二个。

比如主函数第一次进入dfs函数栈时，那么里面的for循环表示：遍历所有candidates，当它们其中之一为【答案中的第一个】时的情况。因此需要` if(i-1 >= 0 && candidates[i] == candidates[i-1] && i > index) continue;`来去重。因此【答案中的第一个】这个位置我们已经用candidates[i]试过了，所以不用再试了。



