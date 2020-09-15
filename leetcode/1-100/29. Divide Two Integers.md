#### 29. Divide Two Integers

> Given two integers `dividend` and `divisor`, divide two integers without using multiplication, division and mod operator.
>
> Return the quotient after dividing `dividend` by `divisor`.
>
> The integer division should truncate toward zero, which means losing its fractional part. For example, `truncate(8.345) = 8` and `truncate(-2.7335) = -2`.
>
> **Example 1:**
>
> ```
> Input: dividend = 10, divisor = 3
> Output: 3
> Explanation: 10/3 = truncate(3.33333..) = 3.
> ```
>
> **Example 2:**
>
> ```
> Input: dividend = 7, divisor = -3
> Output: -2
> Explanation: 7/-3 = truncate(-2.33333..) = -2.
> ```
>
> **Note:**
>
> - Both dividend and divisor will be 32-bit signed integers.
> - The divisor will never be 0.
> - Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function **returns 231 − 1 when the division result overflows**.



```cpp
class Solution {
public:
    // -2147483648 -1
    
    int divide(int a, int b) {
        return Olgn(a, b);
    }
    
    int Olgn(int a, int b){
        if(a == 0) return 0;
        if(a == INT_MIN && b == -1) return INT_MAX;
        int ans = 0;
        int positive = -1;
        if(a > 0){
            positive *= -1;
            a = -a;
        }
        if(b > 0){
            positive *= -1;
            b = -b;
        }
        vector<int> powers;
        vector<int> powersof2;
        int p = 1*b;
        int t = -1;
        while(p >= a){
            powers.push_back(p);
            powersof2.push_back(t);
            if(p < INT_MIN/2){
                break;
            }
            p += p;
            t += t;
        };
        for(int i=powers.size()-1;i>=0;--i){
            if(powers[i] >= a){
                ans += powersof2[i];
                a -= powers[i];
            }
        }
        return positive*ans;
    } 
};
```

1. trans into negative:

   - to avoid overflow, we need to convert both A and B into negative, and record their flags.

2. build an array, which is B's powerOf2 array, which looks like:[ b, 2\*b, 4\*b, 8\*b, 16\*b, 32\*b, ....] 

   and another array [1, 2, 4, 8, 16, 32 , ...] correspond to previous one.

   - keep building until array.back() is greater than A.

   - this is because for any A, can be transformed into 

     `x1 * b + x2 * 2b + x3 * 4b + x4 * 8b + x5 * 16b + ...`

     this is becaus if k == A/B, then K can be transformed into 
   
  `x1 * 1 + x2 * 2 + x3 * 4 + x4 * 8 + x5 * 16 + ... `

3. start from back of the array, for example,an one point arrya[i] == 16b,  and  A is greater than 16b, then x5 must be 1, so we add 16 to the final ans。After travel from back to begin of array, we can get the K.

