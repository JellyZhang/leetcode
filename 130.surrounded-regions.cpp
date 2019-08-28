class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    void dfs(vector<vector<char>>& board,int x,int y,char a,char b){
        //change all char a to char b
        board[x][y]=b;
        for(int i=0;i<4;++i){
            int tx = x+dx[i];
            int ty = y+dy[i];
            if(tx>=0 && tx <board.size() && ty>=0 && ty<board[0].size() && board[tx][ty]==a){
                dfs(board,tx,ty,a,b);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.size()==0)
            return;
        for(int j=0;j<board[0].size();++j){
            if(board[0][j]=='O')
                dfs(board,0,j,'O','$');
            if(board[board.size()-1][j]=='O')
                dfs(board,board.size()-1,j,'O','$');
        }
        for(int i=0;i<board.size();++i){
            if(board[i][0]=='O')
                dfs(board,i,0,'O','$');
            if(board[i][board[0].size()-1]=='O')
                dfs(board,i,board[0].size()-1,'O','$');
        }
        for(int i=0;i<board.size();++i)
            for(int j=0;j<board[0].size();++j)
                if(board[i][j]=='O')
                    board[i][j]='X';
        for(int i=0;i<board.size();++i)
            for(int j=0;j<board[0].size();++j)
                if(board[i][j]=='$')
                    board[i][j]='O';


        return;
    }
};
