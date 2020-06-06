#### 28. Implement strStr()

> Return the index of the first occurrence of needle in haystack, or **-1** if needle is not part of haystack.
>
> **Example 1:**
>
> ```
> Input: haystack = "hello", needle = "ll"
> Output: 2
> ```
>
> **Example 2:**
>
> ```
> Input: haystack = "aaaaa", needle = "bba"
> Output: -1
> ```

```c++
// Simple Solution (using substr)
// Time complexity: O(m*n)
// Space complexity: O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
         int m = haystack.size(); 
     		 int n = needle.size();
         if(!n) return 0;
         if(!m) return -1;
         for(int i=0;i + n <= m;++i){
             if(haystack.substr(i,n) == needle){
                 return i;
             }
         }
         return -1;
    }
};
```

```c++
// Rabin-Karp algorithm  (rolling hash)
// Time complexity: O(n)
class Solution {
public:
    int strStr(string haystack, string needle) {
        const int MOD = 127; // a prime, bigger would be better
        const int base = 256;
        int m = haystack.size();
        int n = needle.size();
        if(!n) return 0;
        if(!m) return -1;
        int cur = 0;  //cur hash
        int pa = 0;  // pattern hash
        int highest = 1;  // times of hightest dight
        for(int i=0;i<n;++i){
          	if(i != n-1) highest = (highest*base)%MOD;
            pa =  (pa*base + needle[i])%MOD;
            cur = (cur*base + haystack[i])%MOD;
        }
        
        // check pos 0
        if(pa == cur && haystack.substr(0, n) == needle) return 0;
      
        for(int i=n;i<m;++i){
            cur = ((cur - haystack[i-n]*highest)*base + haystack[i])%MOD;
            if(cur < 0) cur += MOD;
            if(pa == cur && haystack.substr(i-n+1, n) == needle) return i-n+1;
        }
        return -1;
    }
};
```



