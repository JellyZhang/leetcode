> Given two words *word1* and *word2*, find the minimum number of operations required to convert *word1* to *word2*.
>
> You have the following 3 operations permitted on a word:
>
> 1. Insert a character
> 2. Delete a character
> 3. Replace a character
>
> **Example 1:**
>
> ```
> Input: word1 = "horse", word2 = "ros"
> Output: 3
> Explanation: 
> horse -> rorse (replace 'h' with 'r')
> rorse -> rose (remove 'r')
> rose -> ros (remove 'e')
> ```
>
> **Example 2:**
>
> ```
> Input: word1 = "intention", word2 = "execution"
> Output: 5
> Explanation: 
> intention -> inention (remove 't')
> inention -> enention (replace 'i' with 'e')
> enention -> exention (replace 'n' with 'x')
> exention -> exection (replace 'n' with 'c')
> exection -> execution (insert 'u')
> ```

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if(!m) return n;
        if(!n) return m;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=0;i<=m;++i){
            for(int j=0;j<=n;++j){
                if(i*j == 0){
                    dp[i][j] = i + j;
                }else if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                }
            }
        }
        return dp[m][n];
    }
};
```

if word1[i-1] != word2[j-1] then

​	dp(i,j) can be 

- dp(i-1, j) then delete word1[i-1]
- dp(i, j-1) then insert word2[j-1]
- dp(i,j) then replace word1[i-1] with word2[j-1]

​	