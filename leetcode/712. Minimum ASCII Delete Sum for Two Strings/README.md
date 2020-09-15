> Given two strings `s1, s2`, find the lowest ASCII sum of deleted characters to make two strings equal.
>
> **Example 1:**
>
> ```
> Input: s1 = "sea", s2 = "eat"
> Output: 231
> Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
> Deleting "t" from "eat" adds 116 to the sum.
> At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
> ```
>
> 
>
> **Example 2:**
>
> ```
> Input: s1 = "delete", s2 = "leet"
> Output: 403
> Explanation: Deleting "dee" from "delete" to turn the string into "let",
> adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
> At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
> If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
> ```
>
> 
>
> **Note:**
>
> `0 < s1.length, s2.length <= 1000`.
>
> All elements of each string will have an ASCII value in `[97, 122]`.

```cpp
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        int sum = 0;
        for(char ch:s1){
            sum += ch;
        }
        for(char ch:s2){
            sum += ch;
        }
        if(!m || !n) return sum;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + s1[i-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return sum - 2 * dp[m][n];
        
    }
};
```

assume the same part left from s1 and s2 is s3. 

then  DeleteSum = sum(s1) + sum(s2) - 2 * sum(s3)

if we want minimum deleteSum, then we should get max of sum(s3)

dp\[i\]\[j\] = when facing s1[0:i] and s2[0:j], the max sum of ascii of common sub-sequence between them. 

`if s1[i-1] == s2[j-1] then dp[i][j] = dp[i-1][j-1] + int(s[i-1])`

`if s1[i-1] != s2[j-1] then dp[i][j] = max(dp[i-1][j], dp[i][j-1])`



