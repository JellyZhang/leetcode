> Given *n* non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
>
> ![img](rainwatertrap.png)
> The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. **Thanks Marcos** for contributing this image!
>
> **Example:**
>
> ```
> Input: [0,1,0,2,1,0,1,3,2,1,2,1]
> Output: 6
> ```

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int left_max = 0, right_max = 0;
        int ans = 0;
        while(left < right){
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            if(left_max < right_max){
                ans += left_max - height[left];
                left++;
            }else {
                ans += right_max - height[right];
                right--;
            }
        }
        return ans;
    }
};
```

Assume left_max < right_max, then we can know the limit of how much pos[left] can hold is depending on left_max. (Cause we already there at least  one point >= right_max > left_max, so what's on the right doesnot  matter very much).

