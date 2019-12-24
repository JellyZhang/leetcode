/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 */

// @lc code=start
class Solution {
private:
    int dx[8] = {0,0,1,-1,1,1,-1,-1};
    int dy[8] = {1,-1,0,0,1,-1,-1,1};
public:
    bool checkBounderAvailable(vector<vector<char>>& board, int x, int y){
        return ( 0<=x && x<board.size() && 0<=y && y<board[0].size());
    }
    int countMines(vector<vector<char>>& board, int x, int y){
        int ans = 0;
        for(int k=0;k<8;++k){
            int tx = x + dx[k];
            int ty = y + dy[k];
            if(checkBounderAvailable(board,tx,ty) && board[tx][ty] == 'M')
                ans++;
        }
        return ans;
    }
    void dfs(vector<vector<char>>& board, int x, int y){
        if(board[x][y] == 'M'){
            board[x][y] = 'X';
            return;
        }
        int mines = countMines(board,x,y);
        if(mines == 0)
            board[x][y] = 'B';
        else{
            board[x][y] = '0'+ mines; 
            return;
        }
        for(int k=0;k<8;++k){
            int tx = x + dx[k];
            int ty = y + dy[k];
            if(checkBounderAvailable(board,tx,ty) && board[tx][ty] == 'E')
                dfs(board,tx,ty);
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        dfs(board,click[0],click[1]);
        return board;
    }
};
// @lc code=end
