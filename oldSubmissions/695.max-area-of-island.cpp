/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    bool checkBoundAvailble(vector<vector<int>>& grid, int x, int y){
        if( 0<=x && x<grid.size() && 0<=y && y<grid[0].size() && grid[x][y] == 1){
            return true;
        }
        return false;
    }
    void dfs(vector<vector<int>>& grid, int x, int y, int& area){
        for(int k=0;k<4;k++){
            int tx = x + dx[k];
            int ty = y + dy[k];
            if(checkBoundAvailble(grid,tx,ty)){
                grid[tx][ty] = 0;
                area++;
                dfs(grid,tx,ty,area);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(checkBoundAvailble(grid,i,j)){
                    int area = 1;
                    grid[i][j] = 0;
                    dfs(grid,i,j,area);
                    ans = max(ans,area);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
