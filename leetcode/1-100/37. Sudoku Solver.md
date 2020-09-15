> Write a program to solve a Sudoku puzzle by filling the empty cells.
>
> A sudoku solution must satisfy **all of the following rules**:
>
> 1. Each of the digits `1-9` must occur exactly once in each row.
> 2. Each of the digits `1-9` must occur exactly once in each column.
> 3. Each of the the digits `1-9` must occur exactly once in each of the 9 `3x3` sub-boxes of the grid.
>
> Empty cells are indicated by the character `'.'`.
>
> ![img](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)
> A sudoku puzzle...
>
> ![img](https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png)
> ...and its solution numbers marked in red.
>
> **Note:**
>
> - The given board contain only digits `1-9` and the character `'.'`.
> - You may assume that the given Sudoku puzzle will have a single unique solution.
> - The given board size is always `9x9`.

```cpp
class Solution {
public:
    unordered_map<int,unordered_set<int>> rows;
    unordered_map<int,unordered_set<int>> cols;
    unordered_map<int,unordered_set<int>> blocks;
    vector<vector<char>> ans;
    bool solved;
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j] == '.') continue;
                rows[i].insert(board[i][j]-'0');
                cols[j].insert(board[i][j]-'0');
                int blockNum = (i/3)*3 + (j/3);
                blocks[blockNum].insert(board[i][j]-'0');
            }
        }
        solved = false;
        dfs(board, 0, 0);
        board = ans;
        return;
    }
    void dfs(vector<vector<char>>& board, int x, int y){
        if(y == board[0].size()){
            dfs(board, x + 1, 0);
            return;
        }
        if(x == board.size() && y == 0){
            ans = board;
            solved = true;
            return;
        }
        if(board[x][y] != '.'){
            return dfs(board, x, y+1);
        }
        for(int i=1;i<=9 && !solved;++i){
            int blockNum = (x/3)*3 + (y/3);
            if(rows[x].count(i) || cols[y].count(i) || blocks[blockNum].count(i)){
                continue;
            }
            rows[x].insert(i);
            cols[y].insert(i);
            blocks[blockNum].insert(i);
            board[x][y] = '0'+i;
            dfs(board, x, y+1);
            rows[x].erase(i);
            cols[y].erase(i);
            blocks[blockNum].erase(i);
            board[x][y] = '.';
        }
    }
};
```

simple dfs.

PS: to calculate the index of blocks number: (x/3)*3 + (y/3)