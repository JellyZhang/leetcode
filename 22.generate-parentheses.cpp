class Solution {
public:
    int max_nums ; // max num of open
    int count_open ;// of open
    int count_close;
    int endlength ; // of str to end dfs
    string str ;
    vector<string> ans;
    void dfs(){
        if(count_open+ count_close == endlength){
            ans.push_back(str);
            return;
        }
        if(count_open < max_nums){
            str.push_back('(');
            ++count_open;
            dfs();
            --count_open;
            str.pop_back();
        }
        if(count_close < count_open){
            str.push_back(')');
            ++count_close;
            dfs();
            --count_close;
            str.pop_back();
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        max_nums = n;
        endlength = 2*n;
        str = "";
        count_open = 0;
        count_close = 0;
        ans.clear();
        dfs();
        return ans;
    }
};
