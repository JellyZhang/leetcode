#### 14. Longest Common Prefix

> Write a function to find the longest common prefix string amongst an array of strings.
>
> If there is no common prefix, return an empty string `""`.
>
> **Example 1:**
>
> ```
> Input: ["flower","flow","flight"]
> Output: "fl"
> ```
>
> **Example 2:**
>
> ```
> Input: ["dog","racecar","car"]
> Output: ""
> Explanation: There is no common prefix among the input strings.
> ```

```c++
string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        int index = 0;
        bool contn = true;
        while(contn){
            if(index >= strs[0].size()) break;
            char cur = strs[0][index];
            for(int i=0;i<strs.size();++i){
                if(index >= strs[i].size() || strs[i][index] != cur){
                    contn = false;
                }
            }
            if(contn) index++;
        }
        return strs[0].substr(0,index);
    }
```

Try every digits, see if all str has same char at index of 0.then index of 1. then index of 2...

care about that index may >= str.size