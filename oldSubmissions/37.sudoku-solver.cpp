class Solution {
public:

    vector<vector<char>> result;
    bool visited_row[9][9];
    bool visited_col[9][9];
    bool visited_blo[9][9];
    bool solved;
    void dfs(int i,int j){
        //find next block to fill
        int cnt = i*9+j+1;
        int row,col;
        while(cnt<81){
            row = cnt/9;
            col = cnt-row*9;
            if(result[row][col]=='.'){
                break;
            }
            ++cnt;
        }
        if(cnt==81){
            solved = true;
            return;
        }
        int block_num = col/3*3+row/3;
        for(int index=0;index<9;++index){
            if(visited_row[row][index] || visited_col[col][index] || visited_blo[block_num][index]){
                continue;
            }
            else{
                visited_row[row][index] = true;
                visited_col[col][index] = true;
                visited_blo[block_num][index] = true;
                result[row][col]='0'+index+1;
                cout<<row<<" "<<col<<" "<<index+1<<"\t";
                dfs(row,col);
                if(solved)return;
                result[row][col]='.';
                visited_row[row][index] = false;
                visited_col[col][index] = false;
                visited_blo[block_num][index] = false;
            }
        }


    }
    void solveSudoku(vector<vector<char>>& board) {
        result = board;
        solved = false;
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                visited_row[i][j]=false;
                visited_col[i][j]=false;
                visited_blo[i][j]=false;
            }
        }
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]!='.'){
                    int index = board[i][j]-'0'-1;
                    int block_num = j/3*3+i/3;
                    visited_row[i][index] = true;
                    visited_col[j][index] = true;
                    visited_blo[block_num][index] = true;
                }
            }
        }
        dfs(0,-1);
        board = result;
    }
};
