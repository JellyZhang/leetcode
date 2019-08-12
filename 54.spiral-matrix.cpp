class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int len_row = matrix.size();
        if(len_row==0){
            return ans;
        }
        int len_col = matrix[0].size();
        int dir = 0;
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        //direction,0 right,1 down ,2 left,3 up
        int row = 0;
        int col = 0;
        vector<vector<int>> visited(len_row,vector<int>(len_col,0));
        visited[0][0]=1;
        ans.push_back(matrix[0][0]);
        while(true){
            //before visit
            int nxt_row = row + dx[dir];
            int nxt_col = col + dy[dir];
            if(nxt_row==len_row || nxt_row==-1 || nxt_col==len_col || nxt_col==-1 || visited[nxt_row][nxt_col]==1){
                dir = (dir+1)%4;
                nxt_row = row + dx[dir];
                nxt_col = col + dy[dir];
                if(nxt_row==len_row || nxt_row==-1 || nxt_col==len_col || nxt_col==-1 || visited[nxt_row][nxt_col]==1){
                    break;
                }
            }
            //visit
            visited[nxt_row][nxt_col] =1;
            ans.push_back(matrix[nxt_row][nxt_col]);
            //after visit
            row = nxt_row;
            col = nxt_col;
        }
        return ans;
    }
};
