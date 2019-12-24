/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        int cnt = 1;
        int dir = 0;
        int x = 0;
        int y = 0;
        while(checkBound(x,y,n,mat)){
            mat[x][y] = cnt++;
            if(!checkBound(x+dx[dir],y+dy[dir],n,mat)){
                dir = (dir+1)%4;
            }
            x = x + dx[dir];
            y = y + dy[dir];
        }
        return mat;
    }
    bool checkBound(int x, int y, int n, vector<vector<int>>& mat){
        if( x<0 || x>=n || y<0 || y>=n || mat[x][y]){
            return false;
        }
        return true;
    }
};
// @lc code=end
