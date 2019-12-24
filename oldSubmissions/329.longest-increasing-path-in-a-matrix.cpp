/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> memo;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return 0;
        if(matrix[0].size()==0)
            return 0;
        int ans = 1;
        memo.assign(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                ans = max(ans, dfs(matrix,i,j));
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& matrix, int x, int y){
        if(memo[x][y]){
            return memo[x][y];
        }
        int temp_max = 1;
        for(int k=0;k<4;++k){
            int tx = x + dx[k];
            int ty = y + dy[k];
            if(0<=tx && tx<matrix.size() && 0<=ty && ty<matrix[0].size() && matrix[tx][ty]>matrix[x][y]){
                temp_max = max(temp_max,1 + dfs(matrix,tx,ty));
            }
        }
        memo[x][y] = temp_max;
        return temp_max;
    }
};
// @lc code=end
