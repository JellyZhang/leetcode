#### 154. Find Minimum in Rotated Sorted Array II

> Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
>
> (i.e.,  `[0,1,2,4,5,6,7]` might become  `[4,5,6,7,0,1,2]`).
>
> Find the minimum element.
>
> The array may contain duplicates.
>
> **Example 1:**
>
> ```
> Input: [1,3,5]
> Output: 1
> ```
>
> **Example 2:**
>
> ```
> Input: [2,2,2,0,1]
> Output: 0
> ```
>
> **Note:**
>
> - This is a follow up problem to [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/).
> - Would allow duplicates affect the run-time complexity? How and why?

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int mid;
        while(low < high){
            mid = (low+high)/2;
            if(nums[low] < nums[high]){
                return nums[low];
            }
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                high--;
                continue;
                // can also do low--, but will need to prove when mid at rotate-point
            }
            if(nums[mid] <= nums[high]){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return nums[low];
    }
};
```

​	we say the ans_index = the rotate point.

1. firstly, get rid of no-rotate-situation, check if nums[low] < nums[high].
2. then we ensure  there is a rotate point.
3. we start from [ low <= high, low=mid+1, high=mid-1]  version. In this version, high may get to the other side, which means high < ans_index.  If so, then we would never find the right ans.
4. To avoid this kind of situation, we should do [low=mid+1, high = mid] verison, after this change, we can find that, if low== high ==mid, then we would be in endless-loop.  Since high is always >= ans_index, low is always <= ans_index. so when low  == high, we can know low == high == ans_index, which is the end the algorithm. so we get our [low < high, low=mid+1, high=mid] version of binary search.
5. Now let's take care of nums[low] == nums[mid] == nums[high] situation. 
   - now that low < high ,we can know mid ≠ high.
   - so we can delete high. Because if the value of nums[high] is the min element, we will find it out in the following steps, because same value nums[mid] is still there.
   - // plus, we can also do [ low++ ] here in addition
   - // image the situation of  low == mid pointing at the same element,  we can know there are only two elementes left in our window.(the other is high). And the two elements are of same value. we do [ low++] wont affect us finding the min value
   - // then the other situation is low and mid are pointing at two different elements, this situation is same as the [high--] situation : delete it is safe because we have another same value element (nums[mid]) in our window, we can still find the right ans.

