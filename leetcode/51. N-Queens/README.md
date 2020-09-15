> The *n*-queens puzzle is the problem of placing *n* queens on an *n*×*n* chessboard such that no two queens attack each other.
>
> ![img](README.assets/8-queens.png)
>
> Given an integer *n*, return all distinct solutions to the *n*-queens puzzle.
>
> Each solution contains a distinct board configuration of the *n*-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space respectively.
>
> **Example:**
>
> ```
> Input: 4
> Output: [
>  [".Q..",  // Solution 1
>   "...Q",
>   "Q...",
>   "..Q."],
> 
>  ["..Q.",  // Solution 2
>   "Q...",
>   "...Q",
>   ".Q.."]
> ]
> Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
> ```

```cpp
class Solution {
public:
    unordered_map<int,int> visited_col;
    unordered_map<int,int> visited_slash;
    unordered_map<int,int> visited_rslash;
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> selected;
        dfs(ans, n, selected);
        return ans;
    }
    void dfs(vector<vector<string>>& ans, int n, vector<string>& selected){
        int i = selected.size();
        if(i == n){
            ans.push_back(selected);
            return;
        }
        for(int j=0;j<n;++j){
            if(!visited_col[j] && !visited_slash[i-j] && !visited_rslash[i+j]){
                string t(n, '.');
                t[j] = 'Q';
                selected.push_back(t);
                setVisit(i, j, 1);
                dfs(ans, n, selected);
                setVisit(i, j, 0);
                selected.pop_back();
            }
        }
    }
    void setVisit(int i, int j, int flag){
        visited_col[j] = flag;
        visited_slash[i-j] = flag;
        visited_rslash[i+j] = flag;
    }
};
```

simple backtrack dfs