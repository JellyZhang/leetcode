> Given a matrix of *m* x *n* elements (*m* rows, *n* columns), return all elements of the matrix in spiral order.
>
> **Example 1:**
>
> ```
> Input:
> [
>  [ 1, 2, 3 ],
>  [ 4, 5, 6 ],
>  [ 7, 8, 9 ]
> ]
> Output: [1,2,3,6,9,8,7,4,5]
> ```
>
> **Example 2:**
>
> ```
> Input:
> [
>   [1, 2, 3, 4],
>   [5, 6, 7, 8],
>   [9,10,11,12]
> ]
> Output: [1,2,3,4,8,12,11,10,9,5,6,7]
> ```

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        unordered_map<int,unordered_map<int,int>> visited;
        int i = 0, j = 0;
        int m = matrix.size();
        if(!m) return {};
        int n = matrix[0].size();
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        for(int j=0;j<n;++j){
            visited[-1][j] = 1;
            visited[m][j] = 1;
        }
        for(int i=0;i<m;++i){
            visited[i][-1] = 1;
            visited[i][n] = 1;
        }
        vector<int> ans;
        int cur = 0;
        while(!visited[i][j]){
            ans.push_back(matrix[i][j]);
            visited[i][j] = 1;
            int tx = i + dx[cur];
            int ty = j + dy[cur];
            if(visited[tx][ty]){
                cur = (cur + 1)%4;
            }
            i = i + dx[cur];
            j = j + dy[cur];
        }
        return ans;
    }
};
```

