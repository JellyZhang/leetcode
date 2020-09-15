> Given two binary strings, return their sum (also a binary string).
>
> The input strings are both **non-empty** and contains only characters `1` or `0`.
>
> **Example 1:**
>
> ```
> Input: a = "11", b = "1"
> Output: "100"
> ```
>
> **Example 2:**
>
> ```
> Input: a = "1010", b = "1011"
> Output: "10101"
> ```
>
>  
>
> **Constraints:**
>
> - Each string consists only of `'0'` or `'1'` characters.
> - `1 <= a.length, b.length <= 10^4`
> - Each string is either `"0"` or doesn't contain any leading zero.



```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int pa = a.size()-1, pb = b.size() -1;
        string res(max(a.size(), b.size()) + 1, '0');
        int pc = res.size()-1;
        int carry = 0;
        for(;pa >= 0 || pb >= 0 || carry; pa--,pb--,pc--){
            int na = (pa >= 0)?(a[pa]-'0'):(0);
            int nb = (pb >= 0)?(b[pb]-'0'):(0);
            int nc = na + nb + carry;
            carry = 0;
            if(nc >= 2){
                nc -= 2;
                carry = 1;
            }
            res[pc] = nc + '0';
        }
        size_t pos = res.find_first_not_of('0');
        if(pos == string::npos) return "0";
        return res.substr(pos);
        
    }
};
```

