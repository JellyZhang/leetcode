#### 32. Longest Valid Parentheses

> Given a string containing just the characters `'('` and `')'`, find the length of the longest valid (well-formed) parentheses substring.
>
> **Example 1:**
>
> ```
> Input: "(()"
> Output: 2
> Explanation: The longest valid parentheses substring is "()"
> ```
>
> **Example 2:**
>
> ```
> Input: ")()())"
> Output: 4
> Explanation: The longest valid parentheses substring is "()()"
> ```



```cpp
// stack version
// Time: On
// Space: On
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int ans = 0;
        for(int i=0;i<s.size();++i){
            if(s[i] == '('){
                stk.push(i);
            }else{
                stk.pop();
                if(stk.empty()){
                    stk.push(i);
                }else{
                    ans = max(ans, i - stk.top());
                }
            }
        }
        return ans;      
    }
};
```

 stk.top() will always be the index of first non-available pos.

栈顶端总是目前为止最大的无法构成pair的字符位置。

```cpp
// dp version
// Time: On
// Space: On
class Solution {
public:
    int longestValidParentheses(string s) {
        // dp[i] 以i位置结尾的最长的有效字符串
        // dp[i] == ')' &&  i-1 - dp[i-1] == '(' then dp[i] maybe dp[i-1] + 2 + dp[i-1-dp[i-1] -1]
        vector<int> dp(s.size(),0);
        int ans = 0;
        for(int i=1;i<s.size();++i){
            if(s[i] == ')' && i-1-dp[i-1] >= 0 && s[i-1-dp[i-1]] == '('){
                if(i-1-dp[i-1]-1 >= 0){
                    dp[i] = dp[i-1] + 2 + dp[i-1-dp[i-1]-1];
                }else{
                    dp[i] = dp[i-1] + 2;
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```



```cpp
// Scan Version
// Time: On
// Space: O1

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0;
        int ans = 0;
        for(int i=0;i<s.size();++i){
            if(s[i] == '(') left++;
            else right++;
            if(right > left){
                left = right = 0;
            }
            if(left == right){
                ans = max(ans, left * 2);
            }
        }
        left = right = 0;
        for(int i=s.size()-1; i>=0 ;i--){
            if(s[i] == '(') left++;
            else right++;
            if(left > right){
                left = right = 0;
            }
            if(left == right){
                ans = max(ans, left * 2);
            }
        }
        return ans;
    }
};
```

left , right means how many available characters are there.

assume [i,j] is the longest valid parentheses。then when we do left scan and encouter i-1, obviously at i-1, left >= right.

- if left == right, then we can find longest valid substring in our left scan.
- if left > right, then we do our right scan. Again ,when we at j+1,  obviously right  >= left.
  - if right == left, then we can find the longest valid substring.
  - if right > left, this situation is impossible. Because if so, and with left > right at i+1, we can see that this "longest valid substring " is no longer the longest. So it is against our origin assumption.