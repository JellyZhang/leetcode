#### 9. Palindrome Number

> Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
>
> **Example 1:**
>
> ```
> Input: 121
> Output: true
> ```
>
> **Example 2:**
>
> ```
> Input: -121
> Output: false
> Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
> ```
>
> **Example 3:**
>
> ```
> Input: 10
> Output: false
> Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
> ```

```c++
bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        vector<int> digts;
        while(x){
            digts.push_back(x%10);
            x/=10;
        }
        int len = digts.size();
        for(int i=0;i<len/2+1;i++){
            if(digts[i] != digts[len-1-i]) return false;
        }
        return true;
    }
```

Store all digits, and compare head to tail.

Note:  0  -> true, negative -> false