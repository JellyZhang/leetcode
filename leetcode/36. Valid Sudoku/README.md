> Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated **according to the following rules**:
>
> 1. Each row must contain the digits `1-9` without repetition.
> 2. Each column must contain the digits `1-9` without repetition.
> 3. Each of the 9 `3x3` sub-boxes of the grid must contain the digits `1-9` without repetition.
>
> ![img](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)
> A partially filled sudoku which is valid.
>
> The Sudoku board could be partially filled, where empty cells are filled with the character `'.'`.
>
> **Example 1:**
>
> ```
> Input:
> [
>   ["5","3",".",".","7",".",".",".","."],
>   ["6",".",".","1","9","5",".",".","."],
>   [".","9","8",".",".",".",".","6","."],
>   ["8",".",".",".","6",".",".",".","3"],
>   ["4",".",".","8",".","3",".",".","1"],
>   ["7",".",".",".","2",".",".",".","6"],
>   [".","6",".",".",".",".","2","8","."],
>   [".",".",".","4","1","9",".",".","5"],
>   [".",".",".",".","8",".",".","7","9"]
> ]
> Output: true
> ```
>
> **Example 2:**
>
> ```
> Input:
> [
>   ["8","3",".",".","7",".",".",".","."],
>   ["6",".",".","1","9","5",".",".","."],
>   [".","9","8",".",".",".",".","6","."],
>   ["8",".",".",".","6",".",".",".","3"],
>   ["4",".",".","8",".","3",".",".","1"],
>   ["7",".",".",".","2",".",".",".","6"],
>   [".","6",".",".",".",".","2","8","."],
>   [".",".",".","4","1","9",".",".","5"],
>   [".",".",".",".","8",".",".","7","9"]
> ]
> Output: false
> Explanation: Same as Example 1, except with the 5 in the top left corner being 
>     modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
> ```
>
> **Note:**
>
> - A Sudoku board (partially filled) could be valid but is not necessarily solvable.
> - Only the filled cells need to be validated according to the mentioned rules.
> - The given board contain only digits `1-9` and the character `'.'`.
> - The given board size is always `9x9`.

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> s;
        // check row
        for(int i=0;i<9;++i){
            s.clear();
            for(int j=0;j<9;++j){
                if(board[i][j] == '.') continue;
                if(s.count(board[i][j])){
                    return false;
                }
                s.insert(board[i][j]);
            }
        }
        // check column
        for(int j=0;j<9;++j){
            s.clear();
            for(int i=0;i<9;++i){
                if(board[i][j] == '.') continue;
                if(s.count(board[i][j])){
                    return false;
                }
                s.insert(board[i][j]);
            }
        }
        //check block
        int dx[9] = {0,0,0,1,1,1,2,2,2};
        int dy[9] = {0,1,2,0,1,2,0,1,2};
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                s.clear();
                int x = i*3;
                int y = j*3;
                for(int k=0;k<9;++k){
                    int tx = x + dx[k];
                    int ty = y + dy[k];
                    if(board[tx][ty] == '.') continue;
                    if(s.count(board[tx][ty])){
                        return false;
                    }
                    s.insert(board[tx][ty]);
                }
            }
        }
        return true;
    }
};
```

