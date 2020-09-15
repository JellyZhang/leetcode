> Implement `int sqrt(int x)`.
>
> Compute and return the square root of *x*, where *x* is guaranteed to be a non-negative integer.
>
> Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
>
> **Example 1:**
>
> ```
> Input: 4
> Output: 2
> ```
>
> **Example 2:**
>
> ```
> Input: 8
> Output: 2
> Explanation: The square root of 8 is 2.82842..., and since 
>              the decimal part is truncated, 2 is returned.
> ```

```cpp
typedef long long ll;
class Solution {
public:
    int mySqrt(int x) {
        ll lo = 1;
        ll hi = x;
        while(lo <= hi){
            ll mid = lo + (hi- lo)/2;
            if(mid*mid > x){
                hi = mid - 1;
            }else if(mid*mid < x){
                lo = mid + 1;
            }else{
                return mid;
            }
        }
        return hi;
    }
};


// Solution 2: bit manipulation
class Solution {
public:
    int mySqrt(int x) {
        long long ans = 0;
        long long bit = 1l << 16;
        while(bit > 0) {
            ans |= bit;
            if (ans * ans > x) {
                ans ^= bit;
            }
            bit >>= 1;
        }
        return (int)ans;
    }
};
```

