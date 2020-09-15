> Given an input string (`s`) and a pattern (`p`), implement wildcard pattern matching with support for `'?'` and `'*'`.
>
> ```
> '?' Matches any single character.
> '*' Matches any sequence of characters (including the empty sequence).
> ```
>
> The matching should cover the **entire** input string (not partial).
>
> **Note:**
>
> - `s` could be empty and contains only lowercase letters `a-z`.
> - `p` could be empty and contains only lowercase letters `a-z`, and characters like `?` or `*`.
>
> **Example 1:**
>
> ```
> Input:
> s = "aa"
> p = "a"
> Output: false
> Explanation: "a" does not match the entire string "aa".
> ```
>
> **Example 2:**
>
> ```
> Input:
> s = "aa"
> p = "*"
> Output: true
> Explanation: '*' matches any sequence.
> ```
>
> **Example 3:**
>
> ```
> Input:
> s = "cb"
> p = "?a"
> Output: false
> Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
> ```
>
> **Example 4:**
>
> ```
> Input:
> s = "adceb"
> p = "*a*b"
> Output: true
> Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
> ```
>
> **Example 5:**
>
> ```
> Input:
> s = "acdcb"
> p = "a*c?b"
> Output: false
> ```

```cpp
// DP Solution
// O(mn)

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        dp[0][0] = 1;
        for(int j=1;j<=n;++j){
            dp[0][j] = dp[0][j-1] && (p[j-1] == '*');
        }
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j];
                }else if(p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1]);
                }
            }
        }
        return dp[m][n];
        
    }
};
```

```cpp
// DFS+Memo
// worst O(mn) 

class Solution {
public:
    vector<vector<int>> memo;
    bool isMatch(string s, string p) {
        memo.assign(s.size()+1, vector<int>(p.size()+1,0));
        return dfs(s, p, 0, 0);
    }
    bool dfs(string& s, string& p, int i, int j){
        if(i == s.size() && j == p.size()) return true;
        if(j == p.size()) return false;
        if(i == s.size()){
            while(j < p.size()){
                if(p[j] != '*') return false;
                j++;
            }
            return true;
        }
        if(memo[i][j] != 0) return memo[i][j] == 1;
        bool ans = false;
        if(p[j] == '?'){
            ans = dfs(s, p, i+1, j+1);
        }else if(p[j] == '*'){
            ans =  dfs(s, p, i, j+1) || dfs(s, p, i+1, j) || dfs(s, p, i+1, j+1);
        }else {
            ans = s[i] == p[j] && dfs(s, p, i+1, j+1);
        }
        memo[i][j] = (ans)?(1):(-1);
        return ans;
    }
};
```

"*" could match :

- zero char.
- one char and continue matching.
- one char and stop matching.