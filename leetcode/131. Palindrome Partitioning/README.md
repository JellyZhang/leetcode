> Given a string *s*, partition *s* such that every substring of the partition is a palindrome.
>
> Return all possible palindrome partitioning of *s*.
>
> **Example:**
>
> ```
> Input: "aab"
> Output:
> [
>   ["aa","b"],
>   ["a","a","b"]
> ]
> ```

```cpp
class Solution {
public:
    vector<vector<int>> isPalin;
    vector<vector<string>> partition(string s) {
        int n = s.size();
        isPalin.assign(n, vector<int>(n,0));
        for(int len=0;len<n;++len){
            for(int i=0;i+len<n;++i){
                int j = i + len;
                if(s[i] == s[j] && (j-i<2 || isPalin[i+1][j-1])){
                    isPalin[i][j] = 1;
                }
            }
        }
        vector<string> selected;
        vector<vector<string>> ans;
        dfs(s, 0, ans, selected);
        return ans;
        
    }
    void dfs(string& s, int start,  vector<vector<string>>& ans, vector<string>& selected){
        if(start == s.size()){
            ans.push_back(selected);
            return;
        }
        for(int end=start;end<s.size();++end){
            if(isPalin[start][end]){
                selected.push_back(s.substr(start, end - start + 1));
                dfs(s, end+1, ans, selected);
                selected.pop_back();
            }
        }
    }
};
```

DFS. 

先用区间DP算出isPalin二维数组，之后便可以O1的时间得出一个子串是否是回文串。