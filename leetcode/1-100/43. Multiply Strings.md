> Given two non-negative integers `num1` and `num2` represented as strings, return the product of `num1` and `num2`, also represented as a string.
>
> **Example 1:**
>
> ```
> Input: num1 = "2", num2 = "3"
> Output: "6"
> ```
>
> **Example 2:**
>
> ```
> Input: num1 = "123", num2 = "456"
> Output: "56088"
> ```
>
> **Note:**
>
> 1. The length of both `num1` and `num2` is < 110.
> 2. Both `num1` and `num2` contain only digits `0-9`.
> 3. Both `num1` and `num2` do not contain any leading zero, except the number 0 itself.
> 4. You **must not use any built-in BigInteger library** or **convert the inputs to integer** directly.

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int len3 = len1 + len2;
        string ans(num1.size() + num2.size(),'0');
        for(int i=0;i<len1;++i){
            for(int j=0;j<len2;++j){
                int t = (num1[len1-1-i] -'0')*(num2[len2-1-j]-'0') + ans[i+j]-'0';
                ans[i+j] = (t%10 + '0');
                ans[i+j+1] += t/10;
            }
            
        }
        reverse(ans.begin(), ans.end());
        //cout<<ans<<endl;
        int pos = ans.find_first_not_of('0');
        if(pos == string::npos){
            return "0";
        }
        return ans.substr(pos);
        
    }
};
```

can also be written as:

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int len3 = len1 + len2;
        string ans(num1.size() + num2.size(),'0');
        for(int i=0;i<len1;++i){
            for(int j=0;j<len2;++j){
                int t = (num1[len1-1-i] -'0')*(num2[len2-1-j]-'0') + ans[len3-1-i-j]-'0';
                ans[len3-1-i-j] = (t%10 + '0');
                ans[len3-1-i-j-1] += t/10;
            }
            
        }
        //reverse(ans.begin(), ans.end());
        //cout<<ans<<endl;
        int pos = ans.find_first_not_of('0');
        if(pos == string::npos){
            return "0";
        }
        return ans.substr(pos);
        
    }
};
```

