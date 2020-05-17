#### 20. Valid Parentheses

> Given a string containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.
>
> An input string is valid if:
>
> 1. Open brackets must be closed by the same type of brackets.
> 2. Open brackets must be closed in the correct order.
>
> Note that an empty string is also considered valid.
>
> **Example 1:**
>
> ```
> Input: "()"
> Output: true
> ```
>
> **Example 2:**
>
> ```
> Input: "()[]{}"
> Output: true
> ```
>
> **Example 3:**
>
> ```
> Input: "(]"
> Output: false
> ```
>
> **Example 4:**
>
> ```
> Input: "([)]"
> Output: false
> ```
>
> **Example 5:**
>
> ```
> Input: "{[]}"
> Output: true
> ```

```c++
bool isValid(string s) {
        unordered_map<char,char> maps = {{')','('},{']','['},{'}','{'}};
        unordered_set<char> lefts = {'(','[','{'};
        stack<char> stk;
        for(char ch:s){
            if(lefts.count(ch)){
                stk.push(ch);
            }else{
                if(stk.empty() || stk.top() != maps[ch]) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
```

Stack.

Note: check stack empty() at end. If !stk.empt(). Then there is ramining char.