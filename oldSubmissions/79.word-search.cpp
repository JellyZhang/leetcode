class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int m;
    int n;
    bool dfs(vector<vector<char>>& board,vector<vector<int>>& visited,string word,int now,int x,int y){
        if(now==word.size()){
            return true;
        }
        for(int i=0;i<4;++i){
            int tx = x+dx[i];
            int ty = y+dy[i];
            if(0<=tx && tx<m && 0<=ty && ty<n && !visited[tx][ty] && board[tx][ty]==word[now]){
                visited[tx][ty]=1;
                if(dfs(board,visited,word,now+1,tx,ty)){
                    return true;
                }
                visited[tx][ty]=0;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0){
            return true;
        }
        m = board.size();
        if(m==0){
            return false;
        }
        n =board[0].size();
        if(n==0){
            return false;
        }
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]==word[0]){
                    visited[i][j]=1;
                    if(dfs(board,visited,word,1,i,j)){
                        return true;
                    }
                    visited[i][j]=0;
                }
            }
        }
        return false;
    }
};
