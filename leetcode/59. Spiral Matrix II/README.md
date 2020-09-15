> Given a positive integer *n*, generate a square matrix filled with elements from 1 to *n*2 in spiral order.
>
> **Example:**
>
> ```
> Input: 3
> Output:
> [
>  [ 1, 2, 3 ],
>  [ 8, 9, 4 ],
>  [ 7, 6, 5 ]
> ]
> ```

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int i = 0, j = 0;
        int cur = 1;
        int dir = 0;
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        while(i >= 0 && i < n && j >= 0 && j < n && !ans[i][j]){
            ans[i][j] = cur++;
            int tx = i + dx[dir];
            int ty = j + dy[dir];
            if(tx < 0 || tx >= n || ty < 0 || ty >= n || ans[tx][ty]){
                dir = (dir+1)%4;
            }
            i = i + dx[dir];
            j = j + dy[dir];
        }
        return ans;
    }
};
```

