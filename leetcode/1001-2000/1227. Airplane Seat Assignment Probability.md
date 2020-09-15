> `n` passengers board an airplane with exactly `n` seats. The first passenger has lost the ticket and picks a seat randomly. But after that, the rest of passengers will:
>
> - Take their own seat if it is still available, 
> - Pick other seats randomly when they find their seat occupied 
>
> What is the probability that the n-th person can get his own seat?
>
>  
>
> **Example 1:**
>
> ```
> Input: n = 1
> Output: 1.00000
> Explanation: The first person can only get the first seat.
> ```
>
> **Example 2:**
>
> ```
> Input: n = 2
> Output: 0.50000
> Explanation: The second person has a probability of 0.5 to get the second seat (when first person gets the first seat).
> ```
>
>  
>
> **Constraints:**
>
> - `1 <= n <= 10^5`

```cpp
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n == 1) return 1.0;
        return 0.5;
    }
};
```

the 1st person have n place to select.

f[n] = (1/n)\*(1) + (1/n)(f[n-1]) + (1/n)\*(f[n-2]) + ... + (1/n)/*(f[2])

----pick 1st seat---- pick 2ed seat ----.......------------pick (n-1)th seat

if the first person picks ith seat, then we know anyone between (1, i) gets their own seat.

then when come to person i, it become a sub-problem, that ith is the first person of the sub-problem.