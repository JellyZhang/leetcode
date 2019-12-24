class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size()==0)
            return;
        int n = board.size();
        int m = board[0].size();
        int dx[8]={-1,-1,-1,0,0,1,1,1};
        int dy[8]={0,1,-1,1,-1,0,1,-1};
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int cnt = 0;
                for(int k=0;k<8;k++){
                    int tx = i+dx[k];
                    int ty = j+dy[k];
                    if(tx>=0 && tx<n && ty>=0 && ty<m && board[tx][ty]%2==1){
                        cnt++; 
                    }
                }
                if(board[i][j]==0 && cnt==3){
                    board[i][j]=2;
                }
                else if(board[i][j]==1 && (cnt<2 || cnt>3)){
                    board[i][j]=3;
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j]==2)
                    board[i][j]=1;
                else if(board[i][j]==3)
                    board[i][j]=0;
            }
        }
    }
};
