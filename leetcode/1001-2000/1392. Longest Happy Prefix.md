> A string is called a *happy prefix* if is a **non-empty** prefix which is also a suffix (excluding itself).
>
> Given a string `s`. Return the **longest happy prefix** of `s` .
>
> Return an empty string if no such prefix exists.
>
>  
>
> **Example 1:**
>
> ```
> Input: s = "level"
> Output: "l"
> Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".
> ```
>
> **Example 2:**
>
> ```
> Input: s = "ababab"
> Output: "abab"
> Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.
> ```
>
> **Example 3:**
>
> ```
> Input: s = "leetcodeleet"
> Output: "leet"
> ```
>
> **Example 4:**
>
> ```
> Input: s = "a"
> Output: ""
> ```
>
>  
>
> **Constraints:**
>
> - `1 <= s.length <= 10^5`
> - `s` contains only lowercase English letters.

```cpp
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> nxt(n+1, 0);
        nxt[0] = -1;
        int k = 0;
        int ans = 0;
        for(int i=1;i<=n;++i){
            int k = nxt[i-1];
            while(k != -1 && s[i-1] != s[k]){
                k = nxt[k];
            }
            nxt[i] = k+1;
        }
        //cout<<"maxlen = "<<nxt.back()<<endl;
        return s.substr(0, nxt.back());
    }
};
```

