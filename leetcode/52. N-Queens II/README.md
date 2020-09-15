> The *n*-queens puzzle is the problem of placing *n* queens on an *n*×*n* chessboard such that no two queens attack each other.
>
> ![img](README.assets/8-queens-20200830221732465.png)
>
> Given an integer *n*, return the number of distinct solutions to the *n*-queens puzzle.
>
> **Example:**
>
> ```
> Input: 4
> Output: 2
> Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
> [
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
> ```

```cpp
class Solution {
public:
    unordered_map<int,int> visited_col;
    unordered_map<int,int> visited_slash;
    unordered_map<int,int> visited_rslash;
    int totalNQueens(int n) {
        int ans = 0;
        dfs(ans, n, 0);
        return ans;
    }
    void dfs(int& ans, int n, int i){
        if(i == n){
            ans++;
            return;
        }
        for(int j=0;j<n;++j){
            if(!visited_col[j] && !visited_slash[i-j] && !visited_rslash[i+j]){
                string t(n, '.');
                t[j] = 'Q';
                setVisit(i, j, 1);
                dfs(ans, n, i+1);
                setVisit(i, j, 0);
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

similar to #51.