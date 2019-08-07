class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int> imap_row[9];
        unordered_map<char,int> imap_col[9];
        unordered_map<char,int> imap_blo[9];
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]=='.'){
                    continue;
                }
                if(imap_row[i].find(board[i][j])!=imap_row[i].end()){
                    cout<<"i:"<<i<<" j:"<<j;
                    return false;
                }
                imap_row[i].insert({board[i][j],1});

                if(imap_col[j].find(board[i][j])!=imap_col[j].end()){
                    cout<<"j:"<<j;
                    return false;
                }
                imap_col[j].insert({board[i][j],1});

                int block_num =(j/3)*3+i/3;
                if(imap_blo[block_num].find(board[i][j])!=imap_blo[block_num].end()){
                    cout<<"blo:"<<block_num;
                    return false;
                }
                imap_blo[block_num].insert({board[i][j],1});
            }
        }
        return true; 
    }
};
