> Given a string `s`, partition `s` such that every substring of the partition is a palindrome.
>
> Return *the minimum cuts needed* for a palindrome partitioning of `s`.
>
>  
>
> **Example 1:**
>
> ```
> Input: s = "aab"
> Output: 1
> Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
> ```
>
> **Example 2:**
>
> ```
> Input: s = "a"
> Output: 0
> ```
>
> **Example 3:**
>
> ```
> Input: s = "ab"
> Output: 1
> ```
>
>  
>
> **Constraints:**
>
> - `1 <= s.length <= 2000`
> - `s` consists of lower-case English letters only.



```cpp
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if(n < 2) return 0;
        if(n == 2) return (s[0]==s[1])?(0):(1);
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> minCuts(n+1);
        for(int i=0;i<n;++i){
            dp[i][i] = 1;
        }
        minCuts[0] = -1;
        for(int j=0;j<n;++j){
            minCuts[j+1] = minCuts[j] + 1;
            for(int i=0;i<j;++i){
                if(s[i]== s[j] && (j-i==1 || dp[i+1][j-1]) ){
                    dp[i][j] = 1;
                    minCuts[j+1] = min(minCuts[j+1], 1 + minCuts[i]);
                }
            }
        }
        return minCuts[n];
    }
};
```

minCuts[j+1] --> minCuts of substr[0~j].

minCuts[j+1]:

- if we regard s[j]  as a single palindrome string, then minCuts[j+1] = minCuts[j] + 1
- if there exists any  i between [0~j-1] that substr[i~j] is a palindrome, then minCuts[j+1] = minCuts[i] + 1