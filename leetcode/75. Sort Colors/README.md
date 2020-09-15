> Given an array with *n* objects colored red, white or blue, sort them **[in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** so that objects of the same color are adjacent, with the colors in the order red, white and blue.
>
> Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
>
> **Note:** You are not suppose to use the library's sort function for this problem.
>
> **Example:**
>
> ```
> Input: [2,0,2,1,1,0]
> Output: [0,0,1,1,2,2]
> ```
>
> **Follow up:**
>
> - A rather straight forward solution is a two-pass algorithm using counting sort.
>   First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
> - Could you come up with a one-pass algorithm using only constant space?



```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        for(int p=0;p<=j;++p){
            if(nums[p] == 0){
                swap(nums[i++], nums[p]);
            }else if(nums[p] == 2){
                swap(nums[j--], nums[p]);
                p--;
            }
        }
        return ;
    }
};
```

important : p<=j, because j means [j+1, ~] is all 2, but nums[j] is unknow.