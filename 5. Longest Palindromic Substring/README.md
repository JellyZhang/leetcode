#### 5. Longest Palindromic Substring

> Given a string **s**, find the longest palindromic substring in **s**. You may assume that the maximum length of **s** is 1000.
>
> **Example 1:**
>
> ```
> Input: "babad"
> Output: "bab"
> Note: "aba" is also a valid answer.
> ```
>
> **Example 2:**
>
> ```
> Input: "cbbd"
> Output: "bb"
> ```

Assume s[i] is the center of the palindrome substr, expand it .

do it for all i .[0,s.size()-1]

Note: baaaaaaaacc. 

Take care same char occur together.

```c++
string longestPalindrome(string s) {
        int ans = 0;
        int ans_left = -1;
        for(int k=0;k<s.size();++k){
            int i = k;
            int j = k;
            while( j< s.size() && s[j] == s[i]) j++;
            i--;
            // _____(i)aaaaa(j)_____
          // i and j will be first not char'a'
            while(i >= 0 && j < s.size() && s[i] == s[j]){
                i--;
                j++;
            }
            if(j-i-1 > ans){
                ans = j - i - 1;
                ans_left = i + 1;
            }
        }
        return s.substr(ans_left, ans);
    }
```

#### 