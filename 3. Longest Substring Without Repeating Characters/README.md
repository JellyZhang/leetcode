#### 3. Longest Substring Without Repeating Characters

> Given a string, find the length of the **longest substring** without repeating characters.
>
> **Example 1:**
>
> ```
> Input: "abcabcbb"
> Output: 3 
> Explanation: The answer is "abc", with the length of 3. 
> ```
>
> **Example 2:**
>
> ```
> Input: "bbbbb"
> Output: 1
> Explanation: The answer is "b", with the length of 1.
> ```
>
> **Example 3:**
>
> ```
> Input: "pwwkew"
> Output: 3
> Explanation: The answer is "wke", with the length of 3. 
>           Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
>            
> ```

Sliding window.

when sliding, check whether s[j] has shown in s[i~j]. if so, then move i to (the pos of previous j)-1

```c++
// "abba"
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> pos;
        int i = 0, j = 0;
        int ans = 0;
        for(;j<s.size();j++){
          // pos[s[j]] >= i to avoid earsing abandoned chars
            if(pos.count(s[j]) && pos[s[j]] >= i){
                i = pos[s[j]] + 1;
            }
            pos[s[j]] = j;
            ans = max(ans, j-i+1);
        }
        return ans;
    }
```

