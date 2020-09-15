> There are several stones **arranged in a row**, and each stone has an associated value which is an integer given in the array `stoneValue`.
>
> In each round of the game, Alice divides the row into **two non-empty rows** (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.
>
> The game ends when there is only **one stone remaining**. Alice's is initially **zero**.
>
> Return *the maximum score that Alice can obtain*.
>
>  
>
> **Example 1:**
>
> ```
> Input: stoneValue = [6,2,3,4,5,5]
> Output: 18
> Explanation: In the first round, Alice divides the row to [6,2,3], [4,5,5]. The left row has the value 11 and the right row has value 14. Bob throws away the right row and Alice's score is now 11.
> In the second round Alice divides the row to [6], [2,3]. This time Bob throws away the left row and Alice's score becomes 16 (11 + 5).
> The last round Alice has only one choice to divide the row which is [2], [3]. Bob throws away the right row and Alice's score is now 18 (16 + 2). The game ends because only one stone is remaining in the row.
> ```
>
> **Example 2:**
>
> ```
> Input: stoneValue = [7,7,7,7,7,7,7]
> Output: 28
> ```
>
> **Example 3:**
>
> ```
> Input: stoneValue = [4]
> Output: 0
> ```
>
>  
>
> **Constraints:**
>
> - `1 <= stoneValue.length <= 500`
> - `1 <= stoneValue[i] <= 10^6`



```cpp
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        return top_down(stoneValue);
        // bottom_up is TLE. FUCK LEETCODE.
    }
    int bottom_up(vector<int>& stoneValue){
        int n = stoneValue.size();
        vector<int> preSum(n+1, 0);
        for(int i=1;i<=n;++i){
            preSum[i] = preSum[i-1] + stoneValue[i-1];
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for(int len=1;len<n;++len){
            for(int i=0;i+len<n;i++){
                int j = i + len;
                for(int k=i;k<j;k++){
                    if(preSum[k+1] - preSum[i] < preSum[j+1]-preSum[k+1]){
                        dp[i][j] = max(dp[i][j], dp[i][k] + preSum[k+1] - preSum[i]);
                    }else if(preSum[k+1] - preSum[i] > preSum[j+1]-preSum[k+1]){
                        dp[i][j] = max(dp[i][j], dp[k+1][j] + preSum[j+1]-preSum[k+1]);
                    }else{
                        dp[i][j] = max(dp[i][j], max(dp[i][k], dp[k+1][j]) + preSum[j+1]-preSum[k+1]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
    vector<vector<int>> memo;
    vector<int> preSum;
    int top_down(vector<int>& stoneValue){
        int n = stoneValue.size();
        memo.assign(n+1, vector<int>(n+1, 0));
        preSum.assign(n+1, 0);
        for(int i=1;i<=n;++i){
            preSum[i] = preSum[i-1] + stoneValue[i-1];
        }
        return dfs(0, n-1);
    }
    int dfs(int i, int j){
        if(i == j) return 0;
        if(memo[i][j] != 0){
            return memo[i][j];
        }
        int ans = 0;
        for(int k=i;k<j;++k){
            if(preSum[k+1] - preSum[i] < preSum[j+1]-preSum[k+1]){
                    ans = max(ans, dfs(i,k) + preSum[k+1] - preSum[i]);
                }else if(preSum[k+1] - preSum[i] > preSum[j+1]-preSum[k+1]){
                    ans = max(ans, dfs(k+1,j) + preSum[j+1]-preSum[k+1]);
                }else{
                    ans = max(ans, max(dfs(i,k), dfs(k+1,j)) + preSum[j+1]-preSum[k+1]);
                }
        }
        memo[i][j] = ans;
        return ans;
    }
};
```

区间dp

