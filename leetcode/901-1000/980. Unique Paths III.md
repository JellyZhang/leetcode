> On a 2-dimensional `grid`, there are 4 types of squares:
>
> - `1` represents the starting square. There is exactly one starting square.
> - `2` represents the ending square. There is exactly one ending square.
> - `0` represents empty squares we can walk over.
> - `-1` represents obstacles that we cannot walk over.
>
> Return the number of 4-directional walks from the starting square to the ending square, that **walk over every non-obstacle square exactly once**.
>
>  
>
> **Example 1:**
>
> ```
> Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
> Output: 2
> Explanation: We have the following two paths: 
> 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
> 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
> ```
>
> **Example 2:**
>
> ```
> Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
> Output: 4
> Explanation: We have the following four paths: 
> 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
> 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
> 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
> 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
> ```
>
> **Example 3:**
>
> ```
> Input: [[0,1],[2,0]]
> Output: 0
> Explanation: 
> There is no path that walks over every empty square exactly once.
> Note that the starting and ending square can be anywhere in the grid.
> ```
>
>  
>
> **Note:**
>
> 1. `1 <= grid.length * grid[0].length <= 20`



```cpp
class Solution {
public:
    int ans;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int uniquePathsIII(vector<vector<int>>& grid) {
        ans = 0;
        int total = 0;
        int n = grid.size();
        if(!n) return 0;
        int m = grid[0].size();
        int sx, sy;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] != -1) total++;
                if(grid[i][j] == 1){
                    sx = i;
                    sy = j;
                }
            }
        }
        vector<vector<int>> visited(n, vector<int>(m, 0));
        visited[sx][sy] = 1;
        dfs(grid, visited, sx, sy, total-1);
        return ans;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y, int target){
        if(grid[x][y] == 2){
            if(target == 0){
                ans++;
            }
            return;
        }
        for(int k=0;k<4;++k){
            int tx = x + dx[k];
            int ty = y + dy[k];
            if(tx >= 0 && tx < grid.size() && ty >= 0 && ty < grid[0].size() && !visited[tx][ty] && grid[tx][ty] != -1){
                visited[tx][ty] = 1;
                dfs(grid, visited, tx, ty, target-1);
                visited[tx][ty] = 0;
            }
        }
        return;
    }
};
```

DFS. we find all steps that from start to end.

Then DFS, when we get to end-point and see if we have walked enough steps.