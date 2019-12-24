class Solution {
public:
    int max_length;
    vector<int> selected;
    vector<vector<string>> ans;
    bool* visited_col;
    bool* visited_slash;
    bool* visited_rslash;
    void dfs(int now){
        //now = now dealing row
        if(now==max_length){
            vector<string> result;
            for(int i=0;i<max_length;++i){
                string temp = "";
                for(int j=0;j<max_length;++j){
                    if(selected[i]!=j){
                        temp += ".";
                    }
                    else{
                        temp += "Q";
                    }
                }
                result.push_back(temp);
            }
            ans.push_back(result);
            return;
        }
        for(int col=0;col<max_length;++col){
            if(!visited_col[col] && !visited_slash[now+col] && !visited_rslash[now-col+max_length-1]){
                visited_col[col] = true;
                visited_slash[now+col] = true;
                visited_rslash[now-col+max_length-1] = true;
                selected.push_back(col);
                dfs(now+1);
                visited_col[col] = false;
                visited_slash[now+col] = false;
                visited_rslash[now-col+max_length-1] = false;
                selected.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        visited_col = new bool[n];
        visited_slash = new bool[2*n];
        visited_rslash = new bool[2*n];

        for(int i=0;i<n;++i){
            visited_col[i] = false;
            visited_slash[i] = false;
            visited_rslash[i] = false;
        }
        for(int i=n;i<2*n;++i){
            visited_slash[i] = false;
            visited_rslash[i] = false;
        }
        selected.clear();
        ans.clear();
        max_length = n;
        dfs(0);
        return ans;
    }
};
