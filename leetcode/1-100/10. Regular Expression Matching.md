#### 10. Regular Expression Matching

> Given an input string (`s`) and a pattern (`p`), implement regular expression matching with support for `'.'` and `'*'`.
>
> ```
> '.' Matches any single character.
> '*' Matches zero or more of the preceding element.
> ```
>
> The matching should cover the **entire** input string (not partial).
>
> **Note:**
>
> - `s` could be empty and contains only lowercase letters `a-z`.
> - `p` could be empty and contains only lowercase letters `a-z`, and characters like `.` or `*`.
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
> p = "a*"
> Output: true
> Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
> ```
>
> **Example 3:**
>
> ```
> Input:
> s = "ab"
> p = ".*"
> Output: true
> Explanation: ".*" means "zero or more (*) of any character (.)".
> ```
>
> **Example 4:**
>
> ```
> Input:
> s = "aab"
> p = "c*a*b"
> Output: true
> Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
> ```
>
> **Example 5:**
>
> ```
> Input:
> s = "mississippi"
> p = "mis*is*p*."
> Output: false
> ```

```c++
bool isMatch(string s, string p){
        vector<vector<int>> dp(s.size() + 1,vector<int>(p.size() + 1,0));
        dp[s.size()][p.size()] = 1;
        for(int i=s.size();i>=0;i--){
            for(int j=p.size()-1;j>=0;j--){
                bool first = (i < s.size()) && ((s[i] == p[j]) || (p[j] == '.'));
                if(j+1<p.size() && p[j+1] == '*'){
                    dp[i][j] = dp[i][j+2] || (first && dp[i+1][j]);
                }else{
                    dp[i][j] = (first && dp[i+1][j+1]);
                }
            }
        }
        return dp[0][0];
    }
```

DP. From back to start. O(n^2)

dp[i] [j] => whether s[0 -> i-1] and p[0 -> j-1] matches.

firstly, dp[s.size()] [p.size()] = 1 , we assume it matches at end, then find whether dp[0] [0] == 1.

if j==p.size  and i<p.size , then dp[i] [j] always == 0, so we travel i from s.size, j from p.size -1