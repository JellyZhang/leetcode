> Given a *m* x *n* grid filled with non-negative numbers, find a path from top left to bottom right which *minimizes* the sum of all numbers along its path.
>
> **Note:** You can only move either down or right at any point in time.
>
> **Example:**
>
> ```
> Input:
> [
>   [1,3,1],
>   [1,5,1],
>   [4,2,1]
> ]
> Output: 7
> Explanation: Because the path 1→3→1→1→1 minimizes the sum.
> ```

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(!n) return 0;
        int m = grid[0].size();
        vector<vector<int>> minSum(n, vector<int>(m, INT_MAX));
        minSum[0][0] = grid[0][0];
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(i-1 >= 0) minSum[i][j] = min(minSum[i][j], minSum[i-1][j] + grid[i][j]);
                if(j-1 >= 0) minSum[i][j] = min(minSum[i][j], minSum[i][j-1] + grid[i][j]);
               // cout<<i<<" "<<j<<" "<<minSum[i][j]<<endl;
            }
        }
        return minSum[n-1][m-1];
    }
};
```

