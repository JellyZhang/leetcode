#### 31. Next Permutation

> Implement **next permutation**, which rearranges numbers into the lexicographically next greater permutation of numbers.
>
> If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
>
> The replacement must be **in-place** and use only constant extra memory.
>
> Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
>
> ```
> 1,2,3` → `1,3,2`
> `3,2,1` → `1,2,3`
> `1,1,5` → `1,5,1
> ```

```cpp
class Solution {
public:
  // 2  3  6  5  4  1
  void nextPermutation(vector<int>& nums) {
        int k,i;
        // from right to left, find the first index not in descend order.
        for(k = nums.size() - 2;k >= 0;k--){
            if(nums[k] < nums[k+1]) break;
        }
        if(k == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        // find the smallest one at right of nums[k]. start from right we can find it easily. start from right words too.
        for(i=nums.size()-1;i>=0;--i){
            if(nums[i] > nums[k]){
                break;
            }
        }
        // now we have the next number to replace nums[k].
        swap(nums[i], nums[k]);
        // now we want all numbers at right of nums[k] be the smallest permutation.
        // since they were descending order, and after the swap, they are still in  descending order.
        // so we can just reverse them, to get the smallest permutation.
        reverse(nums.begin()+k+1,nums.end());
        return;
    }
};
```

