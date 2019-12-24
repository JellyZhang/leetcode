class Solution {
public:
    int max_length;
    vector<int> selected;
    int ans;
    vector<int> visited_col;
    vector<int> visited_slash;
    vector<int> visited_rslash;
    void dfs(int now){
        //now = now dealing row
        if(now==max_length){
            ++ans;
            return;
        }
        for(int col=0;col<max_length;++col){
            if(!visited_col[col] && !visited_slash[now+col] && !visited_rslash[now-col+max_length-1]){
                visited_col[col] = 1;
                visited_slash[now+col] = 1;
                visited_rslash[now-col+max_length-1] = 1;
                selected.push_back(col);
                dfs(now+1);
                visited_col[col] = 0;
                visited_slash[now+col] = 0;
                visited_rslash[now-col+max_length-1] = 0;
                selected.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        visited_col.assign(n,0);
        visited_slash.assign(2*n,0);
        visited_rslash.assign(2*n,0);
        selected.clear();
        ans=0;
        max_length = n;
        dfs(0);
        return ans;
    }
};
