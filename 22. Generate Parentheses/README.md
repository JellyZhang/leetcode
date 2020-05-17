#### 22. Generate Parentheses

> Given *n* pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
>
> For example, given *n* = 3, a solution set is:
>
> ```
> [
> "((()))",
> "(()())",
> "(())()",
> "()(())",
> "()()()"
> ]
> ```

```c++
vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(n, n, ans, "");
        return ans;
    }
    void dfs(int left, int right, vector<string>& ans, string selected){
        if(left == 0 && right == 0){
            ans.push_back(selected);
            return;
        }
        if(left > 0)
            dfs(left-1, right, ans, selected + '(');
        if(right > left)
            dfs(left, right-1, ans, selected + ')');
    }
```

DFS. 

Note: ')))(((' is not allowed.