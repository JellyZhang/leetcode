> The set `[1,2,3,...,*n*]` contains a total of *n*! unique permutations.
>
> By listing and labeling all of the permutations in order, we get the following sequence for *n* = 3:
>
> 1. `"123"`
> 2. `"132"`
> 3. `"213"`
> 4. `"231"`
> 5. `"312"`
> 6. `"321"`
>
> Given *n* and *k*, return the *k*th permutation sequence.
>
> **Note:**
>
> - Given *n* will be between 1 and 9 inclusive.
> - Given *k* will be between 1 and *n*! inclusive.
>
> **Example 1:**
>
> ```
> Input: n = 3, k = 3
> Output: "213"
> ```
>
> **Example 2:**
>
> ```
> Input: n = 4, k = 9
> Output: "2314"
> ```

```cpp
class Solution {
public:
    vector<int> fact;
    string ans;
    string getPermutation(int n, int k) {
        fact.assign(11, 0);
        vector<int> nums;
        fact[0] = 1;
        for(int i=1;i<=n;++i){
            nums.push_back(i);
            fact[i] = fact[i-1] * i;
        }
        string ans = "";
        k--;
        for(int i=0;i<n;++i){
            int idx = k/fact[n-1-i];
            ans += (nums[idx] + '0');
            nums.erase(nums.begin() + idx);
            k = k%fact[n-1-i];
        }
        return ans;
    }
};
```

假设目前剩下的数有n个，排好序后，若选了当前index=i的数，那么它略过的数就是 i * (n-1)!个

