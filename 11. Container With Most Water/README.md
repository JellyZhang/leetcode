#### 11. Container With Most Water

> Given *n* non-negative integers *a1*, *a2*, ..., *an* , where each represents a point at coordinate (*i*, *ai*). *n* vertical lines are drawn such that the two endpoints of line *i* is at (*i*, *ai*) and (*i*, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
>
> **Note:** You may not slant the container and *n* is at least 2.
>
> 
>
> ![img](README.assets/question_11-9701039.jpg)
>
> The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
>
> 
>
> **Example:**
>
> ```
> Input: [1,8,6,2,5,4,8,3,7]
> Output: 49
> ```

```c++
int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int ans = 0;
        while(i < j){
            ans = max(ans, (j-i)*min(height[i],height[j]));
            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
```

Two pointer.

Assume index i has a lower height, then the max area it can get is  height[i]*(j-i), since he is the limit of area. After this, we can abandon it from the array by i++.