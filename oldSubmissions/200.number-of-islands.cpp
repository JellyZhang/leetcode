class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)
            return 0;
        int ans=0;
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ans++;
                }
            }
        return ans;
    }
    void dfs(vector<vector<char>>& grid, int x, int y){
        for(int i=0;i<4;++i){
            int tx = x+dx[i];
            int ty = y+dy[i];
            if(tx>=0 && tx<grid.size() && ty>=0 && ty<grid[0].size() && grid[tx][ty]=='1'){
                grid[tx][ty]='0';
                dfs(grid,tx,ty);
            }
        }
    }
};
