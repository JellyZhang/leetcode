#### 6. ZigZag Conversion

> The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
>
> ```
> P   A   H   N
> A P L S I I G
> Y   I   R
> ```
>
> And then read line by line: `"PAHNAPLSIIGYIR"`
>
> Write the code that will take a string and make this conversion given a number of rows:
>
> ```
> string convert(string s, int numRows);
> ```
>
> **Example 1:**
>
> ```
> Input: s = "PAYPALISHIRING", numRows = 3
> Output: "PAHNAPLSIIGYIR"
> ```
>
> **Example 2:**
>
> ```
> Input: s = "PAYPALISHIRING", numRows = 4
> Output: "PINALSIGYAHRPI"
> Explanation:
> 
> P     I    N
> A   L S  I G
> Y A   H R
> P     I
> ```

use string array to store ans for every row, and splice them together.

dir means direction, add it to target row.

```c++
// "AB" 1 
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        vector<string> ans(numRows);
        int insertTo = 0;
        int dir = 1;
        // 1 down , -1 up
        for(int i=0;i<s.size();++i){
            ans[insertTo] += s[i];
            insertTo += dir;
            if(insertTo == numRows-1 || insertTo == 0){
              // turn around
                dir *= -1;
            }
        }
        string rtn;
        for(string& str:ans){
            rtn += str;
        }
        return rtn;
    }
```

